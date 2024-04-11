/****************************************************************************
** QRegistrarCajaMaterial meta object code from reading C++ file 'IMP_RegistrarCajaMaterial.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistrarCajaMaterial.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistrarCajaMaterial::className() const
{
    return "QRegistrarCajaMaterial";
}

QMetaObject *QRegistrarCajaMaterial::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistrarCajaMaterial( "QRegistrarCajaMaterial", &QRegistrarCajaMaterial::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistrarCajaMaterial::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistrarCajaMaterial", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistrarCajaMaterial::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistrarCajaMaterial", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistrarCajaMaterial::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistrarCajaMaterial::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRegistrar", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotCapturandoCaja", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotCapturandoDescripcion", 0, 0 };
    static const QUMethod slot_3 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRegistrar()", &slot_0, QMetaData::Private },
	{ "SlotCapturandoCaja(const QString&)", &slot_1, QMetaData::Private },
	{ "SlotCapturandoDescripcion()", &slot_2, QMetaData::Private },
	{ "SlotAceptar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistrarCajaMaterial", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistrarCajaMaterial.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistrarCajaMaterial::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistrarCajaMaterial" ) )
	return this;
    return RegistrarCajaMaterial::qt_cast( clname );
}

bool QRegistrarCajaMaterial::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRegistrar(); break;
    case 1: SlotCapturandoCaja((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: SlotCapturandoDescripcion(); break;
    case 3: SlotAceptar(); break;
    default:
	return RegistrarCajaMaterial::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistrarCajaMaterial::qt_emit( int _id, QUObject* _o )
{
    return RegistrarCajaMaterial::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistrarCajaMaterial::qt_property( int id, int f, QVariant* v)
{
    return RegistrarCajaMaterial::qt_property( id, f, v);
}

bool QRegistrarCajaMaterial::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
