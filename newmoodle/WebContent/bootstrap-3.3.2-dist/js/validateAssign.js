$(document).ready(
    function() {
        $("#assign").validate({
            rules: {
                'facid': {
                    required: true
                },
                'subname': {
                    required: true
                },
                'subid': {
                    required: true
                },
                'branch':{
                    required:true
                },
                'semester':{
                    required:true
                }

            },

            submithandler: function (form) {
                form.submit();
            }

        });

    });