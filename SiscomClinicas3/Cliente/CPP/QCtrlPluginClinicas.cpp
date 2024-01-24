
#include <QCtrlPluginClinicas.h>
#include <QCtrlClinicas.h>
#include <QSisExpediente.h>
#include <QSisResultadosGen.h>
#include <QSisImporteServicios.h>
#include <QSisEstsMedico.h>
#include <QSisPacientes.h>

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

QCtrlPluginClinicas::QCtrlPluginClinicas()
{
}

QStringList QCtrlPluginClinicas::keys() const
{
    QStringList list;
    list 			<< 
    "QCtrlClinicas"		<<
    "QSisExpediente"		<<
    "QSisResultadosGen"		<<
    "QSisImporteServicios"	<<
    "QSisEstsMedico"		<<
    "QSisPacientes";
    return list;
}

QWidget* QCtrlPluginClinicas::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlClinicas" )
	return new QCtrlClinicas( parent, name );
    if ( key == "QSisExpediente" )
	return new QSisExpediente( parent, name );
   
    if ( key == "QSisResultadosGen" )
	return new QSisResultadosGen( parent, name );
    if ( key == "QSisImporteServicios" )
	return new QSisImporteServicios( parent, name );
    if ( key == "QSisEstsMedico" )
	return new QSisEstsMedico( parent, name );
    if ( key == "QSisPacientes" )
	return new QSisPacientes( parent, name );
    return 0;
}

QString QCtrlPluginClinicas::group( const QString& feature ) const
{
    if ( feature == "QCtrlClinicas" )
	return "Siscom Clinicas3";
    if ( feature == "QSisExpediente" )
	return "Siscom Clinicas3";
    if ( feature == "QSisResultadosGen" )
	return "Siscom Clinicas3";
    if ( feature == "QSisImporteServicios" )
	return "Siscom Clinicas3";
    if ( feature == "QSisEstsMedico" )
	return "Siscom Clinicas3";
    if ( feature == "QSisPacientes" )
	return "Siscom Clinicas3";
    return QString::null;
}

QIconSet QCtrlPluginClinicas::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginClinicas::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlClinicas" )
	return "QCtrlClinicas.h";
    if ( feature == "QSisExpediente" )
	return "QSisExpediente.h";
    if ( feature == "QSisResultadosGen" )
	return "QSisResultadosGen.h";
    if ( feature == "QSisImporteServicios" )
	return "QSisImporteServicios.h";
    if ( feature == "QSisEstsMedico" )
	return "QSisEstsMedico.h";
    if ( feature == "QSisPacientes" )
	return "QSisPacientes.h";
    return QString::null;
}

QString QCtrlPluginClinicas::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlClinicas" )
	return "File Chooser Widget";
    if ( feature == "QSisExpediente" )
	return "File Chooser Widget";
    if ( feature == "QSisResultadosGen" )
	return "File Chooser Widget";
    if ( feature == "QSisImporteServicios" )
	return "File Chooser Widget";
    if ( feature == "QSisEstsMedico" )
	return "File Chooser Widget";
    if ( feature == "QSisPacientes" )
	return "Pacientes Por Estado Consulta";
    return QString::null;
}

QString QCtrlPluginClinicas::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlClinicas" )
	return "A widget to choose a file or directory";
    if ( feature == "QSisExpediente" )
	return "A widget to choose a file or directory";
    if ( feature == "QSisResultadosGen" )
	return "A widget to choose a file or directory";
    if ( feature == "QSisImporteServicios" )
	return "A widget to choose a file or directory";
    if ( feature == "QSisEstsMedico" )
	return "A widget to choose a file or directory";
    if ( feature == "QSisPacientes" )
	return "Pacientes por estado de consulta";
    return QString::null;
}

bool QCtrlPluginClinicas::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginClinicas )

