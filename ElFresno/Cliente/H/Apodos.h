#ifndef __APODOS_H__
#define __APODOS_H__
#include <qptrlist.h>
class CQ_Apodo
{
	public:
		CQ_Apodo(const char *,
			 const char *);
		void PonIdPersona(const char *);
		void PonApodo(const char *);
		void PonEdoRegistro(const char *);
		const char *ObtenIdPersona();
		const char *ObtenApodo();
		const char *ObtenEdoRegistro();
	private:
		const char *chrPtrIdPersona;
		const char *chrPtrApodo;
		const char *chrPtrEdoRegistro;
};
class CQ_Apodos:public QPtrList<CQ_Apodo>
{
	public:
		CQ_Apodos();
};
#endif
