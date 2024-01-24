
#ifndef __IMP_TRANSFERENCIAEXPENDIOAEXPENDIO_H__
#define __IMP_TRANSFERENCIAEXPENDIOAEXPENDIO_H__
#include <UIC_H_TransferenciaExpendioAExpendio.h>
#include <zProductosTransferir.h>
class SiscomDatCom;
class SiscomRegistro3;

class zSiscomConexion;
class zSiscomRegistro;
class QTransferenciaExpendioAExpendio:public TransferenciaExpendioAExpendio
{
 Q_OBJECT
public:
	QTransferenciaExpendioAExpendio(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QTransferenciaExpendioAExpendio();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	SiscomRegistro3 *SisReg3ExpendioO;
	SiscomRegistro3 *SisReg3ExpendioD;
	zSiscomRegistro *zSisRegProducto;
	zSiscomRegistro *zSisRegExiExpOrigenDestino;
	zProductosTransferir zProdsTransferir;
private:
	void ConectaSlots();
	void IniciaVariables();
	void HabilitaDesHabilitaProductos();
	int ConsultandoExistenciaExpendioDestinoOrigen();
	int ConsultaExistenciaExpendioDestinoOrigen();
	void MuestraConsultaExistenciaExpendioDestinoOrigen();
	void AnalizandoExistencia();
	void ValidandoDatosTransferencia();
	int SePuedeTransferirLaCantidad();
	void AnexarProductoTransferencia();
	void MuestraProductosTransferir();
	void EnviaTransferencia();
	void AgregaDatosTransferencia();
	void EnviandoTransferencia();
	void CambiaCantidad(int pintNProducto);
	void LiberaDespuesRegistro();
	void ExpendioSinConexion();
private slots:
	void SlotExpendioO(SiscomRegistro3 *pSiscomReg3ExpOrigen);
	void SlotExpendioD(SiscomRegistro3 *pSiscomReg3ExpDestino);
	void SlotProducto(zSiscomRegistro *pzSisRegProducto);
	void SlotCapturoCantidad();
	void SlotAnexar();
	void SlotRegistrar();
	void SlotSeleccionaProducto(int,int,int,const QPoint &);
	void SlotEliminaProducto();
};
extern "C" QTransferenciaExpendioAExpendio *InstanciaTransferenciaExpendioAExpendio(void *,char **,void *,const char *,int);
#endif
