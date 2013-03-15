#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#define MAXLEN 80
#define EXTRA 5
#define MAXINPUT MAXLEN + EXTRA + 2

class HTTPRequest
{
public:
    HTTPRequest();
    virtual ~HTTPRequest();
    char* getqueryString() { return queryString; }
    void getFormValue( char* key, char** value );
    bool isGet();
    bool isPost();
    bool isDelete();
    bool isPut();
    bool isOptions();
    bool isHead();

protected:

private:
    char* queryString;
    char* requestMethod;

    void decodePathParams( char *src );
};

#endif // HTTPREQUEST_H
