/****************************************************************************
** QtImpRecibirTransferencias meta object code from reading C++ file 'QtImpRecibirTransferencias.h'
**
** Created: Sat Feb 22 23:13:28 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRecibirTransferencias.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRecibirTransferencias::className() const
{
    return "QtImpRecibirTransferencias";
}

QMetaObject *QtImpRecibirTransferencias::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRecibirTransferencias( "QtImpRecibirTransferencias", &QtImpRecibirTransferencias::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRecibirTransferencias::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRecibirTransferencias", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRecibirTransferencias::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRecibirTransferencias", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRecibirTransferencias::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RecibirTransferencias::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pintFila", &static_QUType_int, 0, QUParameter::In },
	{ "pintColumna", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotMuestraContenidoTransferencia", 4, param_slot_0 };
    static const QUMethod slot_1 = {"SlotRecibirTransferencia", 0, 0 };
    static const QUMethod slot_2 = {"SlotRecibirParcialTransferencia", 0, 0 };
    static const QUMethod slot_3 = {"SlotActualizar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotMuestraContenidoTransferencia(int,int,int,const QPoint&)", &slot_0, QMetaData::Private },
	{ "SlotRecibirTransferencia()", &slot_1, QMetaData::Private },
	{ "SlotRecibirParcialTransferencia()", &slot_2, QMetaData::Private },
	{ "SlotActualizar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpRecibirTransferencias", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRecibirTransferencias.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRecibirTransferencias::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRecibirTransferencias" ) )
	return this;
    return RecibirTransferencias::qt_cast( clname );
}

bool QtImpRecibirTransferencias::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotMuestraContenidoTransferencia((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 1: SlotRecibirTransferencia(); break;
    case 2: SlotRecibirParcialTransferencia(); break;
    case 3: SlotActualizar(); break;
    default:
	return RecibirTransferencias::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpRecibirTransferencias::qt_emit( int _id, QUObject* _o )
{
    return RecibirTransferencias::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRecibirTransferencias::qt_property( int id, int f, QVariant* v)
{
    return RecibirTransferencias::qt_property( id, f, v);
}

bool QtImpRecibirTransferencias::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
