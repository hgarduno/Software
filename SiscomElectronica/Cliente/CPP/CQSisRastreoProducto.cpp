#include <CQSisRastreoProducto.h>
#include <string.h>
CQSisRastreoProducto::CQSisRastreoProducto(SiscomRegistro3 *pSisReg3Expendio,
					   SiscomRegistro3 *pSisReg3Producto,
					   const char *pchrPtrFechaIni,
					   const char *pchrPtrFechaFin)
{	
  SiscomAgregaSubRegistro();
  Expendio(pSisReg3Expendio);
  Producto(pSisReg3Producto);
  SiscomAgregaRegistro(2,RangoRastreo(pchrPtrFechaIni,pchrPtrFechaFin));
  /*
  SiscomContenidoRegistro4Log(this);
  */
}
SiscomRegistro3 *CQSisRastreoProducto::RangoRastreo(const char *pchrPtrFechaIni,
						    const char *pchrPtrFechaFin)
{
SiscomRegistro3 *lSisReg3Rango=new SiscomRegistro3;

	(*lSisReg3Rango) 				<<
	new SiscomCampo3("FechaIni",pchrPtrFechaIni)	<<
	new SiscomCampo3("FechaFin",pchrPtrFechaFin);
return lSisReg3Rango;
}

void CQSisRastreoProducto::AsignaRastreo(SiscomRegistro4 *pSisReg4Rastreo)
{
	SisReg4Rastreo=pSisReg4Rastreo;
}
const char *CQSisRastreoProducto::ExistenciaExpendio()
{
return SisReg4Rastreo->CampoRegistroSubGrupo(0,1,0,"existencia");
}
const char *CQSisRastreoProducto::ExistenciaBodegas()
{
return SisReg4Rastreo->CampoRegistroSubGrupo(0,1,0,"exbodegas");
}
SiscomRegistro3Lst *CQSisRastreoProducto::ExistenciasBodegas()
{
return SisReg4Rastreo->RegistrosSubGrupo(0,2);
}

SiscomRegistro3Lst *CQSisRastreoProducto::VentasProducto()
{
return SisReg4Rastreo->RegistrosSubGrupo(0,3);
}


SiscomRegistro3Lst *CQSisRastreoProducto::ComprasProducto()
{
return SisReg4Rastreo->RegistrosSubGrupo(0,4);
}


SiscomRegistro3Lst *CQSisRastreoProducto::TransferenciasBodegasExpendio()
{
return SisReg4Rastreo->RegistrosSubGrupo(0,5);
}
SiscomRegistro3Lst *CQSisRastreoProducto::TransferenciasExpendioExpendio()
{
return SisReg4Rastreo->RegistrosSubGrupo(0,6);
}
SiscomRegistro3Lst *CQSisRastreoProducto::ActualizoInventario()
{
return SisReg4Rastreo->RegistrosSubGrupo(0,7);
}
const char *CQSisRastreoProducto::TotalVentas()
{
return SisReg4Rastreo->CampoRegistroSubGrupo(0,0,0,"TotalVentas");
}

const char *CQSisRastreoProducto::TotalCompras()
{
return SisReg4Rastreo->CampoRegistroSubGrupo(0,0,0,"TotalCompras");
}
const char *CQSisRastreoProducto::TotalTransBodegaExpendio()
{
return SisReg4Rastreo->CampoRegistroSubGrupo(0,0,0,"TotalTransBodExp");
}
const char *CQSisRastreoProducto::TotalTransExpendioExpendio()
{
return SisReg4Rastreo->CampoRegistroSubGrupo(0,0,0,"TotalTransExpExp");
}
int CQSisRastreoProducto::EdoConsultaTransExpExp()
{
SiscomRegistro3Lst *lSisReg3LstTransEE;
lSisReg3LstTransEE=TransferenciasExpendioExpendio();
lSisReg3LstTransEE->first();
return !strcmp((*lSisReg3LstTransEE)["SqlTransExpendioExpendio"],
	        "Vacio");
}
int CQSisRastreoProducto::EdoConsultaActualizoInventario()
{
ActualizoInventario()->first();
return !strcmp((*ActualizoInventario())["SqlActualizoInventario"],
	       "Vacio");
}
CQSisRastreandoProducto::CQSisRastreandoProducto(SiscomDatCom *pSisDatCom):
			 SiscomOperaciones3(pSisDatCom)
{


}

void CQSisRastreandoProducto::Rastrea(CQSisRastreoProducto *pCQSRastreoProducto)
{
SiscomRegistro4 *lSisReg4Regreso=new SiscomRegistro4;
SiscomEnvia("RastreaProducto",
	    0,
	    pCQSRastreoProducto,
	    lSisReg4Regreso);

SiscomContenidoRegistro4Log(lSisReg4Regreso);

pCQSRastreoProducto->first();
lSisReg4Regreso->first();
pCQSRastreoProducto->AsignaRastreo(lSisReg4Regreso);
}
