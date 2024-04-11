/****************************************************************************
** QtImpTransferenciasEnviadas meta object code from reading C++ file 'QtImpTransferenciasEnviadas.h'
**
** Created: Sat Jan 27 16:39:24 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpTransferenciasEnviadas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpTransferenciasEnviadas::className() const
{
    return "QtImpTransferenciasEnviadas";
}

QMetaObject *QtImpTransferenciasEnviadas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpTransferenciasEnviadas( "QtImpTransferenciasEnviadas", &QtImpTransferenciasEnviadas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpTransferenciasEnviadas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpTransferenciasEnviadas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpTransferenciasEnviadas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpTransferenciasEnviadas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpTransferenciasEnviadas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = TransferenciasEnviadas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCapturoRangoFechas", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionoTransferencia", 4, param_slot_1 };
    static const QUMethod slot_2 = {"SlotCopiar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCapturoRangoFechas()", &slot_0, QMetaData::Private },
	{ "SlotSeleccionoTransferencia(int,int,int,const QPoint&)", &slot_1, QMetaData::Private },
	{ "SlotCopiar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpTransferenciasEnviadas", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpTransferenciasEnviadas.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpTransferenciasEnviadas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpTransferenciasEnviadas" ) )
	return this;
    return TransferenciasEnviadas::qt_cast( clname );
}

bool QtImpTransferenciasEnviadas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCapturoRangoFechas(); break;
    case 1: SlotSeleccionoTransferencia((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotCopiar(); break;
    default:
	return TransferenciasEnviadas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpTransferenciasEnviadas::qt_emit( int _id, QUObject* _o )
{
    return TransferenciasEnviadas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpTransferenciasEnviadas::qt_property( int id, int f, QVariant* v)
{
    return TransferenciasEnviadas::qt_property( id, f, v);
}

bool QtImpTransferenciasEnviadas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
