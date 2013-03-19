#include <iostream>
#include <vector>

#include "ControllerManager.h"
#include "MainController.h"
#include "TestController.h"
#include "RedirectExampleController.h"

using namespace std;

ControllerManager::ControllerManager() {
}

ControllerManager::~ControllerManager() {
    for( vector<Route>::iterator p=routes.begin(); p!=routes.end(); ++p ) {
        delete (*p).handler;
    }
}

bool ControllerManager::setUrlHandler( string method, string urlFormat,  GenericController* handler ) {
    Route route( method, urlFormat, handler );
    routes.push_back( route );
    return true;
}

void ControllerManager::route() {
    for( vector<Route>::iterator p=routes.begin(); p!=routes.end(); ++p ) {
        if( (*p).urlFormat.compare( getRequestedUri() ) == 0 &&
            (*p).method.find( getHttpMethod() ) != string::npos ) {
            (*p).handler->handleRequest();
            break;
        }
    }
}

