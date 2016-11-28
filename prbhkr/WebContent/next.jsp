<%@page import="java.sql.*" %>
<html>
<head></head>
<body>
<%
String s=request.getParameter("t1");
String c=request.getParameter("t2");
out.println("ready for connection");
Class.forName("oracle.jdbc.driver.OracleDriver");
Connection cn=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","system","sneha");
out.println("Connection established successfully");
PreparedStatement st=cn.prepareStatement("select * from docotor where speacility=? and location=?");
st.setString(1,s);
st.setString(2,c);
ResultSet rs = st.executeQuery();
%>
<table border="1">
<tr>
<th>name</th>
<th>speciality</th>
<th>timing</th>
<th>city</th>
<th>Mobile no</th>
</tr>
<%
while(rs.next())
{	
%> 
<tr>
<td><%=rs.getString(1) %></td>
<td><%=rs.getString(2) %></td>
<td><%=rs.getString(3) %></td>
<td><%=rs.getString(4) %></td>
<td><%=rs.getString(5) %></td>
<td><%=rs.getString(6) %></td>
</tr>
<%} %>
</table>

</body>
</html>