#ifndef __CQSISOPTIENDAS43QT_H__
#define __CQSISOPTIENDAS43QT_H__

#include <SiscomOperaciones3.h>

class CQSisEmpresa3Qt;
class CQSisLstProducto3Qt;
class SiscomRegistro4;
class CQSisOpTiendas43Qt:public SiscomOperaciones3
{
public:
	CQSisOpTiendas43Qt(SiscomDatCom *pSisDatCom);
	int EmpresaRegistrada(CQSisEmpresa3Qt *pCQSEmpresa3Qt,
			      SiscomRegistro3LstLst *pSisReg3LstLstReg);
	void AnexaDireccion(SiscomRegistro3 *pSisReg3Direccion);
	void RegistraProductos(CQSisLstProducto3Qt *pCQSLProductos);

	void PreciosProducto(const char *pchrPtrIdProducto,
			     SiscomRegistro3Lst *pSisReg3LstPProducto);

	void DireccionesCliente(const char *pchrPtrIdPersona,
			 SiscomRegistro3Lst *pSisReg3LstDireccionesP);
	void AnexaDireccion(SiscomRegistro3Lst *pSisReg3LstDirecciones);

	void DatosProductosPorFamilia(const char *pchrPtrIdFamilia,
				      SiscomRegistro4 *pSisReg4Productos);

};
#endif
