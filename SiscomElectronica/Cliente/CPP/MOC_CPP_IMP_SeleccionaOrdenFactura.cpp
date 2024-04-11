/****************************************************************************
** QSeleccionaOrdenFactura meta object code from reading C++ file 'IMP_SeleccionaOrdenFactura.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SeleccionaOrdenFactura.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSeleccionaOrdenFactura::className() const
{
    return "QSeleccionaOrdenFactura";
}

QMetaObject *QSeleccionaOrdenFactura::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSeleccionaOrdenFactura( "QSeleccionaOrdenFactura", &QSeleccionaOrdenFactura::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSeleccionaOrdenFactura::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeleccionaOrdenFactura", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSeleccionaOrdenFactura::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeleccionaOrdenFactura", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSeleccionaOrdenFactura::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SeleccionaOrdenFactura::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAFechaInicio", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoAFechaFin", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoAConsultar", 0, 0 };
    static const QUMethod slot_3 = {"SlotConsultar", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "pintOrden", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotOrden", 4, param_slot_4 };
    static const QUMethod slot_5 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_6 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_7 = {"SlotReEnviar", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"SlotCapturandoNoOrden", 1, param_slot_8 };
    static const QUMethod slot_9 = {"SlotCapturoNoOrden", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAFechaInicio()", &slot_0, QMetaData::Private },
	{ "SlotFocoAFechaFin()", &slot_1, QMetaData::Private },
	{ "SlotFocoAConsultar()", &slot_2, QMetaData::Private },
	{ "SlotConsultar()", &slot_3, QMetaData::Private },
	{ "SlotOrden(int,int,int,const QPoint&)", &slot_4, QMetaData::Private },
	{ "SlotAceptar()", &slot_5, QMetaData::Private },
	{ "SlotCancelar()", &slot_6, QMetaData::Private },
	{ "SlotReEnviar()", &slot_7, QMetaData::Private },
	{ "SlotCapturandoNoOrden(const QString&)", &slot_8, QMetaData::Private },
	{ "SlotCapturoNoOrden()", &slot_9, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSeleccionaOrdenFactura", parentObject,
	slot_tbl, 10,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSeleccionaOrdenFactura.setMetaObject( metaObj );
    return metaObj;
}

void* QSeleccionaOrdenFactura::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSeleccionaOrdenFactura" ) )
	return this;
    return SeleccionaOrdenFactura::qt_cast( clname );
}

bool QSeleccionaOrdenFactura::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAFechaInicio(); break;
    case 1: SlotFocoAFechaFin(); break;
    case 2: SlotFocoAConsultar(); break;
    case 3: SlotConsultar(); break;
    case 4: SlotOrden((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 5: SlotAceptar(); break;
    case 6: SlotCancelar(); break;
    case 7: SlotReEnviar(); break;
    case 8: SlotCapturandoNoOrden((const QString&)static_QUType_QString.get(_o+1)); break;
    case 9: SlotCapturoNoOrden(); break;
    default:
	return SeleccionaOrdenFactura::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSeleccionaOrdenFactura::qt_emit( int _id, QUObject* _o )
{
    return SeleccionaOrdenFactura::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSeleccionaOrdenFactura::qt_property( int id, int f, QVariant* v)
{
    return SeleccionaOrdenFactura::qt_property( id, f, v);
}

bool QSeleccionaOrdenFactura::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
