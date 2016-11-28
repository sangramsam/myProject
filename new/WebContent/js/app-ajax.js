//$(document).ready(function() {
//        $('#userName').blur(function(event) {
//                var name = $('#userName').val();
//                $.get('GetUserServlet', {
//                        userName : name
//                }, function(responseText) {
//                        $('#ajaxGetUserServletResponse').text(responseText);
//                });
//        });
//});
//

$(document).ready(function() {
	$('#btn').on('click',function() {
		$.ajax({
			url : 'GetUserServlet',
			data : {
				userName : $('#userName').val(),
				pass:$("#pass").val(),
			},
			success : function(responseText) {
				$('#ajaxGetUserServletResponse').text(responseText).show();
			}
		});
	});
});