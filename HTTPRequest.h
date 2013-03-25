#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include "Declarations.h"

class HTTPRequest {
public:
    HTTPRequest();
    virtual ~HTTPRequest() {};

    string getqueryString() { return queryString; }
    string getHttpMethod() { return httpMethod; };
    string getRequestedUri() { return requestedUri; };

    string getFormValue( const char* key );
    string getHeader( const char* key );
    string getCookie( const char* key );

    bool existFormKey( const char* key );

protected:

private:
    string queryString;
    string httpMethod;
    string requestedUri;

    string decodePathParams( const char* src );
};

#endif // HTTPREQUEST_H
