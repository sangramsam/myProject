$(document).ready(function()
		{
	$('#assign').submit(function()
			{
		$.ajax({
			url:'AssignSubject',
			type:'POST',
			data : {
				facid: $('#facid').val(),
				subname:$('#subname').val(),
				subid:$('#subid').val(),
				branch:$('#branch').val(),
				semester:$('#semester').val(),
			},
			success:function(data)
			{
				if(data=="Subject Assign Successfully")
					{
					$('#resmesg').text(data).toSlideDown(2000);
					}
				else
					{
					$('#resmesg').text(data);
				
					}
							
			},
			});
	
		return false;
		
			});
	
		});