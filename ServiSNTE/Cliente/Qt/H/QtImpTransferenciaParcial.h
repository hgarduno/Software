#ifndef __QTIMPTRANSFERENCIAPARCIAL_H__
#define __QTIMPTRANSFERENCIAPARCIAL_H__
#include <cstddef>
#include <TransferenciaParcial.h>

class zSiscomConexion;
class zSiscomRegistros;
class QtImpTransferenciaParcial:public TransferenciaParcial
{
Q_OBJECT
public:
	QtImpTransferenciaParcial(QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false,
              zSiscomRegistros *pzSisRegsProductosTransferencia=0);
	int Aceptar();
private:
    void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
    void IniciaVariables(zSiscomRegistros *pzProductos);
    void MandaProductosSeleccionados();
    zSiscomRegistros *ObtenListaProductosSeleccionados(bool);
    zSiscomRegistros *ObtenListaProductosADevolucion();
private:
    zSiscomConexion *zSisConexion;
	int intAceptar;
    zSiscomRegistros *pzSisRegsProdTrans;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
    void SlotContenidosTabla(int pintFila,
                         int pintColumna,
                         int,
                         const QPoint &);
    void SlotCheckTabla(int pintFila,
                         int pintColumna);
};
#endif
