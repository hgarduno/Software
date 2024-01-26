#ifndef __ZSISCOMVENTANA_H__
#define __ZSISCOMVENTANA_H__
#include <zSiscomModulosMenus.h>
#include <qmainwindow.h>

class zSiscomMenusVentana;
class zSiscomMenus;
class zSiscomMenu;
class zSiscomQAction;
class zSiscomConfiguracion;
class zSiscomConexion;
class QPopupMenu;
class QWorkspace;
class zSiscomVentana:public QMainWindow
{
Q_OBJECT
public:
	zSiscomVentana(QWidget *pQWParent=0,
		       const char *pchrPtrName=0,
		       WFlags pwFlags=WType_TopLevel);

	zSiscomVentana(zSiscomConexion *pzSisConexion,
			QWidget *pQWParent=0,
		       const char *pchrPtrName=0,
		       WFlags pwFlags=WType_TopLevel);
	void Menus(zSiscomMenusVentana *pzSisMenusVentana);
	void MuestraMenus();
	QPopupMenu *FormaMenu(zSiscomMenus *pzSisMenus);
	zSiscomQAction *OpcionMenu(zSiscomMenu *pzSisMenu);
	void AreaTrabajo(QWorkspace *pQWSAreaTrabajo);
	void Configuracion(zSiscomConfiguracion *pzSisConfiguracion);
	virtual void AreaTrabajo();
	void Conexion(zSiscomConexion *pzSisConexion);
	void CargaModulo(zSiscomMenu *);

private:
	zSiscomMenusVentana *zSisMenusVentana;
	zSiscomConfiguracion *zSisConfiguracion;
	QWorkspace *QWSAreaTrabajo;
	zSiscomConexion *zSisConexion;
	zSiscomModulosMenus zSisModsMens;
private slots:
	void SlotSelecciono(zSiscomQAction *);
	void SlotInicioPantalla(zSiscomConexion *pzSisConexion);
};

#endif


