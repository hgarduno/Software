#ifndef __IMP_PLUGINCONTROLFECHA_H__
#define __IMP_PLUGINCONTROLFECHA_H__

#include <qwidgetplugin.h>

class PluginControlFecha2:public QWidgetPlugin
{
public:
	PluginControlFecha2();
	QStringList keys() const ;
	QWidget *create(const QString &,QWidget *pQWParent=0,const char *pchrPtrNombre=0);
	QString group(const QString &)const ;
	QIconSet iconSet(const QString &) const ;
	QString includeFile(const QString &) const ;
	QString toolTip(const QString &) const ;
	QString whatsThis(const QString &) const ;
	bool isContainer(const QString &) const ;

};

#endif
