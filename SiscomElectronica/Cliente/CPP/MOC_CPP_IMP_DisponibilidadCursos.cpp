/****************************************************************************
** QDisponibilidadCursos meta object code from reading C++ file 'IMP_DisponibilidadCursos.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_DisponibilidadCursos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QDisponibilidadCursos::className() const
{
    return "QDisponibilidadCursos";
}

QMetaObject *QDisponibilidadCursos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDisponibilidadCursos( "QDisponibilidadCursos", &QDisponibilidadCursos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDisponibilidadCursos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDisponibilidadCursos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDisponibilidadCursos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDisponibilidadCursos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDisponibilidadCursos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = DisponibilidadCursos::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotFechaCurso", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFechaCurso(SiscomRegistro3*)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDisponibilidadCursos", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDisponibilidadCursos.setMetaObject( metaObj );
    return metaObj;
}

void* QDisponibilidadCursos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDisponibilidadCursos" ) )
	return this;
    return DisponibilidadCursos::qt_cast( clname );
}

bool QDisponibilidadCursos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFechaCurso((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    default:
	return DisponibilidadCursos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDisponibilidadCursos::qt_emit( int _id, QUObject* _o )
{
    return DisponibilidadCursos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDisponibilidadCursos::qt_property( int id, int f, QVariant* v)
{
    return DisponibilidadCursos::qt_property( id, f, v);
}

bool QDisponibilidadCursos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
