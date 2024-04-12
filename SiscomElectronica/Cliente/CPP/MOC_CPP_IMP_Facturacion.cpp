/****************************************************************************
** QFacturacion meta object code from reading C++ file 'IMP_Facturacion.h'
**
** Created: Thu Apr 11 21:51:17 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Facturacion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QFacturacion::className() const
{
    return "QFacturacion";
}

QMetaObject *QFacturacion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFacturacion( "QFacturacion", &QFacturacion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFacturacion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFacturacion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFacturacion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFacturacion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFacturacion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Facturacion::staticMetaObject();
    static const QUMethod slot_0 = {"S_ImprimeFactura", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_ImprimeFactura()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QFacturacion", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFacturacion.setMetaObject( metaObj );
    return metaObj;
}

void* QFacturacion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFacturacion" ) )
	return this;
    return Facturacion::qt_cast( clname );
}

bool QFacturacion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_ImprimeFactura(); break;
    default:
	return Facturacion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QFacturacion::qt_emit( int _id, QUObject* _o )
{
    return Facturacion::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QFacturacion::qt_property( int id, int f, QVariant* v)
{
    return Facturacion::qt_property( id, f, v);
}

bool QFacturacion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
