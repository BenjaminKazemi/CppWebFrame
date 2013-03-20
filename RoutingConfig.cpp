#include "RoutingConfig.h"

#include "Declarations.h"
#include "ControllerManager.h"
#include "MainController.h"
#include "TestController.h"
#include "RedirectExampleController.h"

void handler_main();
void handler_test();
void handler_redirect();
void handler_all();

Routes RoutingConfig::config() {
    Routes routes;

    routes.push_back( Route::New( "GET|POST",    "/main",            handler_main ) );
    routes.push_back( Route::New( "POST",        "/main/test",       handler_main ) );
    routes.push_back( Route::New( "PUT",         "/main/redirect",   handler_main ) );
    routes.push_back( Route::New( "*",           "/main/test",       handler_test ) );
    routes.push_back( Route::New( "GET",         "/main/redirect",   handler_redirect ) );
    routes.push_back( Route::New( "*",           "*",                handler_all ) );

    return routes;
}

void handler_main() {
    MainController m;
    m.handleRequest();
}

void handler_test() {
    TestController m;
    m.handleRequest();
}

void handler_redirect() {
    RedirectExampleController m;
    m.handleRequest();
}

void handler_all() {
    TestController m;
    m.handleAll();
}

