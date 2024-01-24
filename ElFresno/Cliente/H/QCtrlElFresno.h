#ifndef __QCTRLELFRESNO_H__
#define __QCTRLELFRESNO_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>

class QIconView;
class QHBoxLayout;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlElFresnos: public QWidget
{
    Q_OBJECT
public:
    QCtrlElFresnos( QWidget *parent = 0, const char *name = 0);
private slots:
signals:
};

#endif

