/****************************************************************************
** QOrdenesPorFecha meta object code from reading C++ file 'IMP_OrdenesPorFecha.h'
**
** Created: Thu Apr 11 21:51:19 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_OrdenesPorFecha.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QOrdenesPorFecha::className() const
{
    return "QOrdenesPorFecha";
}

QMetaObject *QOrdenesPorFecha::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QOrdenesPorFecha( "QOrdenesPorFecha", &QOrdenesPorFecha::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QOrdenesPorFecha::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenesPorFecha", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QOrdenesPorFecha::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenesPorFecha", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QOrdenesPorFecha::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = OrdenesPorFecha::staticMetaObject();
    static const QUMethod slot_0 = {"S_SeleccionaOrdenes", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionaOrdenes()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QOrdenesPorFecha", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QOrdenesPorFecha.setMetaObject( metaObj );
    return metaObj;
}

void* QOrdenesPorFecha::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QOrdenesPorFecha" ) )
	return this;
    return OrdenesPorFecha::qt_cast( clname );
}

bool QOrdenesPorFecha::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionaOrdenes(); break;
    default:
	return OrdenesPorFecha::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QOrdenesPorFecha::qt_emit( int _id, QUObject* _o )
{
    return OrdenesPorFecha::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QOrdenesPorFecha::qt_property( int id, int f, QVariant* v)
{
    return OrdenesPorFecha::qt_property( id, f, v);
}

bool QOrdenesPorFecha::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
