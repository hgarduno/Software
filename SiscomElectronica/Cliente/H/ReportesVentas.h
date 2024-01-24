#ifndef __REPORTESVENTAS_H__
#define __REPORTESVENTAS_H__
#include <ProductosE.h>
#include <SISCOMComunicaciones++.h>
class RegistroRepVenta:public SiscomInformacion
{
public:
	RegistroRepVenta(const char *,
			 const char *,
			 const char *,
			 const char *,
			 const char *,
			 const char *);

};
class RegistrosRepVenta:public QPtrList<RegistroRepVenta>
{

public:
	RegistrosRepVenta();
	RegistrosRepVenta &operator<<(RegistroRepVenta *);

};
class ReportesVentasSrv
{
public:
	ReportesVentasSrv(SiscomDatCom *,const char *);
	void GeneraReporteVentas(const char *,
				 const char *,
				 ProductosE &);
	void GeneraReporteVentas(const char *,
				 const char *,
				 RegistrosRepVenta &,
				 RegistrosRepVenta &,
				 RegistrosRepVenta &,
				 RegistrosRepVenta &,
				 RegistrosRepVenta &);

private:
	SiscomDatCom *SisDatCom;
	const char *chrPtrIdExpendio;
private:
	void GeneraProductos(const SiscomComunicaSrv *,
			     ProductosE &);
	void GeneraReportes(const SiscomComunicaSrv *,
				 RegistrosRepVenta &,
				 RegistrosRepVenta &,
				 RegistrosRepVenta &,
				 RegistrosRepVenta &,
				 RegistrosRepVenta &);
			    
};

#endif
