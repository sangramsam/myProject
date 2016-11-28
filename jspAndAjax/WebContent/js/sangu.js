$(document).ready(function()
		{
	$('#name').change(function()
			{
		$.ajax({
			url:'snh',
			type:'POST',
			data : {
				name : $('#name').val(),
			},
			datatype:'json',
			data:$('#itm').serialize(),
			success:function(data)
			{
				$.each(data, function(i, sa){
					$("#list").append(
							"<option id='course-" + sa.id + "' value='"+sa.id+"'>" + sa.id + "</option>");
				});
			},
			});
	
		return false;
		
			});
		});