#ifndef __QCTRLCLINICA_H__
#define __QCTRLCLINICA_H__
#include <qwidget.h>
#include <qwidgetplugin.h>

class QT_WIDGET_PLUGIN_EXPORT QCtrlClinicas: public QWidget
{
    Q_OBJECT
public:
    QCtrlClinicas( QWidget *parent = 0, const char *name = 0);
};

#endif

