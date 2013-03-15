#include "MainController.h"

using namespace std;

int main ()
{
    MainController* controller = new MainController( "/cgi-bin/hello.cgi" );
    controller->handleRequest();

    return 0;
}
