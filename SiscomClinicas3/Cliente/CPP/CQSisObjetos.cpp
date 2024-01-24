#include <CQSisObjetos.h>
#include <CQSisServicios.h>
#include <CQSisTipoPrecio.h>
#include <CQSisPersonas.h>
#include <CQSisConsultas.h>
#include <CQSisExpedientes.h>
#include <CQSisCotizando.h>
#include <CQSisRecetas.h>
#include <CQSisPrecios.h>
#include <CQSisPreciosServicios.h>
#include <CQSisMatHosp.h>
CQSisObjetos::CQSisObjetos()
{


}
void CQSisObjetos::Servicios(SiscomRegistrosPro2 *pSRegistrosPro2,
			     CQSisLstServicio *pCQSLServicio)
{

	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	 (*pCQSLServicio) << Servicio(pSRegistrosPro2);

}
CQSisServicio *CQSisObjetos::Servicio(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisServicio(
		(*pSRegistrosPro2)["idservicio"],
		(*pSRegistrosPro2)["clave"],
		(*pSRegistrosPro2)["descripcion"],
		(*pSRegistrosPro2)["tipo"]);
}

void CQSisObjetos::TipoPrecios(SiscomRegistrosPro2 *pSRegistrosPro2,
			       CQSisLstTipoPrecio *pCQSLTPrecio)
{

	for(;
	     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	     ++(*pSRegistrosPro2))
	  (*pCQSLTPrecio) << TipoPrecio(pSRegistrosPro2);
}
CQSisTipoPrecio *CQSisObjetos::TipoPrecio(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisTipoPrecio(
		(*pSRegistrosPro2)["idprecio"],
		(*pSRegistrosPro2)["nombre"],
		(*pSRegistrosPro2)["descripcion"]);
}

CQSisPersona *CQSisObjetos::Persona(SiscomRegistrosPro2 *pSRegistrosPro2)
{

return new CQSisPersona(
		(*pSRegistrosPro2)["idpersona"],
		(*pSRegistrosPro2)["nombre"],
		(*pSRegistrosPro2)["apaterno"],
		(*pSRegistrosPro2)["amaterno"],
		(*pSRegistrosPro2)["rfc"],
		(*pSRegistrosPro2)["firma"],
		(*pSRegistrosPro2)["password"],
		"",
		(*pSRegistrosPro2)["idperfil"]);
}
void CQSisObjetos::Personas(SiscomRegistrosPro2 *pSRegistrosPro2,
			    CQSisLstPersona *pCQSLPersona)
{
	for(;
	     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	     ++(*pSRegistrosPro2))
	    (*pCQSLPersona) << Persona(pSRegistrosPro2);
}


CQSisConsulta *CQSisObjetos::Consulta(SiscomRegistrosPro2 *pSRegistrosPro2)
{

return new CQSisConsulta(
	(*pSRegistrosPro2)["idconsulta"],
	new CQSisPersona(
			 (*pSRegistrosPro2)["idpaciente"],
			 (*pSRegistrosPro2)["nmbpaciente"],
			 (*pSRegistrosPro2)["apatpaciente"],
			 (*pSRegistrosPro2)["amatpaciente"],
			 "",
			 "",
			 "",
			 "",
			 ""),
	new CQSisPersona(
			(*pSRegistrosPro2)["idmedico"],
			 (*pSRegistrosPro2)["nmbmedico"],
			 (*pSRegistrosPro2)["apatmedico"],
			 (*pSRegistrosPro2)["amatmedico"],
			 "",
			 "",
			 "",
			 "",
			 ""),
	new CQSisPersona(
			(*pSRegistrosPro2)["idempleado"],
			 (*pSRegistrosPro2)["nmbempleado"],
			 (*pSRegistrosPro2)["apatempleado"],
			 (*pSRegistrosPro2)["amatempleado"],
			 "",
			 "",
			 "",
			 "",
			 ""),
	(*pSRegistrosPro2)["fecha"],
	(*pSRegistrosPro2)["noconsulta"],
	(*pSRegistrosPro2)["idestado"],
	(*pSRegistrosPro2)["estado"]);
	

}
void CQSisObjetos::Consultas(SiscomRegistrosPro2 *pSRegistrosPro2,
			     CQSisLstConsulta *pCQSLConsulta)
{
for(;
    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
    ++(*pSRegistrosPro2))
    (*pCQSLConsulta) << Consulta(pSRegistrosPro2);
}


void CQSisObjetos::NombreCompleto(CQSisPersona *pCQSPersona,
				  char *pchrPtrNombre)
{

sprintf(pchrPtrNombre,
	"%s %s %s",
	(*pCQSPersona)["Nombre"],
	(*pCQSPersona)["APaterno"],
	(*pCQSPersona)["AMaterno"]);
}

CQSisExpediente *CQSisObjetos::Expediente(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisExpediente(
		(*pSRegistrosPro2)["idconsulta"],
		(*pSRegistrosPro2)["observaciones"],
		(*pSRegistrosPro2)["fecha"]);
}



CQSisExpediente *CQSisObjetos::Expediente2(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisExpediente(
		Persona(pSRegistrosPro2),
		(*pSRegistrosPro2)["observaciones"],
		(*pSRegistrosPro2)["fecha"]);
}
void CQSisObjetos::Expedientes(SiscomRegistrosPro2 *pSRegistrosPro2,
			      CQSisLstExpediente *pCQSLExpediente)
{
for(;
     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
   ++(*pSRegistrosPro2))
 (*pCQSLExpediente) << Expediente(pSRegistrosPro2);
}

void CQSisObjetos::Expedientes2(SiscomRegistrosPro2 *pSRegistrosPro2,
			      CQSisLstExpediente *pCQSLExpediente)
{
for(;
     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
   ++(*pSRegistrosPro2))
 (*pCQSLExpediente) << Expediente2(pSRegistrosPro2);
}
CQSisCotizando *CQSisObjetos::Cotizando(SiscomRegistrosPro2 *pSRegistrosPro2)
{

return new CQSisCotizando(
		(*pSRegistrosPro2)["idservicio"],
		(*pSRegistrosPro2)["clave"],
		(*pSRegistrosPro2)["descripcion"],
		(*pSRegistrosPro2)["idpersona"],
		(*pSRegistrosPro2)["idprecio"],
		(*pSRegistrosPro2)["precio"],
		(*pSRegistrosPro2)["importe"],
		(*pSRegistrosPro2)["cantidad"],
		"Si",
		"");
}
void CQSisObjetos::Cotizando(SiscomRegistrosPro2 *pSRegistrosPro2,
			     CQSisLstCotizando *pCQSLCotizando)
{
const char *lchrPtrImporteTotal=0;
for(;
    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
    ++(*pSRegistrosPro2))
{
if(strcmp((*pSRegistrosPro2)["clave"],"TotalServicio"))
 (*pCQSLCotizando) << Cotizando(pSRegistrosPro2);
 lchrPtrImporteTotal=(*pSRegistrosPro2)["importe"];
}
pCQSLCotizando->ImporteTotal(lchrPtrImporteTotal);
}
CQSisReceta *CQSisObjetos::CQSReceta(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisReceta(
	    (*pSRegistrosPro2)["idconsulta"],
	    (*pSRegistrosPro2)["fecha"],
	    (*pSRegistrosPro2)["folio"],
	    (*pSRegistrosPro2)["folio"],
	    (*pSRegistrosPro2)["receta"]);
}
void CQSisObjetos::Recetas(SiscomRegistrosPro2 *pSRegistrosPro2,
			   CQSisLstReceta *pCQSLReceta)
{
for(;
    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
    ++(*pSRegistrosPro2))
  (*pCQSLReceta) << CQSReceta(pSRegistrosPro2);
}

CQSisPrecioServicio *CQSisObjetos::PrecioServicio(
			SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisPrecioServicio(
		Servicio(pSRegistrosPro2),
		new CQSisPrecio(
			(*pSRegistrosPro2)["idprecio"],
			(*pSRegistrosPro2)["nombre"],
			(*pSRegistrosPro2)["dsc"]),
		(*pSRegistrosPro2)["precio"]);
}
void CQSisObjetos::PreciosServicio(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			CQSisLstPrecioServicio *pCQSLPServicio)
{
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	 (*pCQSLPServicio) << PrecioServicio(pSRegistrosPro2);
}

CQSisMatHosp *CQSisObjetos::MaterialHospitalizado(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisMatHosp(
		(*pSRegistrosPro2)["idconsulta"],
		(*pSRegistrosPro2)["idserprod"],
		(*pSRegistrosPro2)["clave"],
		(*pSRegistrosPro2)["descripcion"],
		(*pSRegistrosPro2)["idempleado"],
		(*pSRegistrosPro2)["nombre"],
		(*pSRegistrosPro2)["apaterno"],
		(*pSRegistrosPro2)["amaterno"],
		(*pSRegistrosPro2)["fecha"],
		(*pSRegistrosPro2)["cantidad"]);

}
void CQSisObjetos::MaterialesHospitalizado(SiscomRegistrosPro2 *pSRegistrosPro2,
					   CQSisLstMatHosp *pCQSLMHosp)
{

	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	  (*pCQSLMHosp) << MaterialHospitalizado(pSRegistrosPro2);
}
