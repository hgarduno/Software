#ifndef __ZCAJAS_H__
#define __ZCAJAS_H__
#include <zSiscomRegistros.h>

class zDenominacion;
class zCaja;
class zEncabezadosCaja;

class zCajas:public zSiscomRegistros
{
public:
	zCajas();
	zDenominacion *Denominacion(int,int);
	void Actualiza(zSiscomRegistros *pzSisRegsCajas);
	zCaja *Caja(zCaja *,zSiscomRegistros *);
	zCaja *Principal();
	void EncabezadosGastos(zEncabezadosCaja *);
	void EncabezadosPagoTarjeta(zEncabezadosCaja *);
	void EncabezadosImporteGastos(zEncabezadosCaja *);
	void EncabezadosVentasEfectivo(zEncabezadosCaja *);
	zEncabezadosCaja *EncabezadosCorte();
private:
	zEncabezadosCaja *zEncaSCorte;
};
#endif
