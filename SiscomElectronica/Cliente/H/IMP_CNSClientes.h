#ifndef __IMP_CNSCLIENTES_H__
#define __IMP_CNSCLIENTES_H__

#include <UIC_H_CNSClientes.h>
#include <Personas.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class SiscomDatCom;
class Persona;
class SiscomRegistro3;
class QCNSClientes : public CNSClientes
{
    Q_OBJECT

public:
    QCNSClientes(const char *pchrPtrIdExpendio,
    		 SiscomDatCom *,
    		 QWidget* parent = 0,
		 const char* name = 0,
		 bool modal = FALSE,
		 WFlags fl = 0 );
    ~QCNSClientes();
    int ObtenSeleccion();
    Persona *ObtenPersona();
    SiscomRegistro3 *Escuela();
private:
SiscomDatCom *SisDatCom;
Personas PPersonas;
Persona *PPersona;
QLineEdit *QLERFCCombo;
int intSeleccion;
const char *chrPtrIdExpendio;
SiscomRegistro3 *SisReg3Escuela;
private:
	void ConsultaClientes();
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
private slots:
	void S_Cliente(int );

	void S_SelCliente(int);
	void S_SelCliente();

	void S_Aceptar();
	void S_Cancelar();

	void SlotEscuela(SiscomRegistro3 *);
};

#endif 
