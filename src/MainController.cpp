#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "MainController.h"

using namespace std;

MainController::MainController() {
}

MainController::~MainController() {
    delete this;
}

void MainController::handleRequest() {
    try {
        string nameF, nameM, nameL;

        response->addHeader( "First-Name", "Benyamin" );
        response->addHeader( "Last-Name", "Kazemi" );

        response->out << "<html>\n";
        response->out << "<head>\n";
        response->out << "<title> MainController </title>\n";
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
        response->out << "Testing response->out really quick! <br> <br>" ;

        response->out << "isGet: " << request->isGet() << "<br>" << endl;
        response->out << "isPost: " << request->isPost() << "<br> \n";
        response->out << "isPut: " << request->isPut() << "<br> \n";
        response->out << "isDelete: " << request->isDelete() << "<br> \n";
        response->out << "isOptions: " << request->isOptions() << "<br> \n";
        response->out << "isHead: " << request->isHead() << "<br> \n";

        response->out << "</body>\n";
        response->out << "</html>\n";

        response->send();
    }
    catch( exception e ) {
        printf("Content-type:text/html\r\n\r\n" );
        printf("<html>\n" );
        printf("<head>\n" );
        printf("<title> MainController </title>\n" );
        printf("</head>\n" );
        printf("<body>\n" );
        printf("<h3>ERROR!</h3>\n" );
        printf("</body>\n" );
        printf("</html>\n" );
    }
}
