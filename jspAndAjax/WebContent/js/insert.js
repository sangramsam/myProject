$(document).ready(function()
		{
	$('#insert').submit(function()
			{
		$.ajax({
			url:'insert',
			type:'POST',
			data : {
				Name : $('#t1').val(),
			},
			success:function(data)
			{
				$('#mesg').append(data);			
			},
			});
	
		return false;
		
			});
	
		});