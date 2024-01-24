
#ifndef __IMP_CIERRAAPARTADO_H__
#define __IMP_CIERRAAPARTADO_H__
#include <UIC_H_CierraApartado.h>
class zSiscomConexion;

class zSiscomRegistros;
class zSiscomRegistro;

class QCierraApartado:public CierraApartado
{
 Q_OBJECT
public:
	QCierraApartado(
	    zSiscomConexion *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCierraApartado();
	void setFocus();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsApartados;
	zSiscomRegistro *zSisRegApartado;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
	void HabilitaDesHabilitaPagar();
private slots:
	void SlotConsulta();
	void SlotSeleccionaApartado(int,int,int ,const QPoint &);
	void SlotPagar();
	void SlotCancelar();
	void SlotFocoAFechaFin();
	void SlotFocoAConsulta();
	void closeEvent(QCloseEvent *);
signals:
	void SignalPagar(zSiscomRegistro *);
	void SignalCancelar();
};
#endif
