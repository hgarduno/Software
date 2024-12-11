#ifndef __QTTRANSFIEREBODEGABODEGA_H__
#define __QTTRANSFIEREBODEGABODEGA_H__
#include <UIC_H_TransfiereBodegaBodega.h>
#include <zTransferenciasBodegaBodega.h>

class zSiscomConexion;
class zBodega;
class zSiscomRegistro;
class zTransfiereBodegaBodega;
class zExistenciaBodega;
class QCtrlCmbBodegas4;
class QtTransfiereBodegaBodega:public TransfiereBodegaBodega
{
Q_OBJECT
public:
	QtTransfiereBodegaBodega(QWidget *,const char *,WFlags);
	void Conexion(zSiscomConexion *);

	zSiscomConexion *Conexion();

	void IniciaVariables();
	void IniciandoVariables();
	zTransfiereBodegaBodega *BodegaBodega();

private:
	zSiscomConexion *zSisConexion;
	zBodega *zBodegaD;
	zBodega *zBodegaO;
	zSiscomRegistro *zSisRegProducto;
	zTransfiereBodegaBodega *zTransfiereBB;
	zExistenciaBodega *zExistenciaBO;
	zExistenciaBodega *zExistenciaBD;
	zTransferenciasBodegaBodega zTransBodBod;
	int intNTransferencia;
private:
	const char *Producto();
	void IniciaControles();
	void Conexiones();
	void ConectaSlotBodega(QCtrlCmbBodegas4 *,const char *pchrPtrSlot);
	void ConectaSlots();
	void SeleccionoBodegaOrigen(zBodega *);
	void SeleccionoBodegaDestino(zBodega *);
	void SeleccionoProducto(zSiscomRegistro *);

	void Transfiriendo();
	void FormaBodegaBodega();

	void Existencia(QLineEdit *,zExistenciaBodega *);
	void MuestraExistencia(QLineEdit *,zExistenciaBodega *);

	void ExistenciaOrigen();
	void ExistenciaDestino();
	void ExistenciaBodega(zBodega *);

	zBodega *BodegaD();
	zBodega *BodegaO();
	zExistenciaBodega *IniciaExistenciaBodega(zBodega *);
	void MuestraRegistro();
	void setFocus();

	void ActivaActualiza();
	void HabilitaProductos();
private slots:
	void SlotBodegaO(zBodega *);
	void SlotBodegaD(zBodega *);
	void SlotProducto(zSiscomRegistro *);
	void SlotFocoAActualiza();
	void SlotTransfiere();
	zTransferenciasBodegaBodega &Transferencias();
	void AsignandoTransferencias();
	zExistenciaBodega *BodegaExistenciaO();
	zExistenciaBodega *BodegaExistenciaD();

	void HabilitaDesHabilita(bool);
	void MuestraBodega(QLineEdit *,zBodega *);

public:	
	virtual	void Transfiere();
	virtual void Consultando(zExistenciaBodega *);
	virtual int ValidaExistenciaBodegaO(zExistenciaBodega *);
};

#endif
