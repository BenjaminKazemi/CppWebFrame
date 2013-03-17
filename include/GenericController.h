#include "HTTPRequest.h"
#include "HTTPResponse.h"

#ifndef GENERICCONTROLLER_H
#define GENERICCONTROLLER_H

using namespace std;

class GenericController {
    public:
        GenericController();
        virtual ~GenericController();
        virtual void handleRequest() = 0;

        GenericController* operator=(const GenericController *rhs);

        HTTPRequest* request;
        HTTPResponse* response;

    protected:

    private:
};

#endif // GENERICCONTROLLER_H
