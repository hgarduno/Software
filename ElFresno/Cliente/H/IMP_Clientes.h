#ifndef __IMP_CLIENTES_H__
#define __IMP_CLIENTES_H__

#include <UIC_H_Clientes.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QTextEdit;
class QPushButton;
class CSISCOMDatComunicaciones;

class QClientes : public Clientes
{
    Q_OBJECT

public:
    QClientes(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QClientes();
private:
    CSISCOMDatComunicaciones *CSisDatCom;
private:
    	void ConectaSlots();
	void IniciaVariables();
private:
	QLineEdit *QLECEstado;
private slots:
	void S_PasaFocoNombre();
	void S_PasaFocoAPaterno();
	void S_PasaFocoAMaterno();
	void S_PasaFocoApodo();
	void S_PasaFocoCalle();
	void S_PasaFocoNumero();
	void S_PasaFocoCP();
	void S_PasaFocoColonia();
	void S_PasaFocoMunicipio();
	void S_PasaFocoEstado();
	void S_PasaFocoReferencias();
	void S_AnexarTelefono();
	void S_Registrar();
	void S_BuscarCliente();
	void S_ModificaDatos();
};
extern "C" QClientes *InstanciaClientes(void *,void *,const char *,int );
#endif 
