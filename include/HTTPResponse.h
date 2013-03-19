#include <string>
#include <sstream>
#include <cookie.h>

#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

using namespace std;

class HTTPResponse {
    public:
        HTTPResponse();
        virtual ~HTTPResponse();
        void addHeader( string key, string value );
        void addCookie( Cookie cookie );
        void setContentType( string contentType );
        void setCharset( string charSet );
        void send();
        ostringstream out;
        void redirect( string url, bool sendParams = true, bool keepMethod = true );
        void redirectOutside( string url );

    protected:
        string headers;
        string contentType;
        string charSet;

    private:
};

#endif // HTTPRESPONSE_H
