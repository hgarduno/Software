#include <qapplication.h>
#include <SiscomTrampolin.h>
#include <signal.h>
QFont gQFTipoLetra;
FILE *gPtrFleArchivoLog;
FILE *gPtrFleArchivoLog3Qt;
SISCOMVentanaPrincipal *w;
void ControladorSIGINT(int pintNSenal)
{
sigset_t lSigset_tMask,lSigset_tAnterior;
signal(SIGINT,ControladorSIGINT);
sigfillset(&lSigset_tMask);
sigprocmask(SIG_SETMASK,&lSigset_tMask,&lSigset_tAnterior);
SiscomMensajesLog(gPtrFleArchivoLog,
		  "ControladorSIGINT:Imposible interrumpir el sistema");
}
void ControladorSIGSEGV(int pintNSenal)
{
sigset_t lSigset_tMask,lSigset_tAnterior;
signal(SIGSEGV,ControladorSIGSEGV);
sigfillset(&lSigset_tMask);
sigprocmask(SIG_SETMASK,&lSigset_tMask,&lSigset_tAnterior);
SiscomMensajesLog(gPtrFleArchivoLog,
		  "ControladorSIGSEGV:El Sistema Trono");
exit(0);
}
void InstalaManejadorSenales()
{

	signal(SIGINT,ControladorSIGINT);
	signal(SIGSEGV,ControladorSIGSEGV); 

}
void AbreArchivoLog(char **pchrPtrArgv,const char *pchrPtrEmpleado)
{
char lchrArrArchivo[1024];
    if(pchrPtrArgv[2])
    {
		sprintf(lchrArrArchivo,
			"%s/%s.log",
			getenv("HOME"),
			pchrPtrEmpleado);
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Se Abrio El Archivo Log:%s",
			 lchrArrArchivo);
	gPtrFleArchivoLog=fopen(lchrArrArchivo,"a+");

    }

}
int main( int argc, char ** argv )
{

    QApplication a( argc, argv );
    //a.setFont(QFont("Helvetica [Cronyx]", 18));
    InstalaManejadorSenales();
    gPtrFleArchivoLog=stdout;
    gPtrFleArchivoLog3Qt=gPtrFleArchivoLog;
    w = new SiscomTrampolin(); 
    if(argv[1] &&
    	!strcmp(argv[1],"Maximizada"))
    w->showMaximized();
    else
    w->show();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}

