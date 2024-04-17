/****************************************************************************
** CQSisControladorSeguridad meta object code from reading C++ file 'IMP_ControladorSeguridad.h'
**
** Created: Fri Apr 12 21:24:06 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ControladorSeguridad.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisControladorSeguridad::className() const
{
    return "CQSisControladorSeguridad";
}

QMetaObject *CQSisControladorSeguridad::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisControladorSeguridad( "CQSisControladorSeguridad", &CQSisControladorSeguridad::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisControladorSeguridad::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisControladorSeguridad", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisControladorSeguridad::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisControladorSeguridad", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisControladorSeguridad::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ControladorSeguridad::staticMetaObject();
    static const QUMethod slot_0 = {"SlotManejadorUsuarios", 0, 0 };
    static const QUMethod slot_1 = {"SlotCapturaAplicacion", 0, 0 };
    static const QUMethod slot_2 = {"SlotRegistraAplicacion", 0, 0 };
    static const QUMethod slot_3 = {"SlotCargaAplicacion", 0, 0 };
    static const QUMethod slot_4 = {"SlotIniciaComunicaciones", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotEstanRegLasPantallas", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_ptr, "QSiscomListaPantallasBD", QUParameter::In }
    };
    static const QUMethod slot_6 = {"SlotLasPantallas", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotMuestraDatosPantalla", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "QSiscomListaPantallasBD", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQPerfiles", QUParameter::In }
    };
    static const QUMethod slot_8 = {"SlotConsultaAplicacion", 3, param_slot_8 };
    static const QUMethod slot_9 = {"SlotCargaPerfiles", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"SlotMuestraDscPerfil", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_ptr, "CQPerfiles", QUParameter::In }
    };
    static const QUMethod slot_11 = {"SlotRegistroPerfiles", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"SlotMuestraUsuariosXPerfil", 1, param_slot_12 };
    static const QUMethod slot_13 = {"SlotCapturaFirmas", 0, 0 };
    static const QUMethod slot_14 = {"S_ActualizaPantalla", 0, 0 };
    static const QUMethod slot_15 = {"S_ActualizaAplicacion", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotManejadorUsuarios()", &slot_0, QMetaData::Private },
	{ "SlotCapturaAplicacion()", &slot_1, QMetaData::Private },
	{ "SlotRegistraAplicacion()", &slot_2, QMetaData::Private },
	{ "SlotCargaAplicacion()", &slot_3, QMetaData::Private },
	{ "SlotIniciaComunicaciones()", &slot_4, QMetaData::Private },
	{ "SlotEstanRegLasPantallas(int)", &slot_5, QMetaData::Private },
	{ "SlotLasPantallas(const QSiscomListaPantallasBD&)", &slot_6, QMetaData::Private },
	{ "SlotMuestraDatosPantalla(int)", &slot_7, QMetaData::Private },
	{ "SlotConsultaAplicacion(int,const QSiscomListaPantallasBD&,CQPerfiles*)", &slot_8, QMetaData::Private },
	{ "SlotCargaPerfiles()", &slot_9, QMetaData::Private },
	{ "SlotMuestraDscPerfil(int)", &slot_10, QMetaData::Private },
	{ "SlotRegistroPerfiles(CQPerfiles*)", &slot_11, QMetaData::Private },
	{ "SlotMuestraUsuariosXPerfil(int)", &slot_12, QMetaData::Private },
	{ "SlotCapturaFirmas()", &slot_13, QMetaData::Private },
	{ "S_ActualizaPantalla()", &slot_14, QMetaData::Private },
	{ "S_ActualizaAplicacion()", &slot_15, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisControladorSeguridad", parentObject,
	slot_tbl, 16,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisControladorSeguridad.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisControladorSeguridad::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisControladorSeguridad" ) )
	return this;
    return ControladorSeguridad::qt_cast( clname );
}

bool CQSisControladorSeguridad::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotManejadorUsuarios(); break;
    case 1: SlotCapturaAplicacion(); break;
    case 2: SlotRegistraAplicacion(); break;
    case 3: SlotCargaAplicacion(); break;
    case 4: SlotIniciaComunicaciones(); break;
    case 5: SlotEstanRegLasPantallas((int)static_QUType_int.get(_o+1)); break;
    case 6: SlotLasPantallas((const QSiscomListaPantallasBD&)*((const QSiscomListaPantallasBD*)static_QUType_ptr.get(_o+1))); break;
    case 7: SlotMuestraDatosPantalla((int)static_QUType_int.get(_o+1)); break;
    case 8: SlotConsultaAplicacion((int)static_QUType_int.get(_o+1),(const QSiscomListaPantallasBD&)*((const QSiscomListaPantallasBD*)static_QUType_ptr.get(_o+2)),(CQPerfiles*)static_QUType_ptr.get(_o+3)); break;
    case 9: SlotCargaPerfiles(); break;
    case 10: SlotMuestraDscPerfil((int)static_QUType_int.get(_o+1)); break;
    case 11: SlotRegistroPerfiles((CQPerfiles*)static_QUType_ptr.get(_o+1)); break;
    case 12: SlotMuestraUsuariosXPerfil((int)static_QUType_int.get(_o+1)); break;
    case 13: SlotCapturaFirmas(); break;
    case 14: S_ActualizaPantalla(); break;
    case 15: S_ActualizaAplicacion(); break;
    default:
	return ControladorSeguridad::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisControladorSeguridad::qt_emit( int _id, QUObject* _o )
{
    return ControladorSeguridad::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CQSisControladorSeguridad::qt_property( int id, int f, QVariant* v)
{
    return ControladorSeguridad::qt_property( id, f, v);
}

bool CQSisControladorSeguridad::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
