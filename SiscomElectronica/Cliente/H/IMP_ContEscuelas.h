#ifndef __IMP_CONTESCUELAS_H__
#define __IMP_CONTESCUELAS_H__

#include <UIC_H_ContEscuelas.h>
#include <Escuelas.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTable;
class SiscomDatCom;

class QContEscuelas : public ContEscuelas
{
    Q_OBJECT

public:
    QContEscuelas(SiscomDatCom *,
    		  char **,
    		  QWidget* parent = 0, 
		  const char* name = 0,
		  bool modal = FALSE,
		  WFlags fl = 0 );
    ~QContEscuelas();
    Escuela *ObtenEscuela();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	Escuela *EEscuela;
	Escuelas EEscuelas;
private:
	void ConsultaLasEscuelas();
	void ConectaSlots();
private slots:
	void S_SelEscuela();
	void S_Anexar();
	void S_Registrar();
};

#endif 
