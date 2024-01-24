
#ifndef __IMP_CLIENTESREGISTRADOS_H__
#define __IMP_CLIENTESREGISTRADOS_H__
#include <UIC_H_ClientesRegistrados.h>

class zSiscomRegistros;
class QClientesRegistrados:public ClientesRegistrados
{
 Q_OBJECT
public:
	QClientesRegistrados(
	    zSiscomRegistros *pzSisRegsClientes,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QClientesRegistrados();
private:
	zSiscomRegistros *zSisRegsClientes;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
