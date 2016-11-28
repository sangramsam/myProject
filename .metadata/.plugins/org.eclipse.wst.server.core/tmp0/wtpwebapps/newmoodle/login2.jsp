<%@ page language="java" contentType="text/html; charset=ISO-8859-1"  pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head lang="en">
    <meta charset="UTF-8">
    <title>Moodle</title>
    <link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="style.css">
    <script src="bootstrap-3.3.2-dist/js/jquery.js"></script>
    <script src="bootstrap-3.3.2-dist/js/jquery.validate.min.js"></script>
    <script src="bootstrap-3.3.2-dist/js/validate.js" ></script>
        <script src="bootstrap-3.3.2-dist/js/login.js" ></script>
    <script src="bootstrap-3.3.2-dist/js/insert.js" ></script>
    <script src="bootstrap-3.3.2-dist/js/changePasssword.js" ></script>
        
    
 <link rel="shortcut icon" type="image/x-icon" href="img/picto_navigation.png" />
</head>
<body>
<nav class="navbar navbar-fixed-top navbar-inverse  no-margin navbar-inner " style="height: 30px">
        <div class="navbar-header">
            <button type="button" class="navbar-toggle collapsed " data-toggle="collapse" data-target="#bs-itm-navbar-collapse-1">
                <span class="sr-only ">Toggle navigation</span>
                <span class="glyphicon glyphicon-play" style="color: #ffffff"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
            <a class="navbar-brand w pull-left" href="#" style="top:2px"><h4><b>ITMU Moodle</b></h4></a>
        </div>

        <div class="collapse navbar-collapse navbar-right" id="bs-itm-navbar-collapse-1">
            <ul class="nav navbar-nav">
                <li rol="presentation"><a href="First.jsp">Home</a> </li>
            </ul>

        </div>

</nav>
<br/>
<br/>
<br/>
<div class="container">
<div class="col-lg-12">
<div class="panel panel-default" style="background-color: #dcdcdc;background-color: rgba(255,255,255,0.6);">
    <div class="panel-heading" style="background-color:#1abc9c;color:white!important;"><p><strong>Login To Your Account/ Register New</strong></p></div>
    <div class="panel-body">
        <div class="col-md-6">
            <h3 style="color: #000000">Log In</h3>
            <div class="login-form">
            
  				 <form class="form-group" method="post" action="/newmoodle/login" id="login">
  				 <div class="form-group">
                    <div class="input-group input-group-lg">
                        <input type="text" class="form-control" name="username" placeholder="Username" id="username">
                        <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                    </div>
                    <label id="usrname-error" class="error" for="username"></label>
                    </div>
                    <div class="form-group">
                        <div class="input-group input-group-lg">
                            <input type="password" class="form-control" placeholder="Password" id="password" name="password">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
                        </div>
                        <label id="ppassword-error" class="error" for="password"></label>
                        </div>
                        
                        
                        <div class="form-group  ">
                            <div class="input-group input-group-lg">
                                <label for="student" id="std"><input type="radio" id="user" name="user" value="student" name="user"/>Student</label>&nbsp;&nbsp;
                                <label for="admin" id="ad"><input type="radio" id="user" value="admin"  name="user"/>Admin</label>&nbsp;&nbsp;
                                <label for="faculty" id="fac"><input type="radio" id="user" value="faculty" name="user"/>Faculty</label>
                            </div>
                        </div>
                        <button class="btn btn-primary btn-lg btn-block" type="submit" >Log in</button>
                        <div id="mesg"> </div>
                        </form>
                        <a class="login-link" data-toggle="modal" data-target=".changePassword">Lost your password?</a>
                        
                        <div class="modal fade changePassword" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true" data-backdrop="static" data-keyboard="false">
                            <div class="modal-dialog modal-lg">
                                <div class="modal-content">
                                <div class="modal-header" style="background-color:#1abc9c;">
        		<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        		<h4 class="modal-title" style="text-align:center" ><b>Change Your Password </b></h4>
     					 </div>
                                    <div class="login-form">
                                    
                                        <form class="form-group" method="post" action="/newmoodle/changePassword" id="change">
                                        <div class="form-group">
                                            <div class="input-group input-group-sm">
                                                <input type="text" class="form-control"  placeholder="Username" id="fusername" name="fusername">
                                                <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                                            </div>
                                            <label id="usrname-error" class="error" for="fusername"></label>
                                            </div>
                                            
                                            <div class="form-group">
                                                <div class="input-group input-group-sm">
                                                    <input type="password" class="form-control" placeholder="Password" id="fpassword" name="fpassword">
                                                    <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
                                                </div>
                                                     <label id="ppassword-error" class="error" for="fpassword"></label>
                                            </div>
                                            
                                            <div class="form-group">
                                                <div class="input-group input-group-sm">
                                                    <input type="password" class="form-control" placeholder="Confirm Password" id="fcpassword" name="fcpassword">
                                                    <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
                                                </div>
                                                <label id="ppassword-error" class="error" for="fcpassword"></label>
                                                
                                            </div>
                                        
                                            <div class="form-group">
                                                <div class="input-group input-group-sm">
                                                    <input type="date" class="form-control dateclass placeholderclass" placeholder="Date of Birth" id="dob" name="dob" onclick="$(this).removeClass('placeholderclass')">
                                                    <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
                                                </div>
                                                <label id="DOB-error" class="error" for="dob"></label>
                                            </div>
                                            <label style="color:#16A085">Please select</label>
                                            <div class="form-group  ">
                            <div class="input-group input-group-lg">
                                <label for="student" id="std"><input type="radio" id="cuser" name="cuser" value="student" name="user"/>Student</label>&nbsp;&nbsp;
                                <label for="admin" id="ad"><input type="radio" id="cuser" value="admin"  name="cuser"/>Admin</label>&nbsp;&nbsp;
                                <label for="faculty" id="fac"><input type="radio" id="cuser" value="faculty" name="cuser"/>Faculty</label>
                            </div>
                        </div>
                                            <button type="submit" class="btn btn-primary">Change</button>
                                            <div id="resp" style="color:red"></div>
                                        </form>
                                        </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
        <div class="col-md-6">
            <h3 style="color: #000000">Sign up New Account</h3>
            <div class="login-form">
                <form class="form-group" action="/newmoodle/student_signup" method="Post" id="signup">
                    <div class="form-group ">
                        <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="please enter your name" >
                            <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                            <input type="text" class="form-control" id="name" name="name" placeholder="name">
                        </div>
                        <label id="text-error" class="error" for="name"></label>
                    </div>
                    <div class="form-group ">
                        <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="please enter Roll no" >
                            <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                            <input type="text" class="form-control" id="rollno" name="rollno" placeholder="Roll-No">
                        </div>
                        <label id="rollno-error" class="error" for="rollno"></label>
                    </div>
                    <div class="form-group">
                        <div class="input-group  input-group-sm"  data-toggle="tooltip" data-placement="left" title="please enter at least 8 character long password">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
                            <input type="password" class="form-control" id="Password" name="Password" placeholder="password">
                        </div>
                        <label id="password-error" class="error" for="Password"></label>
                    </div>
                    <div class="form-group">
                        <div class="input-group  input-group-sm"  data-toggle="tooltip" data-placement="left" title="Reapeat password">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
                            <input type="password" class="form-control" id="Rpassword" name="Rpassword" placeholder="Confirm-password">
                        </div>
                        <label id="Rpassword-error" class="error" for="Rpassword"></label>
                    </div>
                    <div class="form-group">
                        <div class="input-group  input-group-sm"  data-toggle="tooltip" data-placement="left" title="please enter valid email id">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-envelope" ></span> </div>
                            <input type="email" class="form-control" id="email" name="email" placeholder="email">
                        </div>
                        <label id="email-error" class="error" for="email"></label>
                    </div>
                    <div class="form-group">
                        <div class="input-group  input-group-sm"  data-toggle="tooltip" data-placement="left" title="please enter your course">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-book"></span> </div>
                            <input type="text" class="form-control" id="course" name="course" placeholder="Course">
                        </div>
                        <label id="course-error" class="error" for="course"></label>
                    </div>
                    <div class="form-group">
                        <div class="input-group  input-group-sm"  data-toggle="tooltip" data-placement="left" title="please enter your semester">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-book"></span> </div>
                            <input type="text" class="form-control" id="sem" placeholder="semester" name="sem" >
                        </div>
                        <label id="sem-error" class="error" for="sem"></label>
                    </div>
                    <div class="form-group">
                        <div class="input-group  input-group-sm"  data-toggle="tooltip" data-placement="left" title="please enter your Date of Bitrh">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-book"></span> </div>
                            <input type="date" class="form-control" id="DOB" placeholder="DOB" name="DOB">
                        </div>
                        <label id="DOB-error" class="error" for="DOB"></label>
                    </div>
                    <div class="form-group">
                    <button type="submit" class="btn btn-success center-block" value="login" id="btn">Sign Up</button>
                    </div>
                </form>
        </div>
    </div>
</div>
</div></div></div>
                    <script type="text/javascript">
                        $( document ).ready(function() {
                            $("[data-toggle=tooltip]").tooltip();
                        });</script>

<script src="bootstrap-3.3.2-dist/js/bootstrap.min.js"></script>
</body>
</html>