#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "MainController.h"

MainController::MainController() {}

MainController::~MainController() {
}

void MainController::handleRequest() {
    string nameF, nameM, nameL;

    Cookie c("user", "Benjamin");
    response->addCookie( c );
    response->addHeader( "First-Name", "Benyamin" );
    response->addHeader( "Last-Name", "Kazemi" );
    c.name = "test_cookie";
    c.value = "Test_Benjamin";
    response->addCookie( c );

    response->out << "<html>\n";
    response->out << "<head>\n";
    response->out << "<title> ControllerManager </title>\n";
    response->out << "</head>\n";
    response->out << "<body>\n";
    nameM = request->getFormValue( "nameM" );
    nameL = request->getFormValue( "nameL" );
    nameF = request->getFormValue( "nameF" );
    request->getFormValue( "nonExistingParam" );

    if( nameF.empty() && nameM.empty() && nameL.empty() ) {
        response->out << "<h2>Hello World!</h2>\n";
    }

    if( !nameF.empty() ) {
        response->out << "<h2>nameF: " << nameF << "</h2>\n";
    }
    if( !nameM.empty() ) {
        response->out << "<h2>nameM: " << nameM.c_str() << "</h2>\n";
    }
    if( !nameL.empty() ) {
        response->out << "<h2>nameL: " << nameL.c_str() << "</h2>\n";
    }

    response->out << "existFormKey(test): " << request->existFormKey("test") << "<br>";
    response->out << "requested URI: {" << request->getRequestedUri() << "}<br>";

    response->out << "httpMethod: " << request->getHttpMethod() << "<br>" << endl;
    response->out << "header(name): " << request->getHeader("name") << "<br>" << endl;
    response->out << "HTTP_COOKIE: " << getenv("HTTP_COOKIE") << "<br>" << endl;

    response->out << "</body>\n";
    response->out << "</html>\n";

    response->send();
}
