#ifndef __REPORTEFECHACORTE_H__
#define __REPORTEFECHACORTE_H__

#include <SISCOMComunicaciones++.h>
class ProductoProt2;

class RegistroRepFechaCorte:public SiscomInformacion
{
public:
	RegistroRepFechaCorte(ProductoProt2 *,
			      const char *,
			      const char *,
			      const char *,
			      const char *);

};

class RegistrosRepFechaCorte:public QPtrList<RegistroRepFechaCorte>
{
public:
	RegistrosRepFechaCorte();

	RegistrosRepFechaCorte &operator<<(RegistroRepFechaCorte *);
	void GeneraRegistros(const SiscomComunicaSrv *);
};
class OpReporteFechaCorte
{
public:
	OpReporteFechaCorte(SiscomDatCom *);
	void ObtenReporteFechaCorte(const char *,
				   const char *,
				   const char *,
				   RegistrosRepFechaCorte &);
	void ObtenFechasCorte(const char *,RegistrosRepFechaCorte &);
	


private:
	SiscomDatCom *SisDatCom;
private:
};
#endif

