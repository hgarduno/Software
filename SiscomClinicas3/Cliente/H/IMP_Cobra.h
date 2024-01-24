
#ifndef __IMP_COBRA_H__
#define __IMP_COBRA_H__
#include <UIC_H_Cobra.h>
#include <CQSisCotizando.h>
class SiscomDatCom;
class CQSisConsulta;
class CQSisEstadoConsulta;
class SisUsuarioSeg3;
class QCobra:public Cobra
{
 Q_OBJECT
public:
	QCobra(CQSisConsulta *,
		SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCobra();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisConsulta *CQSConsulta;
	CQSisLstCotizando CQSLCotizando;
	SisUsuarioSeg3 *SUSeg3Firmado;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraPaciente();
	void CotizandoConsulta();
	void ConsultaConsulta();
	void MuestraCotizacion();
	void RegistraCobro();
	CQSisEstadoConsulta *ConsultaCobrada();
private slots:
	void SlotRegistraCobro();
};
#endif
