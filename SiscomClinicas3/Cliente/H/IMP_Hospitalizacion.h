
#ifndef __IMP_HOSPITALIZACION_H__
#define __IMP_HOSPITALIZACION_H__
#include <UIC_H_Hospitalizacion.h>
#include <CQSisCotizando.h>
#include <CQSisMatHosp.h>
class SiscomDatCom;
class SisUsuarioSeg3;
class CQSisServicio;
class CQSisConsulta;
class CQSisPrecio;
class CQSisCliente;
class CQSisFormaPago;
class CQSisProducto;
class CQSisProdCotiza;
class CQSisContacto;
class QHospitalizacion:public Hospitalizacion
{
 Q_OBJECT
public:
	QHospitalizacion(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QHospitalizacion();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SisUsuarioSeg3 *SUSeg3Firmado;
	CQSisPrecio *CQSPrecio;
	CQSisConsulta *CQSConsulta;
	CQSisLstCotizando CQSLCotizando;
	CQSisProdCotiza *CQSPCFarmacia;
	CQSisLstMatHosp CQSLMHosp;

private:
	void ConectaSlots();
	void IniciaVariables();
	void IniciaServicios();
	CQSisCotizando *Servicio(CQSisServicio *);
	CQSisCotizando *Servicio(CQSisProdCotiza *);
	void MuestraCotizacion();
	void CotizandoConsulta();
	void CotizaConsulta();
	void Registra();
	void RegistraMaterialServicios();
	void ConsultaConsulta();
	void ConsultandoConsulta();
	void RegistraMaterialSesion();
private slots:
	void SlotServicioGeneral(CQSisServicio *);
	void SlotServicioMedico(CQSisServicio *);
	void SlotConsulta(CQSisConsulta *);
	void SlotPrecio(CQSisPrecio *);
	void SlotPasaFocoFechaFin();
	void SlotPasaFocoConsultas();
	void SlotRegistra();
	void SlotCotiza(CQSisCliente *,
			CQSisFormaPago *,
			CQSisPrecio *,
			CQSisProducto *,
			CQSisProdCotiza *,
			CQSisContacto *);
	void SlotAnexarProductoFarmacia();
};
extern "C" QHospitalizacion *InstanciaHospitalizacion(void *,char **,void *,const char *,int);
#endif
