#ifndef __ZPRUEBAS_H__
#define __ZPRUEBAS_H__
#include <Pruebas.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
class QT_WIDGET_PLUGIN_EXPORT zPruebas:public Pruebas
{
Q_OBJECT
public:
	zPruebas(QWidget *pQWParent=0,
		 const char *pchrPtrName=0);


};

#endif
