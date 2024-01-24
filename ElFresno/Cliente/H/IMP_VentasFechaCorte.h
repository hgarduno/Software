#ifndef __IMP_VENTASFECHACORTE_H__
#define __IMP_VENTASFECHACORTE_H__

#include <UIC_H_VentasFechaCorte.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class Empresa;
class QPushButton;
class CSISCOMDatComunicaciones;

class QVentasFechaCorte : public VentasFechaCorte
{
    Q_OBJECT

public:
    QVentasFechaCorte(CSISCOMDatComunicaciones *,
    		      Empresa *,
    			QWidget* parent = 0,
			const char* name = 0,
			WFlags fl = 0 );
    ~QVentasFechaCorte();
private:
	CSISCOMDatComunicaciones *CSisDatCom;
	Empresa *E_Expendio;
private:
	void ConectaSlots();

private slots:
	void S_FechaCorte();
};

#endif 
