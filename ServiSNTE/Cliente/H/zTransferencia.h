#ifndef __ZTRANSFERENCIA_H__
#define __ZTRANSFERENCIA_H__
#include <zSiscomRegistro.h>
class zProductos;
class zOrden;
class zTransferencia:public zSiscomRegistro
{
 public:
    zTransferencia(zSiscomRegistro *pzSisRegTienda,
                zSiscomRegistro *pzSisRegVendedor, 
                zSiscomRegistro *pzSisRegChofer, 
                zSiscomRegistro *pzSisRegCamion);
	void Productos(zProductos *pzProdsTransferencia);
	void IdEstado(const unsigned char *pchrPtrIdEstado);
	void ObservacionGeneral(const unsigned char *pchrPtrObservacionGeneral);
	void IdTipoTransferencia(const char *pchrPtrIdTipoTransferencia);
	void EsStock(const char *pchrPtrEsStock);
	void TiendaOrigen(zSiscomRegistro *pzSisRegTiendaOrigen);
	void Dia(const unsigned char *pchrPtrDia);
	void Mes(const unsigned char *pchrPtrMes);
	void Anio(const unsigned char *pchrPtrAnio);
	zSiscomRegistro *TiendaOrigen();
	zSiscomRegistro *TiendaDestino();
	const char *Chofer();
	const char *Camion();
	const char *Placas();
    	zProductos *Productos();
	const char *Dia();
	const char *Mes();
	const char *Anio();
	zOrden *Orden();
	void AsignaOrden();
private:
	zOrden *zOrdenT;

};

#endif
