$(document).ready(function()
		{
		$('#list').change(function()
				{
			$.ajax({
				url:'snh2',
				type:'POST',
				data : {
					list : $('#list').val(),
					name:$('#name').val(),
				},
				datatype:'json',
				data:$('#itm').serialize(),
				success:function(data)
				{
					$.each(data, function(i, sa){
						$("#sub").append(
								"<option id='sub-" + sa.id + "' value='"+sa.id+"'>" + sa.id + "</option>");
					});
				},
				});
		
			return false;
			
				});	
});