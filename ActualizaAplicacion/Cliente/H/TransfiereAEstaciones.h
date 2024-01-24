#ifndef __TRANSFIEREAESTACIONES_H__
#define __TRANSFIEREAESTACIONES_H__
#include <SISCOMComunicaciones++.h>
#include <qthread.h>
#include <qevent.h>

class ListaEstaciones;
class QEEdoTransmision:public QCustomEvent
{
	public:
		QEEdoTransmision(const char *,
				 const char *,
				 const char *,
				 const char *);
		const char *ObtenEdoTransmision();
		const char *ObtenArchivo();
		const char *ObtenDirIpEstacion();
		const char *ObtenPtoComEstacion();
private:
	const char *chrPtrEdoTransmision;
	const char *chrPtrArchivo;
	const char *chrPtrDirIpEstacion;
	const char *chrPtrPtoComEstacion;
	

};
class TransfiereAEstaciones:public QThread
{
public:

	TransfiereAEstaciones(QObject *,
			      SiscomDatCom *,
			      const char *,
			      ListaEstaciones *);
	~TransfiereAEstaciones();
	void run();
private:
        SiscomComunicaSrv *SComunicaSrv;
        SiscomDatCom *SDatCom;
        SiscomRegistroPro2 SRegistroPro2;
	const char *chrPtrOperacion;
	ListaEstaciones *LstEstaciones2;
	QObject *QOParent;
private:
	void EnviaOrden();
	void CreaRegistroComunicaciones();
	void NotificaSeLeyoTodo();


};	 

#endif
