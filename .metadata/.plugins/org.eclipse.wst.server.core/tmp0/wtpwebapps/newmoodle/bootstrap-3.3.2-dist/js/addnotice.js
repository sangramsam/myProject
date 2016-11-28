$(document).ready(function()
		{
	$('#add').submit(function()
			{
		$.ajax({
			url:'Addnotice',
			type:'POST',
			data : {
				notice : $('#notice').val(),
				
			},
			success:function(data)
			{
				if(data=="success")
					{
					alert("added successfully")
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