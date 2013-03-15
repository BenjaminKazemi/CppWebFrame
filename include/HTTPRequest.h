#include <string>

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

using namespace std;

class HTTPRequest {
public:
    HTTPRequest();
    virtual ~HTTPRequest();
    string getqueryString() { return queryString; }
    string getFormValue( const char* key );
    bool existFormKey( const char* key );
    bool isGet();
    bool isPost();
    bool isDelete();
    bool isPut();
    bool isOptions();
    bool isHead();

protected:

private:
    string queryString;
    string httpMethod;

    string decodePathParams( const char *src );
};

#endif // HTTPREQUEST_H
