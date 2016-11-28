$(document).ready(
    function() {
        $("#list").validate({
            rules: {
                'courseid': {
                    required: true
                },
                'semid': {
                    required: true
                }

            },

            submithandler: function (form) {
                form.submit();
            }

        });

    });