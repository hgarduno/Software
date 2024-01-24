#ifndef __IMP_MANEJADORPROVEEDORES_H__
#define __IMP_MANEJADORPROVEEDORES_H__

#include <UIC_H_ManejadorProveedores.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;
class QComboBox;
class SiscomDatCom;
class EmpresaN;

class QManejadorProveedores : public ManejadorProveedores
{
    Q_OBJECT

public:
    QManejadorProveedores(SiscomDatCom *,char **, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QManejadorProveedores();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QLineEdit *QLECEstado;
	EmpresaN *Empresa;
private:
	void IniciaVariables();
	void ConectaSlots();
	void HabilitaAnexar();
	void LimpiaRegistros();
	void closeEvent(QCloseEvent *);
private slots:
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
	void S_RegistrarProveedor();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QManejadorProveedores *InstanciaManejadorProveedores(void *,
								char **,
								void *,
								const char *,
								int );
#endif 
