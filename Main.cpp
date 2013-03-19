#include <stdlib.h>

#include "ControllerManager.h"
#include "MainController.h"
#include "TestController.h"
#include "RedirectExampleController.h"

using namespace std;

int main() {
    ControllerManager controller;

    controller.setUrlHandler("GET|POST",    "/main",            new MainController() );
    controller.setUrlHandler("POST",        "/main/test",       new MainController() );
    controller.setUrlHandler("PUT",         "/main/redirect",   new MainController() );

    controller.setUrlHandler("GET",         "/main/test",       new TestController() );
    controller.setUrlHandler("GET",         "/main/redirect",   new RedirectExampleController() );

    controller.route();

    return EXIT_SUCCESS;
}
