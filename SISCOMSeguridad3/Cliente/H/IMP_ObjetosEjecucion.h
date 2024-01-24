#ifndef __CQSISOBJETOSEJECUCION_H__
#define __CQSISOBJETOSEJECUCION_H__

#include <UIC_H_ObjetosEjecucion.h>
#include <GeneralBibliotecaSeguridad3.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLineEdit;
class QPushButton;
class CSISCOMDatComunicaciones;
class QSiscomObjetosQT;
class CQSisObjetosEjecucion : public ObjetosEjecucion
{
    Q_OBJECT

public:
	enum BTN_Seleccion
	{
		BTN_Aceptar ,
		BTN_Cancelar
	};
    CQSisObjetosEjecucion(CSISCOMDatComunicaciones *,const char *, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CQSisObjetosEjecucion();
	BTN_Seleccion ObtenBotonSeleccionado();
	const char *ObtenLosObjetosAAnexar(QSiscomListaObjQ &);
private:
	CSISCOMDatComunicaciones *CSisDatCom;
	QSiscomListaObjQ QSLObjetosQT;
	QSiscomListaObjQ QSLObjetosAAnexar;
	int intCualObjeto;
	BTN_Seleccion BTNCual;
	const char *chrPtrNmbForma;
	
private:
	void ConectaSlots();
	void ConsultaObjetos();
	void MuestraObjetos();
	void MuestraPropiedadesXObjeto(int);
	void MuestraObjetoAAnexar();
private slots:
	void SlotSeleccionaObjeto(int,int,int,const QPoint &);
	void SlotAnexarObjeto();
	void SlotAceptar();
};

#endif 
