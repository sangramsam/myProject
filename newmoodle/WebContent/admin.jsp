<!DOCTYPE html>
<html>
<head lang="en">
    <meta charset="UTF-8">
    <title>Moodle</title>
    <link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="style.css">
    <script src="bootstrap-3.3.2-dist/js/jquery.js"></script>
    <script src="bootstrap-3.3.2-dist/js/jquery.validate.min.js"></script>
    <script src="bootstrap-3.3.2-dist/js/validatefacresitration.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/validateAssign.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/validatecourse.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/validateList.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/facultyRegis.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/AssignSubject.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/Addcourse.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/Search.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/searchfaculty.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/findstudent.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/searchAssignSubject.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/update.js" type="text/javascript"></script>
    
    <link rel="shortcut icon" type="image/x-icon" href="img/picto_navigation.png" />
</head>
<body>
<%
if(null==session.getAttribute("name"))
{
	response.sendRedirect("login.jsp");
	return;
}
else
{
String  username=null;
username=(String)session.getAttribute("name");
%>
<nav class="navbar  navbar-inverse navbar-fixed-top no-margin navbar-inner " style="height: 30px">
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
           <li rol="presentation" class="active"><p><span class="glyphicon glyphicon-user"></span><%=username.toUpperCase() %>&nbsp;&nbsp;&nbsp;<a href="/newmoodle/logout" class="btn-sm btn-default">Logout</a></p></li>
        </ul>

    </div>
</nav>
<br/><br/><br/>
<div class="row">
    <div class="col-md-3">
        <div class="btn-group-vertical " role="group" aria-label="...">
            <button type="button" class="btn btn-default disabled"><b>ADD</b></button>
        <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".addfaculty">Register Faculty</button>
       <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".assignsubject">Assign Subject</button>
       <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".addCourse">Add Course & Subject Name</button>
    </div>
    </div>
    <div class="col-md-3 ">
        <div class="btn-group-vertical " role="group" aria-label="...">
            <button type="button" class="btn btn-default disabled"><b>SEARCH</b></button>
       <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".listStudent">List Student</button>
       <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".listfaculty">List Faculty</button>
       <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".searchstudent">Search Student</button>
       <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".searchAssign">Search Subject Assign</button>
    </div>
    </div>
    <div class="col-md-3">
        <div class="btn-group-vertical " role="group" aria-label="...">
            <button type="button" class="btn btn-default disabled"><b>UPDATE</b></button>
           <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".update"><span class="glyphicon glyphicon-plus-sign"></span>&nbsp;&nbsp;Update Student</button>
           <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".question"><span class="glyphicon glyphicon-plus-sign"></span>&nbsp;&nbsp;Update Faculty</button>
           <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".question"><span class="glyphicon glyphicon-plus-sign"></span>&nbsp;&nbsp;Update Assign Subject</button>

        </div>
    </div>
    <div class="col-md-3">
        <div class="btn-group-vertical " role="group" aria-label="...">
            <button type="button" class="btn btn-default disabled"><b>DELETE</b></button>
            <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".question"><span class="glyphicon glyphicon-plus-sign"></span>&nbsp;&nbsp;Delete Student</button>
            <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".question"><span class="glyphicon glyphicon-plus-sign"></span>&nbsp;&nbsp;Delete Faculty</button>
            <button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".question"><span class="glyphicon glyphicon-plus-sign"></span>&nbsp;&nbsp;Delete Assign Subject</button>

        </div>
    </div>
</div>

<div class="modal fade addfaculty" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg">
        <div class="modal-content">
            <h4 style="color: #2ec866"><b> Faculty Registration</b></h4>
            <div class="login-form">
                <form class="form-group" method="post" action="/newmoodle/factlyRegis" id="facultyregis">
                <div class="form-group">
                    <div class="input-group input-group-sm">
                        <input type="text" class="form-control" name="username" placeholder="Username /Factid" id="username">
                        <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                    </div>
                    </div>
                    <label id="text-error" class="error" for="username"></label>
                    <div class="form-group">
                        <div class="input-group input-group-sm">
                            <input type="text" class="form-control" placeholder="Name" id="name" name="name">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                        </div>
                    </div>
                    <label id="name-error" class="error" for="name"></label>
                    <div class="form-group">
                        <div class="input-group input-group-sm">
                            <input type="text" class="form-control" placeholder="DepartMent" id="dept" name="dept">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                        </div>
                    </div>
                    <label id="dept-error" class="error" for="dept"></label>
                    <div class="form-group">
                        <div class="input-group input-group-sm">
                            <input type="password" class="form-control" placeholder="Password" id="fpassword" name="fpassword">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
                        </div>
                    </div>
                    <label id="fpassword-error" class="error" for="fpassword"></label>
                    <div class="form-group">
                        <div class="input-group input-group-sm">
                            <input type="password" class="form-control" placeholder=" Confirm Password" id="fcpassword" name="fcpassword">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
                        </div>
                    </div>
                    <label id="fcpassword-error" class="error" for="fcpassword"></label>
                    <div class="form-group">
                        <div class="input-group input-group-sm">
                            <input type="email" class="form-control" placeholder="Email ID" id="femail" name="femail">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-envelope"></span></div>
                        </div>
                    </div>
                    <label id="email-error" class="error" for="femail"></label>
                    <div class="form-group">
                        <div class="input-group input-group-sm">
                            <input type="text" class="form-control" placeholder="Mobile No" id="Fmobile" name="Fmobile">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-phone"></span></div>
                        </div>
                    </div>
                    <label id="fmbile-error" class="error" for="Fmobile"></label>
                    <div class="form-group">
                        <div class="input-group input-group-sm">
                            <input type="date" class="form-control dateclass placeholderclass" placeholder="Date of Birth" id="dob" name="dob" onclick="$(this).removeClass('placeholderclass')">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-calendar"></span></div>
                        </div>
                    </div>
                    <label id="date-error" class="error" for="dob"></label>
                    <button type="submit" class="btn btn-success  center-block">Register</button>
					<div id="mesg" style="color:red"></div>
                </form>
            </div>
        </div>
    </div>
    </div>
<div class="modal fade assignsubject" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg">
        <div class="modal-content">
            <h4 style="color: #2ec866"><b>Assign Subject & Faculty</b></h4>
            <div class="login-form">
                <form class="form-group" method="post" action="/newmoodle/AssignSubject" id="assign" >
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Enter FacultyId">
                        <input type="text" class="form-control" name="facid" placeholder="facultyid" id="facid" >
                        <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                    </div>
                    <label id="facid-error" class="error" for="facid"></label>
                        <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Enter Subject Name">
                            <input type="text" class="form-control" placeholder="SubjectName" id="subname" name="subname">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-flash"></span></div>
                        </div>
                    <label id="subname-error" class="error" for="subname"></label>

                        <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Enter SubjectId">
                            <input type="text" class="form-control" placeholder="Subject Id" id="subid" name="subid">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-asterisk"></span></div>
                        </div>

                    <label id="subid-error" class="error" for="subid"></label>

                        <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Enter Branch">
                            <input type="text" class="form-control" placeholder="Branch" id="branch" name="branch">
                            <div class="input-group-addon"><span class="glyphicon glyphicon-pencil"></span></div>
                        </div>

                    <label id="branch-error" class="error" for="branch"></label>
                        <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Select Semester">
                            <select class="form-control" id="semester" name="semester">
                                <option selected value="">Select Semester</option>
                                <option value="1">1</option>
                                <option value="2">2</option>
                                <option value="3">3</option>
                                <option value="4">4</option>
                                <option value="5">5</option>
                                <option value="6">6</option>
                                <option value="7">7</option>
                                <option value="8">8</option>
                            </select>
                            <div class="input-group-addon"><span class="glyphicon glyphicon-triangle-left"></span></div>
                        </div>

                    <label id="sem-error" class="error" for="semester"></label><br/>
                    <button type="submit" class="btn btn-success  center-block">Assign</button>
					<div id="resmesg" style="color:red"></div>
                </form>
            </div>
        </div>
    </div>
</div>
<div class="modal fade addCourse" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg">
        <div class="modal-content">
            <h4 style="color: #2ec866"><b>Add Course and subject Info</b></h4>
            <div class="login-form">
                <form class="form-group" method="post" action="/newmoodle/AddSubject" id="course" >
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Enter SubjectId">
                        <input type="text" class="form-control" name="subjectid" placeholder="Enter Subject ID" id="subjectid" >
                        <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                    </div>
                    <label id="subjectid-error" class="error" for="subjectid"></label>
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Enter Subject Name">
                        <input type="text" class="form-control" placeholder="Enter SubjectName" id="subjectname" name="subjectname">
                        <div class="input-group-addon"><span class="glyphicon glyphicon-flash"></span></div>
                    </div>
                    <label id="subjectname-error" class="error" for="subjectname"></label>
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Enter Course">
                        <input type="text" class="form-control" placeholder="Enter Branch" id="branchid" name="branchid">
                        <div class="input-group-addon"><span class="glyphicon glyphicon-pencil"></span></div>
                    </div>

                    <label id="course-error" class="error" for="branchid"></label>
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Select Semester">
                        <select class="form-control" id="sem" name="sem">
                            <option selected value="">Select Semester</option>
                            <option value="1">1</option>
                            <option value="2">2</option>
                            <option value="3">3</option>
                            <option value="4">4</option>
                            <option value="5">5</option>
                            <option value="6">6</option>
                            <option value="7">7</option>
                            <option value="8">8</option>
                        </select>
                        <div class="input-group-addon"><span class="glyphicon glyphicon-triangle-left"></span></div>
                    </div>
                    <label id="semester-error" class="error" for="sem"></label>
                    <br/>
                    <button type="submit" class="btn btn-success  center-block">ADD</button>
					<div id="submesg" style="color:red"></div>
                </form>
            </div>
        </div>
    </div>
</div>
<div class="modal fade listStudent" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg">
        <div class="modal-content">
            <h4 style="color: #2ec866"><b>Select Student List</b></h4>
            <div class="login-form">
                <form class="form-group" method="get" action="/newmoodle/searchstudent" id="list" >
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Select Branch">
                        <select class="form-control" id="courseid" name="courseid">
                            <option selected value="">Select Branch</option>
                            <option value="mca">MCA</option>
                            <option value="bca">BCA</option>
                        </select>
                        <div class="input-group-addon"><span class="glyphicon glyphicon-triangle-left"></span></div>
                    </div>
                    <label id="courseid-error" class="error" for="courseid"></label>
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Select Semester">
                        <select class="form-control" id="semid" name="semid">
                            <option selected value="">Select Semester</option>
                            <option value="1">1</option>
                            <option value="2">2</option>
                            <option value="3">3</option>
                            <option value="4">4</option>
                            <option value="5">5</option>
                            <option value="6">6</option>
                            <option value="7">7</option>
                            <option value="8">8</option>
                        </select>
                        <div class="input-group-addon"><span class="glyphicon glyphicon-triangle-left"></span></div>
                    </div>
                    <label id="semid-error" class="error" for="semid"></label>
                    <br/>
                    <button type="submit" class="btn btn-success  pull-right">Search</button>
 <div id="ss" style="color:red"></div>
                </form>
            </div>
        </div>
    </div>
</div>
<div class="modal fade searchstudent" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg">
        <div class="modal-content">
            <h4 style="color: #2ec866"><b>Search Student </b></h4>
            <div class="login-form">
                <form class="form-group" method="get" action="/newmoodle/findstudent" id="searchstudent" >
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Select Branch">
                        <select class="form-control" id="scourse" name="scourse" required>
                            <option selected value="">Select Branch</option>
                            <option value="mca">MCA</option>
                            <option value="bca">BCA</option>
                        </select>
                        <div class="input-group-addon"><span class="glyphicon glyphicon-triangle-left"></span></div>
                    </div>
                    <label id="scourse-error" class="error" for="scourse"></label>
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Enter Student Name">
                        <input type="text" class="form-control" name="sname" placeholder="Enter Student Name" id="sname" required>
                        <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                    </div>
                    <label id="sname-error" class="error" for="sname"></label>
                    <br/>
                    <button type="submit" class="btn btn-success  pull-right">Search</button>
                   
                </form>
            </div>
        </div>
    </div>
</div>
<div class="modal fade listfaculty" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg">
        <div class="modal-content">
            <h4 style="color: #2ec866"><b>Select Faculty List</b></h4>
            <div class="login-form">
                <form class="form-group" method="get" action="/newmoodle/searchfaculty" id="listfac" >
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Select Branch">
                        <select class="form-control" id="department" name="department" required>
                            <option selected value="">Select Deaprtament</option>
                            <option value="soca">SOCA</option>
                            <option value="soet">SOET</option>
                        </select>
                        <div class="input-group-addon"><span class="glyphicon glyphicon-triangle-left"></span></div>
                    </div>
                    <br/>
                    <button type="submit" class="btn btn-success  pull-right">Search</button>
                    <div id="fac" style="color:red"></div>
                </form>
            </div>
        </div>
    </div>
</div>
<div class="modal fade searchAssign" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg">
        <div class="modal-content">
            <h4 style="color: #2ec866"><b>Search Assign Subject </b></h4>
            <div class="login-form">
                <form class="form-group" method="get" action="/newmoodle/searchAssignSubject" id="searchassign">
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Select Branch">
                        <select class="form-control" id="sfcourse" name="sfcourse" required>
                            <option selected value="">Select Branch</option>
                            <option value="mca">MCA</option>
                            <option value="bca">BCA</option>
                        </select>
                        <div class="input-group-addon"><span class="glyphicon glyphicon-triangle-left"></span></div>
                    </div>
                    <label id="scourses-error" class="error" for="sfcourse"></label>
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Enter Subject Code">
                        <input type="text" class="form-control" name="scode" placeholder="Enter Subject Code(E.g MCA-405)" id="scode" required>
                        <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                    </div>
                    <label id="scode-error" class="error" for="scode"></label>
                    <br/>
                    <button type="submit" class="btn btn-success  pull-right">Search</button>
                    <div id="ssubject" style="color:red"></div>
                </form>
            </div>
        </div>
    </div>
</div>
<div class="modal fade update" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg">
        <div class="modal-content">
            <h4 style="color: #2ec866"><b>Update Student </b></h4>
            <div class="login-form">
                <form class="form-group" method="get" action="/newmoodle/findstudentforupdate" id="updatestudent" >
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Select Branch">
                        <select class="form-control" id="ucourse" name="ucourse" required>
                            <option selected value="">Select Branch</option>
                            <option value="mca">MCA</option>
                            <option value="bca">BCA</option>
                        </select>
                        <div class="input-group-addon"><span class="glyphicon glyphicon-triangle-left"></span></div>
                    </div>
                    <label id="scourse-error" class="error" for="scourse"></label>
                    <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="Please Enter Student id">
                        <input type="text" class="form-control" name="uname" placeholder="Enter Student id" id="uname" required>
                        <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
                    </div>
                    <label id="sname-error" class="error" for="uname"></label>
                    <br/>
                    <button type="submit" class="btn btn-success  pull-right">Update</button>
                    <div id="up" style="color:red"></div>
                </form>
            </div>
        </div>
    </div>
</div>
<hr/>
<div class="container">
<table class="table table-bordered hide table-hover table-condensed table-reponsive" id="td" style="background-color:white">
<tr>
<th class="success">NAME</th>
<th class="success">ROLL NO.</th>
<th class="success">EMAIL</th>
<th class="success">DOB</th>
<th class="success">COURSE</th>
<th class="success">SEMESTER</th>

</tr>
</table>
<table class="table table-bordered hide table-hover table-condensed table-reponsive" id="tds" style="background-color:white">
<tr>
<th class="success">NAME</th>
<th class="success">ROLL NO.</th>
<th class="success">EMAIL</th>
<th class="success">COURSE</th>
<th class="success">SEMESTER</th>


</tr>
</table>
<table class="table table-bordered hide table-hover table-condensed table-reponsive" id="tdf" style="background-color:white">
<tr>
<th class="success">NAME</th>
<th class="success">ID.</th>
<th class="success">EMAIL</th>
<th class="success">DOB</th>
<th class="success">MOBILE NO.</th>
<th class="success">DEPARTMENT</th>

</tr>
</table>
<table class="table table-bordered hide table-hover table-condensed table-reponsive" id="tdsub" style="background-color:white">
<tr>
<th class="success">SUBJECT-NAME</th>
<th class="success">SUBJECT-CODE</th>
<th class="success">COURSE</th>
<th class="success">FACULTYID</th>
<th class="success">SEMESTER</th>
<th class="success">FACULTYNAME</th>


</tr>
</table>
<div class="container" id="studentupdate" style="width:500px"></div>
</div>

<script type="text/javascript">
    $( document ).ready(function() {
        $("[data-toggle=tooltip]").tooltip();
    });</script>
<% } %>
<script src="bootstrap-3.3.2-dist/js/bootstrap.min.js"></script>
</body>
</html>