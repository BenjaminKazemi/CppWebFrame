#include "HTTPRequest.h"

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

class MainController : public HTTPRequest {
    public:
        MainController();
        virtual ~MainController();
        void handleRequest();

    protected:

    private:

};

#endif // MAINCONTROLLER_H