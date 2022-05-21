from flask import Flask, request, redirect, url_for
import page
import db 

app = Flask(__name__)
cur, con = db.connect_db()


@app.route('/')
def home():
    return page.home_page


@app.route('/comment', methods=['POST'])
def data():
    comment = request.form["comment"]
    # print(comment)
    cur.execute(f'''insert into rxss_comments values('{comment}')''')
    con.commit()
    return redirect(url_for("home"))
    

@app.route('/getComments')
def get_comments():
    cur.execute('select * from rxss_comments')
    data = cur.fetchall()
    return str(data)

@app.route('/resetDB')
def reset_db():
    cur.execute('truncate table rxss_comments')
    con.commit()
    return redirect(url_for("home"))

@app.route('/search')
def search_comment():
    query = request.args.get("query")
    print(query)
    cur.execute(f'''select * from rxss_comments where comment_text = '{query}' ''')
    data = cur.fetchall()
    if(len(data) == 0):
        return f'''{query} not found'''
    return str(data)
 
if __name__ == '__main__':
    app.run()

# <script> alert("You have been hacked!") </script>