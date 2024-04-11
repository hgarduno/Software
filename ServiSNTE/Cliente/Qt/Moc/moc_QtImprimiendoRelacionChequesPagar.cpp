/****************************************************************************
** QtImprimiendoRelacionChequesPagar meta object code from reading C++ file 'QtImprimiendoRelacionChequesPagar.h'
**
** Created: Sat Jan 27 16:39:55 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImprimiendoRelacionChequesPagar.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImprimiendoRelacionChequesPagar::className() const
{
    return "QtImprimiendoRelacionChequesPagar";
}

QMetaObject *QtImprimiendoRelacionChequesPagar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImprimiendoRelacionChequesPagar( "QtImprimiendoRelacionChequesPagar", &QtImprimiendoRelacionChequesPagar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImprimiendoRelacionChequesPagar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimiendoRelacionChequesPagar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImprimiendoRelacionChequesPagar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimiendoRelacionChequesPagar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImprimiendoRelacionChequesPagar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtImprimiendoReporte::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImprimiendoRelacionChequesPagar", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImprimiendoRelacionChequesPagar.setMetaObject( metaObj );
    return metaObj;
}

void* QtImprimiendoRelacionChequesPagar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImprimiendoRelacionChequesPagar" ) )
	return this;
    return QtImprimiendoReporte::qt_cast( clname );
}

bool QtImprimiendoRelacionChequesPagar::qt_invoke( int _id, QUObject* _o )
{
    return QtImprimiendoReporte::qt_invoke(_id,_o);
}

bool QtImprimiendoRelacionChequesPagar::qt_emit( int _id, QUObject* _o )
{
    return QtImprimiendoReporte::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImprimiendoRelacionChequesPagar::qt_property( int id, int f, QVariant* v)
{
    return QtImprimiendoReporte::qt_property( id, f, v);
}

bool QtImprimiendoRelacionChequesPagar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
