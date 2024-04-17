/****************************************************************************
** QClavesSatSiscom meta object code from reading C++ file 'IMP_ClavesSatSiscom.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ClavesSatSiscom.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QClavesSatSiscom::className() const
{
    return "QClavesSatSiscom";
}

QMetaObject *QClavesSatSiscom::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QClavesSatSiscom( "QClavesSatSiscom", &QClavesSatSiscom::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QClavesSatSiscom::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClavesSatSiscom", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QClavesSatSiscom::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClavesSatSiscom", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QClavesSatSiscom::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ClavesSatSiscom::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionoProducto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotFocoAPalabraClave", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_3 = {"SlotRegistrar", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotCapturandoSat", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotCapturandoPalabraClave", 1, param_slot_5 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionoProducto(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotFocoAPalabraClave()", &slot_1, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_2, QMetaData::Private },
	{ "SlotRegistrar()", &slot_3, QMetaData::Private },
	{ "SlotCapturandoSat(const QString&)", &slot_4, QMetaData::Private },
	{ "SlotCapturandoPalabraClave(const QString&)", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QClavesSatSiscom", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QClavesSatSiscom.setMetaObject( metaObj );
    return metaObj;
}

void* QClavesSatSiscom::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QClavesSatSiscom" ) )
	return this;
    return ClavesSatSiscom::qt_cast( clname );
}

bool QClavesSatSiscom::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionoProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFocoAPalabraClave(); break;
    case 2: SlotFocoARegistrar(); break;
    case 3: SlotRegistrar(); break;
    case 4: SlotCapturandoSat((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: SlotCapturandoPalabraClave((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return ClavesSatSiscom::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QClavesSatSiscom::qt_emit( int _id, QUObject* _o )
{
    return ClavesSatSiscom::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QClavesSatSiscom::qt_property( int id, int f, QVariant* v)
{
    return ClavesSatSiscom::qt_property( id, f, v);
}

bool QClavesSatSiscom::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
