/****************************************************************************
** QBodegasSiscom meta object code from reading C++ file 'IMP_BodegasSiscom.h'
**
** Created: Thu Apr 11 21:40:02 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_BodegasSiscom.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QBodegasSiscom::className() const
{
    return "QBodegasSiscom";
}

QMetaObject *QBodegasSiscom::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QBodegasSiscom( "QBodegasSiscom", &QBodegasSiscom::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QBodegasSiscom::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QBodegasSiscom", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QBodegasSiscom::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QBodegasSiscom", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QBodegasSiscom::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = BodegasSiscom::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotBodega", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotBodega(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QBodegasSiscom", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QBodegasSiscom.setMetaObject( metaObj );
    return metaObj;
}

void* QBodegasSiscom::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QBodegasSiscom" ) )
	return this;
    return BodegasSiscom::qt_cast( clname );
}

bool QBodegasSiscom::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotBodega((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    default:
	return BodegasSiscom::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QBodegasSiscom::qt_emit( int _id, QUObject* _o )
{
    return BodegasSiscom::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QBodegasSiscom::qt_property( int id, int f, QVariant* v)
{
    return BodegasSiscom::qt_property( id, f, v);
}

bool QBodegasSiscom::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
