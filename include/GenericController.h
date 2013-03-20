#include "HTTPRequest.h"
#include "HTTPResponse.h"

#ifndef GENERICCONTROLLER_H
#define GENERICCONTROLLER_H

class GenericController {
    public:
        GenericController();
        virtual ~GenericController();

        GenericController* operator=(const GenericController *rhs);

        HTTPRequest* request;
        HTTPResponse* response;

    protected:

    private:
};

#endif // GENERICCONTROLLER_H
