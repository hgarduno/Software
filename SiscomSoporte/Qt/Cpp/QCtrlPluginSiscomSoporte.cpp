#include <QCtrlPluginSiscomSoporte.h>




#include <zSiscomDesarrollo4.h>

#include <QtCorteCajaImp.h>

FILE *gPtrFleArchivoLog3Qt;

void *gzSiscomConexion;
FILE *gPtrFleArchivoLog;



static const char *filechooser_pixmap[] = {
    "22 22 8 1",
    "  c Gray100",
    ". c Gray97",
    "X c #4f504f",
    "o c #00007f",
    "O c Gray0",
    "+ c none",
    "@ c Gray0",
    "# c Gray0",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "+OOOOOOOOOOOOOOOOOOOO+",
    "OOXXXXXXXXXXXXXXXXXXOO",
    "OXX.          OO OO  O",
    "OX.      oo     O    O",
    "OX.      oo     O   .O",
    "OX  ooo  oooo   O    O",
    "OX    oo oo oo  O    O",
    "OX  oooo oo oo  O    O",
    "OX oo oo oo oo  O    O",
    "OX oo oo oo oo  O    O",
    "OX  oooo oooo   O    O",
    "OX            OO OO  O",
    "OO..................OO",
    "+OOOOOOOOOOOOOOOOOOOO+",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++"
};

QCtrlPluginSiscomSoporte::QCtrlPluginSiscomSoporte()
{

}
QStringList QCtrlPluginSiscomSoporte::keys() const
{
    QStringList list;
   
    list << 
    "QtCorteCajaImp";

  return list;
}
QWidget *QCtrlPluginSiscomSoporte::create(const QString &key,
					     QWidget *parent,
					     const char *name)
{
     if( key == "QtCorteCajaImp")
      return new QtCorteCajaImp(parent,name);
}
QString QCtrlPluginSiscomSoporte::group( const QString& feature ) const
{
     if( feature == "QtCorteCajaImp" ) 
      return "Siscom Electronica Soporte";

 return QString::null;
}

QIconSet QCtrlPluginSiscomSoporte::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}
QString QCtrlPluginSiscomSoporte::includeFile( const QString& feature ) const
{
	if(feature=="QtCorteCajaImp")
	 return "QtCorteCajaImp.h";
return QString::null;
}

QString QCtrlPluginSiscomSoporte::toolTip( const QString& feature ) const
{

	if(feature=="QtCorteCajaImp")
	 return "Corte Caja";

return QString::null;
}

QString QCtrlPluginSiscomSoporte::whatsThis( const QString& feature ) const
{
     if( feature=="QtCorteCajaImp") 
      return "Siscom Electronica Soporte";

return QString::null;
}
bool QCtrlPluginSiscomSoporte::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginSiscomSoporte )

