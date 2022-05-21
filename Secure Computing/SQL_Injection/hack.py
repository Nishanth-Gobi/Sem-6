from flask import Flask, request, redirect, url_for
import pages
import db

app = Flask("__main__")
cur = db.connect()


@app.route("/")
@app.route("/signin", methods=['GET', 'POST'])
def login():
    if request.method == 'GET':
        return pages.signin_page
    elif request.method == 'POST':
        user = request.form['username']
        passw = request.form['pass']
        print("Login:: user: ",user)
        auth = db.user_auth(cur, user, passw)
        if auth:
            return redirect(url_for('success', name=user))
        else:
            return "Error: You are not supposed to be here! "


@app.route("/signup", methods=['GET', 'POST'])
def register():
    if request.method == 'GET':
        return pages.signup_page
    elif request.method == 'POST':
        user = request.form['username']
        passw = request.form['pass']
        print("Login:: user: ",user)
        register(cur, user, passw)
        return redirect(url_for('signin'))


@app.route("/success/<name>")
def home(name):
    return "Welcome %s" % name


if __name__=='__main__':
    app.run(use_reloader=False) 
    
