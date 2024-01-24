#ifndef __QCTRLBODEGAS4_H__
#define __QCTRLBODEGAS4_H__

#include <qwidget.h>
#include <qiconview.h>
#include <qwidgetplugin.h>

class QHBoxLayout;
class QIconView;
class SiscomDatCom;
class zBodega;
class zBodegas;
class zSiscomConexion;

class QIconViewItemBodega4:public QIconViewItem
{
public:
	QIconViewItemBodega4(zBodega *,QIconView *);
	zBodega *Bodega();
private:
	zBodega *zBodegaE;
};

/*!
 * \brief Clase que contiene la funcionalidad para el manejo <br>
 * de los producto mediante un Combo asi como su seleccion
 */
class QT_WIDGET_PLUGIN_EXPORT QCtrlBodegas4:public QWidget 
{
Q_OBJECT
public:
	QCtrlBodegas4(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *);

	void IniciaControl();
private:
	void IniciaVariables();
	void ConectaSlots();
	void ConsultaBodegas();
	void MuestraBodegas();
private:
	QIconView *QIVBodegas;
	QHBoxLayout *QHBLayout;
	SiscomDatCom *SisDatCom;
	zBodegas *zBodegasE;
	zSiscomConexion *zSisConexion;
private slots:
	void SlotBodega(QIconViewItem *);
signals:
	void SignalBodega(zBodega *);

};

#endif

