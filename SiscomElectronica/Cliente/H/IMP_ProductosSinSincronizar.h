
#ifndef __IMP_PRODUCTOSSINSINCRONIZAR_H__
#define __IMP_PRODUCTOSSINSINCRONIZAR_H__
#include <UIC_H_ProductosSinSincronizar.h>
#include <CQSisProductoNoSincronizado.h>
class SiscomDatCom;
class QProductosSinSincronizar:public ProductosSinSincronizar
{
 Q_OBJECT
public:
	QProductosSinSincronizar(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QProductosSinSincronizar();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisProductoNoSincronizado CQSPNSincronizado;
	SiscomRegistro4 SisReg4EdoRegistro;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoProductos();
	void ConsultaProductos();
	void MuestraProductos();
private slots:
	void SlotRegistra();
};
extern "C" QProductosSinSincronizar *InstanciaProductosSinSincronizar(void *,char **,void *,const char *,int);
#endif
