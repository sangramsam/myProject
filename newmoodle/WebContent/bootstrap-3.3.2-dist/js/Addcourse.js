$(document).ready(function()
		{
	$('#course').submit(function()
			{
		$.ajax({
			url:'AddSubject',
			type:'POST',
			data : {
				subjectid: $('#subjectid').val(),
				subjectname:$('#subjectname').val(),
				branchid:$('#branchid').val(),
				sem:$('#sem').val(),
			},
			success:function(data)
			{
				if(data=="Subject Added Successfully")
					{
					$('#submesg').text(data);
					}
				else
					{
					$('#submesg').text(data);
				
					}
							
			},
			});
	
		return false;
		
			});
	
		});