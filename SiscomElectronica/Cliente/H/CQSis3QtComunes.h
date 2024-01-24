#ifndef __CQSIS3QTCOMUNES_H__
#define __CQSIS3QTCOMUNES_H__
#include <SiscomOperaciones3.h>
class CQSisCorteCaja;
class QTable;
/*!
 * En esta clase se almacenaran las operaciones comunes a las 
 * a la aplicacion
 */
class CQSis3QtComunes:public SiscomOperaciones3
{
public:
	/*!
	 * Constructor de la clase
	 */
	CQSis3QtComunes(SiscomDatCom *pSisDatCom);
	const char *ObtenCambio(const char *pchrPtrImporte,
			 const char *pchrPtrRecibo,
			 int *pintPtrImporteValido);
	void ImporteDenominaciones(const char *pchrPtrDenominacion,
				   const char *pchrPtrCantidad,
				   SiscomRegistro3Lst *pSisReg3LstRegreso);
	void CajasRegistradas(const char *pchrPtrIdExpendio,
			      SiscomRegistro3Lst *pSisReg3Cajas);

	void CambiaClave(const char *pchrPtrIdExpendio,
			 const char *pchrPtrCveNueva,
			 SiscomRegistro3 *pSisReg3Producto,
			 SiscomRegistro3Lst *pSisReg3LstRegreso);

	void EliminaProducto(const char *pchrPtrIdExpendio,
			     SiscomRegistro3 *pSisReg3Producto,
			     SiscomRegistro3Lst *pSisReg3LstRegreso);
	void InventariosProgramados(const char *pchrPtrIdExpendio,
				    SiscomRegistro3Lst *pSisReg3LstInventarios);
private:
	void AgregaCveNueva(const char *pchrPtrIdExpendio,
			    const char *pchrPtrCveNueva,
				    SiscomRegistro3 *pSisReg3Producto);
};
#endif
