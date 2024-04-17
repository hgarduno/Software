/****************************************************************************
** QBuscaPersonas meta object code from reading C++ file 'IMP_BuscaPersonas.h'
**
** Created: Fri Apr 12 21:24:26 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_BuscaPersonas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QBuscaPersonas::className() const
{
    return "QBuscaPersonas";
}

QMetaObject *QBuscaPersonas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QBuscaPersonas( "QBuscaPersonas", &QBuscaPersonas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QBuscaPersonas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QBuscaPersonas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QBuscaPersonas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QBuscaPersonas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QBuscaPersonas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = BuscaPersonas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoIdPersona", 0, 0 };
    static const QUMethod slot_3 = {"SlotPasaFocoConsulta", 0, 0 };
    static const QUMethod slot_4 = {"SlotConsulta", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotSeleccionandoPersona", 4, param_slot_5 };
    static const QUMethod slot_6 = {"SlotSeleccionaPersona", 0, 0 };
    static const QUMethod slot_7 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoAPaterno()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoAMaterno()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoIdPersona()", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoConsulta()", &slot_3, QMetaData::Private },
	{ "SlotConsulta()", &slot_4, QMetaData::Private },
	{ "SlotSeleccionandoPersona(int,int,int,const QPoint&)", &slot_5, QMetaData::Private },
	{ "SlotSeleccionaPersona()", &slot_6, QMetaData::Private },
	{ "SlotCancelar()", &slot_7, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QBuscaPersonas", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QBuscaPersonas.setMetaObject( metaObj );
    return metaObj;
}

void* QBuscaPersonas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QBuscaPersonas" ) )
	return this;
    return BuscaPersonas::qt_cast( clname );
}

bool QBuscaPersonas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoAPaterno(); break;
    case 1: SlotPasaFocoAMaterno(); break;
    case 2: SlotPasaFocoIdPersona(); break;
    case 3: SlotPasaFocoConsulta(); break;
    case 4: SlotConsulta(); break;
    case 5: SlotSeleccionandoPersona((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 6: SlotSeleccionaPersona(); break;
    case 7: SlotCancelar(); break;
    default:
	return BuscaPersonas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QBuscaPersonas::qt_emit( int _id, QUObject* _o )
{
    return BuscaPersonas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QBuscaPersonas::qt_property( int id, int f, QVariant* v)
{
    return BuscaPersonas::qt_property( id, f, v);
}

bool QBuscaPersonas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
