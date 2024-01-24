#ifndef __IMP_VEHICULOS_H__
#define __IMP_VEHICULOS_H__

#include <UIC_H_Vehiculos.h>
#include <Vehiculos.h>
#include <VehiculosProt2.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;
class CSISCOMDatComunicaciones;
class SiscomDatCom;

class QVehiculos : public Vehiculos
{
    Q_OBJECT

public:
    QVehiculos(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QVehiculos();
private:
    CSISCOMDatComunicaciones *CSisDatCom;
    SiscomDatCom *SDatCom;
    CQVehiculos CQVVehiculos;
    Vehiculos2 VVehiculos2;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaVehiculos();
	void MuestraVehiculos();
private slots:
	void S_Anexar();
	void S_Registrar();
	void S_PasaFocoDescripcion();
	void S_PasaFocoAnexar();
	void S_SeleccionaVehiculo(int,int,int,const QPoint &);
	void S_ModificaVehiculo(int,int,int,const QPoint &);
	
};
extern "C" QVehiculos *InstanciaVehiculos(void *,void *,const char *,int );
#endif 
