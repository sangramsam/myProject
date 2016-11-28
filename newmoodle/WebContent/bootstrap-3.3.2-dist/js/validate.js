$(document).ready(
    function() {
        $("#signup").validate({
            rules: {
                'name': {
                    required: true,
                    minlength: 5
                },
                'rollno': {
                    required: true,
                    minlength: 5
                },
                'Password': {
                    required: true,
                    minlength: 3,
                    maxlength: 15
                },
                'Rpassword': {
                    required: true,
                    equalTo: "#Password"
                },
                'email': {
                    email: true,
                    required: true
                },
                'course': {
                    required: true
                },
                'sem': {
                    required: true
                },
                'DOB': {
                    required: true
                }

            },
            messages: {
                'email': {
                    required: 'please submit your email'
                }
            },

            submithandler: function (form) {
                form.submit();
            }

        });
        $("#login").validate({
            rules: {
                'username': {
                    required: true,
                    minlength: 5
                },
                'password':{
                    required:true
                },
                'select':{
                    required:true
                }

            },
            submithandler: function (form) {
                form.submit();
            }

        });
        $("#change").validate({
            rules: {
                'fusername': {
                    required: true,
                    minlength: 5
                },
                'fpassword':{
                    required:true,
                    minlength:5,
                    maxlength:10
                },
                'fcpassword':{
                    required:true,
                    equalTo: "#fpassword"
                },
                'DOB':{
                	required:true
                }

            },
            submithandler: function (form) {
                form.submit();
            }

        });
        
        
    });