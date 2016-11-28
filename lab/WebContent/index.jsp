<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="utf-8" import="java.util.*"%>
    <%@ page import="com.lab.doc" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>serach</title>
</head>
<body>
<%
List<doc> list = null;
list = (List<doc>)session.getAttribute("data");
%>
<table border="1">
<tr>
<th>name</th>
<th>address</th>
<th>fee</th>
<th>mob</th>
</tr>
<tr>
<% for(doc d:list)
	{%>
	<td><%=d.getName()%></td>
	<td><%=d.getAddress()%></td>
	<td><%=d.getFee()%></td>
	<td><%=d.getMob()%></td>
	<%} %>
</tr>
</table>
</body>
</html>