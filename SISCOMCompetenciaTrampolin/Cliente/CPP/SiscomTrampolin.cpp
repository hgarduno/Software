#include <SiscomTrampolin.h>

#include <qmessagebox.h>

SiscomTrampolin::SiscomTrampolin(QWidget *pQWParent,
				 const char *pchrPtrName,
				 WFlags pWFlags):
			SISCOMVentanaPrincipal(pQWParent,pchrPtrName,pWFlags)
{

	ObtenDatosComunicacion();
//	PonDatosComunicaciones(5620,"127.0.0.1");
	SiscomIniciaVentana();

}
void SiscomTrampolin::ObtenDatosComunicacion()
{
const char *lchrPtrPto=getenv("PtoComSvr"),
  	   *lchrPtrDirIp=getenv("DirIpSvr");

	if(lchrPtrPto &&
	   lchrPtrDirIp)
	PonDatosComunicaciones(atoi(lchrPtrPto),
				lchrPtrDirIp);
	else
	  QMessageBox::information(this,
	  			    "Mensaje Del Sistema",
				    "NO estan definidas las variables\nPtoComSvr,DirIpSvr");

}
