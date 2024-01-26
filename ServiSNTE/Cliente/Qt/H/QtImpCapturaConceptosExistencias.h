#ifndef __QTIMPCAPTURACONCEPTOSEXISTENCIAS_H__
#define __QTIMPCAPTURACONCEPTOSEXISTENCIAS_H__
#include <cstddef>
#include <CapturaConceptosExistencias.h>

class zSiscomConexion;
class zSiscomRegistro;

class QtImpCapturaConceptosExistencias:public CapturaConceptosExistencias
{
Q_OBJECT
public:
	QtImpCapturaConceptosExistencias(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
private:
	zSiscomConexion *zSisConexion;
private slots:

};



#endif
