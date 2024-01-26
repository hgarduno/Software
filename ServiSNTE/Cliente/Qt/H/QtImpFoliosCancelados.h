#ifndef __QTIMPFOLIOSCANCELADOS_H__
#define __QTIMPFOLIOSCANCELADOS_H__
#include <cstddef>
#include <FoliosCancelados.h>
#include <zSiscomRegistros.h>
class zSiscomConexion;
class zSiscomRegistro;
class zFolio;
class QtImpFoliosCancelados:public FoliosCancelados
{
Q_OBJECT
public:
	QtImpFoliosCancelados(QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  WFlags pWFlags=false);
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaVariables();
	zFolio *Folio();

	void Consultando();
	void Consulta();
	void Muestra();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistros *zSisRegsFoliosCancelados;
private slots:
	void SlotTienda(zSiscomRegistro *pzSisRegTienda);
	void SlotMostrar();
	void SlotFechaInicio();
	void SlotFechaFinal();
};



#endif
