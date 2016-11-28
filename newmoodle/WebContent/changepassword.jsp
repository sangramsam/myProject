<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head lang="en">
    <title>Change passwod</title>
    <link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="style.css">
    <link rel="shortcut icon" type="image/x-icon" href="img/picto_navigation.png" />
</head>
<body>
<br/><br/><br/><br/>

<div class="container">
    <div class="panel  panel-success panel-default " style="height: 500px;width: 600px; color:brown">
        <div class="panel-heading ">
            <h3 class="panel-title " style="color: #000000"><b>Change Password</b></h3>
        </div>
        <div class="panel-body">
<div class="form-group">
    <div class="form-horizontal">
    <div class="form-group ">
        <div class="col-sm-5">
            <label for="rollno" class="control-label">Rollno</label>
        <div class="input-group input-group-sm" data-toggle="tooltip" data-placement="left" title="please enter Roll no" >
            <div class="input-group-addon"><span class="glyphicon glyphicon-user"></span></div>
            <input type="text" class="form-control " id="rollno" name="rollno" placeholder="Roll-No">
            </div>
        </div>
        <label id="rollno-error" class="error" for="rollno"></label>
    </div>
    <div class="form-group ">
        <div class="col-sm-5">
            <label for="DOB" class="control-label">DOB</label>
        <div class="input-group  input-group-sm"  data-toggle="tooltip" data-placement="left" title="please enter your Date of Bitrh">
            <div class="input-group-addon"><span class="glyphicon glyphicon-book"></span> </div>
            <input type="date" class="form-control" id="DOB" placeholder="DOB"  name="DOB">
        </div>
        </div>
        <label id="DOB-error" class="error" for="DOB"></label>
    </div>
    <div class="form-group">
        <div class="col-sm-5">
            <label for="Password" class="control-label">Current Pasword</label>
        <div class="input-group  input-group-sm"  data-toggle="tooltip" data-placement="left" title="please enter at least 8 character long password">
            <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
            <input type="password" class="form-control" id="Password" name="Password" placeholder="password">
        </div>
        <label id="password-error" class="error" for="Password"></label>
    </div>
        </div>
    <div class="form-group">
        <div class="col-sm-5">
            <label for="cPassword" class="control-label">new Pasword</label>
        <div class="input-group  input-group-sm"  data-toggle="tooltip" data-placement="left" title="please enter at least 8 character long password">
            <div class="input-group-addon"><span class="glyphicon glyphicon-lock"></span></div>
            <input type="password" class="form-control" id="cPassword" name="Password" placeholder="password">
        </div>
        <label id="cpassword-error" class="error" for="Password"></label>
    </div>
    </div>
        <br/>
        <button type="submit" class="btn btn-danger">Change Password</button>
</div>
</div>
</div>
</div>
</div>
<script src="bootstrap-3.3.2-dist/js/jquery.js"></script>
<script src="bootstrap-3.3.2-dist/js/bootstrap.min.js"></script>
</body>
</html>