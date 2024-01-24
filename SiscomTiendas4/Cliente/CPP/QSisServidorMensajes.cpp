#include <QSisServidorMensajes.h>
#include <qapplication.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>
QMensajeInterfaz *QMensajeI;
QSisServidorMensajes::QSisServidorMensajes(QWidget *pQWParent,
					   const char *pchrPtrNombre,
					   int pintPtoCom):
					  QWParent(pQWParent),
					  intPtoCom(pintPtoCom)
{
	IniciaServidor();
	start();

}

void QSisServidorMensajes::run()
{
int lintTamano;
struct sockaddr_in lSSocAddrInReg;
char lchrArrCadena[5];
SArgsSiscom lSArgsSiscom;
SiscomLog("");

	 lintTamano=sizeof(struct sockaddr_in);
	   while(1)
	   {
	   	SiscomLog("Esperando...");
	         if((intSocketCliente=::accept(intSocket,
					     (struct sockaddr *)&lSSocAddrInReg,
					     (socklen_t *)&lintTamano))<0)
		 {
	  	 SiscomLog("ACCEPT:%s",strerror(errno));
		 return;
		 }
		 else
		 {
		   SiscomLog("Se recibio un mensaje");
		   ProcesaMensaje(intSocketCliente,&lSArgsSiscom);
		   QMensajeI->CamposSiscomPro2(
		   		lSArgsSiscom.intNRegistrosDat,
				lSArgsSiscom.LCSiscomPro2Dat);
		   QApplication::postEvent(QWParent,QMensajeI);
		/*
		   close(intSocketCliente);
		 */
		 }
	   }

}
void QSisServidorMensajes::ProcesaMensaje(int pintSocket,
					  SArgsSiscom *pSArgsSiscomDat)
{
SSiscomOperaciones *lSSiscomOp=0;
int lintContador;
char *lchrPtrOperacion=0;
int lintNRegistros;
SSiscomOperaciones2 *lSOpPtrOperaciones=0;
SiscomOperaciones2 *lSOpPtrSistema=0;
	SiscomLog("");
	memset(pSArgsSiscomDat,0,sizeof(SArgsSiscom));
	SiscomLeeNumeroRegistros(pintSocket,
				 &lintNRegistros);	
	SiscomLeeOperacion(pintSocket,
                           &lchrPtrOperacion);
	AsignaOperacionesVersion2(pintSocket,
				  lintNRegistros,
				  &lSOpPtrOperaciones,
				  pSArgsSiscomDat);
	ManejadorErrores(pSArgsSiscomDat);
	lSOpPtrSistema=SiscomOperaciones2CualEjecuta(
				lchrPtrOperacion,
				lSOpPtrOperaciones,
				SiscomErrorOperacion2,
				pSArgsSiscomDat);
	SiscomOperaciones2Ejecuta(lSOpPtrSistema,
				  pSArgsSiscomDat);

}
void QSisServidorMensajes::IniciaServidor()
{
int lintTamano;
struct sockaddr_in lSSocAddrInDir;

SiscomLog("");
	if((intSocket=socket(PF_INET,SOCK_STREAM,0) )<0)
	{
	  SiscomLog("SOCKET:%s",strerror(errno));
	  return ;	
	}
	else
	{
	 lSSocAddrInDir.sin_port=htons(intPtoCom);
	 lSSocAddrInDir.sin_family=AF_INET;
	 lSSocAddrInDir.sin_addr.s_addr=INADDR_ANY;
	 if(bind(intSocket,
		 (struct sockaddr *)&lSSocAddrInDir,
		 sizeof(struct sockaddr_in))<0)
	 {
	  SiscomLog("BIND:%s",strerror(errno));
	  return ;	


	 }
	 else
 	   if(listen(intSocket,10)<0)
	  {
	  SiscomLog("LISTEN:%s",strerror(errno));
	  return;	

	  }

	 
	}
SiscomLog("Se creo el socket");
}

void AsignaOperacionesVersion2(int pintSocket,
			       int pintNRegistros,
			       SSiscomOperaciones2 **pSSOperaciones2,
			       SArgsSiscom *pSArgsSiscom)
{
pSArgsSiscom->intSocketCliente=pintSocket;
pSArgsSiscom->intNRegistrosDat=pintNRegistros;
SiscomAnexaOperacion2("ClienteRegistrado",
		      OClienteRegistrado(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("ClienteNuevo",
		      OClienteNuevo(),
		      pSSOperaciones2);
}

void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr)
{
SiscomMensajesLog(gPtrFleArchivoLog,"Operacion No Soportada");
}
SiscomOperaciones2 *OClienteRegistrado()
{
SiscomOperaciones2 *lSOpOperaciones=0;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ClienteRegistrado,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OClienteNuevo()
{
SiscomOperaciones2 *lSOpOperaciones=0;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ClienteNuevo,lSOpOperaciones);
return lSOpOperaciones;
}
void ClienteRegistrado(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomLog("Los Registros:%d",
	  pSAgsSiscom->intNRegistrosDat);
pSAgsSiscom->intCodigoRetorno=0;
QMensajeI=new QMensajeInterfaz(68000);
}
void ClienteNuevo(SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
pSAgsSiscom->intCodigoRetorno=0;
QMensajeI=new QMensajeInterfaz(68001);
}
void Error(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
}
void ManejadorErrores(SArgsSiscom *pSAgsSiscom)
{
pSAgsSiscom->SiscomError[1]=Error;
}


QMensajeInterfaz::QMensajeInterfaz(int pintNumRegistros,
				   LCamposSiscomPro2 *pLCSiscomPro2Dat):
		    QCustomEvent(68000),
		    intNumRegistros(pintNumRegistros),
		    LCSiscomPro2Dat(pLCSiscomPro2Dat)
{


}
QMensajeInterfaz::QMensajeInterfaz(int pintNMensaje):
			QCustomEvent(pintNMensaje)
{

}
void QMensajeInterfaz::CamposSiscomPro2(int pintNRegistros,
					LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
	intNumRegistros=pintNRegistros;
	LCSiscomPro2Dat=pLCSiscomPro2Dat;
}
LCamposSiscomPro2 *QMensajeInterfaz::ObtenMensaje()
{
	return LCSiscomPro2Dat;
}
int QMensajeInterfaz::ObtenNumeroRegistros()
{
	return intNumRegistros;
}
