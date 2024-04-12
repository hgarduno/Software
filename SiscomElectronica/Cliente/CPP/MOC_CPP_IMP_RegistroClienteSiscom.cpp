/****************************************************************************
** QRegistroClienteSiscom meta object code from reading C++ file 'IMP_RegistroClienteSiscom.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroClienteSiscom.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroClienteSiscom::className() const
{
    return "QRegistroClienteSiscom";
}

QMetaObject *QRegistroClienteSiscom::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroClienteSiscom( "QRegistroClienteSiscom", &QRegistroClienteSiscom::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroClienteSiscom::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroClienteSiscom", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroClienteSiscom::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroClienteSiscom", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroClienteSiscom::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroClienteSiscom::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAAPaterno", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoAAMaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoAEscuela", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAGrupo", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoABoleta", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoACorreo", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAReCorreo", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoACelular", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoATCasa", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_9 = {"SlotEscuelas", 1, param_slot_9 };
    static const QUMethod slot_10 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_11 = {"SlotRegistra", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAAPaterno()", &slot_0, QMetaData::Private },
	{ "SlotFocoAAMaterno()", &slot_1, QMetaData::Private },
	{ "SlotFocoAEscuela()", &slot_2, QMetaData::Private },
	{ "SlotFocoAGrupo()", &slot_3, QMetaData::Private },
	{ "SlotFocoABoleta()", &slot_4, QMetaData::Private },
	{ "SlotFocoACorreo()", &slot_5, QMetaData::Private },
	{ "SlotFocoAReCorreo()", &slot_6, QMetaData::Private },
	{ "SlotFocoACelular()", &slot_7, QMetaData::Private },
	{ "SlotFocoATCasa()", &slot_8, QMetaData::Private },
	{ "SlotEscuelas(SiscomRegistro3*)", &slot_9, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_10, QMetaData::Private },
	{ "SlotRegistra()", &slot_11, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroClienteSiscom", parentObject,
	slot_tbl, 12,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroClienteSiscom.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroClienteSiscom::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroClienteSiscom" ) )
	return this;
    return RegistroClienteSiscom::qt_cast( clname );
}

bool QRegistroClienteSiscom::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAAPaterno(); break;
    case 1: SlotFocoAAMaterno(); break;
    case 2: SlotFocoAEscuela(); break;
    case 3: SlotFocoAGrupo(); break;
    case 4: SlotFocoABoleta(); break;
    case 5: SlotFocoACorreo(); break;
    case 6: SlotFocoAReCorreo(); break;
    case 7: SlotFocoACelular(); break;
    case 8: SlotFocoATCasa(); break;
    case 9: SlotEscuelas((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 10: SlotFocoARegistrar(); break;
    case 11: SlotRegistra(); break;
    default:
	return RegistroClienteSiscom::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroClienteSiscom::qt_emit( int _id, QUObject* _o )
{
    return RegistroClienteSiscom::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistroClienteSiscom::qt_property( int id, int f, QVariant* v)
{
    return RegistroClienteSiscom::qt_property( id, f, v);
}

bool QRegistroClienteSiscom::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
