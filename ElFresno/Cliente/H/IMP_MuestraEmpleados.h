#ifndef __IMP_MUESTRAEMPLEADOS_H__
#define __IMP_MUESTRAEMPLEADOS_H__

#include <UIC_H_MuestraEmpleados.h>
#include <CQSiscomCom.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QPushButton;
class CQ_Personas;

class QMuestraEmpleados : public MuestraEmpleados
{
    Q_OBJECT

public:
    QMuestraEmpleados(CQ_Personas *,
    			QWidget* parent = 0,
			const char* name = 0,
			bool modal = FALSE, 
			WFlags fl = 0 );
    ~QMuestraEmpleados();
	SISCOMGlobales::BTN_Captura ObtenBoton();
	CQ_Personas *ObtenEmpleados();
private:
	CQ_Personas *CQPersonas;
	SISCOMGlobales::BTN_Captura BTN_Opcion;
private:
	void MuestraDatos();
	void ConectaSlots();
private slots:
	void S_Aceptar();
	void S_Cancelar();
};

#endif 
