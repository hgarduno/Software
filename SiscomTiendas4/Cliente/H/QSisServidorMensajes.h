#ifndef __QSISSERVIDORMENSAJES_H__
#define __QSISSERVIDORMENSAJES_H__
#include <SISCOMComunicaciones++.h>
#include <qthread.h>

class QMensajeInterfaz:public QCustomEvent
{
public:
	QMensajeInterfaz(int ,LCamposSiscomPro2 *);
	QMensajeInterfaz(int);
	void CamposSiscomPro2(int,LCamposSiscomPro2 *);
	LCamposSiscomPro2 *ObtenMensaje();
	int ObtenNumeroRegistros();

private:
	int intNumRegistros;
	LCamposSiscomPro2 *LCSiscomPro2Dat;	

};

/*
 * Se agregara la funcionalidad que le permita a las
 * aplicaciones recibir mensajes remotos, esto en una
 * primerar instancia se desarrollara para integrar 
 * el requerimiento para el prototipo para las gaseras
 *
 */

class QSisServidorMensajes:public QThread
{
public:

	QSisServidorMensajes(QWidget *,const char *,int );
private:
	void run();
	void IniciaServidor();
	void ProcesaMensaje(int,SArgsSiscom *);
private:
	int intSocket;
	int intPtoCom;
	int intSocketCliente;
	QWidget *QWParent;
	SArgsSiscom *SAgsSiscom;
};

void AsignaOperacionesVersion2(int pintSocket,
			       int pintNRegistros,
			       SSiscomOperaciones2 **pSSOperaciones2,
			       SArgsSiscom *pSArgsSiscom);
void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr);

SiscomOperaciones2 *OClienteRegistrado();
SiscomOperaciones2 *OClienteNuevo();
void ClienteRegistrado(SArgsSiscom *);
void ClienteNuevo(SArgsSiscom *);
void ManejadorErrores(SArgsSiscom *pSAgsSiscom);
#endif
