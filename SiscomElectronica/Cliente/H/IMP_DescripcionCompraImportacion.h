
#ifndef __IMP_DESCRIPCIONCOMPRAIMPORTACION_H__
#define __IMP_DESCRIPCIONCOMPRAIMPORTACION_H__
#include <UIC_H_DescripcionCompraImportacion.h>
class QDescripcionCompraImportacion:public DescripcionCompraImportacion
{
 Q_OBJECT
public:
	QDescripcionCompraImportacion(char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QDescripcionCompraImportacion();
private:
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
extern "C" QDescripcionCompraImportacion *InstanciaDescripcionCompraImportacion(void *,char **,void *,const char *,int);
#endif
