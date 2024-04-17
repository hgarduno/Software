/****************************************************************************
** QTransferenciasBodegasExpendio meta object code from reading C++ file 'IMP_TransferenciasBodegasExpendio.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_TransferenciasBodegasExpendio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QTransferenciasBodegasExpendio::className() const
{
    return "QTransferenciasBodegasExpendio";
}

QMetaObject *QTransferenciasBodegasExpendio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTransferenciasBodegasExpendio( "QTransferenciasBodegasExpendio", &QTransferenciasBodegasExpendio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTransferenciasBodegasExpendio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTransferenciasBodegasExpendio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTransferenciasBodegasExpendio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTransferenciasBodegasExpendio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTransferenciasBodegasExpendio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = TransferenciasBodegasExpendio::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QTransferenciasBodegasExpendio", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTransferenciasBodegasExpendio.setMetaObject( metaObj );
    return metaObj;
}

void* QTransferenciasBodegasExpendio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTransferenciasBodegasExpendio" ) )
	return this;
    return TransferenciasBodegasExpendio::qt_cast( clname );
}

bool QTransferenciasBodegasExpendio::qt_invoke( int _id, QUObject* _o )
{
    return TransferenciasBodegasExpendio::qt_invoke(_id,_o);
}

bool QTransferenciasBodegasExpendio::qt_emit( int _id, QUObject* _o )
{
    return TransferenciasBodegasExpendio::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QTransferenciasBodegasExpendio::qt_property( int id, int f, QVariant* v)
{
    return TransferenciasBodegasExpendio::qt_property( id, f, v);
}

bool QTransferenciasBodegasExpendio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
