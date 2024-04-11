/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/MultiApoyos.ui'
**
** Created: Sat Jan 27 16:38:25 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "MultiApoyos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a MultiApoyos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
MultiApoyos::MultiApoyos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "MultiApoyos" );
    MultiApoyosLayout = new QGridLayout( this, 1, 1, 11, 6, "MultiApoyosLayout"); 

    QTEFormato = new QTextEdit( this, "QTEFormato" );

    MultiApoyosLayout->addWidget( QTEFormato, 0, 0 );

    layout32 = new QGridLayout( 0, 1, 1, 0, 6, "layout32"); 

    QPBImprimeAArchivo = new QPushButton( this, "QPBImprimeAArchivo" );

    layout32->addMultiCellWidget( QPBImprimeAArchivo, 0, 0, 5, 6 );

    QPBImprimeFrente = new QPushButton( this, "QPBImprimeFrente" );

    layout32->addWidget( QPBImprimeFrente, 1, 6 );

    QPBDomicilioParticular = new QPushButton( this, "QPBDomicilioParticular" );

    layout32->addWidget( QPBDomicilioParticular, 0, 1 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );

    layout32->addWidget( QPBImprimir, 1, 3 );

    QPBReferenciasPersonales = new QPushButton( this, "QPBReferenciasPersonales" );

    layout32->addMultiCellWidget( QPBReferenciasPersonales, 0, 0, 3, 4 );

    QPBImprimeAtras = new QPushButton( this, "QPBImprimeAtras" );

    layout32->addMultiCellWidget( QPBImprimeAtras, 1, 1, 4, 5 );

    QPBDatosGenerales = new QPushButton( this, "QPBDatosGenerales" );

    layout32->addWidget( QPBDatosGenerales, 1, 0 );

    QPBDatosEmpleo = new QPushButton( this, "QPBDatosEmpleo" );

    layout32->addWidget( QPBDatosEmpleo, 1, 1 );

    QPBIngresosMensuales = new QPushButton( this, "QPBIngresosMensuales" );

    layout32->addWidget( QPBIngresosMensuales, 1, 2 );

    QPBRFCCliente = new QPushButton( this, "QPBRFCCliente" );

    layout32->addWidget( QPBRFCCliente, 0, 0 );

    QPBDomicilioEmpleo = new QPushButton( this, "QPBDomicilioEmpleo" );

    layout32->addWidget( QPBDomicilioEmpleo, 0, 2 );

    MultiApoyosLayout->addLayout( layout32, 1, 0 );
    languageChange();
    resize( QSize(857, 460).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MultiApoyos::~MultiApoyos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MultiApoyos::languageChange()
{
    setCaption( tr( "MultiApoyos" ) );
    QPBImprimeAArchivo->setText( tr( "Imprime A Archivo" ) );
    QPBImprimeFrente->setText( tr( "Imprime Frente" ) );
    QPBDomicilioParticular->setText( tr( "Domicilio Particular" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QPBReferenciasPersonales->setText( tr( "Referencias Personales" ) );
    QPBImprimeAtras->setText( tr( "Imprime Atras" ) );
    QPBDatosGenerales->setText( tr( "Datos Generales" ) );
    QPBDatosEmpleo->setText( tr( "Datos de Empleo" ) );
    QPBIngresosMensuales->setText( tr( "Ingresos Mensuales" ) );
    QPBRFCCliente->setText( tr( "RFC Cliente" ) );
    QPBDomicilioEmpleo->setText( tr( "Domicilio de Empleo" ) );
}

