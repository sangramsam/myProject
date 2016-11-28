$(document).ready(function()
		{
	$('#updatestudent').submit(function()
			{
		$.ajax({
			url:'findstudentforupdate',
			type:'GET',
//			dataType:'json',
			data : {
				ucourse: $('#ucourse').val(),
				uname:$('#uname').val(),
			},
			success:function(data)
			{
				if(data=="error")
				{
				$('#up').text("no record found");
				}
			else
				var roll=123;
				{
				$.each(data, function(i, da)
						{
					$('#studentupdate').append(
							"<table class='table table-bordered' style='background-color:white'>"+
							"<tr>"+
							"<td>"+
							"<label>Roll_No</label>"+
							"</td>"+
							"<td>"+
							"<input value='"+da.roll_no+"' id='std-roll_no"+roll+"' type='text' disabled/>"+
							"</td>"+
							"</tr>"+
							"<tr>"+
							"<td>"+
							"<label>Name</label>"+
							"</td>"+
							"<td>"+
							"<input value='"+da.name+"' id='std-name"+roll+"' type='text'/>"+
							"</td>"+
							"</tr>"+
							"<tr>"+
							"<td>"+
							"<label>EMAIL</label>"+
							"</td>"+
							"<td>"+
							"<input value='"+da.email+"' id='std-email"+roll+"' type='text'/>"+
							"</td>"+
							"</tr>"+
							"<tr>"+
							"<td>"+
							"<label>DOB</label>"+
							"</td>"+
							"<td>"+
							"<input value='"+da.dob+"' id='std-dob"+roll+"' type='text' disabled />"+
							"</td>"+
							"</tr>"+
							"<tr>"+
							"<td>"+
							"<label>COURSE</label>"+
							"</td>"+
							"<td>"+
							"<input value='"+da.course+"' id='std-course"+roll+"' type='text'/>"+
							"</td>"+
							"</tr>"+
							"<tr>"+
							"<td>"+
							"<label>SEMESTER</label>"+
							"</td>"+
							"<td>"+
							"<input value='"+da.semester+"' id='std-sem"+roll+"' type='text'/>"+
							"</td>"+
							"</tr>"+
							"<tr>"+
							"<td></td>"+
							"<td><button id='btn-save-job"+da.roll_no +"' onClick='saveAfterEdit("+roll+")'  class='btn btn-default'> Edit and Save </button></td>"+
							"</table>"
					
					
					);
					
					
				});

				}			
			
			},
			});
	
		return false;
		
			});
		});
	function saveAfterEdit(roll)
	{
		var roll_no=$("#std-roll_no"+roll).val();
		var name=$("#std-name"+roll).val();
		var email=$("#std-email"+roll).val();
		var dob=$("#std-dob"+roll).val();
		var course=$("#std-course"+roll).val();
		var sem=$("#std-sem"+roll).val();
		$.ajax({
			type:"GET",
			url:"update",
			data : {
				roll_no:  roll_no,
				name:name,
				email:email,
				dob:dob,
				course:course,
				 sem: sem,
			},
			success:function(data)
			{
				if(data=="success")
					{
					alert("success");
					}
				else
					{
					alert("errorr");
				
					}
							
			},
		});
	}
	
		