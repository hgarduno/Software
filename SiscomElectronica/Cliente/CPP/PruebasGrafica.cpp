#include <qapplication.h>
#include <GraficaOrdenes.h>
FILE *gPtrFleArchivoLog;
int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    QGraficaOrdenes *w;
    gPtrFleArchivoLog=stdout;
    w = new QGraficaOrdenes(0,"w"); 
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}

