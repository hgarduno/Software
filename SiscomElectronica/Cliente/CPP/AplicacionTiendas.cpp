#include <qapplication.h>
#include <Personas.h>
#include <SiscomElectronica.h>
#include <SiscomDesarrollo3Qt++.h>

#include <zSiscomConexion.h>
#include <zLineaComandosTiendas.h> 
#include <zManejadorEjecucion.h>

#include <signal.h>


QFont gQFTipoLetra;
FILE *gPtrFleArchivoLog=stdout;
FILE *gPtrFleArchivoLog3Qt=stdout;
/*
SISCOMVentanaPrincipal *w;
*/
SiscomElectronica *w;
Persona *Empleado;


void ControladorSIGINT(int pintNSenal)
{
sigset_t lSigset_tMask,lSigset_tAnterior;
signal(SIGINT,ControladorSIGINT);
sigfillset(&lSigset_tMask);
sigprocmask(SIG_SETMASK,&lSigset_tMask,&lSigset_tAnterior);
}
void ControladorSIGSEGV(int pintNSenal)
{
sigset_t lSigset_tMask,lSigset_tAnterior;
signal(SIGSEGV,ControladorSIGSEGV);
sigfillset(&lSigset_tMask);
sigprocmask(SIG_SETMASK,&lSigset_tMask,&lSigset_tAnterior);
/*
w->CambiaEstadoFirma("0");
*/
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
const char *lchrPtrArchivoConfiguracion;


    //if(pchrPtrArgv[2])
    {
		sprintf(lchrArrArchivo,
			"%s/%s.log",
			getenv("HOME"),
			pchrPtrEmpleado);
	gPtrFleArchivoLog=fopen(lchrArrArchivo,"a+");
	gPtrFleArchivoLog3Qt=gPtrFleArchivoLog;
    }
}
int CargaTipoLetraSistema(const char *pchrPtrArchivo,
			   QFont *pQFLetra)
{
char lchrArrArchivo[256];
sprintf(lchrArrArchivo,
	"%s/%s",
	getenv("HOME"),
	pchrPtrArchivo);
return SiscomDesarrollo3Qt::TipoLetraPerfil(lchrArrArchivo,pQFLetra);
}
FILE *ArchivoEjecuciones()
{
FILE *lFlePtrArchivo;
char lchrArrArchivo[125];
sprintf(lchrArrArchivo,
	"%s/SiscomTiendas.Ejecuciones",
	getenv("HOME"));
if((lFlePtrArchivo=fopen(lchrArrArchivo,"a+")))
    return lFlePtrArchivo;
else
return 0;
}

zManejadorEjecucion *GrabaEjecucion(zLineaComandosTiendas *pzLineaCmdsTiendas)
{
zSiscomConexion lzSisConexion("SiscomTiendas.Ejecuciones","a+");
zManejadorEjecucion *lzManEjecucion=new zManejadorEjecucion(&lzSisConexion);
lzManEjecucion->Agrega(pzLineaCmdsTiendas);
return lzManEjecucion;
}
void GrabaEjecucionSegundoPlano(zLineaComandosTiendas *pzLineaCmdsTiendas,
				int pintPidTiendas)
{

}
void ObtenTipoLetra(QApplication *pQAppTiendas)
{
QFont lQFTipoLetra;
if(!CargaTipoLetraSistema("SiscomElectronica.PerfilSiscomElectronica",
    			  &lQFTipoLetra))
    {
    SiscomEscribeLog3Qt("No se encontro el archivo de perfiles");
    pQAppTiendas->setFont(QFont("Helvetica [Cronyx]", 7));
    }
    else
    pQAppTiendas->setFont(lQFTipoLetra);
}
void EjecutandoMaximizada(SiscomElectronica *pQSiscomElectronica,
		zLineaComandosTiendas *pzLineaCmdsTiendas)
{
    if(pzLineaCmdsTiendas->CorreMaximizada())
    pQSiscomElectronica->showMaximized();
    else
    pQSiscomElectronica->show();
}
void MuestraEjecuciones()
{
zSiscomConexion lzSisConexion("/home/hgarduno/SiscomTiendas.Ejecuciones","r");
zManejadorEjecucion lzManEjecucion(&lzSisConexion,0);
}
int main( int pintArgc, char **pchrPtrArgv)
{
zLineaComandosTiendas lzLineaCmdsTiendas(pintArgc,pchrPtrArgv);
zManejadorEjecucion *lzMnEjecucion;
QApplication a( pintArgc, pchrPtrArgv);
SiscomElectronica *w;
int lintPidTiendas;
    	gPtrFleArchivoLog=stdout;
	/*
	MuestraEjecuciones();
	lzMnEjecucion=GrabaEjecucion(&lzLineaCmdsTiendas);
	MuestraEjecuciones();
	*/
    	w=new SiscomElectronica(lzMnEjecucion,&a);
    	Empleado=w->ObtenEmpleado();
    	AbreArchivoLog(pchrPtrArgv,Empleado->SRegistrosPro2["Firma"]);
	ObtenTipoLetra(&a);
    	EjecutandoMaximizada(w,&lzLineaCmdsTiendas);
    	a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    	a.exec();
}
