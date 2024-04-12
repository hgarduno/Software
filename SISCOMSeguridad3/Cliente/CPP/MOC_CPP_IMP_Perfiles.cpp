/****************************************************************************
** CQSisPerfiles meta object code from reading C++ file 'IMP_Perfiles.h'
**
** Created: Thu Apr 11 21:36:14 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Perfiles.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisPerfiles::className() const
{
    return "CQSisPerfiles";
}

QMetaObject *CQSisPerfiles::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisPerfiles( "CQSisPerfiles", &CQSisPerfiles::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisPerfiles::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisPerfiles", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisPerfiles::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisPerfiles", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisPerfiles::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Perfiles::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRegistraPerfil", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRegistraPerfil()", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "CQPerfiles", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalRegistroPerfil", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalRegistroPerfil(CQPerfiles*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisPerfiles", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisPerfiles.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisPerfiles::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisPerfiles" ) )
	return this;
    return Perfiles::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalRegistroPerfil
void CQSisPerfiles::SignalRegistroPerfil( CQPerfiles* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool CQSisPerfiles::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRegistraPerfil(); break;
    default:
	return Perfiles::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisPerfiles::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalRegistroPerfil((CQPerfiles*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Perfiles::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CQSisPerfiles::qt_property( int id, int f, QVariant* v)
{
    return Perfiles::qt_property( id, f, v);
}

bool CQSisPerfiles::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
