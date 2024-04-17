/****************************************************************************
** QRegistroPlaca meta object code from reading C++ file 'IMP_RegistroPlaca.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroPlaca.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroPlaca::className() const
{
    return "QRegistroPlaca";
}

QMetaObject *QRegistroPlaca::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroPlaca( "QRegistroPlaca", &QRegistroPlaca::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroPlaca::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroPlaca", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroPlaca::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroPlaca", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroPlaca::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroPlaca::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAAPaterno", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoAAMaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoACelular", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAReCelular", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoARegistraPersonales", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAArchivo", 0, 0 };
    static const QUMethod slot_6 = {"SlotRegistraPersonales", 0, 0 };
    static const QUMethod slot_7 = {"SlotRegistraCelular", 0, 0 };
    static const QUMethod slot_8 = {"SlotValidandoCapturaCelular", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ "pintNProducto", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"SlotProducto", 1, param_slot_9 };
    static const QUMethod slot_10 = {"SlotImprimeComprobante", 0, 0 };
    static const QUMethod slot_11 = {"SlotRegistra", 0, 0 };
    static const QUMethod slot_12 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_13 = {"SlotCancelar", 0, 0 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"SlotCapturandoNombre", 1, param_slot_14 };
    static const QUMethod slot_15 = {"SlotCapturandoDatosParaImpreso", 0, 0 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"SlotCapturandoDatosParaImpreso", 1, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"SlotCapturandoCelular", 1, param_slot_17 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAAPaterno()", &slot_0, QMetaData::Private },
	{ "SlotFocoAAMaterno()", &slot_1, QMetaData::Private },
	{ "SlotFocoACelular()", &slot_2, QMetaData::Private },
	{ "SlotFocoAReCelular()", &slot_3, QMetaData::Private },
	{ "SlotFocoARegistraPersonales()", &slot_4, QMetaData::Private },
	{ "SlotFocoAArchivo()", &slot_5, QMetaData::Private },
	{ "SlotRegistraPersonales()", &slot_6, QMetaData::Private },
	{ "SlotRegistraCelular()", &slot_7, QMetaData::Private },
	{ "SlotValidandoCapturaCelular()", &slot_8, QMetaData::Private },
	{ "SlotProducto(int)", &slot_9, QMetaData::Private },
	{ "SlotImprimeComprobante()", &slot_10, QMetaData::Private },
	{ "SlotRegistra()", &slot_11, QMetaData::Private },
	{ "SlotAceptar()", &slot_12, QMetaData::Private },
	{ "SlotCancelar()", &slot_13, QMetaData::Private },
	{ "SlotCapturandoNombre(const QString&)", &slot_14, QMetaData::Private },
	{ "SlotCapturandoDatosParaImpreso()", &slot_15, QMetaData::Private },
	{ "SlotCapturandoDatosParaImpreso(const QString&)", &slot_16, QMetaData::Private },
	{ "SlotCapturandoCelular(const QString&)", &slot_17, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroPlaca", parentObject,
	slot_tbl, 18,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroPlaca.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroPlaca::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroPlaca" ) )
	return this;
    return RegistroPlaca::qt_cast( clname );
}

bool QRegistroPlaca::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAAPaterno(); break;
    case 1: SlotFocoAAMaterno(); break;
    case 2: SlotFocoACelular(); break;
    case 3: SlotFocoAReCelular(); break;
    case 4: SlotFocoARegistraPersonales(); break;
    case 5: SlotFocoAArchivo(); break;
    case 6: SlotRegistraPersonales(); break;
    case 7: SlotRegistraCelular(); break;
    case 8: SlotValidandoCapturaCelular(); break;
    case 9: SlotProducto((int)static_QUType_int.get(_o+1)); break;
    case 10: SlotImprimeComprobante(); break;
    case 11: SlotRegistra(); break;
    case 12: SlotAceptar(); break;
    case 13: SlotCancelar(); break;
    case 14: SlotCapturandoNombre((const QString&)static_QUType_QString.get(_o+1)); break;
    case 15: SlotCapturandoDatosParaImpreso(); break;
    case 16: SlotCapturandoDatosParaImpreso((const QString&)static_QUType_QString.get(_o+1)); break;
    case 17: SlotCapturandoCelular((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return RegistroPlaca::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroPlaca::qt_emit( int _id, QUObject* _o )
{
    return RegistroPlaca::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistroPlaca::qt_property( int id, int f, QVariant* v)
{
    return RegistroPlaca::qt_property( id, f, v);
}

bool QRegistroPlaca::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
