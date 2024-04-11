/****************************************************************************
** CQControlFecha meta object code from reading C++ file 'IMP_QControlFecha.h'
**
** Created: Wed Jan 31 10:35:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_QControlFecha.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQControlFecha::className() const
{
    return "CQControlFecha";
}

QMetaObject *CQControlFecha::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQControlFecha( "CQControlFecha", &CQControlFecha::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQControlFecha::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQControlFecha", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQControlFecha::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQControlFecha", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQControlFecha::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoDia", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoMes", 0, 0 };
    static const QUMethod slot_2 = {"S_PasaFocoAno", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"S_CambioElA_o", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"S_CambioElMes", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"S_CambioElDia", 1, param_slot_5 };
    static const QUMethod slot_6 = {"S_IntrodujoA_o", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoDia()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoMes()", &slot_1, QMetaData::Private },
	{ "S_PasaFocoAno()", &slot_2, QMetaData::Private },
	{ "S_CambioElA_o(const QString&)", &slot_3, QMetaData::Private },
	{ "S_CambioElMes(const QString&)", &slot_4, QMetaData::Private },
	{ "S_CambioElDia(const QString&)", &slot_5, QMetaData::Private },
	{ "S_IntrodujoA_o()", &slot_6, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"Signal_EnterA_o", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "Signal_EnterA_o()", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQControlFecha", parentObject,
	slot_tbl, 7,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQControlFecha.setMetaObject( metaObj );
    return metaObj;
}

void* CQControlFecha::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQControlFecha" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL Signal_EnterA_o
void CQControlFecha::Signal_EnterA_o()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool CQControlFecha::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoDia(); break;
    case 1: S_PasaFocoMes(); break;
    case 2: S_PasaFocoAno(); break;
    case 3: S_CambioElA_o((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: S_CambioElMes((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: S_CambioElDia((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: S_IntrodujoA_o(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQControlFecha::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Signal_EnterA_o(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CQControlFecha::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool CQControlFecha::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
