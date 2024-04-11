/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaConceptosExistencias.ui'
**
** Created: Thu Apr 11 21:07:09 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaConceptosExistencias.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qgroupbox.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaConceptosExistencias as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CapturaConceptosExistencias::CapturaConceptosExistencias( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CapturaConceptosExistencias" );
    CapturaConceptosExistenciasLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaConceptosExistenciasLayout"); 

    layout83 = new QVBoxLayout( 0, 0, 6, "layout83"); 

    layout249 = new QHBoxLayout( 0, 0, 6, "layout249"); 

    layout244 = new QVBoxLayout( 0, 0, 6, "layout244"); 

    textLabel9 = new QLabel( this, "textLabel9" );
    layout244->addWidget( textLabel9 );

    lineEdit71 = new QLineEdit( this, "lineEdit71" );
    layout244->addWidget( lineEdit71 );
    layout249->addLayout( layout244 );
    spacer8 = new QSpacerItem( 321, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout249->addItem( spacer8 );
    layout83->addLayout( layout249 );

    layout247 = new QHBoxLayout( 0, 0, 6, "layout247"); 

    layout245 = new QVBoxLayout( 0, 0, 6, "layout245"); 

    textLabel10 = new QLabel( this, "textLabel10" );
    layout245->addWidget( textLabel10 );

    lineEdit72 = new QLineEdit( this, "lineEdit72" );
    layout245->addWidget( lineEdit72 );
    layout247->addLayout( layout245 );

    layout246 = new QVBoxLayout( 0, 0, 6, "layout246"); 

    textLabel11 = new QLabel( this, "textLabel11" );
    layout246->addWidget( textLabel11 );

    lineEdit73 = new QLineEdit( this, "lineEdit73" );
    lineEdit73->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit73->sizePolicy().hasHeightForWidth() ) );
    layout246->addWidget( lineEdit73 );
    layout247->addLayout( layout246 );
    layout83->addLayout( layout247 );

    buttonGroup1 = new QButtonGroup( this, "buttonGroup1" );
    buttonGroup1->setColumnLayout(0, Qt::Vertical );
    buttonGroup1->layout()->setSpacing( 6 );
    buttonGroup1->layout()->setMargin( 11 );
    buttonGroup1Layout = new QGridLayout( buttonGroup1->layout() );
    buttonGroup1Layout->setAlignment( Qt::AlignTop );

    layout243 = new QHBoxLayout( 0, 0, 6, "layout243"); 

    radioButton17 = new QRadioButton( buttonGroup1, "radioButton17" );
    layout243->addWidget( radioButton17 );

    radioButton18 = new QRadioButton( buttonGroup1, "radioButton18" );
    layout243->addWidget( radioButton18 );

    buttonGroup1Layout->addLayout( layout243, 0, 0 );
    layout83->addWidget( buttonGroup1 );

    groupBox9 = new QGroupBox( this, "groupBox9" );
    groupBox9->setColumnLayout(0, Qt::Vertical );
    groupBox9->layout()->setSpacing( 6 );
    groupBox9->layout()->setMargin( 11 );
    groupBox9Layout = new QGridLayout( groupBox9->layout() );
    groupBox9Layout->setAlignment( Qt::AlignTop );

    layout242 = new QHBoxLayout( 0, 0, 6, "layout242"); 

    layout240 = new QVBoxLayout( 0, 0, 6, "layout240"); 

    checkBox6 = new QCheckBox( groupBox9, "checkBox6" );
    layout240->addWidget( checkBox6 );

    checkBox8 = new QCheckBox( groupBox9, "checkBox8" );
    layout240->addWidget( checkBox8 );
    layout242->addLayout( layout240 );

    layout241 = new QVBoxLayout( 0, 0, 6, "layout241"); 

    checkBox7 = new QCheckBox( groupBox9, "checkBox7" );
    layout241->addWidget( checkBox7 );

    checkBox9 = new QCheckBox( groupBox9, "checkBox9" );
    layout241->addWidget( checkBox9 );
    layout242->addLayout( layout241 );

    groupBox9Layout->addLayout( layout242, 0, 0 );
    layout83->addWidget( groupBox9 );

    layout82 = new QHBoxLayout( 0, 0, 6, "layout82"); 

    pushButton31 = new QPushButton( this, "pushButton31" );
    layout82->addWidget( pushButton31 );

    pushButton23 = new QPushButton( this, "pushButton23" );
    layout82->addWidget( pushButton23 );

    pushButton24 = new QPushButton( this, "pushButton24" );
    layout82->addWidget( pushButton24 );

    pushButton32 = new QPushButton( this, "pushButton32" );
    layout82->addWidget( pushButton32 );
    layout83->addLayout( layout82 );

    CapturaConceptosExistenciasLayout->addLayout( layout83, 0, 0 );
    languageChange();
    resize( QSize(501, 274).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaConceptosExistencias::~CapturaConceptosExistencias()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaConceptosExistencias::languageChange()
{
    setCaption( tr( "Captura Conceptos de Existencias" ) );
    textLabel9->setText( tr( "Clave Concepto:" ) );
    textLabel10->setText( tr( "Nombre Concepto:" ) );
    textLabel11->setText( tr( "Abreviatura:" ) );
    buttonGroup1->setTitle( QString::null );
    radioButton17->setText( tr( "Entrada" ) );
    radioButton18->setText( tr( "Salida" ) );
    groupBox9->setTitle( tr( "Seleccione las opciones deseadas:" ) );
    checkBox6->setText( tr( "Afecta Stock" ) );
    checkBox8->setText( tr( "Crea cuenta por pagar" ) );
    checkBox7->setText( tr( "Crea Factura Financiadora" ) );
    checkBox9->setText( tr( "Crea cuenta por cobrar" ) );
    pushButton31->setText( tr( "Crear" ) );
    pushButton23->setText( tr( "Consultar" ) );
    pushButton24->setText( tr( "Actualizar" ) );
    pushButton32->setText( tr( "Cancelar" ) );
}

