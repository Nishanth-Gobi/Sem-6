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
    
    <a href="/getComments" type="button" class="btn btn-warning"> View Comments </a>
    
    </body>
</html>
'''