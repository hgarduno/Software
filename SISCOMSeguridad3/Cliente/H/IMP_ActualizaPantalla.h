#ifndef __IMP_ACTUALIZAPANTALLA_H__
#define __IMP_ACTUALIZAPANTALLA_H__

#include <UIC_H_ActualizaPantalla.h>
#include <GeneralBibliotecaSeguridad3.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class CSISCOMDatComunicaciones;

class CQSisActualizaPantalla : public ActualizaPantalla
{
    Q_OBJECT

public:
    CQSisActualizaPantalla(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CQSisActualizaPantalla();
	void PonDirectorioQT(QString );
	void PonNombreAplicacion(QString );
	void PonIdAplicacion(QString );
private:

	CSISCOMDatComunicaciones *CSisDatCom;
	QString QSDirectorioQT;
	QString QSIdAplicacion;
	QSiscomListaObjQ QPLObjetos;
private:
	void ConectaSlots();
private slots:

	void S_SeleccionaArchivo();
	
};

#endif 
