/****************************************************************************
** QSisManDirecciones meta object code from reading C++ file 'QSisManDirecciones.h'
**
** Created: Thu Apr 11 20:30:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QSisManDirecciones.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSisManDirecciones::className() const
{
    return "QSisManDirecciones";
}

QMetaObject *QSisManDirecciones::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSisManDirecciones( "QSisManDirecciones", &QSisManDirecciones::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSisManDirecciones::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSisManDirecciones", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSisManDirecciones::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSisManDirecciones", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSisManDirecciones::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QPopupMenu::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSelecciona", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSelecciona(int)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSisManDirecciones", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSisManDirecciones.setMetaObject( metaObj );
    return metaObj;
}

void* QSisManDirecciones::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSisManDirecciones" ) )
	return this;
    return QPopupMenu::qt_cast( clname );
}

bool QSisManDirecciones::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSelecciona((int)static_QUType_int.get(_o+1)); break;
    default:
	return QPopupMenu::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSisManDirecciones::qt_emit( int _id, QUObject* _o )
{
    return QPopupMenu::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSisManDirecciones::qt_property( int id, int f, QVariant* v)
{
    return QPopupMenu::qt_property( id, f, v);
}

bool QSisManDirecciones::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
