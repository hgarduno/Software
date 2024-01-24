#ifndef __CQSISCOTIZANDO_H__
#define __CQSISCOTIZANDO_H__
#include <SISCOMComunicaciones++.h>
class CQSisCotizando:public SiscomInformacion
{
public:
	CQSisCotizando(const char *,
		       const char *,
		       const char *,
		       const char *,
		       const char *,
		       const char *,
		       const char *,
		       const char *,
		       const char *,
		       const char *);
	CQSisCotizando(const char *,
		       const char *,
		       const char *,
		       const char *);

};

class CQSisLstCotizando:public QPtrList<CQSisCotizando>
{
public:
	CQSisLstCotizando();
	CQSisLstCotizando &operator<<(CQSisCotizando *);
	const char *ImporteTotal();
	void ImporteTotal(const char *);
	void AsignaIdConsulta(const char *);

private:
	const char *chrPtrImporteTotal;
};
class CQSisOpCotizando:public SiscomOperaciones
{
public:
	CQSisOpCotizando(SiscomDatCom *);
	void CotizaServicios(CQSisLstCotizando *);
	void CotizaPerfilMedico(const char *,
				const char *,
				CQSisLstCotizando *);
	void CotizaConsulta(CQSisLstCotizando *);
	void CotizaConsulta(const char *,CQSisLstCotizando *);
	void VentasTotalesMedico(const char *,
				 const char *,
				 const char *,
				 CQSisLstCotizando *);
private:
	SiscomParametrosConsulta SPConsulta;
private:
	void Elimina(CQSisLstCotizando *);
};
#endif
