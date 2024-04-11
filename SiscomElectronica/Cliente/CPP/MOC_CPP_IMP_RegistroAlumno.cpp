/****************************************************************************
** QRegistroAlumno meta object code from reading C++ file 'IMP_RegistroAlumno.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroAlumno.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroAlumno::className() const
{
    return "QRegistroAlumno";
}

QMetaObject *QRegistroAlumno::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroAlumno( "QRegistroAlumno", &QRegistroAlumno::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroAlumno::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroAlumno", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroAlumno::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroAlumno", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroAlumno::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroAlumno::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotEscuelas", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotFocoAAPaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoAAMaterno", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAEscuela", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoAGrupo", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoABoleta", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoACorreo", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoAReCorreo", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoACelular", 0, 0 };
    static const QUMethod slot_9 = {"SlotFocoATCasa", 0, 0 };
    static const QUMethod slot_10 = {"SlotFocoANoCredencial", 0, 0 };
    static const QUMethod slot_11 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_12 = {"SlotRegistra", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotEscuelas(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotFocoAAPaterno()", &slot_1, QMetaData::Private },
	{ "SlotFocoAAMaterno()", &slot_2, QMetaData::Private },
	{ "SlotFocoAEscuela()", &slot_3, QMetaData::Private },
	{ "SlotFocoAGrupo()", &slot_4, QMetaData::Private },
	{ "SlotFocoABoleta()", &slot_5, QMetaData::Private },
	{ "SlotFocoACorreo()", &slot_6, QMetaData::Private },
	{ "SlotFocoAReCorreo()", &slot_7, QMetaData::Private },
	{ "SlotFocoACelular()", &slot_8, QMetaData::Private },
	{ "SlotFocoATCasa()", &slot_9, QMetaData::Private },
	{ "SlotFocoANoCredencial()", &slot_10, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_11, QMetaData::Private },
	{ "SlotRegistra()", &slot_12, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroAlumno", parentObject,
	slot_tbl, 13,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroAlumno.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroAlumno::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroAlumno" ) )
	return this;
    return RegistroAlumno::qt_cast( clname );
}

bool QRegistroAlumno::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotEscuelas((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFocoAAPaterno(); break;
    case 2: SlotFocoAAMaterno(); break;
    case 3: SlotFocoAEscuela(); break;
    case 4: SlotFocoAGrupo(); break;
    case 5: SlotFocoABoleta(); break;
    case 6: SlotFocoACorreo(); break;
    case 7: SlotFocoAReCorreo(); break;
    case 8: SlotFocoACelular(); break;
    case 9: SlotFocoATCasa(); break;
    case 10: SlotFocoANoCredencial(); break;
    case 11: SlotFocoARegistrar(); break;
    case 12: SlotRegistra(); break;
    default:
	return RegistroAlumno::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroAlumno::qt_emit( int _id, QUObject* _o )
{
    return RegistroAlumno::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistroAlumno::qt_property( int id, int f, QVariant* v)
{
    return RegistroAlumno::qt_property( id, f, v);
}

bool QRegistroAlumno::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
