#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "Declarations.h"
#include "Cookie.h"

class HTTPResponse {
    public:
        HTTPResponse();
        virtual ~HTTPResponse();
        void addHeader( string key, string value );
        void addCookie( Cookie cookie );
        void setContentType( string contentType );
        void setCharset( string charSet );
        void send();
        void redirect( string url, bool sendParams = true, bool keepMethod = true );
        void redirectOutside( string url );

        ostringstream out;

    protected:
        string headers;
        string contentType;
        string charSet;

    private:
};

#endif // HTTPRESPONSE_H
