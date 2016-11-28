var app=angular.module("app01",["ngRoute"]);

app.config(function($routeProvider){
    $routeProvider.when("/personal",{
            templateUrl:"personal banking.html",
        })
        .when("/home",{
            templateUrl:"mainpage.html"
        })
        .when("/admin",{
            templateUrl:"admin login.html"
        })
        .when("/FAQ",{
            templateUrl:"FAQ.html"
        })
        .when("/MobileDth",{
            templateUrl:"mobdth.html"
        })
        .when("/logIn",{
            templateUrl:"login.html"
        })
        .when("/NewUser",{
            templateUrl:"NewUser.html"
        })

        .when("/forgot",{
            templateUrl:"forgotPassword.html"
        })
        .when("/",{
            templateUrl:"mainpage.html",

        })
        .otherwise({
            redirectTo:'/'
        })
});