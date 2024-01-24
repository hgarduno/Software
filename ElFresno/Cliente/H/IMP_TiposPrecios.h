#ifndef __IMP_TIPOSPRECIOS_H__
#define __IMP_TIPOSPRECIOS_H__

#include <UIC_H_TiposPrecios.h>
#include <TiposPrecios.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QTable;
class CSISCOMDatComunicaciones;

class QTiposPrecios : public TiposPrecios
{
    Q_OBJECT

public:
    QTiposPrecios(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QTiposPrecios();
private:
CSISCOMDatComunicaciones *CSisDatCom;
CQTiposPrecios CQTPrecios;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaLosPrecios();
private slots:
	void S_PasaFocoDescripcion();
	void S_PasaFocoAnexar();
	void S_Anexar();
	void S_Registrar();

};
extern "C" QTiposPrecios *InstanciaTiposPrecios(void *,void *,const char *,int);
#endif 
