#include "MainController.h"

using namespace std;

int main ()
{
    MainController* controller = new MainController();
    controller->handleRequest();

    return 0;
}
