#include "HTTPRequest.h"
#include "Declarations.h"

HTTPRequest::HTTPRequest() {
    queryString = getenv("QUERY_STRING");
    httpMethod = getenv("REQUEST_METHOD");
    requestedUri = getenv("PATH_INFO");
}

HTTPRequest::~HTTPRequest() {
}

string HTTPRequest::getFormValue( const char* key ) {
    if( key == NULL || queryString == "" ) {
        return "";
    }

    int first = 0, last = 0;
    const char* tmpKey = key;
    const char* tmpQueryString = queryString.c_str();
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
        return "";
    } else {
        char* value = new char[last-first];
        int i = 0;
        for( first++; first < last; first++, i++ ) {
            value[i] = queryString[first];
        }
        value[i] = '\0';
        string s = decodePathParams( value );
        delete value;

        return s;
    }
}

bool HTTPRequest::existFormKey( const char* key ) {
    if( key == NULL || *key == '\0' || queryString.empty() ) {
        return "";
    }

    const char* tmpKey = key;
    const char* tmpQueryString = queryString.c_str();
    for(; *tmpQueryString!= '\0'; tmpQueryString++ ) {
        if( *tmpKey == *tmpQueryString ) {
            tmpKey++;
            if( *tmpKey == '\0' && *(tmpQueryString+1) == '=' ) {
                return true;
            }
        } else {
            while( *(tmpQueryString+1) != '\0' && *tmpQueryString != '&' ) {
                tmpQueryString++;
            }
            tmpKey = key;
        }
    }

    return false;
}

string HTTPRequest::decodePathParams( const char *src ) {
    if( src == NULL ) return NULL;

    string dest = "";
    for(; *src != '\0'; src++ ) {
        if(*src == '+') {
            dest += ' ';
        } else if(*src == '%') {
            int code;
            if(sscanf(src+1, "%2x", &code) != 1) {
                code = '?';
            }
            dest += code;
            src +=2;
        } else {
            dest += *src;
        }
    }
    return dest;
}

string HTTPRequest::getHeader( const char *key ) {
    const char *val = getenv( string("HTTP_").append(key).c_str() );
    if( val == 0 ) {
        return "";
    }
    return val;
}
