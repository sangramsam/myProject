$(document).ready(function()
		{
	$('#facultyregis').submit(function()
			{
		$.ajax({
			url:'facultyRegis',
			type:'POST',
			data : {
				username : $('#username').val(),
				name:$('#name').val(),
				dept:$('#dept').val(),
				fpassword:$('#fpassword').val(),
				femail:$('#femail').val(),
				fmobile:$('#Fmobile').val(),
				dob:$('#dob').val(),
			},
			success:function(data)
			{
				if(data=="Sign up succesfully")
					{
					$('#mesg').text(data);
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