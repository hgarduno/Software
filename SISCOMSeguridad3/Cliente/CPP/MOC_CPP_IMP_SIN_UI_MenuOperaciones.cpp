/****************************************************************************
** CQSisMOperaciones meta object code from reading C++ file 'IMP_SIN_UI_MenuOperaciones.h'
**
** Created: Sat Jan 27 16:42:06 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SIN_UI_MenuOperaciones.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisMOperaciones::className() const
{
    return "CQSisMOperaciones";
}

QMetaObject *CQSisMOperaciones::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisMOperaciones( "CQSisMOperaciones", &CQSisMOperaciones::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisMOperaciones::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisMOperaciones", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisMOperaciones::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisMOperaciones", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisMOperaciones::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QPopupMenu::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAnexaObjTEjecucion", 0, 0 };
    static const QUMethod slot_1 = {"SlotEliminaObjTEjecucion", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAnexaObjTEjecucion()", &slot_0, QMetaData::Private },
	{ "SlotEliminaObjTEjecucion()", &slot_1, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"SignalAnexaObjeto", 0, 0 };
    static const QUMethod signal_1 = {"SignalEliminaObjeto", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalAnexaObjeto()", &signal_0, QMetaData::Private },
	{ "SignalEliminaObjeto()", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisMOperaciones", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisMOperaciones.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisMOperaciones::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisMOperaciones" ) )
	return this;
    return QPopupMenu::qt_cast( clname );
}

// SIGNAL SignalAnexaObjeto
void CQSisMOperaciones::SignalAnexaObjeto()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL SignalEliminaObjeto
void CQSisMOperaciones::SignalEliminaObjeto()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool CQSisMOperaciones::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAnexaObjTEjecucion(); break;
    case 1: SlotEliminaObjTEjecucion(); break;
    default:
	return QPopupMenu::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisMOperaciones::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalAnexaObjeto(); break;
    case 1: SignalEliminaObjeto(); break;
    default:
	return QPopupMenu::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CQSisMOperaciones::qt_property( int id, int f, QVariant* v)
{
    return QPopupMenu::qt_property( id, f, v);
}

bool CQSisMOperaciones::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
