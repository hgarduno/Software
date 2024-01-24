#ifndef __PRODUCTOSPROT2_H__
#define __PRODUCTOSPROT2_H__
#include <SISCOMComunicaciones++.h>
#include <Productos.h>
class ProductoProt2:public SiscomInformacion
{
public:
	ProductoProt2(const char *,
		      const char *,
		      const char *,
		      const char *,
		      const char *pchrPtrExistencia="");

};

class ProductosProt2:public QPtrList<ProductoProt2>
{
public:
	ProductosProt2();
	ProductosProt2 &operator<<(ProductoProt2 *);

};
#endif
