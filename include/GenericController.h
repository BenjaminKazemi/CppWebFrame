#include "HTTPRequest.h"
#include "HTTPResponse.h"

#ifndef GENERICCONTROLLER_H
#define GENERICCONTROLLER_H

class GenericController : public HTTPRequest, public HTTPResponse
{
    public:
        GenericController();
        virtual ~GenericController();
    protected:
    private:
};

#endif // GENERICCONTROLLER_H
