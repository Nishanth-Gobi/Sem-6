home_page='''
<html>
    <head>
        <title> Login Page </title>
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    </head>
    <body>
    <form class="jumbotron container mt-5" action="/comment" method="POST">
      <h1 class="justify-content-center"> MAKE A COMMENT</h1>
      <div class="form-group">
        <input type="text" name="comment" class="form-control" id="comment" placeholder="Enter Comment">
      </div>
      <button type="submit" class="btn btn-primary">Submit</button>
    </form>
    
    
    <form class="jumbotron container mt-5" action="/search" method="POST">
        <h1 class="justify-content-center"> SEARCH FOR COMMENT </h1>
        <div class="form-group">
          <input type="text" name="query" class="form-control" id="query" placeholder="Search for a comment">
        </div>
        <button type="submit" class="btn btn-primary">Submit</button>
    </form>
    
    <a href="/getComments" type="button" class="btn btn-secondary"> View Comments </a>
    <a href="/resetDB" type="button" class="btn btn-warning"> Reset DB </a>

    </body>
</html>
'''

login_page = '''
    <html>
        <head>
            <title> Login Page </title>
            <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
        </head>
        <body>
        <form class="jumbotron container mt-5" action="/home" method="POST">
          <h1 class="justify-content-center"> LOGIN </h1>
          <div class="form-group">
            <input type="text" name="Username" class="form-control" id="Username" placeholder="Enter Username">
          </div>
          <div class="form-group">
            <input type="text" name="Password" class="form-control" id="Password" placeholder="Enter Password">
          </div>
          <button type="submit" class="btn btn-primary">Submit</button>
        </form>
        </body>
    </html>
'''