$(document).ready(function()
		{
	$('#signup').submit(function()
			{
		$.ajax({
			url:'student_signup',
			type:'POST',
			data : {
				name : $('#name').val(),
				rollno:$('#rollno').val(),
				Password:$('#Password').val(),
				email:$('#email').val(),
				course:$('#course').val(),
				sem:$('#sem').val(),
				DOB:$('#DOB').val(),
			},
			success:function(data)
			{
				if(data=="success")
					{
					location.href="login.jsp";
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