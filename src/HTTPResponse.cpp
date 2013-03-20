#include "Declarations.h"
#include "HTTPResponse.h"

HTTPResponse::HTTPResponse() {
    contentType = "text/html";
    charSet = "UTF-8";
}

HTTPResponse::~HTTPResponse() {
}

void HTTPResponse::addHeader( string key, string value ) {
    headers += key + ":" + value + "\r\n";
}

void HTTPResponse::send() {
    addHeader( "Content-type", contentType + "; charset=" + charSet );
    std::cout << headers.append("\r\n") << out.str();
}

void HTTPResponse::setContentType( string contentType ) {
    this->contentType = contentType;
}

void HTTPResponse::setCharset( string charSet ) {
    this->charSet = charSet;
}

void HTTPResponse::addCookie( Cookie cookie ) {
    addHeader( "Set-Cookie", cookie.toString() );
}

void HTTPResponse::redirectOutside( string url ) {
    addHeader("Location", url );
    send();
}

void HTTPResponse::redirect( string url, bool sendParams, bool keepMethod ) {
    string redirectUrl = getenv("SERVER_PROTOCOL");
    if( redirectUrl.find("HTTPS") != string::npos ) {
        redirectUrl = "https://";
    } else if( redirectUrl.find("HTTP") != string::npos ) {
        redirectUrl = "http://";
    } else {
        redirectUrl = "http://";
    }

    redirectUrl += getenv("HTTP_HOST") + string(getenv("SCRIPT_NAME")) + url;

    if( sendParams ) {
        redirectUrl += "?" + string(getenv("QUERY_STRING"));
    }

    if( !keepMethod ) {
        addHeader("Status Code", "302 Found");
    } else {
        addHeader("Status Code", "302 Found");
    }
    redirectOutside( redirectUrl );
}
