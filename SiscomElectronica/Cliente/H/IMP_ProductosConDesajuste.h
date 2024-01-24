
#ifndef __IMP_PRODUCTOSCONDESAJUSTE_H__
#define __IMP_PRODUCTOSCONDESAJUSTE_H__
#include <UIC_H_ProductosConDesajuste.h>
class SiscomDatCom;
class QProductosConDesajuste:public ProductosConDesajuste
{
 Q_OBJECT
public:
	QProductosConDesajuste(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QProductosConDesajuste();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
