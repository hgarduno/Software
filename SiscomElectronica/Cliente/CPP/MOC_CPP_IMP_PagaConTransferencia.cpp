/****************************************************************************
** QPagaConTransferencia meta object code from reading C++ file 'IMP_PagaConTransferencia.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_PagaConTransferencia.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPagaConTransferencia::className() const
{
    return "QPagaConTransferencia";
}

QMetaObject *QPagaConTransferencia::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPagaConTransferencia( "QPagaConTransferencia", &QPagaConTransferencia::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPagaConTransferencia::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPagaConTransferencia", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPagaConTransferencia::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPagaConTransferencia", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPagaConTransferencia::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PagaConTransferencia::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoASeReflejo", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotEstadoTransferencia", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotCapturandoTelefono", 1, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotFocoASeReflejo()", &slot_1, QMetaData::Private },
	{ "SlotEstadoTransferencia(int)", &slot_2, QMetaData::Private },
	{ "SlotCapturandoTelefono(const QString&)", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPagaConTransferencia", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPagaConTransferencia.setMetaObject( metaObj );
    return metaObj;
}

void* QPagaConTransferencia::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPagaConTransferencia" ) )
	return this;
    return PagaConTransferencia::qt_cast( clname );
}

bool QPagaConTransferencia::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotFocoASeReflejo(); break;
    case 2: SlotEstadoTransferencia((int)static_QUType_int.get(_o+1)); break;
    case 3: SlotCapturandoTelefono((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return PagaConTransferencia::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPagaConTransferencia::qt_emit( int _id, QUObject* _o )
{
    return PagaConTransferencia::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPagaConTransferencia::qt_property( int id, int f, QVariant* v)
{
    return PagaConTransferencia::qt_property( id, f, v);
}

bool QPagaConTransferencia::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
