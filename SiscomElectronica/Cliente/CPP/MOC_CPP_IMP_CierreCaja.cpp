/****************************************************************************
** QCierreCaja meta object code from reading C++ file 'IMP_CierreCaja.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CierreCaja.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCierreCaja::className() const
{
    return "QCierreCaja";
}

QMetaObject *QCierreCaja::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCierreCaja( "QCierreCaja", &QCierreCaja::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCierreCaja::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCierreCaja", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCierreCaja::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCierreCaja", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCierreCaja::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CierreCaja::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QCierreCaja", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCierreCaja.setMetaObject( metaObj );
    return metaObj;
}

void* QCierreCaja::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCierreCaja" ) )
	return this;
    return CierreCaja::qt_cast( clname );
}

bool QCierreCaja::qt_invoke( int _id, QUObject* _o )
{
    return CierreCaja::qt_invoke(_id,_o);
}

bool QCierreCaja::qt_emit( int _id, QUObject* _o )
{
    return CierreCaja::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCierreCaja::qt_property( int id, int f, QVariant* v)
{
    return CierreCaja::qt_property( id, f, v);
}

bool QCierreCaja::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
