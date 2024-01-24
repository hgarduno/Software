#ifndef __IMP_MANTENFAMILIA_H__
#define __IMP_MANTENFAMILIA_H__

#include <UIC_H_MantenFamilia.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class Familia;
class SiscomDatCom;
class QMantenFamilia : public MantenFamilia
{
    Q_OBJECT

public:
    QMantenFamilia(SiscomDatCom *,
    		   Familia *,
		   QWidget* parent = 0,
		   const char* name = 0,
		   bool modal = FALSE,
		   WFlags fl = 0 );
    ~QMantenFamilia();
private:
	void ConectaSlots();
	void MuestraFamilia();
private:
	Familia *FFamilia;
	SiscomDatCom *SDatCom;
private slots:
	void S_Modifica();
};

#endif 
