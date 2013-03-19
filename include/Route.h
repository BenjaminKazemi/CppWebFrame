#include <string>

#include "GenericController.h"

#ifndef ROUTE_H
#define ROUTE_H

using namespace std;

struct Route {
    string method;
    string urlFormat;
    GenericController *handler;

    Route( string method, string urlFormat, GenericController *handler ) {
        this->method = method;
        this->urlFormat = urlFormat;
        this->handler = handler;
    }

};

#endif // ROUTE_H
