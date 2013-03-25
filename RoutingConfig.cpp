#include "RoutingConfig.h"

#include "Declarations.h"
#include "ControllerManager.h"
#include "MainController.h"
#include "TestController.h"
#include "RedirectExampleController.h"
#include "DriverController.h"

void handler_main();
void handler_test();
void handler_redirect();
void handler_all();
void db_test_all();

Routes RoutingConfig::config() {
    Routes routes;

    routes.push_back( Route::New( "GET|POST",    "/main",            handler_main ) );
    routes.push_back( Route::New( "POST",        "/main/test",       handler_main ) );
    routes.push_back( Route::New( "PUT",         "/main/redirect",   handler_main ) );
    routes.push_back( Route::New( "*",           "/main/test",       handler_test ) );
    routes.push_back( Route::New( "GET",         "/main/redirect",   handler_redirect ) );
    routes.push_back( Route::New( "*",           "/db",              db_test_all ) );
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

void db_test_all() {
    DriverController m;
    m.handleAll();
}

