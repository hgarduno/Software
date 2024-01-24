#include <qapplication.h>
#include <SiscomTiendas41.h>
#include <SiscomDesarrollo3Qt++.h>
#include <signal.h>
#include <stdlib.h>
QFont gQFTipoLetra;
FILE *gPtrFleArchivoLog;
FILE *gPtrFleArchivoLog3Qt;
/*
SISCOMVentanaPrincipal *w;
*/
SiscomTiendas41 *w;
void ControladorSIGINT(int pintNSenal)
{
sigset_t lSigset_tMask,lSigset_tAnterior;
signal(SIGINT,ControladorSIGINT);
sigfillset(&lSigset_tMask);
sigprocmask(SIG_SETMASK,&lSigset_tMask,&lSigset_tAnterior);
SiscomEscribeLog3Qt(
		  "ControladorSIGINT:Imposible interrumpir el sistema");
}
void ControladorSIGSEGV(int pintNSenal)
{
sigset_t lSigset_tMask,lSigset_tAnterior;
signal(SIGSEGV,ControladorSIGSEGV);
sigfillset(&lSigset_tMask);
sigprocmask(SIG_SETMASK,&lSigset_tMask,&lSigset_tAnterior);
SiscomEscribeLog3Qt(
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
	SiscomEscribeLog3Qt(
			  "Se Abrio El Archivo Log:%s",
			 lchrArrArchivo);
	gPtrFleArchivoLog=fopen(lchrArrArchivo,"a+");

    }

}
int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    //a.setFont(QFont("Helvetica [Cronyx]", 9));
    InstalaManejadorSenales();
    gPtrFleArchivoLog=gPtrFleArchivoLog3Qt=stdout;
    w = new SiscomTiendas41(0); 
    AbreArchivoLog(argv,"SiscomTiendas4Log"); 
    gPtrFleArchivoLog3Qt=gPtrFleArchivoLog;
    if(argv[1] &&
    	!strcmp(argv[1],"Maximizada"))
    w->showMaximized();
    else
    w->show();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}

