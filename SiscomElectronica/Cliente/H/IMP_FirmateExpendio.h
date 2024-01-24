#ifndef __IMP_FIRMATEEXPENDIO_H__
#define __IMP_FIRMATEEXPENDIO_H__

#include <UIC_H_FirmateExpendio.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class SiscomDatCom;
class Persona;
class QFirmateExpendio : public FirmateExpendio
{
    Q_OBJECT

public:
    QFirmateExpendio(SiscomDatCom *,
    		     const char *,
    		     const char *,
		     Persona *,
    		     QWidget* parent = 0,
		     const char* name = 0,
		     bool modal = FALSE, WFlags fl = 0 );
    ~QFirmateExpendio();
    int ObtenEdoValidacionUsuario();
private:
	SiscomDatCom *SisDatCom;
	Persona *Empleado;
	const char *chrPtrAplicacion;
	const char *chrPtrIdExpendio;
	int intIntentos;
	int intEdoValidacionUsuario;

	
private:
	void ConectaSlots();
private slots:
	void S_IntrodujoPassword();
};

#endif 
