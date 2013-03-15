#include "GenericController.h"

GenericController::GenericController() {
    request = new HTTPRequest();
    response = new HTTPResponse();
}

GenericController::~GenericController() {
    delete this;
}
