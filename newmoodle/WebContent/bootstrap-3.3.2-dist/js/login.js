$(document).ready(function()
		{
	$('#login').submit(function()
			{
		$.ajax({
			url:'login',
			type:'POST',
			data : {
				username : $('#username').val(),
				password: $('#password').val(),
				user:	$("input[name='user']:checked", '#login').val(),
			},
			success:function(data)
			{
				if(data=="student")
					{
					location.href="student.jsp";
					}
				else if(data=="faculty")
					{
					location.href="faculty.jsp";
					}
				else if(data=="admin")
				{
				location.href="admin.jsp";
				}
			
				else
					{
					$('#mesg').text(data);
					}		
			},
			});
		
	
		return false;
		
			});
	
	
		});