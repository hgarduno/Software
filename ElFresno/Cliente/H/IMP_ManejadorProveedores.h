#ifndef __IMP_MANEJADORPROVEEDORES_H__
#define __IMP_MANEJADORPROVEEDORES_H__

#include <UIC_H_ManejadorProveedores.h>
#include <Empresas.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QTable;
class QPushButton;
class CSISCOMDatComunicaciones;

class QManejadorProveedores : public ManejadorProveedores
{
    Q_OBJECT

public:
    QManejadorProveedores(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QManejadorProveedores();
	void PonEsExpendio(const char *);
private:
    CSISCOMDatComunicaciones *CSisDatCom;
    QLineEdit *QLECEstado;
    Empresa *E_Empresa;
    const char *chrPtrEsExpendio;
    CQEmpresas CQEBuscar;
private slots:
	void S_RegistraProveedor();
	void S_PasaFocoRFC();
	void S_PasaFocoCalle();
	void S_PasaFocoNumero();
	void S_PasaFocoCP();
	void S_PasaFocoColonia();
	void S_PasaFocoMunicipio();
	void S_PasaFocoEstado();
	void S_PasaFocoAnexarDireccion();
	void S_AnexarDireccion();
	void S_AnexarTelefono();
	void S_AnexarContacto();
	void S_BuscarProveedores();
	void S_ModificarDatos();
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraEmpresa(Empresa *);
	void MuestraDirecciones(CQ_Direcciones );
	void MuestraDatosDireccion(CQ_Direccion *);
	void MuestraTelefonos(CQ_Telefonos );
	void MuestraContactos(CQ_Personas );
	void SeHabilitaAnexarDireccion();
	
signals:
	void Signal_EjecutoRegistro();
};


extern "C" QManejadorProveedores *InstanciaManejadorProveedores(void *,void *,const char *,int );
#endif 
