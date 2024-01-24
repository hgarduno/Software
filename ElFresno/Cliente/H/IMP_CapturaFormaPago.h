#ifndef __IMP_CAPTURAFORMAPAGO_H__
#define __IMP_CAPTURAFORMAPAGO_H__

#include <UIC_H_CapturaFormaPago.h>
#include <CQSiscomCom.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class CQControlFecha;

class QCapturaFormaPago : public CapturaFormaPago
{
    Q_OBJECT

public:
    QCapturaFormaPago( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QCapturaFormaPago();
     void ObtenFormaPago(char *,char *);
     SISCOMGlobales::BTN_Captura ObtenOpcion();
private:
	void ConectaSlots();
	void IniciaVariables();
private:
	SISCOMGlobales::BTN_Captura Opcion;
private slots:
	void S_SFormaPago(int);
	void S_Cancelar();	
	void S_Aceptar();
};

#endif 
