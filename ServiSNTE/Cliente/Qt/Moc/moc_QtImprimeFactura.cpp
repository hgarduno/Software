/****************************************************************************
** QtImprimeFactura meta object code from reading C++ file 'QtImprimeFactura.h'
**
** Created: Thu Apr 11 21:08:06 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImprimeFactura.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImprimeFactura::className() const
{
    return "QtImprimeFactura";
}

QMetaObject *QtImprimeFactura::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImprimeFactura( "QtImprimeFactura", &QtImprimeFactura::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImprimeFactura::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeFactura", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImprimeFactura::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeFactura", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImprimeFactura::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zVenta", QUParameter::InOut }
    };
    static const QUMethod slot_0 = {"imprimir", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "imprimir(zVenta&)", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImprimeFactura", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImprimeFactura.setMetaObject( metaObj );
    return metaObj;
}

void* QtImprimeFactura::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImprimeFactura" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QtImprimeFactura::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: imprimir((zVenta&)*((zVenta*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImprimeFactura::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImprimeFactura::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QtImprimeFactura::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES