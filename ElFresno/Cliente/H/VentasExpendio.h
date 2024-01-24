#ifndef __VENTASEXPENDIO_H__
#define __VENTASEXPENDIO_H__
#include <qptrlist.h>
#include <qstringlist.h>
#include <CQSiscomCom.h>

class CSISCOMDatComunicaciones;
class CQOGenericaServidorSiscom;

class VentaExpendio
{

public:
	VentaExpendio(const char *,
		      const char *,
		      const char *,
		      const char *,
		      const char *);
	const char *ObtenCantidad();
	const char *ObtenImporte();
	const char *ObtenCveProducto();
	const char *ObtenPrecioProducto();
	const char *ObtenExistencia();
private:
	const char *chrPtrCveProducto;
	const char *chrPtrImporte;
	const char *chrPtrCantidad;
	const char *chrPtrPrecioProducto;
	const char *chrPtrExistencia;
};

class CQVentasExpendio:public QPtrList<VentaExpendio>
{
	public:
		CQVentasExpendio();
		void PonImporteVenta(const char *);
		const char *ObtenImporteVenta();
private:
	const char *chrPtrImporteVenta;
};

class CQCtrVentasExpendio
{

public:
		CQCtrVentasExpendio(CSISCOMDatComunicaciones *,
				   QStringList ,
				   CQVentasExpendio *);
private:
		
	CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
	SISCOMRegistroEnvio SISCOMRegEnvio;
private:
	void IniciaRegistroEnvio();
	void IniciaComunicacion();
	void EnviaParametrosOperacion(QStringList );
	void EnviaVentasExpendio(CQVentasExpendio *);
	void EnviaInformacion();
	void AnalizaRespuesta(CQVentasExpendio *);
	void AnexaRegistro();
	void AnexaRegistroVacio();

};
#endif
