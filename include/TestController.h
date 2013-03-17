#include "GenericController.h"

#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H


class TestController : public GenericController {
    public:
        TestController();
        virtual ~TestController();
        void handleRequest();

    protected:
    private:
};

#endif // TESTCONTROLLER_H
