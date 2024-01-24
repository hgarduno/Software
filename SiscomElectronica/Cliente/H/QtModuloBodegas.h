
#ifndef __QTMODULOBODEGAS_H__
#define __QTMODULOBODEGAS_H__
#include <UIC_H_ModuloBodegas.h>

class zSiscomConexion;
class QInventarioBodega4;
class QTransfiereBodegaBodega;
class zBodega;
class QtModuloBodegas:public ModuloBodegas
{
Q_OBJECT
public:
	QtModuloBodegas(char **pchrPtrArgumentos,
			QWidget *,
			const char *,
			WFlags);
public:
	void ConectaSlots();
	void IniciaVariables();
	void Conexion(zSiscomConexion *);
	void AgregaOperacion(QWidget *,const QString &);
private:
	zSiscomConexion *zSisConexion;
	QWidget *QWParent;
	QInventarioBodega4 *QInvBodega4;
	QTransfiereBodegaBodega *QTransfiereBB;
	zBodega *zBodegaA;
private:
	void IniciaOperaciones();
	QInventarioBodega4 *InventarioBodega();
	QTransfiereBodegaBodega *TransfiereBodegaBodega();
	void EliminaInicio();
	void IniciaControles();
	zBodega *Bodega();
	void AsignaBodega(zBodega *);
	bool BodegaValida();
	void ActivaOperacion();
	void BodegaAOperaciones();
public slots:
	void SlotBodega(zBodega *);
	void SlotOperacion(QWidget *);
};

#endif
