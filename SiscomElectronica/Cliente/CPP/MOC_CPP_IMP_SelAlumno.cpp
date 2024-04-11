/****************************************************************************
** QSelAlumno meta object code from reading C++ file 'IMP_SelAlumno.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SelAlumno.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSelAlumno::className() const
{
    return "QSelAlumno";
}

QMetaObject *QSelAlumno::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSelAlumno( "QSelAlumno", &QSelAlumno::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSelAlumno::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSelAlumno", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSelAlumno::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSelAlumno", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSelAlumno::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SelAlumno::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionando", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSelecciono", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotEscuela", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_4 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_5 = {"SlotRegistrarAlumno", 0, 0 };
    static const QUMethod slot_6 = {"SlotCancelarRegRapido", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotRegistroAlumno", 1, param_slot_7 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionando(int)", &slot_0, QMetaData::Private },
	{ "SlotSelecciono(int)", &slot_1, QMetaData::Private },
	{ "SlotEscuela(SiscomRegistro3*)", &slot_2, QMetaData::Private },
	{ "SlotAceptar()", &slot_3, QMetaData::Private },
	{ "SlotCancelar()", &slot_4, QMetaData::Private },
	{ "SlotRegistrarAlumno()", &slot_5, QMetaData::Private },
	{ "SlotCancelarRegRapido()", &slot_6, QMetaData::Private },
	{ "SlotRegistroAlumno(const QString&)", &slot_7, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSelAlumno", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSelAlumno.setMetaObject( metaObj );
    return metaObj;
}

void* QSelAlumno::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSelAlumno" ) )
	return this;
    return SelAlumno::qt_cast( clname );
}

bool QSelAlumno::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionando((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotSelecciono((int)static_QUType_int.get(_o+1)); break;
    case 2: SlotEscuela((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotAceptar(); break;
    case 4: SlotCancelar(); break;
    case 5: SlotRegistrarAlumno(); break;
    case 6: SlotCancelarRegRapido(); break;
    case 7: SlotRegistroAlumno((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return SelAlumno::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSelAlumno::qt_emit( int _id, QUObject* _o )
{
    return SelAlumno::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSelAlumno::qt_property( int id, int f, QVariant* v)
{
    return SelAlumno::qt_property( id, f, v);
}

bool QSelAlumno::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
