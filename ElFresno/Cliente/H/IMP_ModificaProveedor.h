#ifndef __IMP_MODIFICAPROVEEDOR_H__
#define __IMP_MODIFICAPROVEEDOR_H__

#include <UIC_H_ModificaProveedor.h>
#include <Empresas.h>
#include <EmpresasProt2.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QLineEdit;
class QTabWidget;
class QWidget;
class QPushButton;
class QComboBox;
class CSISCOMDatComunicaciones;
class Empresa;
class Contacto;
class MedioComunicacion;

class QModificaProveedor : public ModificaProveedor
{
    Q_OBJECT

public:
    QModificaProveedor(CSISCOMDatComunicaciones *,
		       Empresa *,
		    	QWidget* parent = 0,
			const char* name = 0,
			bool modal = FALSE, 
			WFlags fl = 0 );
    ~QModificaProveedor();

private:
    	CSISCOMDatComunicaciones *CSisDatCom;
	SiscomDatCom *SDatCom;
	Empresa *E_Empresa;
private:
	void ConectaSlots();
	void MuestraEmpresa(Empresa *);
	void MuestraDirecciones(CQ_Direcciones );
	void MuestraDatosDireccion(CQ_Direccion *);
	void MuestraTelefonos(CQ_Telefonos );
	void MuestraContactos(CQ_Personas );
	Contacto *CapturaContacto();
	MedioComunicacion *CapturaTelefono();
private slots:
	void S_ModificaGenerales();
	void S_AnexaDireccion();
	void S_AnexaContacto();
	void S_AnexaTelefono();
	void S_EliminaDireccion();
	void S_EliminaTelefono();
	void S_EliminaContacto();

};

#endif 
