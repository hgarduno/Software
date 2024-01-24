#include <CQSisSeguridadCajaVentas.h>
#include <SiscomDesarrollo3Qt++.h>

#include <stdlib.h>
CQSisControlCaja::CQSisControlCaja(const char *pchrPtrIdCaja,
				   const char *pchrPtrDireccionIp,
				   const char *pchrPtrDescripcion,
				   const char *pchrPtrIdControl,
				   const char *pchrPtrNombreQt,
				   const char *pchrPtrNombre,
				   const char *pchrPtrEstado,
				   const char *pchrPtrIdExpendio)
{

	(*this)									<<
	new SiscomCampo3("IdCaja",pchrPtrIdCaja)				<<
	new SiscomCampo3("DireccionIp",pchrPtrDireccionIp)			<<
	new SiscomCampo3("Descripcion",pchrPtrDescripcion)			<<
	new SiscomCampo3("IdControl",pchrPtrIdControl)				<<
	new SiscomCampo3("NombreQt",pchrPtrNombreQt)				<<
	new SiscomCampo3("Nombre",pchrPtrNombre)				<<
	new SiscomCampo3("Estado",pchrPtrEstado)				<<
	new SiscomCampo3("IdExpendio",pchrPtrIdExpendio);

}

CQSisOpControlCaja::CQSisOpControlCaja(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{


}
int CQSisOpControlCaja::IdCaja(SiscomRegistro3Lst *pSisRegLst3Regreso)
{

return atoi((*pSisRegLst3Regreso)["idcaja"]);
	
}
void CQSisOpControlCaja::ObtenControlesCaja(SiscomRegistro3Lst *pSisRegLst3Regreso,
					    CQSisCajaSeguridad *pCQSisCajaSeguridad)
{
int lintIdCaja=IdCaja(pSisRegLst3Regreso);
SiscomRegistro3 *lSisReg3Control;
		while(pSisRegLst3Regreso->current() &&
		      lintIdCaja==IdCaja(pSisRegLst3Regreso))
		{
			lSisReg3Control=pSisRegLst3Regreso->current();
			(*pCQSisCajaSeguridad) << lSisReg3Control;
			SiscomEscribeLog3Qt("\tControl:%s (%s)",
					    (*lSisReg3Control)["nombreqt"],
					    (*lSisReg3Control)["estado"]);
			++(*pSisRegLst3Regreso);
		}
}
void CQSisOpControlCaja::CajasYControles(const char *pchrPtrIdExpendio,
					 SiscomRegistro3Lst *pSisRegLst3Regreso,
					 CQSisCajasSeguridad *pCQSisCajaSeguridad)
{
SiscomRegistro3 *lSisReg3Regreso;
CQSisCajaSeguridad *lCQSCajaSeguridad;
SiscomEnvia("ConsultasSiscomElectronica2",
            pSisRegLst3Regreso,
	    "%s%s",
	    "CajasYControles",
	    pchrPtrIdExpendio);
  pSisRegLst3Regreso->first();
  while((lSisReg3Regreso=pSisRegLst3Regreso->current()))
 {
 	SiscomEscribeLog3Qt("%s",(*lSisReg3Regreso)["descripcion"]);
	AgregaSeguridadCaja(lSisReg3Regreso,
			    pCQSisCajaSeguridad,
			    &lCQSCajaSeguridad);
	ObtenControlesCaja(pSisRegLst3Regreso,lCQSCajaSeguridad);
 }
}
void CQSisOpControlCaja::RegistraEstados(const char *pchrPtrIdExpendio,
					 CQSisCajasSeguridad *pCQSCajasSeg)
{
SiscomRegistro3Lst lSisReg3LstEnvio;
SiscomRegistro3Lst lSisReg3LstCsCaja;
SiscomRegistro3Lst lSisReg3LstRespuesta;
SiscomRegistro3 *lSisReg3Control;
CQSisCajaSeguridad *lCQSCSeguridad;

for(lCQSCSeguridad=pCQSCajasSeg->first();
    lCQSCSeguridad;
    lCQSCSeguridad=pCQSCajasSeg->next())
{
	lSisReg3LstCsCaja=lCQSCSeguridad->ControlesCaja();
	lSisReg3LstEnvio << lSisReg3LstCsCaja;
}
ColocaIdExpendio(lSisReg3LstEnvio,pchrPtrIdExpendio);
SiscomEnvia("ActualizaEdoControlCaja",
	    &lSisReg3LstEnvio,
	    &lSisReg3LstRespuesta);
}
void CQSisOpControlCaja::ColocaIdExpendio(SiscomRegistro3Lst &pSisReg3LstDat,
				          const char *pchrPtrIdExpendio)
{
SiscomRegistro3 *lSisReg3Dat=pSisReg3LstDat.first();
lSisReg3Dat->SiscomActualizaCampo("IdExpendio",pchrPtrIdExpendio);
}
void CQSisOpControlCaja::ControlesSeguridadCaja(
				const char *pchrPtrIdExpendio,
				const char *pchrPtrIdCaja,
				SiscomRegistro3Lst *pSisReg3LstControles)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstControles,
	    "%s%s%s",
	    "ControlesCaja",
	    pchrPtrIdExpendio,
	    pchrPtrIdCaja);
}
void CQSisOpControlCaja::AgregaSeguridadCaja(
				SiscomRegistro3 *pSisReg3Caja,
				CQSisCajasSeguridad *pCQSisCajasSeguridad,
				CQSisCajaSeguridad **pCQSCajaSeguridad)
{
*pCQSCajaSeguridad=new CQSisCajaSeguridad(pSisReg3Caja);
(*pCQSisCajasSeguridad) << *pCQSCajaSeguridad;
}
		
CQSisCajaSeguridad::CQSisCajaSeguridad(SiscomRegistro3 *pSisReg3Caja)
{
	SisReg3Caja=pSisReg3Caja;
}
const CQSisCajaSeguridad &CQSisCajaSeguridad::operator<<(const SiscomRegistro3 *pSisRegControl)
{
	SisReg3LstControl << (SiscomRegistro3 *)pSisRegControl;	
	return (*this);
}
const SiscomRegistro3Lst &CQSisCajaSeguridad::ControlesCaja()
{
	return SisReg3LstControl;
}
const char *CQSisCajaSeguridad::Caja()
{
return (*SisReg3Caja)["descripcion"];
}
CQSisCajasSeguridad::CQSisCajasSeguridad()
{

}
const CQSisCajasSeguridad &CQSisCajasSeguridad::operator<<(const CQSisCajaSeguridad *pCQSCaja)
{
	append(pCQSCaja);
	return *this;
}


CQSisControlesCaja::CQSisControlesCaja()
{

}
SiscomRegistro3 *CQSisControlesCaja::operator[](const char *pchrPtrNmbControl)
{
SiscomRegistro3 *lSisReg3Control;
	for(lSisReg3Control=first();
	    lSisReg3Control;
	    lSisReg3Control=next())
	 if(!strcmp((*lSisReg3Control)["nombreqt"],pchrPtrNmbControl))
	  return lSisReg3Control;
return 0;
}
int CQSisControlesCaja::EsVerdaderoEntero(const char *pchrPtrNmbControl)
{
 SiscomRegistro3 *lSisReg3Dato;
 if((lSisReg3Dato=(*this)[pchrPtrNmbControl]))
  return atoi((*lSisReg3Dato)["estado"]);
 {
    SiscomEscribeLog3Qt("No se encontro:%s",pchrPtrNmbControl);
    return 0;
 }
}
