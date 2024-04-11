/****************************************************************************
** QRegistraProgramaCurso meta object code from reading C++ file 'IMP_RegistraProgramaCurso.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistraProgramaCurso.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistraProgramaCurso::className() const
{
    return "QRegistraProgramaCurso";
}

QMetaObject *QRegistraProgramaCurso::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistraProgramaCurso( "QRegistraProgramaCurso", &QRegistraProgramaCurso::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistraProgramaCurso::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistraProgramaCurso", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistraProgramaCurso::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistraProgramaCurso", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistraProgramaCurso::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistraProgramaCurso::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAAceptar()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistraProgramaCurso", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistraProgramaCurso.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistraProgramaCurso::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistraProgramaCurso" ) )
	return this;
    return RegistraProgramaCurso::qt_cast( clname );
}

bool QRegistraProgramaCurso::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAAceptar(); break;
    case 1: SlotAceptar(); break;
    default:
	return RegistraProgramaCurso::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistraProgramaCurso::qt_emit( int _id, QUObject* _o )
{
    return RegistraProgramaCurso::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistraProgramaCurso::qt_property( int id, int f, QVariant* v)
{
    return RegistraProgramaCurso::qt_property( id, f, v);
}

bool QRegistraProgramaCurso::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
