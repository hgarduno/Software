
#ifndef __IMP_ACTUALIZAEXPENDIO_H__
#define __IMP_ACTUALIZAEXPENDIO_H__

#include <EmpresasN.h>
#include <UIC_H_ActualizaExpendio.h>
#include <SiscomRegistros.h>
class SiscomDatCom;

class QActualizaExpendio:public ActualizaExpendio
{
 Q_OBJECT
public:
	QActualizaExpendio(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QActualizaExpendio();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3LstProductos;

	EmpresasN EExpendios;
	EmpresaN *EExpendio;

	
private:
	void ConectaSlots();
	void IniciaVariables();

	void ConsultandoProductosNoExpendio();
	void ConsultaProductosNoExpendio();
	void MuestraProductosNoExpendio();


	void ConsultandoExpendios();
	void ConsultaExpendios();
	void MuestraExpendios();

	void ActualizaProductosEnElExpendio();
	void ActualizandoProductosEnElExpendio();
private slots:
	void SlotSeleccionaExpendio(int,int,int,const QPoint &);
	void SlotProductos();
};
extern "C" QActualizaExpendio *InstanciaActualizaExpendio(void *,char **,void *,const char *,int);
#endif
