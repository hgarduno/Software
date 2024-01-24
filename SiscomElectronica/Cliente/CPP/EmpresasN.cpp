#include <EmpresasN.h>
/*
 * Para las empresas se consideran los siguientes casos
 * Id Menor que cero, corresponderan a los expendios del
 * negocio.
 *
 * Los de Id mayor que cero, y que se genera de manera 
 * automatica, corresponderan a los proveedores.
 *
 * En este punto es importante considerar otro tipo de 
 * de empresa, los clientes que sean empresas.
 *
 * Para resolver este caso se consideraran los id's de
 * que esten en el rango 1-9000, de esta manera seran
 * identificados en la base de datos las empresas que
 * sean clientes.
 *
 */



EmpresaN::EmpresaN(const char *pchrPtrRazonSocial,
		 const char *pchrPtrIdEmpresa,
		 const char *pchrPtrRFC,
		 const char *pchrPtrPtoAd,
		 const char *pchrPtrDirIp,
		 const char *pchrPtrBase)
{
	SRegistroPro2 			<<
	"RazonSocial"			<<
	"IdEmpresa"			<<
	"RFC"				<<
	"PtoComAd"			<<
	"DirIp"				<<
	"Base";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2						<<
	SiscomCampoPro2("RazonSocial",pchrPtrRazonSocial) 	<<
	SiscomCampoPro2("IdEmpresa",pchrPtrIdEmpresa)		<<
	SiscomCampoPro2("RFC",pchrPtrRFC)			<<
	SiscomCampoPro2("PtoComAd",pchrPtrPtoAd)		<<
	SiscomCampoPro2("DirIp",pchrPtrDirIp)			<<
	SiscomCampoPro2("Base",pchrPtrBase);

	SRegistrosPro2.SiscomAnexaRegistro();
}
const Direcciones &EmpresaN::ObtenDirecciones()
{
	return DDirecciones;
}
const MediosComunicacion &EmpresaN::ObtenMedios()
{
	return MMedios;
}
const Personas &EmpresaN::ObtenContactos()
{
	return PContactos;
}
void EmpresaN::AnexaMedioComunicacion(MedioComunicacion *pMedio)
{
	MMedios << pMedio;
}
void EmpresaN::AnexaContacto(Persona *pPContacto)
{
	PContactos << pPContacto;
}

void EmpresaN::AnexaDireccion(Direccion *pDireccion)
{

	DDirecciones << pDireccion;

}
EmpresasN::EmpresasN()
{

}
EmpresasN &EmpresasN::operator<<(EmpresaN *pEmpresaN)
{
	append(pEmpresaN);
	return *this;
}
ConsultaEmpresasN::ConsultaEmpresasN(SiscomDatCom *pSisDatCom,
				   const char *pchrPtrIdEmpresa,
				   EmpresasN &pEmpresas)
{

SiscomParametrosConsulta lSPConsulta;
			lSPConsulta			<<
			new SiscomParametroConsulta(pchrPtrIdEmpresa);
SiscomGeneralOperacionesSrv lSGenOp(
				pSisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
lSGenOp.SiscomEjecutaEnvio("ConsultaEmpresas");
if(!(chrPtrEdoConexion=lSGenOp.EstadoConexion()))
GeneraEmpresasN((const SiscomComunicaSrv *)lSGenOp,pEmpresas);
else
SiscomLog("El Estado de la Conexion %s",chrPtrEdoConexion);
}
ConsultaEmpresasN::ConsultaEmpresasN(SiscomDatCom *pSisDatCom):
		SisDatCom(pSisDatCom)
{

}
EmpresaN *ConsultaEmpresasN::ObtenMatriz()
{
SiscomParametrosConsulta lSPConsulta;
EmpresasN lEmpresas;
			lSPConsulta			<<
			new SiscomParametroConsulta("ConsultaMatriz");
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
			lSGenOp.SiscomEjecutaEnvio("ConsultaEmpresas");
			GeneraEmpresasN((const SiscomComunicaSrv *)lSGenOp,lEmpresas);

	return lEmpresas.at(0);
}
void ConsultaEmpresasN::GeneraEmpresasN(const SiscomComunicaSrv *pSComunicaSrv,
				      EmpresasN &pEmpresas)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
	for(;!lSRegistrosPro2.SiscomEsElUltimoRegistro();++lSRegistrosPro2)
	  pEmpresas 		<<
	  	new EmpresaN(lSRegistrosPro2["razonsocial"],
			    lSRegistrosPro2["idempresa"],
			    lSRegistrosPro2["rfc"],
			    lSRegistrosPro2["ptocomad"],
			    lSRegistrosPro2["diripsvrad"],
			    lSRegistrosPro2["basedatos"]);
}
const char *ConsultaEmpresasN::EstadoConexion()
{
 return chrPtrEdoConexion;
}
OpEmpresas::OpEmpresas(SiscomDatCom *pSisDatCom):
	SisDatCom(pSisDatCom)
{

}
void OpEmpresas::RegistraEmpresas(EmpresasN &pEmpresas)
{
EmpresaN *lEmpresa;
QRegistrosEnvioEmpresa lQRegEnvio;

	for(lEmpresa=pEmpresas.first();
	    lEmpresa;
	    lEmpresa=pEmpresas.next())
	  lQRegEnvio << new QRegistroEnvioEmpresa(lEmpresa);
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lQRegEnvio);
			lSGenOp.SiscomEjecutaEnvio2("RegistraEmpresas");

}


QRegistroEnvioEmpresa::QRegistroEnvioEmpresa(EmpresaN *pEmpresa):
			Empresa(pEmpresa)
{
	AnexaGenerales();
	AnexaDirecciones();
	AnexaContactos();
	AnexaTelefonos();
}
void QRegistroEnvioEmpresa::AnexaTelefonos()
{
MedioComunicacion *lMedComunicacion;
MediosComunicacion lMedsComunicacion=Empresa->ObtenMedios();

	for(lMedComunicacion=lMedsComunicacion.first();
	    lMedComunicacion;
	    lMedComunicacion=lMedsComunicacion.next())
	{
	SRegistroPro2.SiscomRegistroPro2ReAsigna();
	FormaCamposRegistro();
	SRegistrosPro2 								<<
	SiscomCampoPro2("RazonSocial","")					<<
	SiscomCampoPro2("IdEmpresa","")						<<
	SiscomCampoPro2("RFC","")						<<
	SiscomCampoPro2("Calle","")						<<
	SiscomCampoPro2("Numero","")						<<
	SiscomCampoPro2("Colonia","")						<<
	SiscomCampoPro2("CP","")						<<
	SiscomCampoPro2("Municipio","")						<<
	SiscomCampoPro2("Estado","")						<<
	SiscomCampoPro2("Referencia","")					<<
	SiscomCampoPro2("Telefono",lMedComunicacion->SRegistrosPro2["Medio"])	<<
	SiscomCampoPro2("Comentario",lMedComunicacion->SRegistrosPro2["Departamento"])	<<
	SiscomCampoPro2("IdPersona","")						<<
	SiscomCampoPro2("Nombre","")						<<
	SiscomCampoPro2("APaterno","")						<<
	SiscomCampoPro2("AMaterno","")						<<
	SiscomCampoPro2("Departamento","");
	SRegistrosPro2.SiscomAnexaRegistro();
	}

}
void QRegistroEnvioEmpresa::AnexaContactos()
{
Persona *lPersona;
Personas lPersonas=Empresa->ObtenContactos();
	for(lPersona=lPersonas.first();
	    lPersona;
	    lPersona=lPersonas.next())
	{
	SRegistroPro2.SiscomRegistroPro2ReAsigna();
	FormaCamposRegistro();
	SRegistrosPro2 								<<
	SiscomCampoPro2("RazonSocial","")					<<
	SiscomCampoPro2("IdEmpresa","")						<<
	SiscomCampoPro2("RFC","")						<<
	SiscomCampoPro2("Calle","")						<<
	SiscomCampoPro2("Numero","")						<<
	SiscomCampoPro2("Colonia","")						<<
	SiscomCampoPro2("CP","")						<<
	SiscomCampoPro2("Municipio","")						<<
	SiscomCampoPro2("Estado","")						<<
	SiscomCampoPro2("Referencia","")					<<
	SiscomCampoPro2("Telefono","")						<<
	SiscomCampoPro2("Comentario","")					<<
	SiscomCampoPro2("IdPersona","")						<<
	SiscomCampoPro2("Nombre",lPersona->SRegistrosPro2["Nombre"])		<<
	SiscomCampoPro2("APaterno",lPersona->SRegistrosPro2["APaterno"])	<<
	SiscomCampoPro2("AMaterno",lPersona->SRegistrosPro2["AMaterno"])        <<
	SiscomCampoPro2("Departamento",lPersona->SRegistrosPro2["Departamento"]) ;
	SRegistrosPro2.SiscomAnexaRegistro();
	}

}
void QRegistroEnvioEmpresa::AnexaDirecciones()
{
Direccion *lDireccion;
Direcciones lDirecciones=Empresa->ObtenDirecciones();
	for(lDireccion=lDirecciones.first();
	    lDireccion;
	    lDireccion=lDirecciones.next())
	{
	SRegistroPro2.SiscomRegistroPro2ReAsigna();
	FormaCamposRegistro();
	SRegistrosPro2 								<<
	SiscomCampoPro2("RazonSocial","")					<<
	SiscomCampoPro2("IdEmpresa","")						<<
	SiscomCampoPro2("RFC","")						<<
	SiscomCampoPro2("Calle",lDireccion->SRegistrosPro2["Calle"])		<<
	SiscomCampoPro2("Numero",lDireccion->SRegistrosPro2["Numero"])		<<
	SiscomCampoPro2("Colonia",lDireccion->SRegistrosPro2["Colonia"])	<<
	SiscomCampoPro2("CP",lDireccion->SRegistrosPro2["CP"])			<<
	SiscomCampoPro2("Municipio",lDireccion->SRegistrosPro2["Municipio"])	<<
	SiscomCampoPro2("Estado",lDireccion->SRegistrosPro2["Estado"])		<<
	SiscomCampoPro2("Referencia",lDireccion->SRegistrosPro2["Referencia"])	<<
	SiscomCampoPro2("Telefono","")						<<
	SiscomCampoPro2("Comentario","")					<<
	SiscomCampoPro2("IdPersona","")						<<
	SiscomCampoPro2("Nombre","")						<<
	SiscomCampoPro2("APaterno","")						<<
	SiscomCampoPro2("AMaterno","")						<<
	SiscomCampoPro2("Departamento","");
	SRegistrosPro2.SiscomAnexaRegistro();
	}
}
void QRegistroEnvioEmpresa::AnexaGenerales()
{
	FormaCamposRegistro();
	SRegistrosPro2 								<<
	SiscomCampoPro2("RazonSocial",Empresa->SRegistrosPro2["RazonSocial"])	<<
	SiscomCampoPro2("IdEmpresa",Empresa->SRegistrosPro2["IdEmpresa"])	<<
	SiscomCampoPro2("RFC",Empresa->SRegistrosPro2["RFC"])			<<
	SiscomCampoPro2("Calle","")						<<
	SiscomCampoPro2("Numero","")						<<
	SiscomCampoPro2("Colonia","")						<<
	SiscomCampoPro2("CP","")						<<
	SiscomCampoPro2("Municipio","")						<<
	SiscomCampoPro2("Estado","")						<<
	SiscomCampoPro2("Referencia","")					<<
	SiscomCampoPro2("Telefono","")						<<
	SiscomCampoPro2("Comentario","")					<<
	SiscomCampoPro2("IdPersona","")						<<
	SiscomCampoPro2("Nombre","")						<<
	SiscomCampoPro2("APaterno","")						<<
	SiscomCampoPro2("AMaterno","")						<<
	SiscomCampoPro2("Departamento","");
	SRegistrosPro2.SiscomAnexaRegistro();
}
void QRegistroEnvioEmpresa::FormaCamposRegistro()
{
SRegistroPro2 						<<
	"RazonSocial"					<<
	"IdEmpresa"					<<
	"RFC"						<<
	"Calle"						<<
	"Numero"					<<
	"Colonia"					<<
	"CP"						<<
	"Municipio"					<<
	"Estado"					<<
	"Referencia"					<<
	"Telefono"					<<
	"Comentario"					<<
	"IdPersona"					<<
	"Nombre"					<<
	"APaterno"					<<
	"AMaterno"					<<
	"Departamento";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

}
QRegistrosEnvioEmpresa::QRegistrosEnvioEmpresa()
{

}
QRegistrosEnvioEmpresa &QRegistrosEnvioEmpresa::operator<<(
				QRegistroEnvioEmpresa *pQRegEnvio)
{
	append(pQRegEnvio);
	return *this;
}

