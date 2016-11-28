<%@ page language="java" contentType="text/html; charset=ISO-8859-1"  pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head lang="en">
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Moodle</title>
    <link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="style.css">
    <script src="bootstrap-3.3.2-dist/js/jquery.js"></script>
     <script src="bootstrap-3.3.2-dist/js/insert.js" type="text/javascript"></script>
      <script src="bootstrap-3.3.2-dist/js/frontPageLogin.js" ></script>
    <link rel="shortcut icon" type="image/x-icon" href="img/picto_navigation.png" />
</head>
<body class="modal-open" >
<nav class="navbar navbar-inverse navbar-fixed-top navbar-static-top no-margin navbar-inner " style="height:50px!important;">

        <div class="navbar-header">
            <button type="button" class="navbar-toggle collapsed " data-toggle="collapse" data-target="#bs-itm-navbar-collapse-1">
                <span class="sr-only ">Toggle navigation</span>
                <span class="glyphicon glyphicon-play" style="color: #ffffff"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
            <a class="navbar-brand w" href="#"><img src="img/moodlelogo.jpg"></a>
        </div>

        <div class="collapse navbar-collapse navbar-right" id="bs-itm-navbar-collapse-1">
            <ul class="nav navbar-nav">
                <li ><a id="navv" data-toggle="modal" data-target=".bs-example-modal-md" ><b>Login</b></a> </li>
            </ul>

        </div>

</nav>
<div class="back">
    <div class="col-md-7">
    </div>
    <div class="col-md-5" style="top: 80px">
        <div class="panel panel-default">
            <div class="panel-heading">
                <h1 class="panel-title text-center" style="height: 40px;font-size: 28px">Are you at Moodle? Join Us !</h1>
            </div>
            <div class="panel-body">
                <div class="login-form">
                    <form class="form-group" action="/newmoodle/student_signup" method="POST" id="signup" name="signup">
                            <div  data-toggle="tooltip" data-placement="left" title="please enter your name" >
                                <label class="col-sm-3 col-sm-offset-1 control-label" style="color: #000000" for="firstname">Name<sup style="color: #ff0000">*</sup></label>
                                <div class="col-sm-4 " ><input type="text" class="form-control"style="width: 90%!important;" id="firstname" name="firstname" placeholder="First Name" required></div>
                                <div class="col-sm-4 " ><input type="text" class="form-control"style="width: 90%!important;" id="Lastname" name="Lastname" placeholder="Last Name" required></div>
                            </div>
                            <label id="text-error" class="error" for="name"></label>
                            <div  data-toggle="tooltip" data-placement="left" title="please enter Roll no" >
                                <label  class="col-sm-3 col-sm-offset-1" for="rollno" style="color: #000000">Roll-No<sup style="color: #ff0000">*</sup></label>
                              <div class="col-sm-6">  <input type="text" class="form-control" id="rollno" name="rollno" placeholder="Roll-No" style="width:132%!important;" required >
                            </div>
                            </div>
                        <br/>
                            <label id="rollno-error" class="error" for="rollno"></label>

                            <div   data-toggle="tooltip" data-placement="left" title="please enter at least 8 character long password">
                                <label  class="col-sm-3 col-sm-offset-1" for="password" style="color: #000000">Password<sup style="color: #ff0000">*</sup></label>
                                <div class="col-sm-6"><input type="password" class="form-control" id="Password" name="Password" placeholder="password" style="width: 132%!important;" required >
                            </div>
                                </div><br/>
                            <label id="password-error" class="error" for="Password"></label>
                            <div  data-toggle="tooltip" data-placement="left" title="please enter valid email id">
                                <label  class="col-sm-3 col-sm-offset-1" for="email" style="color: #000000">Email<sup style="color: #ff0000">*</sup></label>
                                <div class="col-sm-6">  <input type="email" class="form-control" id="email" name="email" placeholder="email" style="width: 132%!important;"   required>
                            </div>
                                </div><br/>
                            <label id="email-error" class="error" for="email"></label>


                            <div data-toggle="tooltip" data-placement="left" title="please enter your course">
                                <label  class="col-sm-3 col-sm-offset-1" for="course" style="color: #000000">Course<sup style="color: #ff0000">*</sup></label>
                                <div class="col-sm-6">
                                <input type="text"  id="course" class="form-control" name="course" placeholder="Course" style="width: 132%!important;"  required >
                            </div></div><br/>
                            <label id="course-error" class="error" for="course"></label>


                            <div  data-toggle="tooltip" data-placement="left" title="please enter your semester">
                                <label  class="col-sm-3 col-sm-offset-1" for="sem" style="color: #000000">Semester<sup style="color: #ff0000">*</sup></label>
                                <div class="col-sm-6"><input type="text" class="form-control " id="sem" style="width: 132%!important;"  placeholder="semester" name="sem"  required></div>
                            </div><br/>
                            <label id="sem-error" class="error" for="sem"></label>
                        <div  data-toggle="tooltip" data-placement="left" title="please enter your semester">
                            <label  class="col-sm-3 col-sm-offset-1" for="sem" style="color: #000000">Gender<sup style="color: #ff0000">*</sup></label>
                            <div class="col-sm-6"><label class="radio-inline">
                                <input type="radio" name="gender" id="gender" value="male"  required> <b>Male</b>
                            </label>
                                <label class="radio-inline">
                                    <input type="radio" name="gender" id="gender" value="female"  > <b>Female</b>
                                </label>
                                </div>
                        </div><br/>
                        <div class="form-group">
                            <div class="col-sm-offset-4 col-sm-6">
                          
                                <input type="submit" class="btn btn-primary btn-md btn-block " value="Sign Up">
                            </div>
                        </div>
                    </form>
                    </div><br/>

            </div>
            <div id="mesg"></div>
            <div class="panel-footer"style=" font-size: 10px;"><small>By clicking Sign Up, you agree to our Terms and Conditions and that you have read our Data Use Policy, including our Cookie Use.</small></div>
        </div>

    </div>

</div>
<div id="back2">
    <div class="striped ">
        <h2>connecting moodle</h2>
    </div>
    <br/>
    <div class="col-sm-6 col-md-3 div_thumbnails">
        <div class="div_thumb_img text-center"> <span class=" glyphicon glyphicon-user"></span>

        </div>
        <h2>Create Profile</h2>
    </div>
    <div class="col-sm-6 col-md-3 div_thumbnails">
        <div class="div_thumb_img text-center">
            <span class=" glyphicon glyphicon-question-sign"></span>
        </div>
        <h2>Ask Question</h2>
    </div>
    <div class="col-sm-6 col-md-3 div_thumbnails">
        <div class="div_thumb_img text-center"><span class=" glyphicon glyphicon-share"></span></div>
        <h2>Share </h2>
    </div>
    <div class="col-sm-6 col-md-3 div_thumbnails">
        <div class="div_thumb_img text-center"><span class=" glyphicon glyphicon-upload"></span></div>
        <h2>Upload Material</h2>
    </div>
</div>
<div id="back3"><div class="striped ">
    <h2 style="background-color: #14947b!important;">study</h2>
</div>
    <br/>
    <div class="col-sm-6 col-md-3 div_thumbnails">
        <div class="div_thumb_img text-center"> <span class=" glyphicon glyphicon-refresh"></span>

        </div>
        <h2>Academic Upadates</h2>
    </div>
    <div class="col-sm-6 col-md-3 div_thumbnails">
        <div class="div_thumb_img text-center">
            <span class="glyphicon glyphicon-comment"></span>
        </div>
        <h2>Chat</h2>
    </div>
    <div class="col-sm-6 col-md-3 div_thumbnails">
        <div class="div_thumb_img text-center"><span class="glyphicon glyphicon-bullhorn"></span></div>
        <h2>Discuss Forum</h2>
    </div>
    <div class="col-sm-6 col-md-3 div_thumbnails">
        <div class="div_thumb_img text-center"><span class=" glyphicon glyphicon-download"></span></div>
        <h2>Download Material</h2>
    </div>
</div>
<!-- Login modal -->
<div class="modal fade bs-example-modal-md" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
                    <div class="modal-dialog modal-md">
                        <div class="modal-content">
                            <div class="panel panel-default">
                                <div class="panel-heading" style="background-color:#39424e;color:white!important; text-align: center;font-size: larger"><p><strong>Sign In</strong></p></div>
                                <div class="panel-body" style="background-color:#f5f5f5!important;">

                                    <div class=" col-md-offset-2 col-md-8">
                                        <div class="login-form">
            
  				 <form class="form-group" method="post" action="/newmoodle/login" id="login">
  				 <div class="form-group">
                    <div class="input-group input-group-lg">
                        <input type="text" class="form-control" name="lusername" placeholder="Username" id="lusername">
                        <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                    </div>
                    <label id="usrname-error" class="error" for="username"></label>
                    </div>
                    <div class="form-group">
                        <div class="input-group input-group-lg">
                            <input type="password" class="form-control" placeholder="Password" id="lpassword" name="lpassword">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
                        </div>
                        <label id="ppassword-error" class="error" for="password"></label>
                        </div>
                        <div class="form-group">
                            <div class="input-group input-group-lg">
                                <label for="student" id="std"><input type="radio" id="user" name="user" value="student" name="user"/>Student</label>&nbsp;&nbsp;
                                <label for="admin" id="ad"><input type="radio" id="user" value="admin"  name="user"/>Admin</label>&nbsp;&nbsp;
                                <label for="faculty" id="fac"><input type="radio" id="user" value="faculty" name="user"/>Faculty</label>
                            </div>
                        </div>
                        <button class="btn btn-primary btn-lg btn-block" type="submit" >Log in</button>
                        <div id="response" style="color:red"> </div>
                        </form>
                        <a class="login-link" data-toggle="modal" data-target=".changePassword">Lost your password?</a>

                                        </div>

                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
            </div>


                            <script type="text/javascript">
                                $( document ).ready(function() {
                                    $("[data-toggle=tooltip]").tooltip();
                                });</script>
<div class="container">

</div>
<footer class="site-footer">
    <div class="container">
        <div class="row">
            <div class="col-md-5 col-md-offset-4" >
                <h4>Contact Address</h4>
                <address style="color:#ffffff">
                    ITM University<br/>
                    Opp. Sithouli Railway Station,<br/>
                    NH-75 Sithouli, Jhansi Road,<br/>
                    Gwalior, Madhya Pradesh, India<br/>
                    Pin- 474001
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