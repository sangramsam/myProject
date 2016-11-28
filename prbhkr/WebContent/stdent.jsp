<%@ page contentType="text/html; charset=utf-8" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Untitled Document</title>
</head>

<body background="aurora_burst_2.jpg">
<div style="position:absolute; top: 44px; height: 68px; left: 506px; width: 501px;">
<font size="+4" color="#66FF33"><u>Student Registration</u></font></div>
<div style="position:absolute; left: 525px; top: 184px; width: 339px; height: 370px;">
<table width="336" height="366">
<tr>
<td width="132"><font size="+2">Roll No:</font></td>
<td width="192"><input name="t1" type="text" /></td>
</tr>
<tr>
<td><font size="+2">Name</font>:</td>
<td><input name="t2" type="text" /></td>
</tr>
<tr>
<td><font size="+2">E-mail ID:</font></td>
<td><input type="text" name="t3" /></td>
</tr>
<tr>
<td><font size="+2">Password:</font></td>
<td><input type="password" name="t4" /></td>
</tr>
<tr>
<td><font size="+2">Confirm Password:</font></td>
<td><input type="password" name="t5" /></td>
</tr>
<tr>
<td><font size="+2">Course:</font></td>
<td><input type="text" name="t6" /></td>
</tr>
<tr>
<td><font size="+2">DOB:</font></td>
<td><input type="text" name="t7" /></td>
</tr>
<tr>
<td><font size="+2">Semester:</font></td>
<td><input type="text" name="t8" /></td>
</tr>
</table>
<div style="position:absolute; left: 68px; top: 418px; width: 253px; height: 27px;">
  <input name="Insert" type="submit" value="Insert"/>
  <input name="Update" type="submit" value="Update"/>
  <input name="Delete" type="submit" value="Delete"/>
   <input name="Search" type="submit" value="Search"/>
</div>
</div>
</body>
</html>