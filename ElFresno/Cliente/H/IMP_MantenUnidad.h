#ifndef __IMP_MANTENUNIDAD_H__
#define __IMP_MANTENUNIDAD_H__

#include <UIC_H_MantenUnidad.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class SiscomDatCom;
class Unidad;

class QMantenUnidad : public MantenUnidad
{
    Q_OBJECT

public:
    QMantenUnidad(SiscomDatCom *,
    		  Unidad *,
    		  QWidget  *parent = 0,
		  const char* name = 0, 
		  bool modal = FALSE,
		  WFlags fl = 0 );
    ~QMantenUnidad();
    Unidad *UUnidad;
    SiscomDatCom *SDatCom;
private:
	void ConectaSlots();
	void MuestraUnidad();
private slots:
	void S_ModificaUnidad();
	void S_Cancelar();
};

#endif 
