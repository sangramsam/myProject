<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="utf-8" import="java.util.*" %>
     <%@ page import="com.lms.std" %>
<!DOCTYPE html>
<html>
<head>
<title>Download</title>
    <link rel="shortcut icon" type="image/x-icon" href="img/picto_navigation.png" />
    <link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.min.css">
        <link rel="stylesheet" href="dwn.css">
</head>
<body>
<div class="container">
<h2>Click on file to download</h2>
<%
List<std> job = null;
job = (List<std>)session.getAttribute("filename");
%>
<%
for(std d1: job)
{
%>
<div class="well">
<a href='/newmoodle/download?fname=+<%=d1.getName()%>+'><%=d1.getName() %></a><br/>
</div>
<%}%>
</div>
    <script src="bootstrap-3.3.2-dist/js/jquery.js"></script>
    <script src="bootstrap-3.3.2-dist/js/bootstrap.min.js"></script>
</body>
</html>