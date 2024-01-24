#include <Practicas.h>

Practica::Practica(const char *pchrPtrIdPractica,
		 const char *pchrPtrIdMateria,
		 const char *pchrPtrNombre,
		 const char *pchrPtrEdoRegistro)
{
	SRegistroPro2 			<<
	"IdPractica"			<<
	"IdMateria"			<<
	"Nombre"			<<
	"EdoRegistro";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2						<<
	SiscomCampoPro2("IdPractica",pchrPtrIdPractica) 		<<
	SiscomCampoPro2("IdMateria",pchrPtrIdMateria)		<<
	SiscomCampoPro2("Nombre",pchrPtrNombre)			<<
	SiscomCampoPro2("EdoRegistro",pchrPtrEdoRegistro);

	SRegistrosPro2.SiscomAnexaRegistro();
}
Practicas::Practicas()
{

}
Practicas &Practicas::operator<<(Practica *pPractica)
{
	append(pPractica);
	return *this;
}
ConsultaPracticas::ConsultaPracticas()
{

}
ConsultaPracticas::ConsultaPracticas(SiscomDatCom *pSisDatCom,
				   const char *pchrPtrIdMateria,
				   Practicas &pPracticas)
{
SiscomParametrosConsulta lSPConsulta;

			lSPConsulta			<<
			new SiscomParametroConsulta(pchrPtrIdMateria);
SiscomGeneralOperacionesSrv lSGenOp(
				pSisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
			lSGenOp.SiscomEjecutaEnvio("ConsultaPracticas");
			GeneraPracticas((const SiscomComunicaSrv *)lSGenOp,pPracticas);
}
void ConsultaPracticas::GeneraPracticas(const SiscomComunicaSrv *pSComunicaSrv,
				      Practicas &pPracticas)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	  pPracticas <<
	  	new Practica(lSRegistrosPro2["idpractica"],
			    lSRegistrosPro2["idmateria"],
			    lSRegistrosPro2["nombre"]);
	delete pSComunicaSrv;
}
ConsultaPracticas::ConsultaPracticas(SiscomDatCom *pSisDatCom,
				   const char *pchrPtrIdPractica,
				   const char *pchrPtrIdExpendio,
				   const char *pchrPtrNmbTipoPrecio,
				   ProductosE &pProductos)
{
SiscomParametrosConsulta lSPConsulta;

			lSPConsulta					<<
			new SiscomParametroConsulta(pchrPtrIdPractica)   << 
			new SiscomParametroConsulta(pchrPtrIdExpendio)  <<
			new SiscomParametroConsulta(pchrPtrNmbTipoPrecio);
SiscomGeneralOperacionesSrv lSGenOp(
				pSisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
			lSGenOp.SiscomEjecutaEnvio("ConsultaPracticas");
			GeneraPracticas((const SiscomComunicaSrv *)lSGenOp,pProductos);
}
void ConsultaPracticas::GeneraPracticas(const SiscomComunicaSrv *pSComunicaSrv,
				        ProductosE &pProductos)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
pProductos <<
	  new ProductoE(lSRegistrosPro2["CveProducto"],
	  		 lSRegistrosPro2["Descripcion"],
			 "",
			 "",
			 lSRegistrosPro2["Precio"],
			 lSRegistrosPro2["NmbTipoPrecio"],
			 lSRegistrosPro2["Cantidad"],
			 lSRegistrosPro2["Existencia"],
			 "",
			 lSRegistrosPro2["IdExpendio"],
			 lSRegistrosPro2["ImporteCantidad"],
			 lSRegistrosPro2["SePuedeVender"]);
	delete pSComunicaSrv;
}

void ConsultaPracticas::RegistraPracticas(SiscomDatCom *pSisDatCom,
					  Practicas &pPracticas)
{
SiscomGeneralOperacionesSrv lSGenOp(
				pSisDatCom,
				(QPtrList<SiscomInformacion>*)&pPracticas);
			lSGenOp.SiscomEjecutaEnvio("RegistraPracticas");


}
void ConsultaPracticas::RegistraDetallePractica(SiscomDatCom *pSisDatCom,
						 ProductosE &pProductos)

{
SiscomGeneralOperacionesSrv lSGenOp(
				pSisDatCom,
				(QPtrList<SiscomInformacion>*)&pProductos);
			lSGenOp.SiscomEjecutaEnvio("RegistraDetallePractica");


}
