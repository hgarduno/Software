/****************************************************************************
** QFirmaTiendas meta object code from reading C++ file 'IMP_FirmaTiendas.h'
**
** Created: Fri Apr 12 21:34:41 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_FirmaTiendas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QFirmaTiendas::className() const
{
    return "QFirmaTiendas";
}

QMetaObject *QFirmaTiendas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFirmaTiendas( "QFirmaTiendas", &QFirmaTiendas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFirmaTiendas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFirmaTiendas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFirmaTiendas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFirmaTiendas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFirmaTiendas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = FirmaTiendas::staticMetaObject();
    static const QUMethod slot_0 = {"S_AnexarServidor", 0, 0 };
    static const QUMethod slot_1 = {"S_EliminarServidor", 0, 0 };
    static const QUMethod slot_2 = {"S_Aceptar", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_3 = {"S_SeleccionoServidor", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_4 = {"S_SeleccionoExpendio", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_5 = {"S_SeleccionaEmpleado", 1, param_slot_5 };
    static const QUMethod slot_6 = {"S_SeleccionarLetra", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_AnexarServidor()", &slot_0, QMetaData::Private },
	{ "S_EliminarServidor()", &slot_1, QMetaData::Private },
	{ "S_Aceptar()", &slot_2, QMetaData::Private },
	{ "S_SeleccionoServidor(QIconViewItem*)", &slot_3, QMetaData::Private },
	{ "S_SeleccionoExpendio(QIconViewItem*)", &slot_4, QMetaData::Private },
	{ "S_SeleccionaEmpleado(QIconViewItem*)", &slot_5, QMetaData::Private },
	{ "S_SeleccionarLetra()", &slot_6, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QFirmaTiendas", parentObject,
	slot_tbl, 7,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFirmaTiendas.setMetaObject( metaObj );
    return metaObj;
}

void* QFirmaTiendas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFirmaTiendas" ) )
	return this;
    return FirmaTiendas::qt_cast( clname );
}

bool QFirmaTiendas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_AnexarServidor(); break;
    case 1: S_EliminarServidor(); break;
    case 2: S_Aceptar(); break;
    case 3: S_SeleccionoServidor((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 4: S_SeleccionoExpendio((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 5: S_SeleccionaEmpleado((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 6: S_SeleccionarLetra(); break;
    default:
	return FirmaTiendas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QFirmaTiendas::qt_emit( int _id, QUObject* _o )
{
    return FirmaTiendas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QFirmaTiendas::qt_property( int id, int f, QVariant* v)
{
    return FirmaTiendas::qt_property( id, f, v);
}

bool QFirmaTiendas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
