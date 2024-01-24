#ifndef __PERFILES_H__
#define __PERFILES_H__
#include <qptrlist.h>
class CQPerfil
{
	public:
		CQPerfil(const char *,const char *);
		void PonIdPerfil(const char *);
		void PonNmbPerfil(const char *);
		void PonEdoRegistro(const char *);

		const char *ObtenIdPerfil();
		const char *ObtenNmbPerfil();
		const char *ObtenEdoRegistro();

	private:
		const char *chrPtrIdPerfil;
		const char *chrPtrNmbPerfil;
		const char *chrPtrEdoRegistro;

};

class CQ_Perfiles:public QPtrList<CQPerfil>
{
	public:
		CQ_Perfiles();
};
#endif
