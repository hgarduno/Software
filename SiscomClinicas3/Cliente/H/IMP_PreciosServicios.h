
#ifndef __IMP_PRECIOSSERVICIOS_H__
#define __IMP_PRECIOSSERVICIOS_H__
#include <UIC_H_PreciosServicios.h>
#include <CQSisPreciosServicios.h>
class SiscomDatCom;
class CQSisPersona;
class CQSisServicio;
class CQSisPrecio;
class QPreciosServicios:public PreciosServicios
{
 Q_OBJECT
public:
	QPreciosServicios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPreciosServicios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisPersona *CQSPersona;
	CQSisServicio *CQSSGeneral;
	CQSisServicio *CQSSMedico;
	CQSisLstPrecioServicio CQSLPServicio;
	CQSisPrecio *CQSPrecio;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ServiciosMedico();
	void MuestraServicio(CQSisServicio *);

	void ConsultandoPreciosServicio();
	void ConsultaPreciosServicio();
	void MuestraPreciosServicio();

	void ConsultandoPreciosServicioMedico();
	void ConsultaPreciosServicioMedico();


	void Actualiza();
	void ActualizaServicioGeneral();
	void ActualizaServicioMedico();
	void HabilitaActualizar();


private slots:
	void SlotMedico(CQSisPersona *);
	void SlotServicioMedico(CQSisServicio *);
	void SlotServicioGeneral(CQSisServicio *);
	void SlotPasaFocoActualiza();
	void SlotActualiza();
	void SlotPrecio(CQSisPrecio *);
};
extern "C" QPreciosServicios *InstanciaPreciosServicios(void *,char **,void *,const char *,int);
#endif
