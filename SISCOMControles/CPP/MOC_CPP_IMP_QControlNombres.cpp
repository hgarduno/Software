/****************************************************************************
** CQControlNombres meta object code from reading C++ file 'IMP_QControlNombres.h'
**
** Created: Sat Jan 27 17:40:05 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_QControlNombres.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQControlNombres::className() const
{
    return "CQControlNombres";
}

QMetaObject *CQControlNombres::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQControlNombres( "CQControlNombres", &CQControlNombres::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQControlNombres::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQControlNombres", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQControlNombres::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQControlNombres", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQControlNombres::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QControlNombres::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_2 = {"S_EnterAMaterno", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoAPaterno()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoAMaterno()", &slot_1, QMetaData::Private },
	{ "S_EnterAMaterno()", &slot_2, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"SignalEnterAMaterno", 0, 0 };
    static const QUMethod signal_1 = {"SignalEnterNombre", 0, 0 };
    static const QUMethod signal_2 = {"SignalEnterAPaterno", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalEnterAMaterno()", &signal_0, QMetaData::Private },
	{ "SignalEnterNombre()", &signal_1, QMetaData::Private },
	{ "SignalEnterAPaterno()", &signal_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQControlNombres", parentObject,
	slot_tbl, 3,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQControlNombres.setMetaObject( metaObj );
    return metaObj;
}

void* CQControlNombres::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQControlNombres" ) )
	return this;
    return QControlNombres::qt_cast( clname );
}

// SIGNAL SignalEnterAMaterno
void CQControlNombres::SignalEnterAMaterno()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL SignalEnterNombre
void CQControlNombres::SignalEnterNombre()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL SignalEnterAPaterno
void CQControlNombres::SignalEnterAPaterno()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

bool CQControlNombres::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoAPaterno(); break;
    case 1: S_PasaFocoAMaterno(); break;
    case 2: S_EnterAMaterno(); break;
    default:
	return QControlNombres::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQControlNombres::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalEnterAMaterno(); break;
    case 1: SignalEnterNombre(); break;
    case 2: SignalEnterAPaterno(); break;
    default:
	return QControlNombres::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CQControlNombres::qt_property( int id, int f, QVariant* v)
{
    return QControlNombres::qt_property( id, f, v);
}

bool CQControlNombres::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
