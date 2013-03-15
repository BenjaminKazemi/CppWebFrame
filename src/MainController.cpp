#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "MainController.h"

using namespace std;

MainController::MainController() {}

MainController::~MainController() {
    delete this;
}

void MainController::handleRequest() {
    try {
        char *nameF = NULL, *nameM = NULL, *nameL = NULL;

        addHeader( "Content-type", "text/html; charset=utf-8" );
        addHeader( "First-Name", "Benyamin" );
        addHeader( "Last-Name", "Kazemi" );
        printHeaders();

        printf( "<html>\n" );
        printf( "<head>\n" );
        printf( "<title> MainController </title>\n" );
        printf( "</head>\n" );
        printf( "<body>\n" );
        getFormValue( "nameM", &nameM );
        getFormValue( "nameL", &nameL );
        getFormValue( "nameF", &nameF );

        if( nameF == NULL && nameM == NULL && nameL == NULL ) {
            printf( "<h2>Hello World!</h2>\n" );
        }

        if( nameF != NULL ) {
            printf( "<h2>nameF: %s</h2>\n", nameF );
        }
        if( nameM != NULL ) {
            printf( "<h2>nameM: %s</h2>\n", nameM );
        }
        if( nameL != NULL ) {
            printf( "<h2>nameL: %s</h2>\n", nameL );
        }

        printf( "isGet: %i<br> \n", isGet() );
        printf( "isPost: %i<br> \n", isPost() );
        printf( "isPut: %i<br> \n", isPut() );
        printf( "isDelete: %i<br> \n", isDelete() );
        printf( "isOptions: %i<br> \n", isOptions() );
        printf( "isHead: %i<br> \n", isHead() );

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
