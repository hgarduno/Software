#include <CQSisOpTiendas43Qt.h>
#include <CQSisEmpresas.h>
#include <CQSisProductos.h>
#include <SiscomRegistros4.h>
CQSisOpTiendas43Qt::CQSisOpTiendas43Qt(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{


}


int CQSisOpTiendas43Qt::EmpresaRegistrada(
				CQSisEmpresa3Qt *pCQSEmpresa3Qt,
				SiscomRegistro3LstLst *pSisReg3LstLstReg)
{
SiscomEnvia("EmpresaRegistrada",
	    pCQSEmpresa3Qt,
	    pSisReg3LstLstReg);
return pSisReg3LstLstReg->count();
}


void CQSisOpTiendas43Qt::AnexaDireccion(SiscomRegistro3 *pSisReg3Direccion)
{
SiscomRegistro3Lst lSisReg3LstRegreso;
SiscomEnvia("AnexaDireccion",
	    pSisReg3Direccion,
	    &lSisReg3LstRegreso);
}
void CQSisOpTiendas43Qt::RegistraProductos(CQSisLstProducto3Qt *pCQSLProductos)
{
SiscomRegistro3Lst lSisReg3LstRegreso;
SiscomEnvia("RegistraProducto",
	    (SiscomRegistro3Lst *)pCQSLProductos,
	     &lSisReg3LstRegreso);
}

void CQSisOpTiendas43Qt::PreciosProducto(const char *pchrPtrIdProducto,
					 SiscomRegistro3Lst *pSisReg3LstPProducto)
{
SiscomEnvia("ConsultaTiendas4",
	     pSisReg3LstPProducto,
	    "%s%s",
	    "PreciosProducto",
	    pchrPtrIdProducto);
}
void CQSisOpTiendas43Qt::DireccionesCliente(const char *pchrPtrIdPersona,
				     SiscomRegistro3Lst *pSisReg3LstDireccionesP)
{
SiscomEnvia("ConsultaTiendas4",
	     pSisReg3LstDireccionesP,
	     "%s%s",
	     "DireccionesCliente",
	     pchrPtrIdPersona);
}
void CQSisOpTiendas43Qt::AnexaDireccion(SiscomRegistro3Lst *pSisReg3LstDirecciones)
{
SiscomEnvia("RegistraDireccion2",
	     pSisReg3LstDirecciones);
}

void CQSisOpTiendas43Qt::DatosProductosPorFamilia(const char *pchrPtrIdFamilia,
						  SiscomRegistro4 *pSisReg4Productos)
{
SiscomEnvia("ConsultaTiendas4",
	     pSisReg4Productos,
	     "%s%s",
	     "DatosProductosPorFamilia",
	     pchrPtrIdFamilia);

}
