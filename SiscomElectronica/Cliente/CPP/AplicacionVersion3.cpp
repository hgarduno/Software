#include <qapplication.h>
#include <SISCOMVentanaPrincipal.h>
#include <signal.h>
QFont gQFTipoLetra;
FILE *gPtrFleArchivoLog;
void ControladorSIGINT(int pintNSenal)
{
sigset_t lSigset_tMask,lSigset_tAnterior;
signal(SIGINT,ControladorSIGINT);
sigfillset(&lSigset_tMask);
sigprocmask(SIG_SETMASK,&lSigset_tMask,&lSigset_tAnterior);
SiscomMensajesLog(gPtrFleArchivoLog,
		  "ControladorSIGINT:Imposible interrumpir el sistema");
}
void InstalaManejadorSenales()
{

	signal(SIGINT,ControladorSIGINT);

}
int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    gPtrFleArchivoLog=stdout;
    a.setFont(QFont("Helvetica [Cronyx]", 12 ));
    if(!strcmp(argv[1],"Maximizada"))
    w->showMaximized();
    else
    w->show();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}

