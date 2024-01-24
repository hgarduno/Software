#ifndef __PRECIOS_H__
#define __PRECIOS_H__
#include <qptrlist.h>
#include <qstringlist.h>
class CQ_Persona;
class CSISCOMDatComunicaciones;
class CQOGenericaServidorSiscom;
class TipoPrecio;
class Precio
{
public:
	Precio(const char *,
	       const char *,
	       const char *,
	       TipoPrecio *);
	void PonPersona(CQ_Persona *);
	void PonIdPrecio(const char *);
	void PonDescripcion(const char *);
	void PonPrecio(const char *);
	void PonTipoPrecio(TipoPrecio *);
	void PonEdoRegistro(const char *);
	
	const char *ObtenIdPrecio();
	const char *ObtenDescripcion();
	const char *ObtenPrecio();
	TipoPrecio *ObtenTipoPrecio();
	const char *ObtenEdoRegistro();
	CQ_Persona *ObtenPersona();

private:
	const char *chrPtrIdPrecio;
	const char *chrPtrDescripcion;
	const char *chrPtrPrecio;
	const char *chrPtrEdoRegistro;
	CQ_Persona *CQPPersona;
	TipoPrecio *T_TipoPrecio;

	

};

class CQPrecios:public QPtrList<Precio>
{
public:
	CQPrecios();
	void PonClave(const char *);
	const char *ObtenClave();
private:
	const char *chrPtrClave;


};
class CQCtrPrecios
{
public:
	enum CtrPrecios
	{
		Registrar 
	};
	CQCtrPrecios(CSISCOMDatComunicaciones *,
		     CtrPrecios ,
		     const char *,
		     CQPrecios *);
	CQCtrPrecios(CSISCOMDatComunicaciones *,
		     QStringList ,
		     CQPrecios *);
private:

	CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
	const char *chrPtrParametrosRegPrecios;
	int intNumParametrosRegPrecios;
private:
	void RegistraLosPrecios(const char *,CQPrecios *);
	void OperacionesPrecios(QStringList ,CQPrecios *);
	void AnexaParametros(QStringList );
	void AnexaPrecios(CQPrecios *);
	void AnalizaRespuesta(CQPrecios *);
};
#endif
