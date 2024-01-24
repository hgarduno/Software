
#ifndef __IMP_PERFILCONSULTAMEDICO_H__
#define __IMP_PERFILCONSULTAMEDICO_H__
#include <UIC_H_PerfilConsultaMedico.h>
#include <CQSisServicios.h>
class SiscomDatCom;
class CQSisPersona;
class CQSisServicio;
class QPerfilConsultaMedico:public PerfilConsultaMedico
{
 Q_OBJECT
public:
	QPerfilConsultaMedico(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPerfilConsultaMedico();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisPersona *CQSPersona;
	CQSisServicio *CQSSMedico;
	CQSisServicio *CQSSGeneral;
	CQSisLstServicio CQSLSPerfil;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ServiciosMedico();
	void AnexaServicio(CQSisServicio *);
	void MuestraServicio(CQSisServicio *);
private slots:
	void SlotMedico(CQSisPersona *);
	void SlotServicioMedico(CQSisServicio *);
	void SlotServicioGeneral(CQSisServicio *);
	void SlotRegistra();
};
extern "C" QPerfilConsultaMedico *InstanciaPerfilConsultaMedico(void *,char **,void *,const char *,int);
#endif
