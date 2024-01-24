#ifndef __COMPRASE_H__
#define __CMPORASE_H__
#include <SISCOMComunicaciones++.h>
#include <qstringlist.h>
#include <ProductosE.h>
class SiscomDatCom;
class CompraE:public SiscomInformacion
{
public:
	CompraE(ProductoE *,
		const char *,
		const char *);
};

class ComprasE:public QPtrList<CompraE>
{
public:
	ComprasE();

	ComprasE &operator<<(CompraE *);

};
class OpCompras
{
public:
	OpCompras(SiscomDatCom *,
		 const char *,
		 ProductosE &);
	void RegistraCompras();
	void ConsultaCompras();
private:
	SiscomDatCom *SisDatCom;
	const char *chrPtrIdEmpleado;
	ProductosE PProductos;


};
#endif
