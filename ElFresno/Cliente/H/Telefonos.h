#ifndef __TELEFONOS__
#define __TELEFONOS__
#include <qptrlist.h>


class CQ_Telefono
{
	public:
		CQ_Telefono(const char *,
			     const char *);
		void PonIdPersona(const char *);
		void PonTelefono(const char *);
		const char *ObtenIdTelefono();
		const char *ObtenTelefono();
		const char *ObtenIdPersona();
		const char *ObtenEdoRegistro();

	private:
		const char *chrPtrIdPersona;
		const char *chrPtrTelefono;
		const char *chrPtrEdoRegistro;
};

class CQ_Telefonos:public QPtrList<CQ_Telefono>
{
	public:
			CQ_Telefonos();
};
#endif
