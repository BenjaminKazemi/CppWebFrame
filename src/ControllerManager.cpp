#include <iostream>
#include <vector>

#include "ControllerManager.h"
#include "RoutingConfig.h"
#include "MainController.h"
#include "TestController.h"
#include "RedirectExampleController.h"

#include "RedirectExampleController.h"

ControllerManager::ControllerManager( Routes routes ) {
    this->routes = routes;
}

bool ControllerManager::setUrlHandler( string method, string urlFormat, Handler handler  ) {
    Route route( method, urlFormat, handler );
    routes.push_back( route );
    return true;
}

void ControllerManager::route() {
    for( Routes::iterator p = routes.begin(); p != routes.end(); ++p ) {
        if( ( (*p).urlFormat.compare( getRequestedUri() ) == 0 || (*p).urlFormat.compare( "*" ) == 0) &&
            ( (*p).method.find( getHttpMethod() ) != string::npos || (*p).method.compare( "*" ) == 0 ) ) {
            (*p).handler();
            break;
        }
    }
}

int main() {
    RoutingConfig routingConfig;
    ControllerManager controllerManager( routingConfig.config() );

    controllerManager.route();

    return EXIT_SUCCESS;
}
