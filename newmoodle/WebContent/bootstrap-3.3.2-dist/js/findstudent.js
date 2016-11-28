$(document).ready(function()
		{
	$('#searchstudent').submit(function()
			{
		$.ajax({
			url:'findstudent',
			type:'GET',
//			dataType:'json',
			data : {
				scourse: $('#scourse').val(),
				sname:$('#sname').val(),
			},
			success:function(data)
			{
				if(data=="error")
					{
					$('#ss').text("no record found");
					}
				else
					{
				$('#tds').removeClass("hide");
				$.each(data, function(i, da)
						{
					$('.table').append(
							"<tr><td>"+da.name+"</td>"
							+"<td>"+da.roll_no+"</td>"
							+"<td>"+da.email+"</td>"
							+"<td>"+da.course+"</td>"
							+"<td>"+da.semester+"</td>"
							+"</tr>"
							);
					
					
				});
					}
							
			},
			});
	
		return false;
		
			});
	
		});