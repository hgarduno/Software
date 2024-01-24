/*! \file ControladorOrdenes.cpp
 * Archivo que contiene la funcionalidad para el control
 * de las ordenes realizadas en el proceso de venta, cotizacion
 *
 * Autor: Heli Garduno Esquivel
 * Fecha: 2007-06-06
 *
 */
#include <ControladorOrdenes.h>

IdentificadorOrden::IdentificadorOrden(const char *pchrPtrIdOrden,
				       const char *pchrPtrParametro)
{
	SRegistroPro2 <<
	"IdOrden"     <<
	"Parametro";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2					<<
	SiscomCampoPro2("IdOrden",pchrPtrIdOrden)	<<
	SiscomCampoPro2("Parametro",pchrPtrParametro);
	SRegistrosPro2.SiscomAnexaRegistro();
}

IdentificadorOrdenes::IdentificadorOrdenes()
{

}

IdentificadorOrdenes &IdentificadorOrdenes::operator<<(IdentificadorOrden *pIdOrden)
{
	append(pIdOrden);
	return *this;
}

OpIdentificadorOrdenes::OpIdentificadorOrdenes(SiscomDatCom *pSisDatCom,
					       IdentificadorOrdenes *pIdOrden):
			SiscomOperaciones(pSisDatCom,
					 (QPtrList<SiscomInformacion> *)pIdOrden)
{

}
void OpIdentificadorOrdenes::SiscomGeneraRegistros(
			const SiscomComunicaSrv *pSComunicaSrv,
			QPtrList<SiscomInformacion> *pQPtrSInformacion)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
IdentificadorOrdenes *lIdOrdenes=(IdentificadorOrdenes *)pQPtrSInformacion;
	 for(;
	     !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	     ++lSRegistrosPro2)
	  (*lIdOrdenes)<< new IdentificadorOrden(lSRegistrosPro2["IdOrden"],"");
}

OpProductosOrdenes::OpProductosOrdenes(SiscomDatCom *pSisDatCom,
		     IdentificadorOrdenes *pIdOrdenes):
		 SiscomOperaciones(pSisDatCom,
		 		   (QPtrList<SiscomInformacion> *)pIdOrdenes)
{


}
OpProductosOrdenes::OpProductosOrdenes(SiscomDatCom *pSisDatCom,
				       SiscomParametrosConsulta *pGOrdenes):
			SiscomOperaciones(pSisDatCom,
					  (QPtrList<SiscomInformacion> *)pGOrdenes)
{


}
void OpProductosOrdenes::SiscomGeneraRegistros(
			const SiscomComunicaSrv *pSComunicaSrv,
			QPtrList<SiscomInformacion> *pQPtrSInformacion)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
ProductosE *lPProductos=(ProductosE *)pQPtrSInformacion;

	 for(;
	     !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	     ++lSRegistrosPro2)
	 {
	  (*lPProductos) <<
	  	new ProductoE(
			lSRegistrosPro2["cveproducto"],
			"",
			"",
			"",
			lSRegistrosPro2["precio"],
			"",
			lSRegistrosPro2["cantidad"],
			"",
			"",
			"",
			lSRegistrosPro2["importe"],
			"",
			"1",
			"",
			"",
			"",
			"",
			"",
			lSRegistrosPro2["idventa"],
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"");
	 }
}

GeneralOrden::GeneralOrden(const char *pchrPtrIdOrden,
			   const char *pchrPtrFecha,
			   const char *pchrPtrImporteO,
			   const char *pchrPtrImporteIva,
			   Persona *pPCliente):
	PCliente(pPCliente)
{

	SRegistroPro2	<<
	"IdOrden"	<<
	"Fecha"		<<
	"ImporteO"	<<
	"ImporteIVA";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("IdOrden",pchrPtrIdOrden)	<<
	SiscomCampoPro2("Fecha",pchrPtrFecha)		<<
	SiscomCampoPro2("ImporteO",pchrPtrImporteO)	<<
	SiscomCampoPro2("ImporteIVA",pchrPtrImporteIva);
	SRegistrosPro2.SiscomAnexaRegistro();
}
Persona *GeneralOrden::ObtenCliente()
{
	return PCliente;
}
GeneralesOrden::GeneralesOrden()
{

}
GeneralesOrden &GeneralesOrden::operator<<(GeneralOrden *pGOrden)
{
	append(pGOrden);
	return *this;
}

OpGeneralesOrden::OpGeneralesOrden(SiscomDatCom *pSisDatCom,
				   SiscomParametrosConsulta *pGOrden):
		SiscomOperaciones(pSisDatCom,
				 (QPtrList<SiscomInformacion>*)pGOrden)
{


}

void OpGeneralesOrden::SiscomGeneraRegistros(
			const SiscomComunicaSrv *pSComunicaSrv,
			QPtrList<SiscomInformacion> *pQPtrSInformacion)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
GeneralesOrden *lGOrden=(GeneralesOrden *)pQPtrSInformacion;
Persona *lPCliente;
	 for(;
	     !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	     ++lSRegistrosPro2)
	 {
	   lPCliente=new Persona(lSRegistrosPro2["Nombre"],
	   			 lSRegistrosPro2["APaterno"],
				 lSRegistrosPro2["AMaterno"],
				 "",
				 lSRegistrosPro2["IdCliente"],
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "");
	   (*lGOrden) << new GeneralOrden(lSRegistrosPro2["NumOrden"],
	   				  lSRegistrosPro2["Fecha"],
					  lSRegistrosPro2["ImporteTotal"],
					  lSRegistrosPro2["ImporteIVA"],
					  lPCliente);
	  }
}

