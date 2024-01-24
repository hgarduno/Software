#ifndef __DIRECCIONES_H__
#define __DIRECCIONES_H__
#include <qptrlist.h>

class CQ_Direccion
{
	public:
		CQ_Direccion(const char *,
			     const char *,
			     const char *,
			     const char *,
			     const char *,
			     const char *,
			     const char *);
		const char *ObtenCalle();
		const char *ObtenNumero();
		const char *ObtenCP();
		const char *ObtenColonia();
		const char *ObtenDelegacion();
		const char *ObtenEstado();
		const char *ObtenReferencias();
		const char *ObtenEdoRegistro();
		

		void PonCalle(const char *);
		void PonNumero(const char *);
		void PonColonia(const char *);
		void PonCP(const char *);
		void PonDelegacion(const char *);
		void PonReferencias(const char *);
		void PonEdoRegistro(const char *);
	private:
		const char *chrPtrCalle;
		const char *chrPtrNumero;
		const char *chrPtrColonia;
		const char *chrPtrDelegacion;
		const char *chrPtrCP;
		const char *chrPtrEstado;
		const char *chrPtrReferencias;
		const char *chrPtrIdPersona;
		const char *chrPtrIdEmpresa;
		const char *chrPtrEdoRegistro;
};
class CQ_Direcciones:public QPtrList<CQ_Direccion>
{
	public:
		CQ_Direcciones();
};

#endif
