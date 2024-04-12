/****************************************************************************
** QAlumnoRegistrado meta object code from reading C++ file 'IMP_AlumnoRegistrado.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_AlumnoRegistrado.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QAlumnoRegistrado::className() const
{
    return "QAlumnoRegistrado";
}

QMetaObject *QAlumnoRegistrado::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAlumnoRegistrado( "QAlumnoRegistrado", &QAlumnoRegistrado::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAlumnoRegistrado::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAlumnoRegistrado", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAlumnoRegistrado::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAlumnoRegistrado", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAlumnoRegistrado::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = AlumnoRegistrado::staticMetaObject();
    static const QUMethod slot_0 = {"SlotInscribirCliente", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotInscribirCliente()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QAlumnoRegistrado", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAlumnoRegistrado.setMetaObject( metaObj );
    return metaObj;
}

void* QAlumnoRegistrado::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAlumnoRegistrado" ) )
	return this;
    return AlumnoRegistrado::qt_cast( clname );
}

bool QAlumnoRegistrado::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotInscribirCliente(); break;
    case 1: SlotCancelar(); break;
    default:
	return AlumnoRegistrado::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QAlumnoRegistrado::qt_emit( int _id, QUObject* _o )
{
    return AlumnoRegistrado::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QAlumnoRegistrado::qt_property( int id, int f, QVariant* v)
{
    return AlumnoRegistrado::qt_property( id, f, v);
}

bool QAlumnoRegistrado::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
