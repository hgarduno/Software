
#ifndef __IMP_RECEPCION_H__
#define __IMP_RECEPCION_H__
#include <UIC_H_Recepcion.h>
#include <CQSisConsultas.h>
class SiscomDatCom;
class SisUsuarioSeg3;
class CQSisPersona;
class CQSisPrecio;
class QRecepcion:public Recepcion
{
 Q_OBJECT
public:
	QRecepcion(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRecepcion();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisPersona *CQSPMedico;
	CQSisConsulta *CQSConsulta;
	CQSisLstConsulta CQSLCRegistradas;
	CQSisPrecio *CQSPrecio;
	SisUsuarioSeg3 *SUSeg3Firmado;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultasPendientesMedico();
	void ConsultasRegistradas();
	void ConsultaConsultas(const char *,
			       const char *,
			       const char *,
			       const char *);
	void MuestraConsultas();
	void FormaNombre(CQSisPersona *,char *);
	void PasaPaciente();
	void CotizaPerfilMedico();
	void IniciaPrecios();
	void Cobrar();
	void EliminaConsulta();
	void Hospitalizar();

private slots:
	void SlotRegistraPaciente();
	void SlotMedico(CQSisPersona *);
	void SlotMarcaConsulta(int,int,int,const QPoint &);
	void SlotPasaPaciente();
	void SlotPrecio(CQSisPrecio *);
	void SlotCobrar();
	void SlotActualizar();
	void SlotEliminar();
	void SlotHospitalizar();
};
extern "C" QRecepcion *InstanciaRecepcion(void *,char **,void *,const char *,int);
#endif
