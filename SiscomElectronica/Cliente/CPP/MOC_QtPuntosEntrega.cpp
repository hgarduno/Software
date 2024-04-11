/****************************************************************************
** QtPuntosEntrega meta object code from reading C++ file 'QtPuntosEntrega.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtPuntosEntrega.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtPuntosEntrega::className() const
{
    return "QtPuntosEntrega";
}

QMetaObject *QtPuntosEntrega::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtPuntosEntrega( "QtPuntosEntrega", &QtPuntosEntrega::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtPuntosEntrega::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtPuntosEntrega", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtPuntosEntrega::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtPuntosEntrega", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtPuntosEntrega::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PuntosEntrega::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoACalle", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoANumExterior", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoANumInterior", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAMunicipio", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoAColonia", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoACP", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAEstado", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoAReferencias", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoACalle()", &slot_0, QMetaData::Private },
	{ "SlotFocoANumExterior()", &slot_1, QMetaData::Private },
	{ "SlotFocoANumInterior()", &slot_2, QMetaData::Private },
	{ "SlotFocoAMunicipio()", &slot_3, QMetaData::Private },
	{ "SlotFocoAColonia()", &slot_4, QMetaData::Private },
	{ "SlotFocoACP()", &slot_5, QMetaData::Private },
	{ "SlotFocoAEstado()", &slot_6, QMetaData::Private },
	{ "SlotFocoAReferencias()", &slot_7, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtPuntosEntrega", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtPuntosEntrega.setMetaObject( metaObj );
    return metaObj;
}

void* QtPuntosEntrega::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtPuntosEntrega" ) )
	return this;
    return PuntosEntrega::qt_cast( clname );
}

bool QtPuntosEntrega::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoACalle(); break;
    case 1: SlotFocoANumExterior(); break;
    case 2: SlotFocoANumInterior(); break;
    case 3: SlotFocoAMunicipio(); break;
    case 4: SlotFocoAColonia(); break;
    case 5: SlotFocoACP(); break;
    case 6: SlotFocoAEstado(); break;
    case 7: SlotFocoAReferencias(); break;
    default:
	return PuntosEntrega::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtPuntosEntrega::qt_emit( int _id, QUObject* _o )
{
    return PuntosEntrega::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtPuntosEntrega::qt_property( int id, int f, QVariant* v)
{
    return PuntosEntrega::qt_property( id, f, v);
}

bool QtPuntosEntrega::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
