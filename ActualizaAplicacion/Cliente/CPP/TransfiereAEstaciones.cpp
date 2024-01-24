#include <TransfiereAEstaciones.h>
#include <Estaciones.h>
#include <qapplication.h>
TransfiereAEstaciones::TransfiereAEstaciones(QObject *pQOParent,
					     SiscomDatCom *pSDatCom,
					     const char *pchrPtrOperacion,
					     ListaEstaciones *pLstEstaciones):
				SDatCom(pSDatCom),
				chrPtrOperacion(pchrPtrOperacion),
				LstEstaciones2(pLstEstaciones),
				QOParent(pQOParent)
{
	CreaRegistroComunicaciones();
	EnviaOrden();
	start();
}
TransfiereAEstaciones::~TransfiereAEstaciones()
{
	wait();
	delete SComunicaSrv;	
	
}
void TransfiereAEstaciones::run()
{

	while(SComunicaSrv->SiscomObtenRespuesta())
	{
         SiscomRegistrosPro2 lSRegistrosPro2(SComunicaSrv); 
	  QApplication::postEvent(QOParent,
				  new QEEdoTransmision(
					lSRegistrosPro2["EdoTransmision"],
		 			lSRegistrosPro2["Archivo"],
		 			lSRegistrosPro2["Estacion"],
		 			lSRegistrosPro2["Puerto"]));
	}
}
void TransfiereAEstaciones::CreaRegistroComunicaciones()
{
	SRegistroPro2 <<
	"Estacion" ;

}
void TransfiereAEstaciones::EnviaOrden()
{
SiscomRegistrosPro2 lSRegistrosPro2(&SRegistroPro2);

	lSRegistrosPro2 <<
	SiscomCampoPro2("Estacion","Todas");
	lSRegistrosPro2.SiscomAnexaRegistro();	
	SComunicaSrv=new SiscomComunicaSrv(SDatCom);
	if(!SComunicaSrv->SiscomObtenEdoConexion())
	{
	   SComunicaSrv->SiscomEnvia(&lSRegistrosPro2,"TransfiereAEstaciones");
	}
}
QEEdoTransmision::QEEdoTransmision(const char *pchrPtrEdoTransmision,
				   const char *pchrPtrArchivo,
				   const char *pchrPtrDirIpEstacion,
			           const char *pchrPtrPtoComEstacion):
		QCustomEvent(QEvent::User+100),
		chrPtrEdoTransmision(pchrPtrEdoTransmision),
		chrPtrArchivo(pchrPtrArchivo),
		chrPtrDirIpEstacion(pchrPtrDirIpEstacion),
		chrPtrPtoComEstacion(pchrPtrPtoComEstacion)
{


}
const char *QEEdoTransmision::ObtenEdoTransmision()
{
	return chrPtrEdoTransmision;
}
const char *QEEdoTransmision::ObtenArchivo()
{
	return chrPtrArchivo;
}
const char *QEEdoTransmision::ObtenDirIpEstacion()
{
	return chrPtrDirIpEstacion;
}
const char *QEEdoTransmision::ObtenPtoComEstacion()
{
	return chrPtrPtoComEstacion;
}

