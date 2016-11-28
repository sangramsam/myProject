<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="utf-8" import="java.util.*" %>
    <%@ page import="com.lms.std" %>
    <%@ page import="com.lms.notice" %>
    <%@ page import="com.lms.ansbbean" %>
    
<!DOCTYPE html>
<html>
<head lang="en">
    <meta charset="UTF-8">
    <title>Student</title>
    <link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="style.css">
    <link rel="shortcut icon" type="image/x-icon" href="img/picto_navigation.png" />
    <script src="bootstrap-3.3.2-dist/js/jquery.js"></script>
    <script src="bootstrap-3.3.2-dist/js/insertquestion.js"></script>
    
</head>
<body >
<%
if(null==session.getAttribute("user"))
{
	response.sendRedirect("login.jsp");
	return;
}
else
{
String  username=null;
username=(String)session.getAttribute("user");
List<ansbbean> answer=null;
answer=(List<ansbbean>)session.getAttribute("answer");
List<std> jobList = null;
jobList = (List<std>)session.getAttribute("data");
List<notice> ntlist = null;
ntlist=(List<notice>)session.getAttribute("nt");
%>
<% //ArrayList<std> output = (ArrayList<std>)session.getAttribute("list");
//int siz=output.size();%>
<nav class="navbar navbar-fixed-top  no-margin navbar-inner navbar-default navbar-inverse ">
    <div class="container-fluid">
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

                <li rol="presentation" class="active"><p><span class="glyphicon glyphicon-user"></span><%=username.toUpperCase() %>&nbsp;&nbsp;&nbsp;<a href="/newmoodle/logout" class="btn-sm btn-default">Logout</a></p></li>
               
</ul>
        </div>
    </div>
</nav>
<br/><br/><br/><br/>
<div class="col-md-6">
<%-- <% for(std d: jobList) --%>
<%-- { %> --%>
<!--     <div class="well" style="background-color:lightyellow"> -->
<%--        <div id="sub" style="color:black;"><h4><%=d.getSubjectname().toUpperCase()%></h4></div> --%>
<%--         <div id="fac" style="color:black;"><%=d.getFacultyname().toUpperCase()%></div> --%>
<%--         <div id="std" style="color:black;"><a style="color:black;" href='/newmoodle/list_file?name=+<%=d.getSubject_id()%>+'>Study Material</a></div> --%>
<!--     </div><br/> -->
<%--     <%} %> --%>
   <div class="panel-group" id="accordion" role="tablist" aria-multiselectable="true">
   <% for(std d: jobList)
  {%>
  <div class="panel panel-default">
    <div class="panel-heading" role="tab" id="<%=d.getSubjectname() %>">
      <h4 class="panel-title">
        <a class="collapsed" data-toggle="collapse" data-parent="#accordion" href="#<%=d.getSubject_id()%>" aria-expanded="false" aria-controls="<%=d.getSubject_id()%>">
         <span class="glyphicon glyphicon-triangle-right"></span><b><%=d.getSubjectname().toUpperCase() %></b>
        </a>
      </h4>
    </div>
    <div id="<%=d.getSubject_id()%>" class="panel-collapse collapse collapse" role="tabpanel" aria-labelledby="<%=d.getSubjectname() %>">
      <div class="panel-body">
        <p style="color:black">Faculty Name &nbsp;&nbsp;&nbsp;<b><%=d.getFacultyname().toUpperCase()%></b></p>
        <p style="color:black">Subject-Code &nbsp;&nbsp;&nbsp;<b><%=d.getSubject_id().toUpperCase() %></b></p>
        <p style="color:black"><a style="color:black;" href='/newmoodle/list_file?name=+<%=d.getSubject_id()%>+'>Download material</a></p>
      </div>
    </div>
  </div>
  <%} %>
   </div>
   <button type="button" class="btn btn-lg btn-danger" data-toggle="modal" data-target=".question"><span class="glyphicon glyphicon-plus-sign"></span>&nbsp;&nbsp;Question & Answer</button>
   <div class="modal fade question" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
            <div class="modal-dialog modal-lg">
                <div class="modal-content">
        <div class="panel panel-default">
              <div class="panel-heading">ANSWER</div>
             
            <%if(answer.isEmpty())
      					{%>
      					<div class="panel-body">
      					 <div class="form-group">
                    <div class="well">
                    <p> <h2>Opps !!!!</h2> no new mesg</p>
                    </div></div>
                    </div>
      					<% }
      					else 
      					{
               for(ansbbean ans:answer)
            	   {
				%>
            	   <div class="panel-body">
            	    <form method="post" action="/newmoodle/markeasread">
                    <div class="well" id="<%=ans.getReply_date()%>">
                        <p class="pull-right"><b><%= ans.getReply_by()%> </b>(<small><%=ans.getReply_date() %></small>)</p>
                        <p style="color:blue"><%= ans.getAnswer()%></p>
                       <button  id="<%=ans.getReply_no() %>" value="make as read" class=" btn btn-success pull-right btn-sm">Mark As Read</button>
                        </div>
                        <div id="mesgn" style="color:red"></div>
                        </form>
       
                        <script type="text/javascript">
			$("documemt").ready(function()
			{
				var reply=document.getElementById("<%=ans.getReply_no()%>");
				var toname="<%=username%>";
				 var rn="<%=ans.getReply_no()%>";
				 var rnn=document.getElementById("<%=ans.getReply_date()%>");
			$(reply).click(function()
				{
			$.ajax({
				type:"POST",
				url:"markasread",
				data:{
					name :toname,
					replyno :rn,
				},
				success:function(mesg)
				{
					if(mesg=="success")
						{
						$(rnn).hide();
						}
					else
						{
						$('#mesgn').text(mesg).slideDown(1000);
						}
				},
			});
			return false;
				});
		});
</script>
                        </div>
                    <%} %>
                    <%} %>
            
        
    </div>
     </div>
            </div>
            </div>
</div>
<div class="col-md-6">
    <div class="panel panel-danger panel-default " style="height: 150px;width: 600px;">
            <div class="panel-heading" style=" background-color:#39424e;color:whitesmoke"><b>Notice</b></div>
            <div class="pannel-body" style="color:black">
             <marquee direction="left">
             <% for(notice n:ntlist)
            	 {
            	 %>
             <p><b> <%=n.getContent() %></b></p>
             <%} %>
             <p>ADD NOTICE HERE;</p>
             </marquee>
        </div>
    </div>
    
   
    <div class="panel panel-default" style="height: 240px;width: 600px;">
        <div class="panel-body">
        <form method="post" class="form-group" action="/newmoodle/question" id="question">
    <div class="form-group">
        <textarea cols="50" rows="5" class="form-control" placeholder="Ask Question In 140 word ?" name="ques" id="ques" maxlength="140"></textarea>
    </div>
    <div class="form-group">
        <select id="name" name="name" class=" form-control">
            <option selected value="">Select Faculty Name</option>
            <% for(std p:jobList)
            	 {
            	 %>
             <option value="<%=p.getFacultyname() %>"><%=p.getFacultyname() %></option>
             <%} %>
          </select>
    </div>
    <div class="form-group">
        <button type="submit" class=" btn btn-danger pull-right" value="Ask Question ?"> Ask Question ?</button>
    </div>
    <div id="mesg" style="color:red"></div>
    </form>
        </div>
</div>
</div>
 <%} %>

<script src="bootstrap-3.3.2-dist/js/bootstrap.min.js"></script>
</body>
</html>