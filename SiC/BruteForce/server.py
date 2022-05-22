from flask import Flask, request

app = Flask(__name__)

home_page = '''
<html>
<head></head>
<body>
    <form action='/welcome'>
        <input type='text' name='username'>
        <input type='text' name='pass'>
        <input type='submit'>
</body>
</html>
'''

@app.route("/")
def home():
    return home_page


@app.route("/welcome")
def welcome():
    #print(request.args.get('username'))
    if request.args.get('username') == 'nish' and ( request.args.get('pass') == '111' or request.args.get('pass') == '1111' or request.args.get('pass') == '11111'):
        return "Youre' In!"

    return "***Illegal access***"

if __name__ == '__main__':
    app.run(debug=True)