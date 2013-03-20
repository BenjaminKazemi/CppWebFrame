#ifndef GENERICCONTROLLER_H
#define GENERICCONTROLLER_H

#include "HTTPRequest.h"
#include "HTTPResponse.h"

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
