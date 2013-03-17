#include <iostream>

#include "ControllerManager.h"
#include "MainController.h"
#include "TestController.h"

using namespace std;

ControllerManager::ControllerManager() {
    setUrlHandler("/main", new MainController() );
    setUrlHandler("/main/test", new TestController() );
//    setUrlHandler("/main/t1", this );
}

ControllerManager::~ControllerManager() {
    for( map<string, GenericController*>::iterator ii = routes.begin(); ii != routes.end(); ++ii ) {
        delete (*ii).second;
    }
}

bool ControllerManager::setUrlHandler( string urlFormat,  GenericController* handler ) {
    routes[urlFormat] = handler;
    return true;
}

void ControllerManager::route() {
    bool handled = false;
    for( map<string, GenericController*>::iterator ii = routes.begin(); ii != routes.end(); ++ii ) {
        //cout << "Content-type: text/html; charset=UTF-8\r\n\r\n";
        //cout << "<h3>request->getRequestedUri() : " << "getRequestedUri()" << "</h3>";
        // response->out << "<h3>(*ii).first.compare( request->getRequestedUri() : " << (*ii).first.compare( request->getRequestedUri() ) << "</h3>";
        if( (*ii).first.compare( getRequestedUri() ) == 0 ) {
            // response->out << "<h3>" << (*ii).first << "</h3>";
            (*ii).second->handleRequest();
            handled = true;
            break;
        }
    }
    if( !handled ) {
//        cout << "OK";
        //send();
    }
}

