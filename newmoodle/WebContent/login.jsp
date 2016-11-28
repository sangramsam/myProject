<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head lang="en">
    <meta charset="UTF-8">
    <title>Moodle</title>
    <link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="style.css">
    <script src="bootstrap-3.3.2-dist/js/jquery.js"></script>
    <script src="bootstrap-3.3.2-dist/js/login.js" ></script>
    <link rel="shortcut icon" type="image/x-icon" href="img/picto_navigation.png" />
</head>
<body bgcolor="white">
<div class="container">
    <div class="login">
        <div id="flat">
            <div class="login-icon">
                <img src="img/picto_navigation.png" alt="welcome">
                <h4>Welcome to Moodle</h4>
            </div>
            <div class="login-form">
            <div id="mesg"></div>
                <form class="form-group" method="post" action="/newmoodle/login" id="login">
                <div class="form-group">
                    <div class="input-group input-group-lg">
                        <input type="text" class="form-control" name="username" placeholder="Username" id="username" required>
                        <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                    </div>
                    <label for="username"></label>
                    </div>
                    <div class="form-group">
                        <div class="input-group input-group-lg">
                            <input type="password" class="form-control" placeholder="Password" id="password" required>
                            <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
                        </div>
                        </div>
                        <label for="password"></label>
                     
                                <label for="student" id="std"><input type="radio" id="user" value="student" name="user"/>Student</label>&nbsp;&nbsp;
                                <label for="admin" id="ad"><input type="radio" id="user" value="admin" name="user"/>Admin</label>&nbsp;&nbsp;
                                <label for="faculty" id="fac"><input type="radio" id="user" value="faculty" name="user"/>Faculty</label>
                          
                        
             <button type="submit" class="btn btn-primary btn-lg btn-block" >Log in</button>
                       
            </form>
                    </div>
                </div>

            </div>
        </div>
<script src="bootstrap-3.3.2-dist/js/jquery.js"></script>
<script src="bootstrap-3.3.2-dist/js/bootstrap.min.js"></script>
</body>
</html>