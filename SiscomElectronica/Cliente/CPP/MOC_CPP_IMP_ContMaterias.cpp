/****************************************************************************
** QContMaterias meta object code from reading C++ file 'IMP_ContMaterias.h'
**
** Created: Fri Apr 12 21:35:19 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ContMaterias.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QContMaterias::className() const
{
    return "QContMaterias";
}

QMetaObject *QContMaterias::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QContMaterias( "QContMaterias", &QContMaterias::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QContMaterias::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QContMaterias", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QContMaterias::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QContMaterias", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QContMaterias::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ContMaterias::staticMetaObject();
    static const QUMethod slot_0 = {"S_SelMateria", 0, 0 };
    static const QUMethod slot_1 = {"S_Anexar", 0, 0 };
    static const QUMethod slot_2 = {"S_Registrar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SelMateria()", &slot_0, QMetaData::Private },
	{ "S_Anexar()", &slot_1, QMetaData::Private },
	{ "S_Registrar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QContMaterias", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QContMaterias.setMetaObject( metaObj );
    return metaObj;
}

void* QContMaterias::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QContMaterias" ) )
	return this;
    return ContMaterias::qt_cast( clname );
}

bool QContMaterias::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SelMateria(); break;
    case 1: S_Anexar(); break;
    case 2: S_Registrar(); break;
    default:
	return ContMaterias::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QContMaterias::qt_emit( int _id, QUObject* _o )
{
    return ContMaterias::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QContMaterias::qt_property( int id, int f, QVariant* v)
{
    return ContMaterias::qt_property( id, f, v);
}

bool QContMaterias::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
