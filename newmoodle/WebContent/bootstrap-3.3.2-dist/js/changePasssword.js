$(document).ready(function()
		{
	$('#change').submit(function()
			{
		$.ajax({
			url:'changePassword',
			type:'POST',
			data : {
				username : $('#fusername').val(),
				password:$('#fpassword').val(),
				DOB:$('#dob').val(),
				cuser:	$("input[name='cuser']:checked", '#change').val(),
			},
			success:function(data)
			{
				if(data=="success")
					{
					alert("password change successfully");
					}
				else
					{
					$('#resp').text(data);
				
					}
							
			},
			});
	
		return false;
		
			});
	
		});