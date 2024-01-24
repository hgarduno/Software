#ifndef __CQSISPRODUCTO_H__
#define __CQSISPRODUCTO_H__
#include <SISCOMComunicaciones++.h>
#include <SiscomRegistros3.h>
class CQSisFamilia;
class CQSisLstPrecio;
class SiscomRegistro3;
class CQSisProducto:public SiscomInformacion
{
public:
	CQSisProducto(CQSisFamilia *,
		      const char *,
		      const char *,
		      const char *);
	~CQSisProducto();
	CQSisProducto();
	CQSisFamilia *ObtenFamilia();
	CQSisLstPrecio *ObtenPrecios();
	void PonPrecios(CQSisLstPrecio *);
private:
	CQSisFamilia *CQSFamilia;
	CQSisLstPrecio *CQSLPrecio;
};

class CQSisLstProducto:public QPtrList<CQSisProducto>
{
public:
	CQSisLstProducto();
	~CQSisLstProducto();
	CQSisLstProducto &operator<<(CQSisProducto *);
};


class CQSisProducto3Qt:public SiscomRegistro3 
{
public:
	CQSisProducto3Qt(const char *pchrPtrIdFamilia,
			 const char *pchrPtrIdProducto,
			 const char *pchrPtrCve,
			 const char *pchrPtrDsc);

};
class CQSisLstProducto3Qt:public QPtrList<CQSisProducto3Qt>
{
public:
	CQSisLstProducto3Qt();

};
#endif
