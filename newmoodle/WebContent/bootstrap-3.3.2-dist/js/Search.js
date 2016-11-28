$(document).ready(function()
		{
	$('#list').submit(function()
			{
		$.ajax({
			url:'searchstudent',
			type:'GET',
//			dataType:'json',
			data : {
				courseid: $('#courseid').val(),
				semid:$('#semid').val(),
			},
			success:function(data)
			{
				if(data=="error")
				{
				$('#ss').text("no record found");
				}
			else
				{

				$('#td').removeClass("hide");
				$.each(data, function(i, da)
						{
					$('.table').append(
							"<tr><td>"+da.name+"</td>"
							+"<td>"+da.roll_no+"</td>"
							+"<td>"+da.email+"</td>"
							+"<td>"+da.dob+"</td>"
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