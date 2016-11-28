$(document).ready(function(e) {
	$("#spsignin").submit(function(e){
	       e.preventDefault();
	});
    $("#btn").click(function(e) {
    	var user=$("#username").val();
    	var pass=$("#pass").val();
        $.ajax({
        	type:"POST",
        	url:"login",
        	data:'user='+encodeURIComponent(user)+'&'+'pass='+encodeURIComponent(user),
        	dataType:"json",
            success : function(responseText) {
                $('mesgs').text(responseText);
            }
        });
    });
});