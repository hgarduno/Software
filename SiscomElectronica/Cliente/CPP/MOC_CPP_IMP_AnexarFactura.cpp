/****************************************************************************
** QAnexarFactura meta object code from reading C++ file 'IMP_AnexarFactura.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_AnexarFactura.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QAnexarFactura::className() const
{
    return "QAnexarFactura";
}

QMetaObject *QAnexarFactura::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAnexarFactura( "QAnexarFactura", &QAnexarFactura::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAnexarFactura::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAnexarFactura", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAnexarFactura::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAnexarFactura", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAnexarFactura::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = AnexarFactura::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_2 = {"SlotConsultaFactura", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotSeleccionaFactura", 4, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private },
	{ "SlotConsultaFactura()", &slot_2, QMetaData::Private },
	{ "SlotSeleccionaFactura(int,int,int,const QPoint&)", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QAnexarFactura", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAnexarFactura.setMetaObject( metaObj );
    return metaObj;
}

void* QAnexarFactura::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAnexarFactura" ) )
	return this;
    return AnexarFactura::qt_cast( clname );
}

bool QAnexarFactura::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCancelar(); break;
    case 2: SlotConsultaFactura(); break;
    case 3: SlotSeleccionaFactura((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return AnexarFactura::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QAnexarFactura::qt_emit( int _id, QUObject* _o )
{
    return AnexarFactura::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QAnexarFactura::qt_property( int id, int f, QVariant* v)
{
    return AnexarFactura::qt_property( id, f, v);
}

bool QAnexarFactura::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
