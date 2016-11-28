$(document).ready(
    function() {
        $("#faculty").validate({
            rules: {
                'course': {
                    required: true,
                                 
                },
                'sem': {
                    required: true,
                },
                'subject': {
                    required: true,
                },
                'upload': {
                    required: true,
                }

            },

            submithandler: function (form) {
                form.submit();
            }

        });
      
    });