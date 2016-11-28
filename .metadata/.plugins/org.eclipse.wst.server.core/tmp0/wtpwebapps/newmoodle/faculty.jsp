<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" import="java.util.*" import ="com.lms.std"%>
      <%@ page import="com.lms.notice" %>
      <%@ page import="com.lms.message" %>
      
<!DOCTYPE html>
<html>
<head lang="en">
    <meta charset="UTF-8">
    <title>Moodle</title>
    <link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.min.css">
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <link rel="stylesheet" href="style.css">
    <script src="bootstrap-3.3.2-dist/js/jquery.js"></script>
    <script src="bootstrap-3.3.2-dist/js/jquery.validate.min.js"></script>
    <script src="bootstrap-3.3.2-dist/js/validatefac.js" ></script>
    <script src="bootstrap-3.3.2-dist/js/select.js"></script>
       <script src="bootstrap-3.3.2-dist/js/addnotice.js"></script>
       <script src="bootstrap-3.3.2-dist/js/AssignSubject.js" type="text/javascript"></script>
        <script src="bootstrap-3.3.2-dist/js/findstudent.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/searchAssignSubject.js" type="text/javascript"></script>
    <script src="bootstrap-3.3.2-dist/js/validateAssign.js" type="text/javascript"></script>
    <link rel="shortcut icon" type="image/x-icon" href="img/picto_navigation.png" />
    
</head><body>
<%
if(null==session.getAttribute("user"))
{
	response.sendRedirect("login.jsp");
	return;
}
else
{
	List<message> mesg = null;
	mesg = (List<message>)session.getAttribute("QA");
String  username=null;
username=(String)session.getAttribute("user");
List<std> jobList = null;
jobList = (List<std>)session.getAttribute("data");
List<notice> ntlist = null;
ntlist=(List<notice>)session.getAttribute("nt");%>
<div class="row">
    </div>
<nav class="navbar navbar-default navbar-inverse navbar-inner" role="navigation">
    <div class="navbar-header">
       <a class="navbar-brand w pull-left" href="#" style="top:2px"><h4><b>ITMU Moodle</b></h4></a>
    </div>
    <ul class="nav navbar-nav pull-right">
        <li class="active"><p>&nbsp;&nbsp;&nbsp;&nbsp;<b><span class="glyphicon glyphicon-user"></span><%= username.toUpperCase() %></b>&nbsp;&nbsp;<a  href="/newmoodle/logout" class="btn-sm btn-default">Logout</a></p> </li>
    </ul>
</nav>

<div class="col-md-6">
<div class="row">

<div class="btn-group-vertical" role="group" aria-label="...">
<button type="button" class="btn btn-default disabled"><b>Tools</b></button>
<button type="button" class="btn btn-lg btn-primary" data-toggle="modal" data-target=".upload"><span class="glyphicon glyphicon-open"></span>&nbsp;&nbsp;Upload Study Material</button>
<button type="button" class="btn btn-lg btn-warning" data-toggle="modal" data-target=".notice"><span class="glyphicon glyphicon-plus-sign"></span>&nbsp;&nbsp;Add Notice</button>
<button type="button" class="btn btn-lg btn-danger" data-toggle="modal" data-target=".question"><span class="glyphicon glyphicon-plus-sign"></span>&nbsp;&nbsp;Question & Answer</button>
<button type="button" class="btn btn-lg btn-success" data-toggle="modal" data-target=".assignsubject"><span class="glyphicon glyphicon-plus-sign"></span>&nbsp;&nbsp;Assign Subject</button>
</div>
&nbsp;&nbsp;&nbsp;&nbsp;
<div class="btn-group-vertical" role="group" aria-label="...">
<button type="button" class="btn btn-default disabled"><b>Search</b></button>
<button type="button" class="btn btn-lg btn-primary" data-toggle="modal" data-target=".searchstudent"><span class="glyphicon glyphicon-open"></span>&nbsp;&nbsp;Search Student</button>
<button type="button" class="btn btn-lg btn-warning" data-toggle="modal" data-target=".searchAssign"><span class="glyphicon glyphicon-plus-sign"></span>&nbsp;&nbsp;Search Assign Subject</button>

</div>
</div>
</div>

<script>
            $(function () {
            	  $('[data-toggle="popover"]').popover();
            	  //$('#message').attr("data-content","sangram singh");
            	});
            </script>
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
<div class="modal fade notice" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg ">
        <div class="modal-content">
            <div class="login-form">
                <form class="form-group" method="post" action="/newmoodle/Addnotice" id="add">

                    <textarea class="form-control" name="notice" cols="50" rows="5" placeholder="Type your notice here" id="notice"></textarea>

                    <label for="username"></label>

                    <br/>
                    <button class="btn btn-primary btn-lg center-block " type="submit">Add</button>
                    <div id=mesg></div>
                </form>
            </div>
        </div>
    </div>
</div>

<div class="modal fade upload" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="panel panel-default" style= "max-height:590px;max-width:4900px; position:relative ;">
        <div class="panel panel-heading" style="background-color:#16A085"><h4 style="text-align: center;color: snow">Upload</h4></div>
        <div class="panel-body">
            <form enctype="multipart/form-data" action="addfile" method="post" id="faculty">
                <div class="form-horizontal">
                    <div class="form-group">
                    <label for=”course” style="color: #000000;">Course</label>
                        <select  id="course" class="form-control" name="course">
                            <option selected value="">Select your Course</option>
                            <option>mca</option>
                            <option>bca</option>
                        </select>
                    </div>
                    <div class="form-group">
                        <label for=”sem” style="color: #000000;">Sem</label>
                        <select  id="sem" class=" form-control" name="sem">
                            <option selected value="">Select your semester</option>
                             <option value="1">1</option>
                             <option value="2">2</option>
                             <option value="3">3</option>
                             <option value="4">4</option>
                             <option value="5">5</option>
                             <option value="6">6</option>
                        </select>
                    </div>
                    <div class="form-group">
                        <label for=”subject” style="color: #000000;">Subject</label>
                        <select id="subject" name="subject" class=" form-control ">
                            <option selected value="">Select your subject</option>
                        </select>
                    </div>
                    <label for=”upload” style="color: #000000;">Upload</label>
                    <div class="form-group">
                        <input type="file" class="form-control" placeholder="upload ur file" name="upload" id="upload">
                    </div>
        <div class="form-group">
            <input type="submit" value="Upload" class=" btn btn-danger">
        </div>
</div>
            </form>
</div>
        </div>
    </div>
    </div>
  </div>
  <div class="modal fade question" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="panel panel-default">
      <form method="post" action="/newmoodle/reply" id="re">
      				<%if(mesg.isEmpty())
      					{%>
      					<div class="panel-body">
      					 <div class="form-group">
                    <div class="well">
                    <p> <h2>Opps !!!!</h2> no new mesg </p>
                    </div></div>
                    </div>
      					<% }
      					else 
      					{
                 for(message m:mesg)
            	 {
            	 %>
            	 <div class="panel-body" id="<%=m.getQuestion()%>" >
                <div class="form-group">
                    <div class="well">
                    <p><b>Question ?</b></p>
                    <p class="pull-left"><%=m.getQuestion() %></p>
                    <p class="pull-right" style="text-align:right"><small>From:<%=m.getName() %></small>(<%=m.getBranch() %>)</p>
                    </div>
                </div>
                <div class="form-group">
                    <textarea cols="50" rows="2" class="form-control" placeholder="Type Your answer Here " name="<%=m.getNo() %>" id="<%=m.getNo()%>"></textarea>
                </div>
                <div class="form-group">
                    <button  id="<%=m.getName() %>" class=" btn btn-danger pull-right" value="Reply">Reply</button>
                </div>
                <div id="mee" style="color:red"></div>
            <div class="divider"></div>
            </div>
            
            </form>
            <script type="text/javascript">
			$("documemt").ready(function()
			{
				var reply=document.getElementById("<%=m.getName()%>");
				var sname="<%=username%>";
				 var scourse="<%=m.getBranch()%>";
				 var sto="<%=m.getName()%>";
				 var idd=document.getElementById("<%=m.getNo()%>");
				 var ques=document.getElementById("<%=m.getQuestion()%>");
				 console.log(idd);
			$(reply).click(function()
				{
			$.ajax({
				type:"POST",
				url:"reply",
				data:{
					name :sname,
					course :scourse,
					to :sto,
					answer :$(idd).val()
				},
				success:function(mesg)
				{
					if(mesg=="Message Successfully send")
						{
						$(ques).hide();
						
						}
					else
						{
						$('#mee').text(mesg).slideDown(1000);
						}
				},
			});
			return false;
				});
		});
</script>

  <%} %>
  <%} %>
  
        </div>
    </div>
  </div>
</div>
    <div class="col-md-6">
        <div class="panel panel-default" style= "height:185px;">
            <div class="panel-heading" style=" background-color:#16A085;color:whitesmoke"><b>Notice & Announcement</b></div>
            <div class="pannel-body" style="color:black">
             <marquee direction="left">
             <% for(notice n:ntlist)
            	 {
            	 %>
             <p><b> <%= n.getContent() %></b></p>
             <%} %>
             </marquee>
        </div>
        </div>
         
    </div>
 <hr/>
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
<table class="table table-bordered hide table-hover table-condensed table-reponsive" id="tds" style="background-color:white">
<tr>
<th class="success">NAME</th>
<th class="success">ROLL NO.</th>
<th class="success">EMAIL</th>
<th class="success">DOB</th>
<th class="success">COURSE</th>
<th class="success">SEMESTER</th>
<th class="success">PASSWORD</th>


</tr>
</table>
<%} %>


    <script src="bootstrap-3.3.2-dist/js/bootstrap.min.js"></script>
</body>
</html>