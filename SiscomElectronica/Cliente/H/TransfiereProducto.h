#ifndef __TRANSFIEREPRODUCTO_H__
#define __TRANSFIEREPRODUCTO_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>
class ProductoE;
class RegProductoTransfiere:public SiscomInformacion
{
public:
	RegProductoTransfiere(ProductoE *,const char *,const char *,const char *);
	RegProductoTransfiere(const char *pchrPtrCveProducto,
			      const char *pchrPtrCantidad,
			      const char *pchrPtrIdMatriz,
			      const char *pchrPtrIdExpendio,
			      const char *pchrPtrIdEmpleado);

};

class RegsProductoTransfiere:public QPtrList<RegProductoTransfiere>
{
public:
	RegsProductoTransfiere();
	RegsProductoTransfiere &operator<<(RegProductoTransfiere *);
	RegProductoTransfiere *operator[](SiscomRegistrosPro2 *pSisRegPro2Producto);
};


class OpTransfiereProductos
{
public:
	OpTransfiereProductos(SiscomDatCom *);
	void EjecutaTransferencia(RegsProductoTransfiere &);
	void ValidaExistencia(RegsProductoTransfiere &);
	const char *ObtenEdoEnvio();
	SiscomRegistrosPro2 *ProductosNoAlcanza();
	int NoAlcanza();
private:
	SiscomDatCom *SisDatCom;
	const char *chrPtrEdoEnvio;
	SiscomRegistrosPro2 *SisRegs2NoAlcanza;
private:
	void AnalizaRegresoEnvio(const SiscomComunicaSrv *);
};
#endif
