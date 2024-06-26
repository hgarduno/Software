/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaDepartamentos.ui'
**
** Created: Thu Apr 11 21:07:09 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaDepartamentos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaDepartamentos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CapturaDepartamentos::CapturaDepartamentos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CapturaDepartamentos" );
    CapturaDepartamentosLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDepartamentosLayout"); 

    layout92 = new QVBoxLayout( 0, 0, 6, "layout92"); 

    layout91 = new QHBoxLayout( 0, 0, 6, "layout91"); 

    layout330 = new QHBoxLayout( 0, 0, 6, "layout330"); 

    layout326 = new QVBoxLayout( 0, 0, 6, "layout326"); 

    textLabel19 = new QLabel( this, "textLabel19" );
    layout326->addWidget( textLabel19 );

    QLEDepartamento = new QLineEdit( this, "QLEDepartamento" );
    QLEDepartamento->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEDepartamento->sizePolicy().hasHeightForWidth() ) );
    layout326->addWidget( QLEDepartamento );
    layout330->addLayout( layout326 );

    QLayoutDepartamento = new QVBoxLayout( 0, 0, 6, "QLayoutDepartamento"); 

    textLabel21 = new QLabel( this, "textLabel21" );
    QLayoutDepartamento->addWidget( textLabel21 );

    QLEAbreviatura = new QLineEdit( this, "QLEAbreviatura" );
    QLEAbreviatura->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEAbreviatura->sizePolicy().hasHeightForWidth() ) );
    QLayoutDepartamento->addWidget( QLEAbreviatura );
    layout330->addLayout( QLayoutDepartamento );
    layout91->addLayout( layout330 );
    spacer3 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout91->addItem( spacer3 );

    checkBox12 = new QCheckBox( this, "checkBox12" );
    layout91->addWidget( checkBox12 );
    layout92->addLayout( layout91 );

    layout329 = new QVBoxLayout( 0, 0, 6, "layout329"); 

    textLabel20 = new QLabel( this, "textLabel20" );
    layout329->addWidget( textLabel20 );

    QLENombreDepartamento = new QLineEdit( this, "QLENombreDepartamento" );
    layout329->addWidget( QLENombreDepartamento );
    layout92->addLayout( layout329 );

    layout90 = new QHBoxLayout( 0, 0, 6, "layout90"); 

    QPBCrear = new QPushButton( this, "QPBCrear" );
    layout90->addWidget( QPBCrear );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout90->addWidget( QPBCancelar );

    pushButton28 = new QPushButton( this, "pushButton28" );
    layout90->addWidget( pushButton28 );

    pushButton48 = new QPushButton( this, "pushButton48" );
    layout90->addWidget( pushButton48 );
    layout92->addLayout( layout90 );

    CapturaDepartamentosLayout->addLayout( layout92, 0, 0 );
    languageChange();
    resize( QSize(389, 176).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDepartamentos::~CapturaDepartamentos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDepartamentos::languageChange()
{
    setCaption( tr( "Captura Departamentos" ) );
    textLabel19->setText( tr( "Departamento:" ) );
    textLabel21->setText( tr( "Abreviatura:" ) );
    checkBox12->setText( QString::null );
    checkBox12->setProperty( "orientation", tr( "Horizontal" ) );
    checkBox12->setProperty( "sizeType", tr( "Expanding" ) );
    textLabel20->setText( tr( "Nombre Departamento:" ) );
    QPBCrear->setText( tr( "Crear" ) );
    QPBCancelar->setText( tr( "Consultar" ) );
    pushButton28->setText( tr( "Actualizar" ) );
    pushButton48->setText( tr( "Cancelar" ) );
}

