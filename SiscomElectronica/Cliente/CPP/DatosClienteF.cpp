#include <DatosClienteF.h>
DatoClienteF::DatoClienteF(DatoClienteF *pDatCliF)
{
	SRegistroPro2 					<<
	"IdDatoClienteF"				<<
	"NumDias"					<<
	"LimiteInferior"				<<
	"LimiteSuperior"				<<
	"Descuento"					<<
	"IdAutorizo"					<<
	"IdExpendio"					<<
	"EdoRegistro";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 							<<
	SiscomCampoPro2("IdDatoClienteF",
			pDatCliF->SRegistrosPro2["IdDatoClienteF"])	<<
	SiscomCampoPro2("NumDias",
			pDatCliF->SRegistrosPro2["NumDias"])		<<
	SiscomCampoPro2("LimiteInferior",
			pDatCliF->SRegistrosPro2["LimiteInferior"])     <<
	SiscomCampoPro2("LimiteSuperior",
			pDatCliF->SRegistrosPro2["LimiteSuperior"]) 	<<
	SiscomCampoPro2("Descuento",
			pDatCliF->SRegistrosPro2["Descuento"])		<<
	SiscomCampoPro2("IdAutorizo",
	                pDatCliF->SRegistrosPro2["IdAutorizo"])		<<
	SiscomCampoPro2("IdExpendio",
			pDatCliF->SRegistrosPro2["IdExpendio"])        	<<
	SiscomCampoPro2("EdoRegistro",
			pDatCliF->SRegistrosPro2["EdoRegistro"]);
	SRegistrosPro2.SiscomAnexaRegistro();
}
DatoClienteF::DatoClienteF(const char *pchrPtrIdDtCliF,
			   const char *pchrPtrNumDias,
			   const char *pchrPtrLInferior,
			     const char *pchrPtrLSuperior,
			     const char *pchrPtrDescuento,
			     const char *pchrPtrIdAutorizo,
			     const char *pchrPtrIdExpendio,
			     const char *pchrPtrEdoRegistro)
{

	SRegistroPro2 					<<
	"IdDatoClienteF"				<<
	"NumDias"					<<
	"LimiteInferior"				<<
	"LimiteSuperior"				<<
	"Descuento"					<<
	"IdAutorizo"					<<
	"IdExpendio"					<<
	"EdoRegistro";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 							<<
	SiscomCampoPro2("IdDatoClienteF",pchrPtrIdDtCliF)		<<
	SiscomCampoPro2("NumDias",pchrPtrNumDias)			<<
	SiscomCampoPro2("LimiteInferior",pchrPtrLInferior)           	<<
	SiscomCampoPro2("LimiteSuperior",pchrPtrLSuperior) 	 	<<
	SiscomCampoPro2("Descuento",pchrPtrDescuento)			<<
	SiscomCampoPro2("IdAutorizo",pchrPtrIdAutorizo)			<<
	SiscomCampoPro2("IdExpendio",pchrPtrIdExpendio)        		<<
	SiscomCampoPro2("EdoRegistro",pchrPtrEdoRegistro);

	SRegistrosPro2.SiscomAnexaRegistro();
}
DatosClienteFrec::DatosClienteFrec()
{

}

DatosClienteFrec &DatosClienteFrec::operator<<(DatoClienteF *pDClienteF)
{
	append(pDClienteF);
	return *this;
}
OperacionesDatosClienteFrec::OperacionesDatosClienteFrec(SiscomDatCom *pSisDatCom,
						   DatosClienteFrec &pDatClienteF):
		SisDatCom(pSisDatCom),
		DatClienteF(pDatClienteF)
{


}
void OperacionesDatosClienteFrec::RegistraDatos()
{

SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&DatClienteF);
			lSGenOp.SiscomEjecutaEnvio("RegistraDatosClienteF");

}
void OperacionesDatosClienteFrec::ConsultaDatos(DatosClienteFrec &pDatClienteFrec)
{
DatoClienteF *lDClienteF=pDatClienteFrec.at(0);
SiscomParametrosConsulta lSPConsulta;

			lSPConsulta 						<<
			new SiscomParametroConsulta("ConsultaDatosClienteF")	<<
			new SiscomParametroConsulta(lDClienteF->SRegistrosPro2["IdExpendio"]);

		pDatClienteFrec.clear();
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
	pDatClienteFrec.clear();
			lSGenOp.SiscomEjecutaEnvio("ConsultaDatosClienteF");
			GeneraRegistrosConsultados((const SiscomComunicaSrv *)lSGenOp,
						   pDatClienteFrec);
}
void OperacionesDatosClienteFrec::GeneraRegistrosConsultados(const SiscomComunicaSrv *pSComunicaSrv,
							     DatosClienteFrec &pDatClienteFrec)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	  pDatClienteFrec <<
	  new DatoClienteF(lSRegistrosPro2["iddatoclientef"],
	  		   lSRegistrosPro2["numdias"],
	  		   lSRegistrosPro2["limiteinferior"],
	  		   lSRegistrosPro2["limitesuperior"],
			   lSRegistrosPro2["descuento"],
			   lSRegistrosPro2["idautorizo"],
			   lSRegistrosPro2["idexpendio"],
			   "Insertado");

delete pSComunicaSrv;
}
