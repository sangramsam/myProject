<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" import="java.util.*"%>
    <%@ page import="snh.sam" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
<link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.min.css">
</head>
<body>
<%
List<sam> jobList = null;
jobList = (List<sam>)session.getAttribute("deta");
%>
<%
for(sam d: jobList)
{
%>
file name is...<a href="retriv"><%=d.getname()%></a>
<%} %>
<script src="bootstrap-3.3.2-dist/js/jquery.js"></script>
<script src="bootstrap-3.3.2-dist/js/bootstrap.min.js"></script>
</body>
</html>