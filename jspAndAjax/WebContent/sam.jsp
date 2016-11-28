<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta  charset="utf-8">
<title>Insert title here</title>
 <link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.min.css">
<script src="js/jquery-1.11.1.min.js" type="text/javascript"></script>
<script src="bootstrap-3.3.2-dist/js/bootstrap.min.js" type="text/javascript"></script>
<script src="js/sangu1.js" type="text/javascript"></script>
</head>
<body>
<form id="itm">
<select name="Name" id="name">
<option value="" selected="selected">select course</option>
<option value="mca">mca</option>
<option value="bca">bca</option>
</select>

			<select id="list" name="list">
				<option value="" selected="selected">select semster</option>
<option value="1">1</option>
<option value="2">2</option>
<option value="3">3</option>
<option value="4">4</option>
			</select>
			
			<select id="sub" >
				
			</select>
<input type="submit"/>
<p id="display"/>
</form>
</body>
</html>