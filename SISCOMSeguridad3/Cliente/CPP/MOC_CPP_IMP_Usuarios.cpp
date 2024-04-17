/****************************************************************************
** CQSisUsuarios meta object code from reading C++ file 'IMP_Usuarios.h'
**
** Created: Fri Apr 12 21:23:57 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Usuarios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisUsuarios::className() const
{
    return "CQSisUsuarios";
}

QMetaObject *CQSisUsuarios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisUsuarios( "CQSisUsuarios", &CQSisUsuarios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisUsuarios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisUsuarios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisUsuarios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisUsuarios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisUsuarios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Usuarios::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRUsuario", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRUsuario()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisUsuarios", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisUsuarios.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisUsuarios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisUsuarios" ) )
	return this;
    return Usuarios::qt_cast( clname );
}

bool CQSisUsuarios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRUsuario(); break;
    default:
	return Usuarios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisUsuarios::qt_emit( int _id, QUObject* _o )
{
    return Usuarios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CQSisUsuarios::qt_property( int id, int f, QVariant* v)
{
    return Usuarios::qt_property( id, f, v);
}

bool CQSisUsuarios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
