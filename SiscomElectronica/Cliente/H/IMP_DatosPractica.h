
#ifndef __IMP_DATOSPRACTICA_H__
#define __IMP_DATOSPRACTICA_H__
#include <UIC_H_DatosPractica.h>
class zSiscomConexion;
class zSiscomRegistro;
class QDatosPractica:public DatosPractica
{
 Q_OBJECT
public:
	QDatosPractica(zSiscomConexion *,
			zSiscomRegistro *pzSisRegEscuela,QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=0,
	    WFlags pWFlags=0);
	~QDatosPractica();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegEscuela;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
