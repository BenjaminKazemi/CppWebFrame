#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "HTTPRequest.h"

HTTPRequest::HTTPRequest() {
    queryString = getenv("QUERY_STRING");
    requestMethod = getenv("REQUEST_METHOD");
    //decodePathParams( queryString );
}

HTTPRequest::~HTTPRequest() {}

void HTTPRequest::getFormValue( char* key, char** value ) {
    if( key == NULL || queryString == NULL ) {
        *value = NULL;
        return;
    }

    int first = 0, last = 0;
    char* tmpKey = key;
    char* tmpQueryString = queryString;
    for(; *tmpQueryString!= '\0'; tmpQueryString++ ) {
        if( *tmpKey == *tmpQueryString ) {
            tmpKey++;
            first++;
            if( *tmpKey == '\0' && *(tmpQueryString+1) == '=' ) {
                last = first;
                tmpQueryString++;
                while( *tmpQueryString != '\0' && *tmpQueryString != '&' ) {
                    last++;
                    tmpQueryString++;
                }
                break;
            }
        } else {
            while( *(tmpQueryString+1) != '\0' && *tmpQueryString != '&' ) {
                first++;
                tmpQueryString++;
            }
            tmpKey = key;
            last = ++first;
        }
    }

    if( first >= last ) {
        *value = NULL;
    } else {
        *value = new char[last-first];
        int i = 0;
        for( first++; first < last; first++, i++ ) {
            (*value)[i] = queryString[first];
        }
        (*value)[i] = '\0';
        decodePathParams( *value );
    }
}

void HTTPRequest::decodePathParams( char *src ) {
    if( src == NULL ) return;

    char *dest = src;
    for(; *src != '\0'; src++, dest++ ) {
        if(*src == '+') {
            *dest = ' ';
        } else if(*src == '%') {
            int code;
            if(sscanf(src+1, "%2x", &code) != 1) {
                code = '?';
            }
            *dest = code;
            src +=2;
        } else {
            *dest = *src;
        }
    }
    *dest = '\0';
}

bool HTTPRequest::isGet() {
    return strcmp("GET", requestMethod) == 0;
}

bool HTTPRequest::isPost() {
    return strcmp("POST", requestMethod) == 0;
}

bool HTTPRequest::isDelete() {
    return strcmp("DELETE", requestMethod) == 0;
}

bool HTTPRequest::isPut() {
    return strcmp("PUT", requestMethod) == 0;
}

bool HTTPRequest::isOptions() {
    return strcmp("OPTIONS", requestMethod) == 0;
}

bool HTTPRequest::isHead() {
    return strcmp("HEAD", requestMethod) == 0;
}

