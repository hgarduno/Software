#ifndef __QTINVENTARIOBODEGA4_H__
#define __QTINVENTARIOBODEGA4_H__
#include <UIC_H_InventarioBodega4.h>


class zSiscomConexion;
class zSiscomRegistro;
class zExistenciaBodega;
class zBodega;
class QtInventarioBodega4:public InventarioBodega4
{
Q_OBJECT
public:
	QtInventarioBodega4(QWidget *,const char *,WFlags );
	void IniciaVariables();
	void Conexion(zSiscomConexion *);
	void ConectaSlots();
	void Bodega(zBodega *);
	void Argumentos(char **);
	zSiscomConexion *Conexion();
	zBodega *Bodega();
	char **Argumentos();
	zExistenciaBodega *ExistenciaBodega();
	void MostrandoExistencia();
	void FocoAProductos();
public:
	virtual void ConsultandoExistencia();
	virtual void Actualizando();
private:
	zSiscomConexion *zSisConexion;
	zBodega *zBodegaE;
	zExistenciaBodega *zExistenciaB;
	char **chrPtrArgumentos;
private:
	void MuestraProducto(zSiscomRegistro *);
	void MuestraExistencia();
	void IniciaControl();
	void IniciandoVariables();
	void AsignaProducto(zSiscomRegistro *);
	void AgregaProductoActualizado();
private slots:
	void SlotProducto(zSiscomRegistro *pzSisRegProducto);
	void SlotCantidad();
	void SlotActualiza();
public slots:
};

#endif
