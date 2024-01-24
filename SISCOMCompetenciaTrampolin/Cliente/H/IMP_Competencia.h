
#ifndef __IMP_COMPETENCIA_H__
#define __IMP_COMPETENCIA_H__
#include <UIC_H_Competencia.h>
class SiscomDatCom;
class CQSisGimnasio;
class CQSisCompetencia;
class CQSisTipoCompetencia;
class QCompetencia:public Competencia
{
 Q_OBJECT
public:
	QCompetencia(SiscomDatCom *,
	    void *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCompetencia();
private:
	SiscomDatCom *SisDatCom;
	void *chrPtrArgumentos;
	void (QCompetencia::*Organizadores[10])();
	CQSisGimnasio *CQSGimnasio;
	CQSisTipoCompetencia *CQSTCompetencia;
	/*
	CQSisCompetencia *CQSCompetencia;

	*/
private:
	void ConectaSlots();
	void IniciaVariables();
	void OrganizadoresGimnasios();
	void OrganizadoresParticular();
	void FormaCompetencia(CQSisCompetencia **);
private slots:
	void SlotPasaFocoDescripcion();
	void SlotPasaFocoFecha();
	void SlotPasaFocoFechaInicio();
	void SlotPasaFocoFechaFin();
	void SlotPasaFocoOrganizador();
	void SlotOrganizador(int);
	void SlotRegistrar();

	void SlotPasaFocoTipoCompetencia();
	void SlotTipoCompetencia(CQSisTipoCompetencia *);
};
extern "C" QCompetencia *InstanciaCompetencia(void *,void *,void *,const char *,int);
#endif
