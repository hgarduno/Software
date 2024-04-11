/****************************************************************************
** QCapturaClientes meta object code from reading C++ file 'IMP_CapturaClientes.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaClientes.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaClientes::className() const
{
    return "QCapturaClientes";
}

QMetaObject *QCapturaClientes::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaClientes( "QCapturaClientes", &QCapturaClientes::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaClientes::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaClientes", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaClientes::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaClientes", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaClientes::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaClientes::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAAPaterno", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoAAMaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoARFC", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoATelefono", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoACorreo", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoACalle", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoANumero", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoAColonia", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoACP", 0, 0 };
    static const QUMethod slot_9 = {"SlotFocoAMunicipio", 0, 0 };
    static const QUMethod slot_10 = {"SlotFocoAEstado", 0, 0 };
    static const QUMethod slot_11 = {"SlotFocoAAceptar", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"SlotCliente", 1, param_slot_12 };
    static const QUMethod slot_13 = {"SlotNCliente", 0, 0 };
    static const QUMethod slot_14 = {"SlotRegistraCliente", 0, 0 };
    static const QUMethod slot_15 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAAPaterno()", &slot_0, QMetaData::Private },
	{ "SlotFocoAAMaterno()", &slot_1, QMetaData::Private },
	{ "SlotFocoARFC()", &slot_2, QMetaData::Private },
	{ "SlotFocoATelefono()", &slot_3, QMetaData::Private },
	{ "SlotFocoACorreo()", &slot_4, QMetaData::Private },
	{ "SlotFocoACalle()", &slot_5, QMetaData::Private },
	{ "SlotFocoANumero()", &slot_6, QMetaData::Private },
	{ "SlotFocoAColonia()", &slot_7, QMetaData::Private },
	{ "SlotFocoACP()", &slot_8, QMetaData::Private },
	{ "SlotFocoAMunicipio()", &slot_9, QMetaData::Private },
	{ "SlotFocoAEstado()", &slot_10, QMetaData::Private },
	{ "SlotFocoAAceptar()", &slot_11, QMetaData::Private },
	{ "SlotCliente(int)", &slot_12, QMetaData::Private },
	{ "SlotNCliente()", &slot_13, QMetaData::Private },
	{ "SlotRegistraCliente()", &slot_14, QMetaData::Private },
	{ "SlotAceptar()", &slot_15, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaClientes", parentObject,
	slot_tbl, 16,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaClientes.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaClientes::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaClientes" ) )
	return this;
    return CapturaClientes::qt_cast( clname );
}

bool QCapturaClientes::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAAPaterno(); break;
    case 1: SlotFocoAAMaterno(); break;
    case 2: SlotFocoARFC(); break;
    case 3: SlotFocoATelefono(); break;
    case 4: SlotFocoACorreo(); break;
    case 5: SlotFocoACalle(); break;
    case 6: SlotFocoANumero(); break;
    case 7: SlotFocoAColonia(); break;
    case 8: SlotFocoACP(); break;
    case 9: SlotFocoAMunicipio(); break;
    case 10: SlotFocoAEstado(); break;
    case 11: SlotFocoAAceptar(); break;
    case 12: SlotCliente((int)static_QUType_int.get(_o+1)); break;
    case 13: SlotNCliente(); break;
    case 14: SlotRegistraCliente(); break;
    case 15: SlotAceptar(); break;
    default:
	return CapturaClientes::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaClientes::qt_emit( int _id, QUObject* _o )
{
    return CapturaClientes::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaClientes::qt_property( int id, int f, QVariant* v)
{
    return CapturaClientes::qt_property( id, f, v);
}

bool QCapturaClientes::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
