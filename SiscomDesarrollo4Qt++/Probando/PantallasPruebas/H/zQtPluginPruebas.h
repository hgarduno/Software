#ifndef __ZQTPLUGINPRUEBAS_H__
#define __ZQTPLUGINPRUEBAS_H__
#include <qwidgetplugin.h>
class zQtPluginPruebas:public QWidgetPlugin
{
public:
	zQtPluginPruebas();

    QStringList keys() const;
    QWidget* create( const QString &classname, QWidget* parent = 0, const char* name = 0 );
    QString group( const QString& ) const;
    QIconSet iconSet( const QString& ) const;
    QString includeFile( const QString& ) const;
    QString toolTip( const QString& ) const;
    QString whatsThis( const QString& ) const;
    bool isContainer( const QString& ) const;


};

#endif