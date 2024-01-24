#ifndef __EMPRESASPROT2_H__
#define __EMPRESASPROT2_H__
#include <SISCOMComunicaciones++.h>

class EmpresaProt2:public SiscomInformacion
{
public:
	EmpresaProt2(const char *,const char *,const char *,const char *);
private:

};

class EmpresasProt2:public QPtrList<EmpresaProt2>
{
public:
	EmpresasProt2();
	operator const EmpresaProt2*()
	{
	   return current();
	}
	EmpresaProt2 *operator++();


};
#endif
