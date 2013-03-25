#ifndef REDIRECTEXAMPLECONTROLLER_H
#define REDIRECTEXAMPLECONTROLLER_H

#include "GenericController.h"

class RedirectExampleController : public GenericController {
    public:
        RedirectExampleController() {};
        virtual ~RedirectExampleController() {};
        void handleRequest();

    protected:
    private:
};

#endif // REDIRECTEXAMPLECONTROLLER_H
