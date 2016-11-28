<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" 
"http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>jQuery, Ajax and Servlet/JSP integration example</title>
<link rel="stylesheet" href="style.css">
<script src="js/jquery-1.11.1.min.js" type="text/javascript"></script>
<!--  <script src="js/app-ajax.js" type="text/javascript"></script>-->
</head>
<body>

	<form>
	
		Username: <input type="text" id="userName" /><br/>
		Password<input type="password" id="pass"/></br/>
		<div id="ajaxGetUserServletResponse" ></div>
						<input type="button" id="btn" value="login"/>
	</form>
	<br>
	<br>

	<strong>Ajax Response</strong>:
	
</body>
<script type="text/javascript">
$(document).ready(function() {
	$('#btn').on('click',function() {
		$.ajax({
			url : 'GetUserServlet',
			data : {
				userName : $('#userName').val(),
				pass:$("#pass").val(),
			},
			success : function(responseText) {
				if(responseText=="success")
					{
					location.href="user.jsp";
					}
			}
		});
	});
});
</script>
</html>