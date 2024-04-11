/****************************************************************************
** CQControlDireccion meta object code from reading C++ file 'IMP_QControlDireccion.h'
**
** Created: Sat Jan 27 17:40:00 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_QControlDireccion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQControlDireccion::className() const
{
    return "CQControlDireccion";
}

QMetaObject *CQControlDireccion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQControlDireccion( "CQControlDireccion", &CQControlDireccion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQControlDireccion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQControlDireccion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQControlDireccion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQControlDireccion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQControlDireccion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QControlDireccion::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoNumero", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoColonia", 0, 0 };
    static const QUMethod slot_2 = {"S_PasaFocoMunicipio", 0, 0 };
    static const QUMethod slot_3 = {"S_PasaFocoCP", 0, 0 };
    static const QUMethod slot_4 = {"S_PasaFocoEstado", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"S_CambioElCodigoPostal", 1, param_slot_5 };
    static const QUMethod slot_6 = {"S_EnterEstado", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoNumero()", &slot_0, QMetaData::Public },
	{ "S_PasaFocoColonia()", &slot_1, QMetaData::Public },
	{ "S_PasaFocoMunicipio()", &slot_2, QMetaData::Public },
	{ "S_PasaFocoCP()", &slot_3, QMetaData::Public },
	{ "S_PasaFocoEstado()", &slot_4, QMetaData::Public },
	{ "S_CambioElCodigoPostal(const QString&)", &slot_5, QMetaData::Public },
	{ "S_EnterEstado()", &slot_6, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"SignalEnterEstado", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalEnterEstado()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQControlDireccion", parentObject,
	slot_tbl, 7,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQControlDireccion.setMetaObject( metaObj );
    return metaObj;
}

void* CQControlDireccion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQControlDireccion" ) )
	return this;
    return QControlDireccion::qt_cast( clname );
}

// SIGNAL SignalEnterEstado
void CQControlDireccion::SignalEnterEstado()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool CQControlDireccion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoNumero(); break;
    case 1: S_PasaFocoColonia(); break;
    case 2: S_PasaFocoMunicipio(); break;
    case 3: S_PasaFocoCP(); break;
    case 4: S_PasaFocoEstado(); break;
    case 5: S_CambioElCodigoPostal((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: S_EnterEstado(); break;
    default:
	return QControlDireccion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQControlDireccion::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalEnterEstado(); break;
    default:
	return QControlDireccion::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CQControlDireccion::qt_property( int id, int f, QVariant* v)
{
    return QControlDireccion::qt_property( id, f, v);
}

bool CQControlDireccion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
