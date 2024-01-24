#include <qapplication.h>
#include <SISCOMVentanaPrincipal.h>
#include <errno.h>
#include <stdlib.h>
QFont gQFTipoLetra;
FILE *gPtrFleArchivoLog;
int errno;
void AbreArchivoLog();
int main( int argc, char ** argv )
{
const char *lchrPtrMaximizada;
    QApplication a( argc, argv );
    gPtrFleArchivoLog=stdout;
    //a.setFont(QFont("Helvetica [Cronyx]", 18));
    SISCOMVentanaPrincipal *w = new SISCOMVentanaPrincipal();
    AbreArchivoLog();
    if(argv[1] &&
       !strcmp(argv[1],"Maximizada"))
    w->showMaximized();
    else
    w->show();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}
void AbreArchivoLog()
{
char lchrArrNmbArchivo[1024];
const char *lchrPtrAplicacion;

	if(!(lchrPtrAplicacion=getenv("Aplicacion")))
	{
    	  gPtrFleArchivoLog=stdout;
	  fprintf(gPtrFleArchivoLog,
	  		    "AbreArchivoLog:No Se existen la variable de ambiente Aplicacion");
			   
	}
	else
	{
	  sprintf(lchrArrNmbArchivo,
	  	  "%s/%s.log",
		  getenv("HOME"),
		  lchrPtrAplicacion);
          if(!(gPtrFleArchivoLog=fopen(lchrArrNmbArchivo,"a+")))
	  {
	    fprintf(stdout,
	    		      "AbreArchivoLog:Error al abrir :%s {%s}",
			       lchrArrNmbArchivo,
			       strerror(errno));
	  }
	  else
	  fprintf(stdout,
	  		    "AbreArchivoLog:Archivo Log %s",
			    lchrArrNmbArchivo);
	}
}
