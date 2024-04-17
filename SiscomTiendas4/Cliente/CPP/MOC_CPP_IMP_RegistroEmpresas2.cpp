/****************************************************************************
** QRegistroEmpresas2 meta object code from reading C++ file 'IMP_RegistroEmpresas2.h'
**
** Created: Fri Apr 12 21:36:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroEmpresas2.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroEmpresas2::className() const
{
    return "QRegistroEmpresas2";
}

QMetaObject *QRegistroEmpresas2::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroEmpresas2( "QRegistroEmpresas2", &QRegistroEmpresas2::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroEmpresas2::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroEmpresas2", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroEmpresas2::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroEmpresas2", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroEmpresas2::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroEmpresas2::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAnexarDireccion", 0, 0 };
    static const QUMethod slot_1 = {"SlotAnexarContacto", 0, 0 };
    static const QUMethod slot_2 = {"SlotAnexarMedioComunicacion", 0, 0 };
    static const QUMethod slot_3 = {"SlotRegistra", 0, 0 };
    static const QUMethod slot_4 = {"SlotVerificaEmpresa", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotTipoEmpresa", 1, param_slot_5 };
    static const QUMethod slot_6 = {"SlotPasaFocoTipoEmpresa", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAnexarDireccion()", &slot_0, QMetaData::Private },
	{ "SlotAnexarContacto()", &slot_1, QMetaData::Private },
	{ "SlotAnexarMedioComunicacion()", &slot_2, QMetaData::Private },
	{ "SlotRegistra()", &slot_3, QMetaData::Private },
	{ "SlotVerificaEmpresa()", &slot_4, QMetaData::Private },
	{ "SlotTipoEmpresa(int)", &slot_5, QMetaData::Private },
	{ "SlotPasaFocoTipoEmpresa()", &slot_6, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroEmpresas2", parentObject,
	slot_tbl, 7,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroEmpresas2.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroEmpresas2::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroEmpresas2" ) )
	return this;
    return RegistroEmpresas2::qt_cast( clname );
}

bool QRegistroEmpresas2::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAnexarDireccion(); break;
    case 1: SlotAnexarContacto(); break;
    case 2: SlotAnexarMedioComunicacion(); break;
    case 3: SlotRegistra(); break;
    case 4: SlotVerificaEmpresa(); break;
    case 5: SlotTipoEmpresa((int)static_QUType_int.get(_o+1)); break;
    case 6: SlotPasaFocoTipoEmpresa(); break;
    default:
	return RegistroEmpresas2::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroEmpresas2::qt_emit( int _id, QUObject* _o )
{
    return RegistroEmpresas2::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistroEmpresas2::qt_property( int id, int f, QVariant* v)
{
    return RegistroEmpresas2::qt_property( id, f, v);
}

bool QRegistroEmpresas2::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
