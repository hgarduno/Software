/****************************************************************************
** QCtrlInventarioProgramado meta object code from reading C++ file 'QCtrlInventarioProgramado.h'
**
** Created: Fri Apr 12 21:22:44 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlInventarioProgramado.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlInventarioProgramado::className() const
{
    return "QCtrlInventarioProgramado";
}

QMetaObject *QCtrlInventarioProgramado::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlInventarioProgramado( "QCtrlInventarioProgramado", &QCtrlInventarioProgramado::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlInventarioProgramado::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlInventarioProgramado", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlInventarioProgramado::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlInventarioProgramado", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlInventarioProgramado::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QTable::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QCtrlInventarioProgramado", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlInventarioProgramado.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlInventarioProgramado::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlInventarioProgramado" ) )
	return this;
    return QTable::qt_cast( clname );
}

bool QCtrlInventarioProgramado::qt_invoke( int _id, QUObject* _o )
{
    return QTable::qt_invoke(_id,_o);
}

bool QCtrlInventarioProgramado::qt_emit( int _id, QUObject* _o )
{
    return QTable::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCtrlInventarioProgramado::qt_property( int id, int f, QVariant* v)
{
    return QTable::qt_property( id, f, v);
}

bool QCtrlInventarioProgramado::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
