#include <stdio.h>
#include "HTTPResponse.h"

HTTPResponse::HTTPResponse() {
}

HTTPResponse::~HTTPResponse() {
    delete this;
}

void HTTPResponse::addHeader( string key, string value ) {
    headers += key + ":" + value + "\r\n";
}

void HTTPResponse::printHeaders() {
    printf( headers.append("\r\n").c_str() );
}
