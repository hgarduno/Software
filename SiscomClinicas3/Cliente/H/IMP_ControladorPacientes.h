
#ifndef __IMP_CONTROLADORPACIENTES_H__
#define __IMP_CONTROLADORPACIENTES_H__
#include <UIC_H_ControladorPacientes.h>
class SiscomDatCom;
class CQSisPersona;
class CQSisPrecio;
class SiscomRegistrosPro2;
class SisUsuarioSeg3;
class QControladorPacientes:public ControladorPacientes
{
 Q_OBJECT
public:
	QControladorPacientes(
	    SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QControladorPacientes();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisPersona *CQSPMedico;
	CQSisPrecio *CQSPrecio;
	SisUsuarioSeg3 *SUSeg3Firmado;
	const char *chrPtrIdPaciente;
private:
	void ConectaSlots();
	void IniciaVariables();
	CQSisPersona *Paciente();
	void RegistraGenerales();
	void EstadoRegistroPaciente(SiscomRegistrosPro2 *);
	void RegistraConsulta();
	void ConsultasPendientesMedico();
	void CotizaPerfilMedico();
	void IniciaPrecios();
	void HabilitaRegistraConsulta();
	const char *ChecaPacientesSimilares();



private slots:
	void SlotRegistraGenerales();
	void SlotMedico(CQSisPersona *);
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoRFC();
	void SlotPasaFocoRegistraGenerales();
	void SlotRegistraConsulta();
	void SlotPrecio(CQSisPrecio *);
	void SlotPasaFocoNombre();
};
#endif
