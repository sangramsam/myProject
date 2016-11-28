$(document).ready(
    function() {
        $("#facultyregis").validate({
            rules: {
                'username': {
                    required: true,
                    minlength:5,
                    maxlength:15

                },
                'name': {
                    required: true
                },
                'dept':{
                    required:true
                },
                'fpassword': {
                    required: true,
                    minlength:5,
                    maxlength:10
                },
                'fcpassword': {
                    required: true,
                    equalTo: "#fpassword"
                },
                'femail':{
                    required:true,
                    email:true
                },
                'Fmobile':{
                    required:true,
                    minlength:10,
                    maxlength:10
                },
                'dob':{
                    required:true,
                }

            },

            submithandler: function (form) {
                form.submit();
            }

        });

    });