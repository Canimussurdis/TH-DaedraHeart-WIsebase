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

def insert_users(connection, cursor):
    with open("users.json","r") as read_file: 
        users = json.load(read_file)

    insert_query = """ INSERT INTO users (name, password, mail, birth_date, sex)
                              VALUES (%s, %s, %s, %s, %s)"""

    for i in range(len(users)):
        user = users[i]
        item_tuple = (user["name"], user["password"], user["mail"], user["birth-date"], user["sex"])
        cursor.execute(insert_query, item_tuple)
    
    connection.commit()

def insert_posts(connection, cursor):
    with open("posts.json","r") as read_file: 
        posts = json.load(read_file)

    insert_query = """ INSERT INTO posts (title, content, pub_date, user_id, rating)
                              VALUES (%s, %s, %s, %s, %s)"""

    for i in range(len(posts)):
        post = posts[i]
        item_tuple = (post["title"], post["content"], post["pub_date"], post["user_id"], post["rating"])
        cursor.execute(insert_query, item_tuple)
    
    connection.commit()

def insert_comments(connection, cursor):
    with open("comments.json","r") as read_file: 
        comments = json.load(read_file)

    insert_query = """ INSERT INTO comments (content, post_id, user_id)
                              VALUES (%s, %s, %s)"""

    for i in range(len(comments)):
        comment = comments[i]
        item_tuple = (comment["content"], comment["post_id"], comment["user_id"])
        cursor.execute(insert_query, item_tuple)
    
    connection.commit()

def delete_data(connection, cursor):
    delete_query = """DELETE FROM users"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM posts"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM comments"""
    cursor.execute(delete_query)

    connection.commit()

try:
    connection = psycopg2.connect(
        host=host,
        user=user,
        password=password,
        database=db_name
    )
    connection.autocommit = True

    cursor = connection.cursor()

    delete_data(connection, cursor)
    insert_users(connection, cursor)
    insert_posts(connection, cursor)
    insert_comments(connection, cursor)

except Exception as _ex:
    print("[INFO] Error while working with PostgreSQL", _ex)
finally:
    if connection:
        cursor.close()
        connection.close()
        print("[INFO] PostgreSQL connection closed")
