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
    <script src="validate.js" type="text/javascript"></script>
    <link rel="shortcut icon" type="image/x-icon" href="img/picto_navigation.png" />
</head>
<body>
<nav class="navbar navbar-inverse navbar-fixed-top navbar-static-top no-margin navbar-inner ">
    <div class="container">
        <div class="navbar-header">
            <button type="button" class="navbar-toggle collapsed " data-toggle="collapse" data-target="#bs-itm-navbar-collapse-1">
                <span class="sr-only ">Toggle navigation</span>
                <span class="glyphicon glyphicon-play" style="color: #ffffff"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
            <a class="navbar-brand w" href="#"><b><h4>ITMU Moodle</b></h4></a>
        </div>
        <div class="collapse navbar-collapse navbar-right" id="bs-itm-navbar-collapse-1">
            <ul class="nav navbar-nav">
                <li rol="presentation"><a href="#">Home</a> </li>
                <li rol="presentation"><a href="login2.jsp">Login</a> </li>
                <li role="presentation"><a href="#footer">Contact Us</a></li>
            </ul>

        </div>
    </div>
</nav>
<br/>
<br/>
<br/>
<br/>
<div class="container">
        <div id="carousel-example-generic" class="carousel slide" data-ride="carousel">
            <!-- Indicators -->
            <ol class="carousel-indicators">
                <li data-target="#carousel-example-generic" data-slide-to="0" class="active"></li>
                <li data-target="#carousel-example-generic" data-slide-to="1"></li>
                <li data-target="#carousel-example-generic" data-slide-to="2"></li>
                <li data-target="#carousel-example-generic" data-slide-to="3"></li>
                <li data-target="#carousel-example-generic" data-slide-to="4"></li>
            </ol>
            <!-- Wrapper for slides -->
            <div class="carousel-inner" role="listbox">
                <div class="item active">
                    <img src="img/website_home_page2.jpg" alt="item1">
                    <div class="carousel-caption" style="color:#000000">

                    </div>
                </div>
                <div class="item">
                    <img src="img/website_home_page3.jpg" alt="picc">
                    <div class="carousel-caption" style="color:#000000">

                    </div>
                </div>
            <div class="item">
                <img src="img/website_home_page4.jpg" alt="picc">
                <div class="carousel-caption">

                </div>
            </div>
            <div class="item">
                <img src="img/website_home_page5.jpg" alt="picc">
                <div class="carousel-caption">

                </div>
            </div>
        </div>

            <!-- Controls -->
            <a class="left carousel-control" href="#carousel-example-generic" role="button" data-slide="prev">
                <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
                <span class="sr-only">Previous</span>
            </a>
            <a class="right carousel-control" href="#carousel-example-generic" role="button" data-slide="next">
                <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
                <span class="sr-only">Next</span>
            </a>
        </div>
    </div>




                            <script type="text/javascript">
                                $( document ).ready(function() {
                                    $("[data-toggle=tooltip]").tooltip();
                                });</script>
<br/>
<div class="container">
<div id="notice" style="background-color: #f5f5f5;color: #000000;max-height: 30px; border: #000000; ">
<marquee><h4 style="color: #ff0000">Annoucement->Last date For apply Exam Form is 15-05-2015.</h4></marquee>
</div>
</div>
<br/>
<br/>
<a name="footer"></a>
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