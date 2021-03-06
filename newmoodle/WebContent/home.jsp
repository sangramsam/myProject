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
    <script src="bootstrap-3.3.2-dist/js/jquery.validate.min.js"></script>
    <script src="bootstrap-3.3.2-dist/js/validate.js" ></script>
    <script src="bootstrap-3.3.2-dist/js/insert.js" ></script>
    <link rel="shortcut icon" type="image/x-icon" href="img/picto_navigation.png" />
    <style type="text/css">
    .error
    {
    color:red:
    }
    </style>
</head>
<body>

<nav class="navbar navbar-fixed-top navbar-static-top no-margin navbar-inner navbar-inverse navbar-embossed navbar-inverse ">
        <div class="navbar-header">
            <button type="button" class="navbar-toggle collapsed " data-toggle="collapse" data-target="#bs-itm-navbar-collapse-1">
                <span class="sr-only ">Toggle navigation</span>
                <span class="glyphicon glyphicon-play" style="color: #ffffff"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
            <a class="navbar-brand w" href="#"><b>ITMU Moodle<b></b></a>
        </div>

        <div class="collapse navbar-collapse navbar-right" id="bs-itm-navbar-collapse-1">
            <ul class="nav navbar-nav">
                <li rol="presentation" class=""><a href="#">Home</a> </li>
                <li rol="presentation"><a href="login.jsp">Login</a> </li>
            </ul>

        </div>

</nav>
<br/><br/><br/>
<div class="container">
    <div class="row">
    <div class="col-md-7 pd">

                <img src="img/logo2.png"class="img-responsive" height="150px" width="350px">
        <div class="container">
            <br/><br/>
        <p style="color:#f5f5f5; font-size: larger" class="text-justify">Awarded on 19 Feb. 2014 by Padma Vibhushan<br/>
            Dr. Karan Singh, Former Union Minister,selected by a process<br/>
            and Jury approved by Planning Commission of India HRD  <br/>(GOI) &
            Assocham.ITM University is a multidisciplinary <br/> university known for
             its quality of research and <br/>teaching across the academic  <br/>spectrum, 
            with subjects  <br/>spanning the sciences, engineering, management, fine arts,<br/>
             social sciences, 
            arts, nursing etc. </p>
            <script>
            $(function () {
            	  $('[data-toggle="popover"]').popover()
            	})
            </script>
           <button type="button" class="btn btn-default" data-container="body" data-toggle="popover" data-placement="bottom" data-content="Vivamus sagittis lacus vel augue laoreet rutrum faucibus."">
  select
</button>

        </div>
    </div>
    <div class="col-md-5  pull-right">
        <!-- Nav tabs -->
        <ul class="nav nav-tabs" role="tablist">
            <li role="presentation" class="active"><a href="#home" aria-controls="home" role="tab" data-toggle="tab">Sign up</a></li>
            <li role="presentation"><a href="#profile" aria-controls="profile" role="tab" data-toggle="tab">Login</a></li>
        </ul>
        <!-- Tab panes -->
        <div class="tab-content">
            <div role="tabpanel" class="tab-pane fade in active"  id="home">
                <div class="panel panel-default " style="max-width: 494px;max-height: 670px">
                        <div class="panel-body " style="background-color:#2ec866"><h4 class="panel-title text-center" style="color: #f5f5f5">SIGN UP</h4></div>
                    <div class="panel-body "  >
                        <form class="form-group" action="/newmoodle/student_signup" method="Post" id="signup">
                        <div id="mesg"></div>
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
                                    <input type="date" class="form-control" id="DOB" placeholder="DOB"  name="DOB">
                                </div>
                                <label id="DOB-error" class="error" for="DOB"></label>
                            </div>
                                <button type="submit" class="btn form-control btn-success navbar navbar-btn signup-btn" value="sign up" id="btn">Sign Up</button>
                        </form>
                    </div>
                </div>
            </div>
            <div role="tabpanel" class="tab-pane fade" id="profile">
                <div class="panel panel-default" style="max-width: 474px;max-height: 480px">
                <div class="panel-heading" style="background-color: #2ec866">
                    <div class="panel-body " style="background-color:#2ec866"><h4 class="panel-title text-center" style="color: #f5f5f5"><b>Login</b></h4></div>
                </div>
                <div class="panel-body" >
                    <form class="form-group"  method="post" action="/newmoodle/login" id="login">
                        <div class="form-group">
                            <div class="input-group input-group-lg" data-toggle="tooltip" data-placement="left" title="please enter your username">
                                <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                                <input type="text" class="form-control" name="username"  id="username"placeholder="Username">
                            </div>
                            <label id="usrname-error" class="error" for="username"></label>
                        </div>
                        <div class="form-group">
                            <div class="input-group input-group-lg" data-toggle="tooltip" data-placement="left" title="please enter your password">
                                <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
                                <input type="password" class="form-control" placeholder="Password" name="password" id="ppassword">
                            </div>
                            <label id="ppassword-error" class="error" for="password"></label>
                        </div>
                        <label for="student" id="std"><input type="radio" id="user" value="student" name="user"/>Student</label>&nbsp;&nbsp;
                                <label for="admin" id="ad"><input type="radio" id="user" value="admin" name="user"/>Admin</label>&nbsp;&nbsp;
                                <label for="faculty" id="fac"><input type="radio" id="user" value="faculty" name="user"/>Faculty</label>
                        <div class="form-group ">
                            <label for="password" class="pull-right" ><a href="#"  ><small>forgot Password</small></a></label>
                        </div>
                        <input type="submit" class="btn btn-success navbar navbar-btn signup-btn" value="login">
                    </form>
                    </div>
                   <script type="text/javascript">
                       $( document ).ready(function() {
                           $("[data-toggle=tooltip]").tooltip();
                       });</script>
                </div>
            </div></div>

        </div>
</div></div>
<br/>
<br/>
<br/>
<br/>
<div class="container">

</div>
<div class="jumbotron op fnt non "  >
    <div class="container">
        <div class="row">
        <div class="col-md-4">
            <figure>
            <img src="img/itm1.jpg"  height="150px"class="img-responsive img-rounded">
                <figcaption><h4 style="color:#ffffff" align="center">ITM UNIVERSITY <br/><small>(MG Block)</small></small></h4></figcaption>
            </figure>
        </div>
        <div class="col-md-4">
            <figure>
                <img src="img/itm2.jpg" height="159px"class="img-responsive img-rounded" >
                <figcaption><h4 style="color:#ffffff" align="center">ITM UNIVERSITY<br/><small>(Main Gate)</small></small></h4></figcaption>
            </figure>
        </div>
        <div class="col-md-4">
            <figure>
            <img src="img/Capture1.JPG" height="158px" class="img-responsive img-rounded">
            <figcaption><h4 style="color:#ffffff" align="center">ITM UNIVERSITY<br/><small>(SOB)</small></small></h4></figcaption>
            </figure>
        </div>

</div>
    </div>
</div>
<br/><br/>
<div class="jumbotron op fnt non jum"  >
    <div class="container">
    <marquee><h3>Welcome to ITM University</h3></marquee>                     
</div>
</div>
    <br/><br/>
    <br/>
    
<footer class="site-footer">
    <div class="container">
        <div class="row">
            <div class="col-md-5">
                <h4>Contact Address</h4>
                <address style="color:#ffffff">
                    ITM University Opp.<br/>
                    Sithouli Railway Station,<br/>
                    NH-75 Sithouli, Jhansi Road,<br/>
                    Gwalior, Madhya Pradesh 474001
                </address>
            </div>
        </div>
        <div class="bottom-footer">
            <div class="col-md-5">@Copyright ITM University Gwalior(MP).</div>
            <div class="col-md-7">
                <ul class="footer-nav">
                    <li><a href="boot.html">Home</a> </li>
                    <li><a href="index.htm">Index</a></li>
                    <li><a href="contact.html">Contacts</a> </li>
                    <li><a href="Link.html">Links</a> </li>
                </ul>
            </div>
        </div>
    </div>
</footer>



<script src="bootstrap-3.3.2-dist/js/bootstrap.min.js"></script>
</body>
</html>