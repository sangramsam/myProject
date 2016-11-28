$(document).ready(function()
		{
	$('#updateUsername').submit(function()
			{
		$.ajax({
			url:'update',
			type:'POST',
			datatype:'json',
			data:$('#updateUsername').serialize(),
			success:function(data)
			{
				if(data.isValid)
					{
					$('#displayname').html("name"+data.username);
					$('#displayname').slideDown(500);
					}
				else
					{
					alert('please enter');
					}
			}
		
		});
		return false;
		
			});
	
		});