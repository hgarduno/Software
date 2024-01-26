#ifndef __QTIMPVISORTRANSFERENCIAS_H__
#define __QTIMPVISORTRANSFERENCIAS_H__
#include <cstddef>
#include <VisorTransferencias.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zTransferencia;
class QtImpVisorTransferencias:public VisorTransferencias
{
Q_OBJECT
public:
	QtImpVisorTransferencias(QWidget *pQWParent,
			  const char *pchrPtrName);
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
private slots:
};
#endif
