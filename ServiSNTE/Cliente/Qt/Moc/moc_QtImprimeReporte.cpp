/****************************************************************************
** QtImprimeReporte meta object code from reading C++ file 'QtImprimeReporte.h'
**
** Created: Thu Apr 11 21:08:44 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImprimeReporte.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImprimeReporte::className() const
{
    return "QtImprimeReporte";
}

QMetaObject *QtImprimeReporte::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImprimeReporte( "QtImprimeReporte", &QtImprimeReporte::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImprimeReporte::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeReporte", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImprimeReporte::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeReporte", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImprimeReporte::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QScrollView::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImprimeReporte", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImprimeReporte.setMetaObject( metaObj );
    return metaObj;
}

void* QtImprimeReporte::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImprimeReporte" ) )
	return this;
    if ( !qstrcmp( clname, "QtBaseMedidas" ) )
	return (QtBaseMedidas*)this;
    return QScrollView::qt_cast( clname );
}

bool QtImprimeReporte::qt_invoke( int _id, QUObject* _o )
{
    return QScrollView::qt_invoke(_id,_o);
}

bool QtImprimeReporte::qt_emit( int _id, QUObject* _o )
{
    return QScrollView::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImprimeReporte::qt_property( int id, int f, QVariant* v)
{
    return QScrollView::qt_property( id, f, v);
}

bool QtImprimeReporte::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
