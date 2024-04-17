/****************************************************************************
** QPuntosAlumnos meta object code from reading C++ file 'IMP_PuntosAlumnos.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_PuntosAlumnos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPuntosAlumnos::className() const
{
    return "QPuntosAlumnos";
}

QMetaObject *QPuntosAlumnos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPuntosAlumnos( "QPuntosAlumnos", &QPuntosAlumnos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPuntosAlumnos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPuntosAlumnos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPuntosAlumnos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPuntosAlumnos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPuntosAlumnos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PuntosAlumnos::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotAlumno", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotValidaPSeleccion", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "pintFila", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotValidaPSeleccion", 4, param_slot_2 };
    static const QUMethod slot_3 = {"SlotReInicia", 0, 0 };
    static const QUMethod slot_4 = {"SlotTomaPromociones", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAlumno(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotValidaPSeleccion()", &slot_1, QMetaData::Private },
	{ "SlotValidaPSeleccion(int,int,int,const QPoint&)", &slot_2, QMetaData::Private },
	{ "SlotReInicia()", &slot_3, QMetaData::Private },
	{ "SlotTomaPromociones()", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPuntosAlumnos", parentObject,
	slot_tbl, 5,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPuntosAlumnos.setMetaObject( metaObj );
    return metaObj;
}

void* QPuntosAlumnos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPuntosAlumnos" ) )
	return this;
    return PuntosAlumnos::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QPuntosAlumnos::SignalTerminar( QWidget* t0 )
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

bool QPuntosAlumnos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAlumno((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotValidaPSeleccion(); break;
    case 2: SlotValidaPSeleccion((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 3: SlotReInicia(); break;
    case 4: SlotTomaPromociones(); break;
    default:
	return PuntosAlumnos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPuntosAlumnos::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return PuntosAlumnos::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QPuntosAlumnos::qt_property( int id, int f, QVariant* v)
{
    return PuntosAlumnos::qt_property( id, f, v);
}

bool QPuntosAlumnos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
