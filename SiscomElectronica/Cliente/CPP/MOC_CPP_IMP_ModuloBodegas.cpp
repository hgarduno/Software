/****************************************************************************
** QModuloBodegas meta object code from reading C++ file 'IMP_ModuloBodegas.h'
**
** Created: Fri Apr 12 21:26:10 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ModuloBodegas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QModuloBodegas::className() const
{
    return "QModuloBodegas";
}

QMetaObject *QModuloBodegas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QModuloBodegas( "QModuloBodegas", &QModuloBodegas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QModuloBodegas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QModuloBodegas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QModuloBodegas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QModuloBodegas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QModuloBodegas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtModuloBodegas::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QModuloBodegas", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QModuloBodegas.setMetaObject( metaObj );
    return metaObj;
}

void* QModuloBodegas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QModuloBodegas" ) )
	return this;
    return QtModuloBodegas::qt_cast( clname );
}

bool QModuloBodegas::qt_invoke( int _id, QUObject* _o )
{
    return QtModuloBodegas::qt_invoke(_id,_o);
}

bool QModuloBodegas::qt_emit( int _id, QUObject* _o )
{
    return QtModuloBodegas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QModuloBodegas::qt_property( int id, int f, QVariant* v)
{
    return QtModuloBodegas::qt_property( id, f, v);
}

bool QModuloBodegas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
