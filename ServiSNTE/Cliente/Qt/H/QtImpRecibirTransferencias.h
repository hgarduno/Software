#ifndef __QTIMPRECIBIRTRANSFERENCIAS_H__
#define __QTIMPRECIBIRTRANSFERENCIAS_H__
#include <cstddef>
#include <RecibirTransferencias.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zTransferencia;
class QtImpRecibirTransferencias:public RecibirTransferencias
{
Q_OBJECT
public:
	QtImpRecibirTransferencias(QWidget *pQWParent,
			  const char *pchrPtrName);
    void MostrarTransferenciasTabla();
    void MostrarDatosTransferencia(const char *pchrPtrTransferencia);
public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
	void IniciaVariables();
    void Reinicia();
private:
	zSiscomConexion *zSisConexion;
    zTransferencia *pzTransferencia;
    zSiscomRegistros *zSisRegTransferencias;
    zSiscomRegistro *zSisRegTransferencia;
    zSiscomRegistros *lzSisRegsProductos;
    zSiscomRegistros *zSisRegsTransferenciaSeleccionada;
private slots:
    void SlotMuestraContenidoTransferencia(int pintFila,
                         int pintColumna,
                         int,
                         const QPoint &);
    void SlotRecibirTransferencia();
    void SlotRecibirParcialTransferencia();
    void SlotActualizar();
};
#endif
