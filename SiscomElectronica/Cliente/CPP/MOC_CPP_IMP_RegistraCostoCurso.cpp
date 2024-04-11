/****************************************************************************
** QRegistraCostoCurso meta object code from reading C++ file 'IMP_RegistraCostoCurso.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistraCostoCurso.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistraCostoCurso::className() const
{
    return "QRegistraCostoCurso";
}

QMetaObject *QRegistraCostoCurso::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistraCostoCurso( "QRegistraCostoCurso", &QRegistraCostoCurso::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistraCostoCurso::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistraCostoCurso", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistraCostoCurso::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistraCostoCurso", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistraCostoCurso::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistraCostoCurso::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotExplicacionPromocion", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotFocoAAnexar", 0, 0 };
    static const QUMethod slot_2 = {"SlotAnexarPrecio", 0, 0 };
    static const QUMethod slot_3 = {"SlotRegistraPrecios", 0, 0 };
    static const QUMethod slot_4 = {"SlotTerminar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotExplicacionPromocion(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotFocoAAnexar()", &slot_1, QMetaData::Private },
	{ "SlotAnexarPrecio()", &slot_2, QMetaData::Private },
	{ "SlotRegistraPrecios()", &slot_3, QMetaData::Private },
	{ "SlotTerminar()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistraCostoCurso", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistraCostoCurso.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistraCostoCurso::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistraCostoCurso" ) )
	return this;
    return RegistraCostoCurso::qt_cast( clname );
}

bool QRegistraCostoCurso::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotExplicacionPromocion((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFocoAAnexar(); break;
    case 2: SlotAnexarPrecio(); break;
    case 3: SlotRegistraPrecios(); break;
    case 4: SlotTerminar(); break;
    default:
	return RegistraCostoCurso::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistraCostoCurso::qt_emit( int _id, QUObject* _o )
{
    return RegistraCostoCurso::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistraCostoCurso::qt_property( int id, int f, QVariant* v)
{
    return RegistraCostoCurso::qt_property( id, f, v);
}

bool QRegistraCostoCurso::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
