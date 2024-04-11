/****************************************************************************
** QCambiaEliminaClaveProducto meta object code from reading C++ file 'IMP_CambiaEliminaClaveProducto.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CambiaEliminaClaveProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCambiaEliminaClaveProducto::className() const
{
    return "QCambiaEliminaClaveProducto";
}

QMetaObject *QCambiaEliminaClaveProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCambiaEliminaClaveProducto( "QCambiaEliminaClaveProducto", &QCambiaEliminaClaveProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCambiaEliminaClaveProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCambiaEliminaClaveProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCambiaEliminaClaveProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCambiaEliminaClaveProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCambiaEliminaClaveProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CambiaEliminaClaveProducto::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pSisReg3Producto", &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProducto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotCambiaClave", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoCambiaClave", 0, 0 };
    static const QUMethod slot_3 = {"SlotEliminaProducto", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProducto(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotCambiaClave()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoCambiaClave()", &slot_2, QMetaData::Private },
	{ "SlotEliminaProducto()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCambiaEliminaClaveProducto", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCambiaEliminaClaveProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QCambiaEliminaClaveProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCambiaEliminaClaveProducto" ) )
	return this;
    return CambiaEliminaClaveProducto::qt_cast( clname );
}

bool QCambiaEliminaClaveProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProducto((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotCambiaClave(); break;
    case 2: SlotPasaFocoCambiaClave(); break;
    case 3: SlotEliminaProducto(); break;
    default:
	return CambiaEliminaClaveProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCambiaEliminaClaveProducto::qt_emit( int _id, QUObject* _o )
{
    return CambiaEliminaClaveProducto::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCambiaEliminaClaveProducto::qt_property( int id, int f, QVariant* v)
{
    return CambiaEliminaClaveProducto::qt_property( id, f, v);
}

bool QCambiaEliminaClaveProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
