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

        response->addHeader( "Content-type", "text/html; charset=utf-8" );
        response->addHeader( "First-Name", "Benyamin" );
        response->addHeader( "Last-Name", "Kazemi" );
        response->printHeaders();

        printf( "<html>\n" );
        printf( "<head>\n" );
        printf( "<title> MainController </title>\n" );
        printf( "</head>\n" );
        printf( "<body>\n" );
        nameM = request->getFormValue( "nameM" );
        nameL = request->getFormValue( "nameL" );
        nameF = request->getFormValue( "nameF" );
        request->getFormValue( "nonExistingParam" );


        if( nameF.empty() && nameM.empty() && nameL.empty() ) {
            printf( "<h2>Hello World!</h2>\n" );
        }

        if( !nameF.empty() ) {
            printf( "<h2>nameF: %s</h2>\n", nameF.c_str() );
        }
        if( !nameM.empty() ) {
            printf( "<h2>nameM: %s</h2>\n", nameM.c_str() );
        }
        if( !nameL.empty() ) {
            printf( "<h2>nameL: %s</h2>\n", nameL.c_str() );
        }

        printf( "existFormKey(test): %i<br> \n", request->existFormKey("test") );

        printf( "isGet: %i<br> \n", request->isGet() );
        printf( "isPost: %i<br> \n", request->isPost() );
        printf( "isPut: %i<br> \n", request->isPut() );
        printf( "isDelete: %i<br> \n", request->isDelete() );
        printf( "isOptions: %i<br> \n", request->isOptions() );
        printf( "isHead: %i<br> \n", request->isHead() );

        printf( "</body>\n" );
        printf( "</html>\n" );

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
