#include <CQSisEmpresas2.h>
#include <SiscomDesarrollo3Qt++.h>
#include <string.h>
CQSisEmpresa2::CQSisEmpresa2()
{
	SiscomAgregaRegistro();
	SiscomAgregaSubRegistro();
	SiscomAgregaSubRegistro();
	SiscomAgregaSubRegistro();
	SiscomAgregaSubRegistro();
}
void CQSisEmpresa2::Generales(const char *pchrPtrIdEmpresa,
			      const char *pchrPtrRazonSocial,
			      const char *pchrPtrTEmpresa)
{
   SiscomAgregaRegistro(0,DatosGenerales(pchrPtrIdEmpresa,
   					pchrPtrRazonSocial,
					pchrPtrTEmpresa));
}
void CQSisEmpresa2::Generales(SiscomRegistro3 *pSisReg3Generales)
{
  SiscomAgregaRegistro(0,pSisReg3Generales);
}
void CQSisEmpresa2::AgregaDireccion(SiscomRegistro3 *pSisReg3Direccion)
{
  SiscomAgregaRegistro(1,pSisReg3Direccion);
}
void CQSisEmpresa2::AgregaContacto(SiscomRegistro3 *pSisReg3Contacto)
{
  SiscomAgregaRegistro(2,pSisReg3Contacto);
}
void CQSisEmpresa2::AgregaMedioComunicacion(SiscomRegistro3 *pSisReg3MedCom)
{
 SiscomAgregaRegistro(3,pSisReg3MedCom);
}
SiscomRegistro3 *CQSisEmpresa2::DatosGenerales(const char *pchrPtrIdEmpresa,
					  const char *pchrPtrRazonSocial,
					  const char *pchrPtrTEmpresa)
{
SiscomRegistro3 *lSisReg3Reg=new SiscomRegistro3;

(*lSisReg3Reg) 					<< 
new SiscomCampo3("IdEmpresa",pchrPtrIdEmpresa)  <<
new SiscomCampo3("RazonSocial",pchrPtrRazonSocial)	<<
new SiscomCampo3("TipoEmpresa",pchrPtrTEmpresa); 
return lSisReg3Reg;
}

void CQSisEmpresa2::AsignaDirecciones(SiscomRegistro3Lst *pSisReg3LstDirs)
{
  if(pSisReg3LstDirs)
  SiscomAgregaRegistros(1,pSisReg3LstDirs);	
}
void CQSisEmpresa2::AsignaContactos(SiscomRegistro3Lst *pSisReg3LstConts)
{
 if(pSisReg3LstConts)
 SiscomAgregaRegistros(2,pSisReg3LstConts);
}
void CQSisEmpresa2::AsignaMediosComunicacion(SiscomRegistro3Lst *pSisReg3LstMsCom)
{
if(pSisReg3LstMsCom)
SiscomAgregaRegistros(3,pSisReg3LstMsCom);
}

CQSisContactoE::CQSisContactoE(const char *pchrPtrIdPersona,
			       const char *pchrPtrDescripcion,
			       const char *pchrPtrNombre,
			       const char *pchrPtrAPaterno,
			       const char *pchrPtrAMaterno)
{
  (*this) 						<<
  new SiscomCampo3("IdPersona",pchrPtrIdPersona) 	<<
  new SiscomCampo3("Descripcion",pchrPtrDescripcion)	<<
  new SiscomCampo3("Nombre",pchrPtrNombre)		<<
  new SiscomCampo3("APaterno",pchrPtrAPaterno)		<<
  new SiscomCampo3("AMaterno",pchrPtrAMaterno);
}

CQSisDireccionE::CQSisDireccionE(const char *pchrPtrIdPersona,
				 const char *pchrPtrIdEmpresa,
				 const char *pchrPtrLinea1,
				 const char *pchrPtrLinea2,
				 const char *pchrPtrLinea3)
{
  (*this)						<<
  new SiscomCampo3("IdPersona",pchrPtrIdPersona)	<<
  new SiscomCampo3("IdEmpresa",pchrPtrIdEmpresa)	<<
  new SiscomCampo3("Linea1",pchrPtrLinea1)		<<
  new SiscomCampo3("Linea2",pchrPtrLinea2)		<<
  new SiscomCampo3("Linea3",pchrPtrLinea3);
}

CQSisMedioComunicacionE::CQSisMedioComunicacionE(const char *pchrPtrIdPersona,	
					       const char *pchrPtrIdEmpresa,
					       const char *pchrPtrIdMedio,
					       const char *pchrPtrDescripcion,
					       const char *pchrPtrDato)
{
  (*this)						<<
  new SiscomCampo3("IdPersona",pchrPtrIdPersona)	<<
  new SiscomCampo3("IdEmpresa",pchrPtrIdEmpresa)	<<
  new SiscomCampo3("IdMedio",pchrPtrIdMedio)		<<
  new SiscomCampo3("Descripcion",pchrPtrDescripcion)	<<
  new SiscomCampo3("Dato",pchrPtrDato);
}

CQSisOperacionesEmp2::CQSisOperacionesEmp2(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{


}
void CQSisOperacionesEmp2::Envia(SiscomRegistro3 *pSisReg3Conf,
				 CQSisEmpresa2 *pCQSisEmp2Datos,
				 SiscomRegistro4 *pSisReg4Resp)
{
SiscomEnvia("RegistraEmpresa2",
	    pSisReg3Conf,
	    pCQSisEmp2Datos,
	    pSisReg4Resp);
}
int CQSisOperacionesEmp2::EmpresaRegistrada(CQSisEmpresa2 *pCQSEmpresa2)
{
char *lchrPtrRespuesta;
int lintNRegistros;
SiscomRegistro4 lSisReg4Resp;
SiscomEscribeLog3Qt("El numero de registros:%d",pCQSEmpresa2->Registros());
SiscomEnvia("EmpresaRegistrada",
	    0,
	    pCQSEmpresa2,
	    0);
SiscomObtenNombreRespuesta(&lchrPtrRespuesta,&lintNRegistros);
SiscomEscribeLog3Qt("El numero :%d %s",lintNRegistros,lchrPtrRespuesta);
if(!strcmp("EmpresaNoRegistrada",lchrPtrRespuesta))
{
SiscomRegistro3Lst lSisReg3LstResp;
SiscomEscribeLog3Qt("Empresa NO Registrada");
SiscomObtenRespuesta(lintNRegistros,&lSisReg3LstResp);
return 0;
}
else
{
SiscomEscribeLog3Qt("La Empresa Ya Esta Registrada:%d Registros de Respuesta",
		    lintNRegistros);
SiscomObtenRespuesta(lintNRegistros,&lSisReg4Resp);
SiscomRegistro3LstContenido((lSisReg4Resp.RegistrosSubGrupo(0,0)));
SiscomRegistro3LstContenido((lSisReg4Resp.RegistrosSubGrupo(0,1)));
SiscomRegistro3LstContenido((lSisReg4Resp.RegistrosSubGrupo(0,2)));
SiscomRegistro3LstContenido((lSisReg4Resp.RegistrosSubGrupo(0,3)));
pCQSEmpresa2->AsignaEmpresa(&lSisReg4Resp);
return 1;
}
}
void CQSisEmpresa2::LimpiaSubGrupo(SiscomRegistro3Lst *pSisReg3LstDat)
{
	if(pSisReg3LstDat)
	pSisReg3LstDat->clear();
}
void CQSisEmpresa2::AsignaEmpresa(SiscomRegistro4 *pSisReg4Resp)
{
     LimpiaSubGrupo(RegistrosSubGrupo(0,0));
     LimpiaSubGrupo(RegistrosSubGrupo(0,1));
     LimpiaSubGrupo(RegistrosSubGrupo(0,2));
     LimpiaSubGrupo(RegistrosSubGrupo(0,3));

    Generales(pSisReg4Resp->RegistroSubGrupo(0,0,0));
    AsignaDirecciones(pSisReg4Resp->RegistrosSubGrupo(0,1));
    AsignaContactos(pSisReg4Resp->RegistrosSubGrupo(0,2));
    AsignaMediosComunicacion(pSisReg4Resp->RegistrosSubGrupo(0,3));
}
