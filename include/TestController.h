#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H

#include "GenericController.h"

class TestController : public GenericController {
    public:
        TestController();
        virtual ~TestController();
        void handleRequest();

    protected:
    private:
};

#endif // TESTCONTROLLER_H
