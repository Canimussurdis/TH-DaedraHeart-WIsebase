import json
from faker import Faker
from random import randint

fake = Faker()

def users():
    users = []
    for i in range(10):
        user = {}
        user['name'] = fake.name()
        user['password'] = fake.word() + str(randint(1, 1000))
        user['mail'] = fake.ascii_email()
        user['birth-date'] = fake.date()

        users.append(user)

    with open("users.json","w") as write_file: 
        json.dump(users, write_file, indent = 4, separators = (',', ': '))

def posts():
    posts = []
    for i in range(20):
        post = {}
        post['title'] = fake.paragraph(1)
        post['content'] = fake.paragraph(4)
        post['pub_date'] = fake.date()
        post['user_id'] = randint(1, 10)

        posts.append(post)

    with open("posts.json","w") as write_file: 
        json.dump(posts, write_file, indent = 4, separators = (',', ': '))

def comments():
    comments = []
    for i in range(40):
        comment = {}
        comment['content'] = fake.paragraph(3)
        comment['user_id'] = randint(1, 10)
        comment['post_id'] = randint(1, 20)

        comments.append(comment)

    with open("comments.json","w") as write_file: 
        json.dump(comments, write_file, indent = 4, separators = (',', ': '))
        
users()
posts()
comments()