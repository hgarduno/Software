
#ifndef __IMP_ADMINISTRACIONCAJAS_H__
#define __IMP_ADMINISTRACIONCAJAS_H__
#include <UIC_H_AdministracionCajas.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class CQSisCaja;
class QAdministracionCajas:public AdministracionCajas
{
 Q_OBJECT
public:
	QAdministracionCajas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QAdministracionCajas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3Cajas;
	SiscomRegistro3 *SisReg3Caja;
	CQSisCaja *CQSCaja;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoCajasRegistradas();
	void ConsultaCajasRegistradas();
	void MuestraCajasRegistradas();
	CQSisCaja *ImporteCaja();
	void RegistraImporteCaja();
	void AgregaCorteCajas();
	void AgregaVentasPorCaja();
	void AgregaSeguridadCaja();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotSeleccionandoCaja(int,int,int,const QPoint &);
	void SlotPasaFocoRegistrarImporte();
	void SlotRegistrarImporte();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QAdministracionCajas *InstanciaAdministracionCajas(void *,char **,void *,const char *,int);
#endif
