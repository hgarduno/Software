
#ifndef __IMP_PUNTOSALUMNOS_H__
#define __IMP_PUNTOSALUMNOS_H__
#include <UIC_H_PuntosAlumnos.h>
#include <CQSisPuntosElectronica.h>
#include <CQSisManejoPromociones.h>
class SiscomDatCom;
class SiscomRegistro3;
class QPuntosAlumnos:public PuntosAlumnos
{
 Q_OBJECT
public:
	QPuntosAlumnos(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPuntosAlumnos();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Alumno;
	CQSisPuntosPromocionCliente CQSPPCliente;
	SiscomRegistro4 SisReg4ValidacionPPSel;
	CQSisManejoPromociones CQSMPromociones;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
	void ConsultaPuntosPromociones();
	void ConsultandoPuntosPromociones();
	void MuestraPuntosPromociones();
	void MuestraPromociones();
	void MuestraPuntosCliente();
	int ValidaPSeleccion();
	void MuestraValidacionPSeleccion();
	int EjecutaValidacionPSeleccion(SiscomRegistro3Lst *pSisReg3LstSeleccion);
	void ActivaTomaPromocion();
	void MuestraPromocionesSeleccionadas();
	void TienePuntosElCliente();
	void ClienteNoTienePuntosSuficientes(int pintFila);
	void PromocionSeleccionada();
	void PromocionSeleccionada(int);
	SiscomRegistro3 *PromocionPorNumero(int pintNPromocion);
private slots:
	void SlotAlumno(SiscomRegistro3 *);
	void SlotValidaPSeleccion();
	void SlotValidaPSeleccion(int pintFila,int,int,const QPoint &);
	void SlotReInicia();
	void SlotTomaPromociones();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QPuntosAlumnos *InstanciaPuntosAlumnos(void *,char **,void *,const char *,int);
#endif
