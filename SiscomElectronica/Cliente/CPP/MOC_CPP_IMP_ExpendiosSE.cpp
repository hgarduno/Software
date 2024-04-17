/****************************************************************************
** QExpendiosSE meta object code from reading C++ file 'IMP_ExpendiosSE.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ExpendiosSE.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QExpendiosSE::className() const
{
    return "QExpendiosSE";
}

QMetaObject *QExpendiosSE::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QExpendiosSE( "QExpendiosSE", &QExpendiosSE::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QExpendiosSE::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QExpendiosSE", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QExpendiosSE::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QExpendiosSE", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QExpendiosSE::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ExpendiosSE::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QExpendiosSE", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QExpendiosSE.setMetaObject( metaObj );
    return metaObj;
}

void* QExpendiosSE::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QExpendiosSE" ) )
	return this;
    return ExpendiosSE::qt_cast( clname );
}

bool QExpendiosSE::qt_invoke( int _id, QUObject* _o )
{
    return ExpendiosSE::qt_invoke(_id,_o);
}

bool QExpendiosSE::qt_emit( int _id, QUObject* _o )
{
    return ExpendiosSE::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QExpendiosSE::qt_property( int id, int f, QVariant* v)
{
    return ExpendiosSE::qt_property( id, f, v);
}

bool QExpendiosSE::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
