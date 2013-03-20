#ifndef ControllerManager_H
#define ControllerManager_H

#include "Route.h"
#include "GenericController.h"

class ControllerManager : private HTTPRequest {
    public:
        ControllerManager( Routes routes );
        virtual ~ControllerManager() {};
        bool setUrlHandler( string method, string urlFormat, Handler handler );
        void route();

    protected:

    private:
        Routes routes;

};

#endif // ControllerManager_H
