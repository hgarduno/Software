#ifndef __QCTRLEXPENDIOSSE_H__
#define __QCTRLEXPENDIOSSE_H__

#include <qwidget.h>
#include <qiconview.h>
#include <qwidgetplugin.h>
#include <zExpendio.h>

#include <zExpendios.h>

class QHBoxLayout;
class QIconView;
class zSiscomConexion;

class QIconViewItemExpendioSE:public QIconViewItem
{
public:
	QIconViewItemExpendioSE(zExpendio *,QIconView *);
	zExpendio *Expendio();
private:
	zExpendio *zExpSiscom;
};

class  QT_WIDGET_PLUGIN_EXPORT QCtrlExpendiosSE:public QWidget 
{
Q_OBJECT
public:
	QCtrlExpendiosSE(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *pzSiscomConexion);

	void IniciaControl();

	void Expendio(const char *);
	void setFocus();
private:
	void IniciaVariables();
	void ConectaSlots();
	void ConsultaExpendios();
	void MuestraExpendios();
private:
	QIconView *QIVExpendios;
	QHBoxLayout *QHBLayout;
	const char *chrPtrIdExpendio;
	zSiscomConexion *zSisConexion;
	zExpendios zExpsSiscom;
private slots:
	void SlotExpendio(QIconViewItem *);
signals:
	void SignalExpendio(zExpendio *);

};

#endif

