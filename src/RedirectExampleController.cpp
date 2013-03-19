#include "RedirectExampleController.h"

RedirectExampleController::RedirectExampleController() {
}

RedirectExampleController::~RedirectExampleController() {
}

void RedirectExampleController::handleRequest() {
    response->redirect( "/main", false );
}

