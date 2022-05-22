import sqlite3

CREATE_DB = '''
CREATE TABLE db (
        username TEXT PRIMARY KEY,
        password TEXT NOT NULL
);
'''

def connect():
    connection = sqlite3.connect('userdb.db')
    cur = connection.cursor()
    return cur

def user_auth(cur, user, passw):
    query = "SELECT * FROM db WHERE username=" + user + " AND password=" + passw + ";"
    cur.execute(query)
    user_record = cur.fetchall()
    print(user_record)
    return user_record

if __name__ == '__main__':
    cur = connect()
    cur.execute("DROP TABLE IF EXISTS db;")
    cur.execute(CREATE_DB)
    ret = cur.execute("SELECT * FROM db;")
    print(ret)