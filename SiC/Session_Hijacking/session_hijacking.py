from flask import Flask, request, redirect
from flask_session import Session
from page import login_page



app = Flask(__name__)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = 'redis'

Session(app)

def valid_login(username: str, password: str):
    return True
    

@app.route("/", methods=['GET','POST'])
@app.route("/login", methods=['GET','POST'])
def login():
    if request.method == 'POST':
        if valid_login(request.form["Username"], request.form["Password"]):
            session["name"] = request.form["Username"]
            return redirect("/home")
        
    return login_page

@app.route("/home")
def home():
    if Session["name"]:
        pass

@app.route("/logout")
def logout():
    session.pop("name")
    return redirect("/")


if __name__ == '__main__':
    app.run(debug=True)