#include <map>

#include "GenericController.h"

#ifndef ControllerManager_H
#define ControllerManager_H

class ControllerManager : private HTTPRequest {
    public:
        ControllerManager();
        virtual ~ControllerManager();
        void route();
        bool setUrlHandler( string urlFormat,  GenericController* handler );

    protected:

    private:
        map<string, GenericController*> routes;

};

#endif // ControllerManager_H
