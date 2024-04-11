/****************************************************************************
** QFamilias meta object code from reading C++ file 'IMP_Familias.h'
**
** Created: Wed Apr 10 21:11:50 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Familias.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QFamilias::className() const
{
    return "QFamilias";
}

QMetaObject *QFamilias::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFamilias( "QFamilias", &QFamilias::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFamilias::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFamilias", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFamilias::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFamilias", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFamilias::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = FamiliasQ::staticMetaObject();
    static const QUMethod slot_0 = {"S_Anexar", 0, 0 };
    static const QUMethod slot_1 = {"S_Registrar", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_2 = {"S_CambiaDatosFamilia", 4, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "S_Anexar()", &slot_0, QMetaData::Private },
	{ "S_Registrar()", &slot_1, QMetaData::Private },
	{ "S_CambiaDatosFamilia(int,int,int,const QPoint&)", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QFamilias", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFamilias.setMetaObject( metaObj );
    return metaObj;
}

void* QFamilias::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFamilias" ) )
	return this;
    return FamiliasQ::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QFamilias::SignalTerminar( QWidget* t0 )
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

bool QFamilias::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_Anexar(); break;
    case 1: S_Registrar(); break;
    case 2: S_CambiaDatosFamilia((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return FamiliasQ::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QFamilias::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return FamiliasQ::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QFamilias::qt_property( int id, int f, QVariant* v)
{
    return FamiliasQ::qt_property( id, f, v);
}

bool QFamilias::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
