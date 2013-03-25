#ifndef ROUTE_H
#define ROUTE_H

#include <string>

typedef void (*Handler)();

struct Route {
    std::string method;
    std::string urlFormat;
    Handler handler;

    Route( std::string method, std::string urlFormat, Handler handler ) {
        this->method = method;
        this->urlFormat = urlFormat;
        this->handler = handler;
    }

    static Route New( std::string method, std::string urlFormat, Handler handler ) {
        Route r( method, urlFormat, handler );
        return r;
    }

};

#endif // ROUTE_H
