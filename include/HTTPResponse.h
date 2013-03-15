#include <iostream>

#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

using namespace std;

class HTTPResponse
{
    public:
        HTTPResponse();
        virtual ~HTTPResponse();
        void addHeader( string key, string value );
        void printHeaders();

    protected:
        string headers;

    private:
};

#endif // HTTPRESPONSE_H
