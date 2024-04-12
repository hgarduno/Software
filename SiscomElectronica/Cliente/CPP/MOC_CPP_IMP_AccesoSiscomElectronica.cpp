/****************************************************************************
** QAccesoSiscomElectronica meta object code from reading C++ file 'IMP_AccesoSiscomElectronica.h'
**
** Created: Thu Apr 11 21:52:02 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_AccesoSiscomElectronica.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QAccesoSiscomElectronica::className() const
{
    return "QAccesoSiscomElectronica";
}

QMetaObject *QAccesoSiscomElectronica::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAccesoSiscomElectronica( "QAccesoSiscomElectronica", &QAccesoSiscomElectronica::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAccesoSiscomElectronica::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAccesoSiscomElectronica", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAccesoSiscomElectronica::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAccesoSiscomElectronica", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAccesoSiscomElectronica::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = AccesoSiscomElectronica::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pQIconViewItemDato", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTipoExpendio", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pQIconViewItemExpendio", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotExpendio", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "pQIconViewItemExpendioServidor", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotExpendioServidor", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "pQIconViewItempEmpleado", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotSeleccionaEmpleado", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotTipoLetra", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTipoExpendio(QIconViewItem*)", &slot_0, QMetaData::Private },
	{ "SlotExpendio(QIconViewItem*)", &slot_1, QMetaData::Private },
	{ "SlotExpendioServidor(QIconViewItem*)", &slot_2, QMetaData::Private },
	{ "SlotSeleccionaEmpleado(QIconViewItem*)", &slot_3, QMetaData::Private },
	{ "SlotTipoLetra()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QAccesoSiscomElectronica", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAccesoSiscomElectronica.setMetaObject( metaObj );
    return metaObj;
}

void* QAccesoSiscomElectronica::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAccesoSiscomElectronica" ) )
	return this;
    return AccesoSiscomElectronica::qt_cast( clname );
}

bool QAccesoSiscomElectronica::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTipoExpendio((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotExpendio((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotExpendioServidor((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotSeleccionaEmpleado((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotTipoLetra(); break;
    default:
	return AccesoSiscomElectronica::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QAccesoSiscomElectronica::qt_emit( int _id, QUObject* _o )
{
    return AccesoSiscomElectronica::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QAccesoSiscomElectronica::qt_property( int id, int f, QVariant* v)
{
    return AccesoSiscomElectronica::qt_property( id, f, v);
}

bool QAccesoSiscomElectronica::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
