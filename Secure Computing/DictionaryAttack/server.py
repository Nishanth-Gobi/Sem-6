from flask import Flask, request, redirect, url_for
import pages

app = Flask(__name__)


@app.route("/failure")
def failure():
    return "Illegal access"


@app.route("/login", methods = ['GET', 'POST'])
def login():
    if request.method=='POST' and 'username' in request.args:
        print("here")
        user = request.args.get('username')
        pas = request.args.get('pass')
        return user
      
    return pages.signin_page


if __name__ == '__main__':
    app.run(debug=True)


'''

@app.route('/welcome/<name>')
def welcome(name):
    return "Youre' In %s!" % name


@app.route("/signup", methods=['GET','POST'])
def signup():    
    
    if request.method == 'POST':

        user = request.args.get('username')
        pas = request.args.get('pass')    
        if pas=='password':
            return redirect(url_for('welcome', name = user))
        else:
            return redirect(url_for('signin'))

    return pages.signup_page   


@app.route("/signin", methods=['GET','POST'])
def signin():

    if request.method == 'POST':
        user = request.args.get('username')
        pas = request.args.get('pass')    
        if pas=='password':
            return redirect(url_for('welcome', name = user))
   
    return pages.signin_page
    
'''