$(document).ready(function()
		{
	$('#searchassign').submit(function()
			{
		$.ajax({
			url:'searchAssignSubject',
			type:'GET',
//			dataType:'json',
			data : {
				sfcourse: $('#sfcourse').val(),
				scode:$('#scode').val(),
			},
			success:function(data)
			{
				if(data=="error")
					{
					$('#ssubject').text("no record found");
					}
				else
					{
				$('#tdsub').removeClass("hide");
				$.each(data, function(i, da)
						{
					$('.table').append(
							"<tr><td>"+da.subjectname+"</td>"+"<td>"+da.subject_id+"</td>"+"<td>"+da.course_id+"</td>"+"<td>"+da.facultyid+"</td>"+"<td>"+da.semester+"</td>"+"<td>"+da.facultyname+"</td>"+"</tr>"
							);
					
					
				});
					}
							
			},
			});
	
		return false;
		
			});
	
		});