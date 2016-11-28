$(document).ready(function()
		{
		$('#sem').change(function()
				{
			
			$.ajax({
				url:'select',
				type:'POST',
				data : {
					course: $('#Course').val(),
					sem:$('#Sem').val(),
				},
				datatype:'json',
				data:$('#faculty').serialize(),
				success:function(data)
				{
					$.each(data, function(i, sa){
						$("#subject").append(
								"<option id='sub-" + sa.name + "' value='"+sa.name+"'>" + sa.name + "</option>");
					});
				},
				});
		
			return false;
			
				});	
});