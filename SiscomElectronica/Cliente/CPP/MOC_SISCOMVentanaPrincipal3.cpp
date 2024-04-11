/****************************************************************************
** SISCOMVentanaPrincipal meta object code from reading C++ file 'SISCOMVentanaPrincipal3.h'
**
** Created: Wed Apr 10 21:12:10 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/SISCOMVentanaPrincipal3.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SISCOMVentanaPrincipal::className() const
{
    return "SISCOMVentanaPrincipal";
}

QMetaObject *SISCOMVentanaPrincipal::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SISCOMVentanaPrincipal( "SISCOMVentanaPrincipal", &SISCOMVentanaPrincipal::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SISCOMVentanaPrincipal::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SISCOMVentanaPrincipal", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SISCOMVentanaPrincipal::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SISCOMVentanaPrincipal", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SISCOMVentanaPrincipal::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotOperacionVentanas", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotMuestraVentanas", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotMuestraVentana", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SlotOperacionVentanas(int)", &slot_0, QMetaData::Private },
	{ "SlotMuestraVentanas()", &slot_1, QMetaData::Private },
	{ "SlotMuestraVentana(int)", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"SISCOMVentanaPrincipal", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SISCOMVentanaPrincipal.setMetaObject( metaObj );
    return metaObj;
}

void* SISCOMVentanaPrincipal::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SISCOMVentanaPrincipal" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool SISCOMVentanaPrincipal::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotOperacionVentanas((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotMuestraVentanas(); break;
    case 2: SlotMuestraVentana((int)static_QUType_int.get(_o+1)); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool SISCOMVentanaPrincipal::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool SISCOMVentanaPrincipal::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool SISCOMVentanaPrincipal::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *CQSiscomModuloTiendas::className() const
{
    return "CQSiscomModuloTiendas";
}

QMetaObject *CQSiscomModuloTiendas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSiscomModuloTiendas( "CQSiscomModuloTiendas", &CQSiscomModuloTiendas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSiscomModuloTiendas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSiscomModuloTiendas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSiscomModuloTiendas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSiscomModuloTiendas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSiscomModuloTiendas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCargaOpcion", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCargaOpcion()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSiscomModuloTiendas", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSiscomModuloTiendas.setMetaObject( metaObj );
    return metaObj;
}

void* CQSiscomModuloTiendas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSiscomModuloTiendas" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool CQSiscomModuloTiendas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCargaOpcion(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSiscomModuloTiendas::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CQSiscomModuloTiendas::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool CQSiscomModuloTiendas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
