#ifndef COOKIE_H
#define COOKIE_H

#include "Declarations.h"

// Needs to improve
struct Cookie {
    string name;
    string value;
    string expires;
    string domain;
    string path;
    bool secured;
    bool httpOnly;

    Cookie( const char *name, const char *value, const char* path = "/" ) {
        this->name = name;
        this->value = value;
        this->path = path;
    }

    string toString() {
        return name + "=" + value + "; path=" + path;
    }
};

#endif // COOKIE_H
