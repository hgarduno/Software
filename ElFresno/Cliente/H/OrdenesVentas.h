#ifndef __ORDENESVENTAS_H__
#define __ORDENESVENTAS_H__
#include <qptrlist.h>
class OrdenVenta
{
public:
	OrdenVenta(const char *,
		   const char *,
		   const char *);
	void PonIdVenta(const char *);
	void PonFechaHora(const char *);
	void PonImporte(const char *);
	const char *ObtenIdVenta();
	const char *ObtenFechaHora();
	const char *ObtenImporte();
private:
	const char *chrPtrIdVenta;
	const char *chrPtrFechaHora;
	const char *chrPtrImporte;
};
class CQOrdenesVenta:public QPtrList<OrdenVenta>
{
public:
	CQOrdenesVenta();
	CQOrdenesVenta operator<<(OrdenVenta *);
};
#endif
