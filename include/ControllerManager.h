#ifndef ControllerManager_H
#define ControllerManager_H

#include "Route.h"
#include "GenericController.h"

class ControllerManager : private HTTPRequest {
    public:
        ControllerManager() {};
        virtual ~ControllerManager() {};
        void route();
        bool setUrlHandler( string method, string urlFormat, Handler handler );

    protected:

    private:
        std::vector<Route> routes;

};

#endif // ControllerManager_H
