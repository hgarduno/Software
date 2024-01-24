#ifndef __ZCIRCUITOIMPRESO_H__
#define __ZCIRCUITOIMPRESO_H__
#include <zSiscomRegistro.h>
class zCircuitoImpreso:public zSiscomRegistro
{
public:
	zCircuitoImpreso(const char *pchrPtrIdImpreso);
	void IdVenta(const char *pchrPtrIdVenta);
	void IdCliente(const char *pchrPtrIdCliente);

	void CveProducto(const char *pchrPtrCveProducto);
	void Memoria(const char *pchrPtrMemoria);
	void Archivo(const char *pchrPtrArchivo);
	void FechaHoraEntrega(const char *pchrPtrFechaHoraEntrega);
	void Pagado(const char *pchrPtrPagado);
};
#endif
