#ifndef __CQSISUSUARIOS_H__
#define __CQSISUSUARIOS_H__

#include <UIC_H_Usuarios.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class CSISCOMDatComunicaciones;
class CQSisUsuarios : public Usuarios
{
    Q_OBJECT

public:
    CQSisUsuarios(CSISCOMDatComunicaciones *,
	     long ,
	     long , QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CQSisUsuarios();
private:
	CSISCOMDatComunicaciones *CSisDatCom;
	long lngIdAplicacion;
	long lngIdPerfil;
private:
	void ConectaSlots();
private slots:
	void SlotRUsuario();
};

#endif 
