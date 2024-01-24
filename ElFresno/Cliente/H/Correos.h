#ifndef __CORREOS_H__
#define __CORREOS_H__
#include <qptrlist.h>

class CQ_Correo
{
	public:
		CQ_Correo(const char *,const char *);
		void PonIdPersona(const char *);
		void PonCorreo(const char *);
		void PonEdoRegistro(const char *);
		const char *ObtenIdPersona();
		const char *ObtenCorreo();
		const char *ObtenEdoRegistro();
	private:
		const char *chrPtrIdPersona;
		const char *chrPtrCorreo;
		const char *chrPtrEdoRegistro;
};
class CQ_Correos:public QPtrList<CQ_Correo>
{
	public:
		CQ_Correos();
};
#endif
