#include <iostream>
#include <stdio.h>
#include "HTTPResponse.h"

HTTPResponse::HTTPResponse() {
    contentType = "text/html";
    charSet = "UTF-8";
}

HTTPResponse::~HTTPResponse() {
    delete this;
}

void HTTPResponse::addHeader( string key, string value ) {
    headers += key + ":" + value + "\r\n";
}

void HTTPResponse::send() {
    addHeader( "Content-type", contentType + "; charset=" + charSet );
    cout << headers.append("\r\n") << out.str();
}

void HTTPResponse::setContentType( string contentType ) {
    this->contentType = contentType;
}

void HTTPResponse::setCharset( string charSet ) {
    this->charSet = charSet;
}
