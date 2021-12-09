import psycopg2
import json
from random import randint
from faker import Faker

fake = Faker()

host = "127.0.0.1"
user = "postgres"
password = "qwerty123"
db_name = "social_network"

connection = None

def insert_customer(connection, cursor):
    with open("customer.json","r") as read_file: 
        customers = json.load(read_file)

    insert_query = """ INSERT INTO customer (customer_name)
                              VALUES (%s)"""

    for i in range(len(customers)):
        customer = customers[i]
        item_tuple = (customer['customer_name'],)
        cursor.execute(insert_query, item_tuple)
    
    connection.commit()

def get_seller():
    with open("seller.json","r") as read_file: 
        sellers = json.load(read_file)

    for i in range(len(sellers)):
        seller = sellers[i]
        global_sellers.append(seller['name'] + str(i))


def insert_brand(connection, cursor):
    with open("brand.json","r") as read_file: 
        brands = json.load(read_file)

    insert_query = """ INSERT INTO brand (brand_name, designer, foundation_date, country)
                              VALUES (%s, %s, %s, %s)"""

    for i in range(len(brands)):
        brand = brands[i]
        item_tuple = (brand['name'] + str(i), brand['designer'], brand['foundation_date'], brand['country'])
        cursor.execute(insert_query, item_tuple)
    
    connection.commit()

def insert_purchase(connection, cursor):
    with open("order.json","r") as read_file: 
        orders = json.load(read_file)

    insert_query = """ INSERT INTO purchase (registration_date, delivery_date, courier, status)
                              VALUES (%s, %s, %s, %s)"""

    for i in range(len(orders)):
        order = orders[i]
        item_tuple = (order['registration_date'], order['delivery_date'], order['courier'], order['status'])
        cursor.execute(insert_query, item_tuple)
    
    connection.commit()

def insert_product(connection, cursor):
    with open("product.json","r") as read_file: 
        products = json.load(read_file)

    insert_query = """ INSERT INTO product (product_name, category, brand, price, product_rating, seller)
                              VALUES (%s, %s, %s, %s, %s, %s)"""

    for i in range(len(products)):
        product = products[i]
        item_tuple = (product['name'] + str(i), product['category'], product['brand'], product['price'], product['rating'], product['seller'])
        cursor.execute(insert_query, item_tuple)
    
    connection.commit()

def insert_purchase_product(connection, cursor):
    with open("order_product.json","r") as read_file: 
        table = json.load(read_file)

    insert_query = """ INSERT INTO purchase_product (purchase_id, product_id)
                              VALUES (%s, %s)"""

    for i in range(len(table)):
        node = table[i]
        item_tuple = (node['order_id'], node['product_id'])
        cursor.execute(insert_query, item_tuple)
    
    connection.commit()

def delete_data(connection, cursor):
    delete_query = """DELETE FROM seller"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM purchase"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM product"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM brand"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM purchase_product"""
    cursor.execute(delete_query)

    connection.commit()

def customer():
    customers = []
    with open("seller.json","r") as read_file: 
        sellers = json.load(read_file)
    for i in range(1000):
        customer = {}
        flag = randint(1, 2)
        if flag == 1:
            customer['customer_name'] = fake.unique.name()
        else:
            customer['customer_name'] = global_sellers[randint(0, 999)]
            print(customer)

        customers.append(customer)

    with open("customer.json","w") as write_file: 
        json.dump(customers, write_file, indent = 4, separators = (',', ': '))


try:
    connection = psycopg2.connect(
        host=host,
        user=user,
        password=password,
        database=db_name
    )
    connection.autocommit = True

    cursor = connection.cursor()

except Exception as _ex:
    print("[INFO] Error while working with PostgreSQL", _ex)
finally:
    if connection:
        cursor.close()
        connection.close()
        print("[INFO] PostgreSQL connection closed")
