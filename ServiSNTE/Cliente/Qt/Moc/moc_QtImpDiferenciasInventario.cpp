/****************************************************************************
** QtImpDiferenciasInventario meta object code from reading C++ file 'QtImpDiferenciasInventario.h'
**
** Created: Tue Jun 24 08:59:57 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpDiferenciasInventario.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpDiferenciasInventario::className() const
{
    return "QtImpDiferenciasInventario";
}

QMetaObject *QtImpDiferenciasInventario::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpDiferenciasInventario( "QtImpDiferenciasInventario", &QtImpDiferenciasInventario::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpDiferenciasInventario::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpDiferenciasInventario", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpDiferenciasInventario::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpDiferenciasInventario", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpDiferenciasInventario::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = DiferenciasInventario::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImpDiferenciasInventario", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpDiferenciasInventario.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpDiferenciasInventario::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpDiferenciasInventario" ) )
	return this;
    return DiferenciasInventario::qt_cast( clname );
}

bool QtImpDiferenciasInventario::qt_invoke( int _id, QUObject* _o )
{
    return DiferenciasInventario::qt_invoke(_id,_o);
}

bool QtImpDiferenciasInventario::qt_emit( int _id, QUObject* _o )
{
    return DiferenciasInventario::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpDiferenciasInventario::qt_property( int id, int f, QVariant* v)
{
    return DiferenciasInventario::qt_property( id, f, v);
}

bool QtImpDiferenciasInventario::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
