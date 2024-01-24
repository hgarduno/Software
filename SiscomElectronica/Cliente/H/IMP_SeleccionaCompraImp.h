
#ifndef __IMP_SELECCIONACOMPRAIMP_H__
#define __IMP_SELECCIONACOMPRAIMP_H__
#include <UIC_H_SeleccionaCompraImp.h>
#include <zComprasImportacion.h>
class zSiscomConexion;
class zCompraImportacion;
class QSeleccionaCompraImp:public SeleccionaCompraImp
{
 Q_OBJECT
public:
	QSeleccionaCompraImp(char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QSeleccionaCompraImp();
	zCompraImportacion *CompraImportacion();
	int Aceptar();
private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zComprasImportacion zCompsImportacion;
	zCompraImportacion *zComImportacion;
	int intAceptar;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consulta();
	void Consultando();
        void Muestra();
private slots:
	void SlotSelecciono(int,int,int,const QPoint &);
	void SlotAceptar();
};
#endif
