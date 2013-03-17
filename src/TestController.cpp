#include "TestController.h"

TestController::TestController() {
}

TestController::~TestController() {
}

void TestController::handleRequest() {
    response->out << "<h4> TestController->OK! </h4>";

    response->send();
}
