import cx_Oracle

def connect_db():
    try:
        cx_Oracle.init_oracle_client("Z:\Secure Computing\instantclient_21_3")
        print("DB connection established")
    except:
        pass

    con = cx_Oracle.connect('MSC19PT09/MSC19PT09@10.1.67.153:1521/ORCL')
    cursor = con.cursor()
    return [cursor, con]


def make_table(cur, con):
    cur.execute('drop table my_comments')
    cur.execute(f'''create table my_comments(comment_text varchar(200))''')
    con.commit()

if __name__ == '__main__':
    
    cur, con = connect_db()
    make_table(cur, con)
    