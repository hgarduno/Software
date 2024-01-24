#include <OrdenesHora.h>
OrdenHora::OrdenHora(const char *pchrPtrFecha,
		     const char *pchrPtrNumOrdenes,
		     const char *pchrPtrImporte,
		     const char *pchrPtrParametro)
{
	SRegistroPro2				<<
	"Fecha"					<<
	"NumOrdenes"				<<
	"Importe"				<<
	"Parametro";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 					<<
	SiscomCampoPro2("Fecha",pchrPtrFecha)		<<
	SiscomCampoPro2("NumOrdenes",pchrPtrNumOrdenes)	<<
	SiscomCampoPro2("Importe",pchrPtrImporte)	<<
	SiscomCampoPro2("Parametro",pchrPtrParametro);

	SRegistrosPro2.SiscomAnexaRegistro();

}

OrdenesHora::OrdenesHora()
{


}

OrdenesHora &OrdenesHora::operator<<(OrdenHora *pOHora)
{
	append(pOHora);
	return *this;

}

OpOrdenesHora::OpOrdenesHora(SiscomDatCom *pSisDatCom,
			      OrdenesHora *pOHora):
		SiscomOperaciones(pSisDatCom,
				  (QPtrList<SiscomInformacion> *)pOHora)
{

}
void OpOrdenesHora::ObtenJornadaTrabajo(SiscomRegistrosPro2 &pSRegistrosPro2)
{
	if(!pSRegistrosPro2.SiscomEsElUltimoRegistro())
	{
	    intHoraInicio=atoi(pSRegistrosPro2["HoraInicio"]);
	    intHoraFin=atoi(pSRegistrosPro2["HoraFin"]);
	    SiscomMensajesLog(gPtrFleArchivoLog,
	    		      "La Jornada De Trabajo:%d,%d",
			      intHoraInicio,
			      intHoraFin);
	    ++pSRegistrosPro2;
	}

}
void OpOrdenesHora::SiscomGeneraRegistros(const SiscomComunicaSrv *pSComunicaSrv,
					  QPtrList<SiscomInformacion> *pQPLSiscom)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
const char *lchrPtrFechaVenta=0,
	    *lchrPtrInicioSemana=0,
	    *lchrPtrFinSemana=0,
	    *lchrPtrDia=0,
	    *lchrPtrHora=0;
int lintHora;
CSisDatosSemana *lCSDatosSemana;
CSisDatoDia *lCSDatoDia;
	ObtenJornadaTrabajo(lSRegistrosPro2);
	for(;
	    !lSRegistrosPro2.SiscomEsElUltimoRegistro();)

	{
	    if((lchrPtrInicioSemana=lSRegistrosPro2["InicioSemana"])[0] &&
	       (lchrPtrFinSemana=lSRegistrosPro2["FinSemana"])[0])
	   {
		lCSDatosSemana=new CSisDatosSemana(
				     "",
				     lchrPtrInicioSemana,
				     lchrPtrFinSemana,
				     "");
		++lSRegistrosPro2;
		while(!lSRegistrosPro2.SiscomEsElUltimoRegistro() &&
		      (lchrPtrDia=lSRegistrosPro2["Dia"])[0])
		{
		  lCSDatoDia=new CSisDatoDia(lchrPtrDia,
		  			     lSRegistrosPro2["FechaVenta"]);
		  ++lSRegistrosPro2;
		  for(lintHora=intHoraInicio;lintHora<intHoraFin;lintHora++)
		  {
		       lCSDatoDia->AnexaDatoDia(new CSisDatoHora(
		     			lSRegistrosPro2["Hora"],
					lSRegistrosPro2["Importe"],
					lSRegistrosPro2["Ordenes"]));
		      ++lSRegistrosPro2;
		  }
		   lCSDatoDia->PonImporteDia(lSRegistrosPro2["ImporteDia"]);
		   lCSDatosSemana->AnexaDia(lCSDatoDia);
		   ++lSRegistrosPro2;
		}
		SiscomMensajesLog(gPtrFleArchivoLog,
				  "Importe Semana:%s",
				  lSRegistrosPro2["ImporteSemana"]);
		lCSDatosSemana->PonImporteSemana(lSRegistrosPro2["ImporteSemana"]);
		++lSRegistrosPro2;
		CSDtsSemanas << lCSDatosSemana;

	   }
	}
delete pSComunicaSrv;	
}
void OpOrdenesHora::ObtenDatosSemanas(CSisDatosSemanas &pCSDtsSemanas)
{
	pCSDtsSemanas=CSDtsSemanas;
}
