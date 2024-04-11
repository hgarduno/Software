/****************************************************************************
** QCtrlSepomexComunicas meta object code from reading C++ file 'QCtrlSepomexComunicas.h'
**
** Created: Sat Jan 27 17:40:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlSepomexComunicas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlSepomexComunicas::className() const
{
    return "QCtrlSepomexComunicas";
}

QMetaObject *QCtrlSepomexComunicas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlSepomexComunicas( "QCtrlSepomexComunicas", &QCtrlSepomexComunicas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlSepomexComunicas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlSepomexComunicas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlSepomexComunicas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlSepomexComunicas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlSepomexComunicas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QCtrlSepomexComunicas", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlSepomexComunicas.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlSepomexComunicas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlSepomexComunicas" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QCtrlSepomexComunicas::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool QCtrlSepomexComunicas::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCtrlSepomexComunicas::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlSepomexComunicas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
