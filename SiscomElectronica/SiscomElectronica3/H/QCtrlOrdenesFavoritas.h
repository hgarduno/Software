#ifndef __QCTRLORDENESFAVORITAS_H__
#define __QCTRLORDENESFAVORITAS_H__
#include <qgroupbox.h>
#include <qwidgetplugin.h>
#include <QtSisBotonOrdenList.h>
#include <zOrdenesFavoritas.h>

#include <zOrdenVenta.h>
class QtSisBotonOrden;
class zSiscomConexion;
class zOrdenFavorita;
class zOrdenVenta;

class QT_WIDGET_PLUGIN_EXPORT QCtrlOrdenesFavoritas:public QGroupBox
{
Q_OBJECT
public:
	QCtrlOrdenesFavoritas(QWidget *pQWParent=0,const char *pchrPtrName=0);
  	void AgregaBotonOrden(QtSisBotonOrden *);
  	void AgregaBotonOrden();
	void HabilitaBotones(bool);
	void HabilitaBotones(QtSisBotonOrden *,bool);
	void HabilitaBotonesSiTieneOrden();
	void IniciaControl();
	void Servidor(zSiscomConexion *);
	void ModoControl(int );
	int ModoControl();
	void ReConsulta();
	QtSisBotonOrden *BotonOrden();
	QtSisBotonOrden *BotonOrden(zOrdenFavorita *);
	QtSisBotonOrden *BotonOrden(const char *pchrPtrTexto,const char *pchrPtrIdOrden);
public slots:
	void SlotOrden();
signals:
	void SignalOrden(QtSisBotonOrden *);
	void SignalOrdenVenta(zOrdenVenta *);
	void SignalEliminaOrden(QtSisBotonOrden *);
private:
	int Consulta();
	int Consultando();
	void AgregandoBotones();
	int ObtenOrdenVenta(const char *pchrPtrIdOrden);
private:
	QtSisBotonOrdenList QtSisBtnOrdenL;
	zSiscomConexion *zSisConexion;
	zOrdenesFavoritas *zOrdsFavoritas;
	int intModoControl;
	zOrdenVenta *zOrdVenta;

};

#endif
