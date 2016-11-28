$(document).ready(function()
		{
	$('#question').submit(function()
			{
		$.ajax({
			url:'question',
			type:'POST',
			data : {
				question: $('#ques').val(),
				name:  $('#name :selected').val()
				
			},
			success:function(data)
			{
				if(data=="success")
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