#ifndef __QTIMPFOLIOAPARTADO_H__
#define __QTIMPFOLIOAPARTADO_H__
#include <cstddef>
#include <FolioApartado.h>

class zSiscomConexion;
class zSiscomRegistro;
class zFolio;
class QtImpFolioApartado:public FolioApartado
{
Q_OBJECT
public:
	QtImpFolioApartado(QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  WFlags pWFlags=false);
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaVariables();
	zFolio *Folio();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistro *zSisRegTipoFolio;
private slots:
	void SlotTienda(zSiscomRegistro *pzSisRegTienda);
	void SlotFocoAFolioFin();
	void SlotFocoARegistrar();
	void SlotRegistrar();
	void SlotTipoFolio(zSiscomRegistro *pzSisRegTipoFolio);
};



#endif
