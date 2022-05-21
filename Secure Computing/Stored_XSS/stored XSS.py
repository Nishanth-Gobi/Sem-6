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
    cur.execute(f'''insert into my_comments values('{comment}')''')
    con.commit()
    return redirect(url_for("home"))
    

@app.route('/getComments')
def get_comments():
    cur.execute(f'''select * from my_comments''')
    data = cur.fetchall()
    return str(data)

 
if __name__ == '__main__':
    app.run()

# <script> alert("You have been hacked!") </script>