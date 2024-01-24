/****************************************************************************
** SiscomImprime meta object code from reading C++ file 'SiscomImprime.h'
**
** Created: Sun Feb 9 02:52:53 2020
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/SiscomImprime.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SiscomImprime::className() const
{
    return "SiscomImprime";
}

QMetaObject *SiscomImprime::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SiscomImprime( "SiscomImprime", &SiscomImprime::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SiscomImprime::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomImprime", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SiscomImprime::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomImprime", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SiscomImprime::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QScrollView::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"SiscomImprime", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SiscomImprime.setMetaObject( metaObj );
    return metaObj;
}

void* SiscomImprime::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SiscomImprime" ) )
	return this;
    return QScrollView::qt_cast( clname );
}

bool SiscomImprime::qt_invoke( int _id, QUObject* _o )
{
    return QScrollView::qt_invoke(_id,_o);
}

bool SiscomImprime::qt_emit( int _id, QUObject* _o )
{
    return QScrollView::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool SiscomImprime::qt_property( int id, int f, QVariant* v)
{
    return QScrollView::qt_property( id, f, v);
}

bool SiscomImprime::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
