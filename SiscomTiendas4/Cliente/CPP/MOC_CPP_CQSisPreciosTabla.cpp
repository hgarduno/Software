/****************************************************************************
** CQSisPreciosTabla meta object code from reading C++ file 'CQSisPreciosTabla.h'
**
** Created: Fri Apr 12 21:36:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/CQSisPreciosTabla.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisPreciosTabla::className() const
{
    return "CQSisPreciosTabla";
}

QMetaObject *CQSisPreciosTabla::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisPreciosTabla( "CQSisPreciosTabla", &CQSisPreciosTabla::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisPreciosTabla::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisPreciosTabla", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisPreciosTabla::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisPreciosTabla", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisPreciosTabla::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QComboBox::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotPrecio", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPrecio(int)", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "CQSisPrecio", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalPrecio", 3, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalPrecio(CQSisPrecio*,int,int)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisPreciosTabla", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisPreciosTabla.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisPreciosTabla::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisPreciosTabla" ) )
	return this;
    return QComboBox::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalPrecio
void CQSisPreciosTabla::SignalPrecio( CQSisPrecio* t0, int t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

bool CQSisPreciosTabla::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPrecio((int)static_QUType_int.get(_o+1)); break;
    default:
	return QComboBox::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisPreciosTabla::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalPrecio((CQSisPrecio*)static_QUType_ptr.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    default:
	return QComboBox::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CQSisPreciosTabla::qt_property( int id, int f, QVariant* v)
{
    return QComboBox::qt_property( id, f, v);
}

bool CQSisPreciosTabla::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
