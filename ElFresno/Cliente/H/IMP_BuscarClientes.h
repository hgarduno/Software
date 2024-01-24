#ifndef __IMP_BUSCARCLIENTES_H__
#define __IMP_BUSCARCLIENTES_H__

#include <UIC_H_BuscarClientes.h>
#include <Personas.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
class QComboBox;
class CSISCOMDatComunicaciones;

class QBuscarClientes : public BuscarClientes
{
    Q_OBJECT

public:
	enum BTN_Botones
	{
		Aceptar,
		Cancelar
	};
    QBuscarClientes(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QBuscarClientes();
	BTN_Botones ObtenSeleccion();
	const CQ_Personas &ObtenPersonas();
	CQ_Persona *ObtenPersona();
	void closeEvent(QCloseEvent *);
private:
CSISCOMDatComunicaciones *CSisDatCom;
CQ_Personas CQPersonas;
CQ_Persona *CQPersona;
BTN_Botones BTN_Seleccion;
private:
	void ConectaSlots();
	QString ObtenDato(QLineEdit *);
	void MuestraDatosPersona();
	void LimpiaControles();
	void IniciaVariables();
private slots:
	void S_Consultar();
	void S_SiguienteCliente();
	void S_ClienteAnterior();
	void S_SeleccionarTodos();
	void S_Aceptar();
	void S_Cancelar();

	void SlotPasaFocoNombre();
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoConsultar();

	
	
};

#endif 
