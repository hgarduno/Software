#ifndef __QTIMPCONTROLREPLICAS_H__
#define __QTIMPCONTROLREPLICAS_H__
#include <cstddef>
#include <ControlReplicas.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpControlReplicas:public ControlReplicas
{
Q_OBJECT
public:
	QtImpControlReplicas(QWidget *pQWParent,
			  const char *pchrPtrName);
public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
	void IniciaVariables();
    void Reinicia();
private:
	zSiscomConexion *zSisConexion;
    zSiscomRegistros *zSisRegTransferencias;
private slots:
};
#endif
