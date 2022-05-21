import sqlite3

connection = sqlite3.connect('userdb.db')
cur = connection.cursor()

CREATE_DB = '''

CREATE TABLE db (

        username TEXT PRIMARY KEY,
        password TEXT NOT NULL
);

'''

cur.execute("DROP TABLE IF EXISTS db;")
cur.execute(CREATE_DB)
cur.execute("SELECT * FROM db;")