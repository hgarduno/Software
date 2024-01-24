#ifndef __IMP_CONSULTAEMPLEADOS_H__
#define __IMP_CONSULTAEMPLEADOS_H__

#include <UIC_H_ConsultaEmpleados.h>
#include <CQSiscomCom.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class SiscomDatCom;
class CQ_Personas;

class QConsultaEmpleados : public ConsultaEmpleados
{
    Q_OBJECT

public:
    QConsultaEmpleados(SiscomDatCom *,
    			QWidget* parent = 0,
    			const char* name = 0,
			bool modal = FALSE, 
			WFlags fl = 0 );
    ~QConsultaEmpleados();
    SISCOMGlobales::BTN_Captura ObtenBoton();
    CQ_Personas *ObtenEmpleados();
private:
	SiscomDatCom *SDatCom;
	SISCOMGlobales::BTN_Captura BTN_Opcion;
	CQ_Personas *CQPersonas;
private:
	void ConectaSlots();
private slots:
	void S_Consulta();


};

#endif 
