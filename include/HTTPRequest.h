#include <string>

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

using namespace std;

class HTTPRequest {
public:
    HTTPRequest( string uriPrefix );
    virtual ~HTTPRequest();

    string getqueryString() { return queryString; }
    string getFormValue( const char* key );
    string getRequestedUri() { return requestedUri; };
    string getHttpMethod() { return httpMethod; };
    string getHeader( const char* key );

    bool existFormKey( const char* key );

protected:

private:
    string queryString;
    string httpMethod;
    string requestedUri;
    string uriPrefix;

    string decodePathParams( const char* src );
};

#endif // HTTPREQUEST_H
