#ifndef DRIVERCONTROLLER_H
#define DRIVERCONTROLLER_H

#include "GenericController.h"

class DriverController : public GenericController {
    public:
        DriverController() {}
        virtual ~DriverController() {}
        void handleAll();

    protected:

    private:
};

#endif // DRIVERCONTROLLER_H
