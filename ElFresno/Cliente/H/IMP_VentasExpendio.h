#ifndef __IMP_VENTASEXPENDIO_H__
#define __IMP_VENTASEXPENDIO_H__

#include <UIC_H_VentasExpendio.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLCDNumber;
class QLabel;
class CSISCOMDatComunicaciones;
class CQVentasExpendio;
class Empresa;
class QVentasExpendio : public VentasExpendio
{
    Q_OBJECT

public:
    QVentasExpendio(CSISCOMDatComunicaciones *,
    		    Empresa *,
		    QWidget* parent = 0,
		    const char* name = 0,
		    WFlags fl = 0 );
    ~QVentasExpendio();
private:
CSISCOMDatComunicaciones *CSisDatCom;
Empresa *E_Empresa;
char *chrPtrFechaIni;
char *chrPtrFechaFin;
private:
	void ConectaSlots();
	void MuestraReporte(CQVentasExpendio *);
private slots:
	void S_FechaReporte();
};

#endif 
