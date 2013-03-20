#include "TestController.h"

void TestController::handleRequest() {
    response->out << "<h4> TestController->OK! </h4>";
    response->send();
}

void TestController::handleAll() {
    response->out << "<h4> All! </h4>";
    response->send();
}
