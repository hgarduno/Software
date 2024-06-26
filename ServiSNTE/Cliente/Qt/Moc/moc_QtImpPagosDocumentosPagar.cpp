/****************************************************************************
** QtImpPagosDocumentosPagar meta object code from reading C++ file 'QtImpPagosDocumentosPagar.h'
**
<<<<<<< HEAD
** Created: Mon Apr 1 17:30:51 2024
=======
** Created: Thu Apr 11 21:08:57 2024
>>>>>>> d8559e8a5b2006215346761b79004c9434166dbc
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpPagosDocumentosPagar.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpPagosDocumentosPagar::className() const
{
    return "QtImpPagosDocumentosPagar";
}

QMetaObject *QtImpPagosDocumentosPagar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpPagosDocumentosPagar( "QtImpPagosDocumentosPagar", &QtImpPagosDocumentosPagar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpPagosDocumentosPagar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpPagosDocumentosPagar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpPagosDocumentosPagar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpPagosDocumentosPagar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpPagosDocumentosPagar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PagosDocumentosPagar::staticMetaObject();
    static const QUMethod slot_0 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotImprimir()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpPagosDocumentosPagar", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpPagosDocumentosPagar.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpPagosDocumentosPagar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpPagosDocumentosPagar" ) )
	return this;
    return PagosDocumentosPagar::qt_cast( clname );
}

bool QtImpPagosDocumentosPagar::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotImprimir(); break;
    default:
	return PagosDocumentosPagar::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpPagosDocumentosPagar::qt_emit( int _id, QUObject* _o )
{
    return PagosDocumentosPagar::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpPagosDocumentosPagar::qt_property( int id, int f, QVariant* v)
{
    return PagosDocumentosPagar::qt_property( id, f, v);
}

bool QtImpPagosDocumentosPagar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
