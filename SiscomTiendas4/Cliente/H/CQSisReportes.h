#ifndef __CQSISREPORTES_H__
#define __CQSISREPORTES_H__
#include <SISCOMComunicaciones++.h>

class CQSisLstProdCotiza;

class CQSisRepVenta:public SiscomInformacion
{
public:
	CQSisRepVenta(
			const char *,
			const char *,
			const char *);
};

class CQSisLstRepVenta:public QPtrList<CQSisRepVenta>
{
public:
	CQSisLstRepVenta();
	CQSisLstRepVenta &operator<<(CQSisRepVenta *);
private:

};
class CQSisOpReportes:public SiscomOperaciones
{
public:
	CQSisOpReportes(SiscomDatCom *);
	void ReporteVentas(const char *,
			   const char *,
			   CQSisLstRepVenta *);
	void DetalleVentas(const char *,
				 const char *,
				 CQSisLstProdCotiza *);
private:
	SiscomParametrosConsulta SPConsulta;
private:
	void FormaReporteVentas(SiscomRegistrosPro2 *,	
				CQSisLstRepVenta *);
	void EliminaProductos(CQSisLstProdCotiza *);	
	void EliminaReportes(CQSisLstRepVenta *);
};
#endif
