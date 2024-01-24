
#ifndef __IMP_ACCIONTRASPASOBODEGAEXP_H__
#define __IMP_ACCIONTRASPASOBODEGAEXP_H__
#include <UIC_H_AccionTraspasoBodegaExp.h>

class zSiscomRegistro;

class QAccionTraspasoBodegaExp:public AccionTraspasoBodegaExp
{
 Q_OBJECT
public:
	QAccionTraspasoBodegaExp(
	   zSiscomRegistro *pzSisRegRespuesta,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QAccionTraspasoBodegaExp();
	int Opcion();
private:
	int intOpcion;
	zSiscomRegistro *zSisRegRespuesta;
private:
	void Muestra();
	void closeEvent(QCloseEvent*);
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotTraspasoExistenciaBodegaExpendio();
	void SlotCancelar();
};
#endif
