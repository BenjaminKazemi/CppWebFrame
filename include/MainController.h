#include "GenericController.h"

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

class MainController : public GenericController {
    public:
        MainController( string uriPrefix );
        virtual ~MainController();
        void handleRequest();

    protected:

    private:

};

#endif // MAINCONTROLLER_H
