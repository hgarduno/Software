
#ifndef __IMP_PRODUCTOSFALTANTES_H__
#define __IMP_PRODUCTOSFALTANTES_H__
#include <UIC_H_ProductosFaltantes.h>
#include <CQSisProductosFaltantes.h>
class SiscomDatCom;
class QProductosFaltantes:public ProductosFaltantes
{
 Q_OBJECT
public:
	QProductosFaltantes(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QProductosFaltantes();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisProductosFaltantes CQSProdsFaltantes;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
private slots:
	void SlotFaltantes();
};
extern "C" QProductosFaltantes *InstanciaProductosFaltantes(void *,char **,void *,const char *,int);
#endif
