
#ifndef __IMP_ORDENSERVICIO_H__
#define __IMP_ORDENSERVICIO_H__
#include <UIC_H_OrdenServicio.h>
#include <CQSisDirecciones.h>
#include <SisMedioComunicacion.h>
class SiscomDatCom;
class QOrdenServicio:public OrdenServicio
{
 Q_OBJECT
public:
	QOrdenServicio(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QOrdenServicio();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstDireccion CQSLDirecciones;
	SisLstMedCom SLMCom;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraDireccionesPropietario();
	void MuestraTelefonos();
	void Direccion(CQSisDireccion *,char *);
	void Telefono(SisMedCom *,char *);
	void closeEvent(QCloseEvent *);
private slots:
	void SlotCapturaNombreEncargadoEntregaVehiculo();
	void SlotCapturaPropietario();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QOrdenServicio *InstanciaOrdenServicio(void *,char **,void *,const char *,int);
#endif
