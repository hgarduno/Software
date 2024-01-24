
#ifndef __IMP_CAPTURARANGOHORA_H__
#define __IMP_CAPTURARANGOHORA_H__
#include <UIC_H_CapturaRangoHora.h>
class QCapturaRangoHora:public CapturaRangoHora
{
 Q_OBJECT
public:
	QCapturaRangoHora(char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaRangoHora();
	int Aceptar();
	void Horas(char *,char*);
private:
	char **chrPtrArgumentos;
	int intAceptar;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotFocoAAceptar();
	void SlotFocoAHoraFin();
	void SlotAceptar();
};
#endif
