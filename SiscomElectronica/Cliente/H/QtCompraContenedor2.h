#ifndef __QTCOMPRACONTENEDOR2_H__
#define __QTCOMPRACONTENEDOR2_H__
#include <UIC_H_CompraContenedor2.h>
#include <zCompraImportacion.h>
class zSiscomConexion;
class zContenedor;
class QtCompraContenedor2:public CompraContenedor2
{
Q_OBJECT
public:
	QtCompraContenedor2(char **,
			    zSiscomConexion *,
			    QWidget *pQWParent,
			    const char *pchrPtrName,
			    WFlags pWFlags);

private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zCompraImportacion zComImportacion;
	zContenedor *zConteC;
private:
	void ConectaSlots();
	void IniciaVariables();
	void CargandoCompra();
	void ConsultandoCompra(const char *);
	int ConsultaCompra(const char *,char *,zCompraImportacion **);
	void MuestraProductos();
	int EnviaDatos(char *);
	void Calculando();
	void MostrandoCalculos();
	zContenedor *Contenedor();
	void AgregandoFacturaContenedor(zCompraImportacion *,zCompraImportacion *);
	void AgregaFacturaContenedor(zCompraImportacion *);
	void IniciaContenedor();
	void ActualizaNumeroPartidas();
public slots:
	void SlotAgregaFactura();
};

#endif
