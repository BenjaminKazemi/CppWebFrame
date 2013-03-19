#include <map>
#include <vector>

#include "Route.h"
#include "GenericController.h"

#ifndef ControllerManager_H
#define ControllerManager_H

class ControllerManager : private HTTPRequest {
    public:
        ControllerManager();
        virtual ~ControllerManager();
        void route();
        bool setUrlHandler( string method, string urlFormat,  GenericController* handler );

    protected:

    private:
        vector<Route> routes;

};

#endif // ControllerManager_H
