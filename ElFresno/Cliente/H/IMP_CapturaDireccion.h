#ifndef __IMP_CAPTURADIRECCION_H__
#define __IMP_CAPTURADIRECCION_H__

#include <UIC_H_CapturaDireccion.h>
#include <CQSiscomCom.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QTextEdit;
class QPushButton;

class QCapturaDireccion : public CapturaDireccion
{
    Q_OBJECT

public:
    QCapturaDireccion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QCapturaDireccion();
	SISCOMGlobales::BTN_Captura ObtenOpcion();
	const char *ObtenCalle();
	const char *ObtenNumero();
	const char *ObtenCP();
	const char *ObtenColonia();
	const char *ObtenMunicipio();
	const char *ObtenEstado();
	const char *ObtenReferencias();

private:
	void ConectaSlots();
	void IniciaVariables();
private:
	QLineEdit *QLECEstado;
	SISCOMGlobales::BTN_Captura Opcion;
private slots:
	void S_PasaFocoNumero();
	void S_PasaFocoCP();
	void S_PasaFocoColonia();
	void S_PasaFocoMunicipio();	
	void S_PasaFocoEstado();
	void S_PasaFocoReferencias();
	void S_Aceptar();
	void S_Cancelar();
};

#endif 
