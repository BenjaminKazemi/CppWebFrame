#include "GenericController.h"

GenericController::GenericController() {
    request = new HTTPRequest();
    response = new HTTPResponse();
}

GenericController::~GenericController() {
    delete request;
    delete response;
}

GenericController* GenericController::operator = ( const GenericController *rhs ) {
    return this;
}

