/****************************************************************************
** QFechaHoraEntrega meta object code from reading C++ file 'IMP_FechaHoraEntrega.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_FechaHoraEntrega.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QFechaHoraEntrega::className() const
{
    return "QFechaHoraEntrega";
}

QMetaObject *QFechaHoraEntrega::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFechaHoraEntrega( "QFechaHoraEntrega", &QFechaHoraEntrega::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFechaHoraEntrega::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFechaHoraEntrega", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFechaHoraEntrega::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFechaHoraEntrega", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFechaHoraEntrega::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = FechaHoraEntrega::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QFechaHoraEntrega", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFechaHoraEntrega.setMetaObject( metaObj );
    return metaObj;
}

void* QFechaHoraEntrega::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFechaHoraEntrega" ) )
	return this;
    return FechaHoraEntrega::qt_cast( clname );
}

bool QFechaHoraEntrega::qt_invoke( int _id, QUObject* _o )
{
    return FechaHoraEntrega::qt_invoke(_id,_o);
}

bool QFechaHoraEntrega::qt_emit( int _id, QUObject* _o )
{
    return FechaHoraEntrega::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QFechaHoraEntrega::qt_property( int id, int f, QVariant* v)
{
    return FechaHoraEntrega::qt_property( id, f, v);
}

bool QFechaHoraEntrega::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
