/****************************************************************************
** QFirmaSistema meta object code from reading C++ file 'IMP_FirmaSistema.h'
**
** Created: Sat Jan 27 17:40:28 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_FirmaSistema.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QFirmaSistema::className() const
{
    return "QFirmaSistema";
}

QMetaObject *QFirmaSistema::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFirmaSistema( "QFirmaSistema", &QFirmaSistema::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFirmaSistema::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFirmaSistema", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFirmaSistema::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFirmaSistema", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFirmaSistema::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = FirmaSistema::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "SiscomDatCom", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotServidor", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "PerfilSeguridadProt2", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotPerfil", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "SisUsuarioSeg3", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotUsuario", 1, param_slot_4 };
    static const QUMethod slot_5 = {"SlotTipoLetra", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private },
	{ "SlotServidor(SiscomDatCom*)", &slot_2, QMetaData::Private },
	{ "SlotPerfil(PerfilSeguridadProt2*)", &slot_3, QMetaData::Private },
	{ "SlotUsuario(SisUsuarioSeg3*)", &slot_4, QMetaData::Private },
	{ "SlotTipoLetra()", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QFirmaSistema", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFirmaSistema.setMetaObject( metaObj );
    return metaObj;
}

void* QFirmaSistema::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFirmaSistema" ) )
	return this;
    return FirmaSistema::qt_cast( clname );
}

bool QFirmaSistema::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCancelar(); break;
    case 2: SlotServidor((SiscomDatCom*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotPerfil((PerfilSeguridadProt2*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotUsuario((SisUsuarioSeg3*)static_QUType_ptr.get(_o+1)); break;
    case 5: SlotTipoLetra(); break;
    default:
	return FirmaSistema::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QFirmaSistema::qt_emit( int _id, QUObject* _o )
{
    return FirmaSistema::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QFirmaSistema::qt_property( int id, int f, QVariant* v)
{
    return FirmaSistema::qt_property( id, f, v);
}

bool QFirmaSistema::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
