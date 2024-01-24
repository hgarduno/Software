#ifndef __QTCOTIZACIONES_H__
#define __QTCOTIZACIONES_H__
#include <UIC_H_Cotizaciones.h>

class QKeyEvent;
class QtCotizaciones:public Cotizaciones
{
Q_OBJECT
public:
	QtCotizaciones(QWidget *pQWParen,const char *pchrPtrName,bool pbModal,WFlags pWFlags);
	void CtrlF12(QKeyEvent *);
	void Teclas(QKeyEvent *);
	void keyPressEvent(QKeyEvent *pQKETeclas); 
	void MascaraTelefonoIdOrden(bool);
private:
private:
	void VerificandoTeclasConCtrl(QKeyEvent *);
};

#endif
