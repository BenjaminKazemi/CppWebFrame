#include "HTTPRequest.h"
#include "HTTPResponse.h"

#ifndef GENERICCONTROLLER_H
#define GENERICCONTROLLER_H

class GenericController {
    public:
        GenericController( string uriPrefix );
        virtual ~GenericController();
        HTTPRequest* request;
        HTTPResponse* response;

    protected:

    private:
};

#endif // GENERICCONTROLLER_H
