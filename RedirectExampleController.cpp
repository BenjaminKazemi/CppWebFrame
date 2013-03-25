#include "RedirectExampleController.h"

void RedirectExampleController::handleRequest() {
    response->redirect( "/main" );
}

