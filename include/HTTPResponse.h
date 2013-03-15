#include <string>
#include <sstream>

#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

using namespace std;

class HTTPResponse {
    public:
        HTTPResponse();
        virtual ~HTTPResponse();
        void addHeader( string key, string value );
        void setContentType( string contentType );
        void setCharset( string charSet );
        void send();
        ostringstream out;

    protected:
        string headers;
        string contentType;
        string charSet;

    private:
};

#endif // HTTPRESPONSE_H
