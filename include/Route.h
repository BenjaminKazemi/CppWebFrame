#ifndef ROUTE_H
#define ROUTE_H

#include "GenericController.h"
#include "ControllerManager.h"

struct Route {
    string method;
    string urlFormat;
    Handler handler;

    Route( string method, string urlFormat, Handler handler) {
        this->method = method;
        this->urlFormat = urlFormat;
        this->handler = handler;
    }

};

#endif // ROUTE_H
