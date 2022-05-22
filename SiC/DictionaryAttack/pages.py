signin_page = '''
<html>
<head></head>
<body>
    <p>Sign In</p><br>
    
    <form action='/login' method='POST'>
        <label>Username:</label>
        <input type='text' name='username'>
        <label>Password:</label>
        <input type='text' name='pass'>
        <input type='submit' value='Sign In'>
    </form>

    <br>
    <p>New here? Click here to <a href='signup'>Sign up</a></p>

</body>
</html>

'''

signup_page = '''
<html>
<head></head>
<body>
    <p>Sign Up</p><br>
    
    <form action='/signup' method='POST'>
        <label>Username:</label>
        <input type='text' name='username'>
        <label>Password:</label>
        <input type='text' name='pass'>
        <input type='submit' value='Sign-Up'>
    </form>

    <br>
    <p>Have an account? <a href='signin'>Sign in</a> instead.</p>

</body>
</html>
'''
