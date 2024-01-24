#ifndef __IMP_REGISTROEMPLEADOS_H__
#define __IMP_REGISTROEMPLEADOS_H__

#include <UIC_H_RegistroEmpleados.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;
class QSiscomPerfilBD;
class CQPerfiles;
class CSISCOMDatComunicaciones;
class SiscomDatCom;
class CQ_Personas;
class CQ_Persona;

class QRegistroEmpleados : public RegistroEmpleados
{
    Q_OBJECT

public:
    QRegistroEmpleados(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QRegistroEmpleados();
private:
    CSISCOMDatComunicaciones *CSisDatCom;
    SiscomDatCom *SDatCom;
    QSiscomPerfilBD *QSPerfilBD;
    CQPerfiles *CQPDatos;
    QLineEdit *QLEEstados;
    CQ_Personas *CQEmpConsultados; 
    CQ_Persona *CQPersonaActual;
private:
    void LlenaComboPerfiles();
    void IniciaVariables();
    void ConectaSlots();
    void ConectaSlotsConsulta();
    void SeSeleccionaronEmpleados();
    void MuestraEmpleadoConsulta();
    void MuestraDireccion();
    void MuestraInformacionSeguridad();
    void CambiaEstadoEdits(bool);
private slots:
	void S_PasaFocoNombre();
	void S_PasaFocoAPaterno();
	void S_PasaFocoAMaterno();
	void S_PasaFocoCalle();
	void S_PasaFocoNumero();
	void S_PasaFocoCP();
	void S_PasaFocoColonia();
	void S_PasaFocoMunicipio();
	void S_PasaFocoEstados();
	void S_PasaFocoAnexarTelefono();
	void S_AnexarTelefono();
	void S_PasaFocoPerfil();
	void S_PasaFocoFirma();
	void S_PasaFocoPassword();
	void S_PasaFocoCPassword();
	void S_PasaFocoRegistrar();
	void S_SeleccionoPerfil(int);
	void S_Registrar();
	void S_ConsultaEmpleados();
public slots:
	void S_Siguiente();
	void S_Anterior();
};
extern "C" QRegistroEmpleados *InstanciaRegistroEmpleados(void *,void *,const char *,int);
#endif 
