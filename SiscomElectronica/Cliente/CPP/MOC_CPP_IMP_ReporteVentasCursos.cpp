/****************************************************************************
** QReporteVentasCursos meta object code from reading C++ file 'IMP_ReporteVentasCursos.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ReporteVentasCursos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QReporteVentasCursos::className() const
{
    return "QReporteVentasCursos";
}

QMetaObject *QReporteVentasCursos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QReporteVentasCursos( "QReporteVentasCursos", &QReporteVentasCursos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QReporteVentasCursos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QReporteVentasCursos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QReporteVentasCursos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QReporteVentasCursos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QReporteVentasCursos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ReporteVentasCursos::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pSisReg3Fecha", &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProgramacionCurso", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProgramacionCurso(SiscomRegistro3*)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QReporteVentasCursos", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QReporteVentasCursos.setMetaObject( metaObj );
    return metaObj;
}

void* QReporteVentasCursos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QReporteVentasCursos" ) )
	return this;
    return ReporteVentasCursos::qt_cast( clname );
}

bool QReporteVentasCursos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProgramacionCurso((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ReporteVentasCursos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QReporteVentasCursos::qt_emit( int _id, QUObject* _o )
{
    return ReporteVentasCursos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QReporteVentasCursos::qt_property( int id, int f, QVariant* v)
{
    return ReporteVentasCursos::qt_property( id, f, v);
}

bool QReporteVentasCursos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
