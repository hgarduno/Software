#include <qapplication.h>
#include <IMP_VentasElectronica.h>
#include <SISCOMComunicaciones++.h>
FILE *gPtrFleArchivoLog;
QFont gQFTipoLetra;
int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    //a.setFont(QFont("Helvetica [Cronyx]", 18));
    gPtrFleArchivoLog=stdout;
    QVentasElectronica *w = new QVentasElectronica(new SiscomDatCom(5645,"127.0.0.1"),0);
    w->show();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}

