#include <stdlib.h>

#include "ControllerManager.h"
#include "MainController.h"
#include "TestController.h"
#include "RedirectExampleController.h"

void handler_main();
void handler_test();
void handler_redirect();

int main() {
    ControllerManager controller;

    controller.setUrlHandler("GET|POST",    "/main",            handler_main );
    controller.setUrlHandler("POST",        "/main/test",       handler_main );
    controller.setUrlHandler("PUT",         "/main/redirect",   handler_main );

    controller.setUrlHandler("*",           "/main/test",       handler_test );
    controller.setUrlHandler("GET",         "/main/redirect",   handler_redirect );

    controller.route();

    return EXIT_SUCCESS;
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

