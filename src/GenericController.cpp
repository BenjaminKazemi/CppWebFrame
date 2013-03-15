#include "GenericController.h"

GenericController::GenericController( string uriPrefix ) {
    request = new HTTPRequest( uriPrefix );
    response = new HTTPResponse();
}

GenericController::~GenericController() {
    delete this;
}
