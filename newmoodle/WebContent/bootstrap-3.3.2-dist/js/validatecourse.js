$(document).ready(
    function() {
        $("#course").validate({
            rules: {
                'subjectid': {
                    required: true
                },
                'subjectname': {
                    required: true
                },
                'branchid': {
                    required: true
                },
                'sem':{
                    required:true
                }

            },

            submithandler: function (form) {
                form.submit();
            }

        });

    });