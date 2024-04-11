/****************************************************************************
** QRegistroAlumnoServicio meta object code from reading C++ file 'IMP_RegistroAlumnoServicio.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroAlumnoServicio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroAlumnoServicio::className() const
{
    return "QRegistroAlumnoServicio";
}

QMetaObject *QRegistroAlumnoServicio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroAlumnoServicio( "QRegistroAlumnoServicio", &QRegistroAlumnoServicio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroAlumnoServicio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroAlumnoServicio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroAlumnoServicio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroAlumnoServicio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroAlumnoServicio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroAlumnoServicio::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotServicio", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotAlumno", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotRegistraHoraEntrada", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotAsignaSalida", 4, param_slot_3 };
    static const QUMethod slot_4 = {"SlotRegistraHoraSalida", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotServicio(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotAlumno(SiscomRegistro3*)", &slot_1, QMetaData::Private },
	{ "SlotRegistraHoraEntrada()", &slot_2, QMetaData::Private },
	{ "SlotAsignaSalida(int,int,int,const QPoint&)", &slot_3, QMetaData::Private },
	{ "SlotRegistraHoraSalida()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroAlumnoServicio", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroAlumnoServicio.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroAlumnoServicio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroAlumnoServicio" ) )
	return this;
    return RegistroAlumnoServicio::qt_cast( clname );
}

bool QRegistroAlumnoServicio::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotServicio((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotAlumno((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotRegistraHoraEntrada(); break;
    case 3: SlotAsignaSalida((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 4: SlotRegistraHoraSalida(); break;
    default:
	return RegistroAlumnoServicio::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroAlumnoServicio::qt_emit( int _id, QUObject* _o )
{
    return RegistroAlumnoServicio::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistroAlumnoServicio::qt_property( int id, int f, QVariant* v)
{
    return RegistroAlumnoServicio::qt_property( id, f, v);
}

bool QRegistroAlumnoServicio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
