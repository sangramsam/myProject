<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head></head>
<body>
<center>
<form action="next.jsp">
<h1><u>Search Doctors Detail</u></h1>
Select Doctor Speciality:<select name="t1">
<option>select</option>
<option>GNY</option>
<option value="eye">eye</option>
<option>HEART</option>
</select><br/>
Select City:<select name="t2">
<option>select</option>
<option value="gwalior">gwalior</option>
<option>LUCKNOW</option>
<option>BIHAR</option>
</select><br/>
<input type="submit" value="search">
</form>
</center>
</body>
</html>