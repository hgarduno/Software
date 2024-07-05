#ifndef __CQSISRASTREOPRODUCTO_H__
#define __CQSISRASTREOPRODUCTO_H__
#include <CQSisProductos4.h>
#include <SiscomOperaciones3.h>
class SiscomDatCom;
class SiscomRegistro3;

class CQSisRastreoProducto:public CQSisProducto4
{
public:
	CQSisRastreoProducto(SiscomRegistro3 *pSisReg3Expendio,
			     SiscomRegistro3 *pSisReg3Producto,
			     const char *pchrPtrFechaIni,
			     const char *pchrPtrFechaFin);
	void AsignaRastreo(SiscomRegistro4 *pSisReg4Rastreo);
	const char *ExistenciaExpendio();
	const char *ExistenciaBodegas();
	SiscomRegistro3Lst *ExistenciasBodegas();
	SiscomRegistro3Lst *VentasProducto();
	SiscomRegistro3Lst *ComprasProducto();
	SiscomRegistro3Lst *TransferenciasBodegasExpendio();
	SiscomRegistro3Lst *TransferenciasExpendioExpendio();
	SiscomRegistro3Lst *ActualizoInventario();
	SiscomRegistro3Lst *TransferenciaBodegaBodega();

	const char *TotalVentas();
	const char *TotalCompras();
	const char *TotalTransBodegaExpendio();
	const char *TotalTransExpendioExpendio();


	int EdoConsultaTransExpExp();
	int EdoConsultaActualizoInventario();
private:
	SiscomRegistro3 *RangoRastreo(const char *pchrPtrFechaIni,
				      const char *pchrPtrFechaFin);
private:
	SiscomRegistro4 *SisReg4Rastreo;
};

class CQSisRastreandoProducto:public SiscomOperaciones3
{
public:
	CQSisRastreandoProducto(SiscomDatCom *pSisDatcom);
	void Rastrea(CQSisRastreoProducto *pCQSRastreoProducto);

};
#endif
