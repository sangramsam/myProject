$(document).ready(function()
		{
	$('#bt').submit(function() {
	$.ajax({
		url : 'retrive',
		type : "get",
		dataType:"json",
		data:$('bt').serialize(),
		success : function(data){
			$.each(data, function(i, da){
				var mesg_data="<div id='msg'"+da.name+"'>"+da.address+"</div>";
				$("#user-list").append(mesg_data);
			});
		},
		failure : function(){
			console.log("findAllUser service failed...");	
			
				
		}
	});
});
});