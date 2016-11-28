$(document).ready(function()
		{
	$('#listfac').submit(function()
			{
		$.ajax({
			url:'searchfaculty',
			type:'GET',
//			dataType:'json',
			data : {
				department: $('#department').val(),
				
			},
			success:function(data)
			{
				if(data=="error")
				{
				$('#fac').text("no record found").fadeIn(10000);
				}
			else
				{
				$('#tdf').removeClass("hide");
				$.each(data, function(i, da)
						{
					$('.table').append(
							"<tr><td>"+da.name+"</td>"+"<td>"+da.facultyid+"</td>"+"<td>"+da.email+"</td>"+"<td>"+da.dob+"</td>"+"<td>"+da.mobile+"</td>"+"<td>"+da.department+"</td>"+"</tr>"
							);
					
					
				});
				}
							
			},
			});
	
		return false;
		
			});
	
		});