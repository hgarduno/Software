
#ifndef __IMP_CENTROMEDICO_H__
#define __IMP_CENTROMEDICO_H__
#include <UIC_H_CentroMedico.h>
#include <CQSisConsultas.h>
#include <CQSisCotizando.h>
class SiscomDatCom;
class SisUsuarioSeg3;
class QObservacionesConsulta;
class QReceta;
class QExpedientes;
class QRecetasConsulta;
class CQSisServicio;
class CQSisPrecio;
class CQSisFormaPago;
class CQSisProducto;
class CQSisProdCotiza;
class CQSisContacto;
class CQSisCliente;

class QCentroMedico:public CentroMedico
{
 Q_OBJECT
public:
	QCentroMedico(CQSisConsulta *,
		SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCentroMedico();
private:
	QWidget *QWParent;
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstCotizando CQSLCotizando;
	CQSisConsulta *CQSConsulta;
	SisUsuarioSeg3 *SUSeg3Firmado;
	QExpedientes *QExpediente;
	CQSisPrecio *CQSPrecio;
	CQSisProdCotiza *CQSPCFarmacia;
	int intProdServSeleccionado;
	int intRecetas;
	int intObservaciones;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaConsultas();
	void MuestraConsultas();
	void ConsultaActual();
	void IniciaServicios();
	void CotizaConsulta();
	void CotizandoConsulta();
	void MuestraCotizacion();
	void IniciaPrecios();
	CQSisCotizando *Servicio(CQSisServicio *);
	CQSisCotizando *Servicio(CQSisProdCotiza *);
	void CotizaPerfilMedico();
	void TerminaConsulta();
	void EliminaConsultaActual();
	void HabilitaBotones();
	void Expedientes(CQSisPersona *);
	void HabilitaTerminar();
	void RecetasObservaciones();
	void CambiaConsultaActual(int);
	void show();
private slots:
	void SlotObservaciones();
	void SlotServicioMedico(CQSisServicio *);
	void SlotServicioGeneral(CQSisServicio *);
	void SlotPrecio(CQSisPrecio *);
	void SlotTerminaConsulta();
	void SlotReceta();
	void SlotCotiza(CQSisCliente *,
			    CQSisFormaPago *,
			    CQSisPrecio *,
			    CQSisProducto *,
			    CQSisProdCotiza *,
			    CQSisContacto *);
	void SlotAnexarProductoFarmacia();
	void SlotExpediente();
	void SlotSeleccionandoDetalle(int,int,int,const QPoint &);
	void SlotEliminarServicio();
	void SlotConsulta(int,int,int,const QPoint &);
	void SlotCerroExpediente(CQSisPersona *);
signals:
	void SignalTerminar(QCentroMedico *);
};
//extern "C" QCentroMedico *InstanciaCentroMedico(void *,char **,void *,const char *,int);
#endif
