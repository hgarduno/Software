/****************************************************************************
** QtImpTransferenciaParcial meta object code from reading C++ file 'QtImpTransferenciaParcial.h'
**
** Created: Sat Jan 27 16:39:07 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpTransferenciaParcial.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpTransferenciaParcial::className() const
{
    return "QtImpTransferenciaParcial";
}

QMetaObject *QtImpTransferenciaParcial::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpTransferenciaParcial( "QtImpTransferenciaParcial", &QtImpTransferenciaParcial::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpTransferenciaParcial::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpTransferenciaParcial", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpTransferenciaParcial::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpTransferenciaParcial", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpTransferenciaParcial::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = TransferenciaParcial::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "pintFila", &static_QUType_int, 0, QUParameter::In },
	{ "pintColumna", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotContenidosTabla", 4, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "pintFila", &static_QUType_int, 0, QUParameter::In },
	{ "pintColumna", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotCheckTabla", 2, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotContenidosTabla(int,int,int,const QPoint&)", &slot_3, QMetaData::Private },
	{ "SlotCheckTabla(int,int)", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpTransferenciaParcial", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpTransferenciaParcial.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpTransferenciaParcial::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpTransferenciaParcial" ) )
	return this;
    return TransferenciaParcial::qt_cast( clname );
}

bool QtImpTransferenciaParcial::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotContenidosTabla((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 4: SlotCheckTabla((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return TransferenciaParcial::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpTransferenciaParcial::qt_emit( int _id, QUObject* _o )
{
    return TransferenciaParcial::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpTransferenciaParcial::qt_property( int id, int f, QVariant* v)
{
    return TransferenciaParcial::qt_property( id, f, v);
}

bool QtImpTransferenciaParcial::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
