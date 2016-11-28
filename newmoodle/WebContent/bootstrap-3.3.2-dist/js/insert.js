$(document).ready(function()
		{
	$('#signup').submit(function()
			{
		$.ajax({
			url:'student_signup',
			type:'POST',
			data : {
				firstname : $('#firstname').val(),
				Lastname: $('#Lastname').val(),
				rollno:$('#rollno').val(),
				Password:$('#Password').val(),
				email:$('#email').val(),
				course:$('#course').val(),
				sem:$('#sem').val(),
				gender:$("input[name='gender']:checked", '#signup').val(),
				
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
	console.log("Sa");
		});