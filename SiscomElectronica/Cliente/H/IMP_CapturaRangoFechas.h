#ifndef __IMP_CAPTURARANGOFECHAS_H__
#define __IMP_CAPTURARANGOFECHAS_H__

#include <UIC_H_CapturaRangoFechas.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;
class QPushButton;

class QCapturaRangoFechas : public CapturaRangoFechas
{
    Q_OBJECT

public:
    QCapturaRangoFechas(QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QCapturaRangoFechas();
    void ObtenRangoFechas(char *,char *);
    int ObtenOpcion();

private:
	int intOpcion;
private:
	void IniciaVariables();
	void ConectaSlots();

private slots:
	void S_PasaFocoFechaFin();
	void S_PasaFocoAceptar();
	void S_Aceptar();
};

#endif 
