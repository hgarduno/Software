#ifndef __IMP_REGISTROEMPLEADOS_H__
#define __IMP_REGISTROEMPLEADOS_H__

#include <UIC_H_RegistroEmpleados.h>
#include <Seguridad3Protocolo2.h>
#include <Direcciones.h>
#include <MediosComunicacion.h>
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
class EmpresaN;
class QRegistroEmpleados : public RegistroEmpleados
{
    Q_OBJECT

public:
    QRegistroEmpleados(SiscomDatCom *,
    		       char **,
		       QWidget* parent = 0,
		       const char* name = 0, 
		       WFlags fl = 0 );
    ~QRegistroEmpleados();
private:
	PerfilesSeguridadProt2 pSeguridadProt2;
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QLineEdit *QLECEstado;
	Persona *PEmpleado;
	Direccion *DDireccion;
	MediosComunicacion MComunicacion;
	EmpresaN *Expendio;
private:
	void LlenaComboPerfiles();
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
private slots:
	void S_PasaFocoNombre();
	void S_PasaFocoAPaterno();
	void S_PasaFocoAMaterno();
	void S_PasaFocoCalle();
	void S_PasaFocoNumero();
	void S_PasaFocoCP();
	void S_PasaFocoColonia();
	void S_PasaFocoMunicipio();
	void S_PasaFocoEstado();
	void S_PasaFocoAnexarTelefono();
	void S_AnexarTelefono();
	void S_RegistraEmpleado();
	void S_Expendio();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QRegistroEmpleados *InstanciaRegistroEmpleados(void *,
							  char **,
							  void *,
							  const char *,
							  int);
#endif 
