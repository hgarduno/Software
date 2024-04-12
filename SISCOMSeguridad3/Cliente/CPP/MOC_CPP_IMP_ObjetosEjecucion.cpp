/****************************************************************************
** CQSisObjetosEjecucion meta object code from reading C++ file 'IMP_ObjetosEjecucion.h'
**
** Created: Thu Apr 11 21:35:58 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ObjetosEjecucion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisObjetosEjecucion::className() const
{
    return "CQSisObjetosEjecucion";
}

QMetaObject *CQSisObjetosEjecucion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisObjetosEjecucion( "CQSisObjetosEjecucion", &CQSisObjetosEjecucion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisObjetosEjecucion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisObjetosEjecucion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisObjetosEjecucion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisObjetosEjecucion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisObjetosEjecucion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ObjetosEjecucion::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionaObjeto", 4, param_slot_0 };
    static const QUMethod slot_1 = {"SlotAnexarObjeto", 0, 0 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionaObjeto(int,int,int,const QPoint&)", &slot_0, QMetaData::Private },
	{ "SlotAnexarObjeto()", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisObjetosEjecucion", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisObjetosEjecucion.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisObjetosEjecucion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisObjetosEjecucion" ) )
	return this;
    return ObjetosEjecucion::qt_cast( clname );
}

bool CQSisObjetosEjecucion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionaObjeto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 1: SlotAnexarObjeto(); break;
    case 2: SlotAceptar(); break;
    default:
	return ObjetosEjecucion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisObjetosEjecucion::qt_emit( int _id, QUObject* _o )
{
    return ObjetosEjecucion::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CQSisObjetosEjecucion::qt_property( int id, int f, QVariant* v)
{
    return ObjetosEjecucion::qt_property( id, f, v);
}

bool CQSisObjetosEjecucion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
