/****************************************************************************
** Form implementation generated from reading ui file 'UI/AdministracionCajas.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_AdministracionCajas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a AdministracionCajas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
AdministracionCajas::AdministracionCajas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "AdministracionCajas" );
    AdministracionCajasLayout = new QGridLayout( this, 1, 1, 11, 6, "AdministracionCajasLayout"); 

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    layout9 = new QVBoxLayout( 0, 0, 0, "layout9"); 

    QPBRangoFechas = new QPushButton( this, "QPBRangoFechas" );
    QPBRangoFechas->setMinimumSize( QSize( 0, 80 ) );
    layout9->addWidget( QPBRangoFechas );

    QPBRangoFechas_2 = new QPushButton( this, "QPBRangoFechas_2" );
    QPBRangoFechas_2->setMinimumSize( QSize( 0, 80 ) );
    layout9->addWidget( QPBRangoFechas_2 );

    QPBRangoFechas_2_2 = new QPushButton( this, "QPBRangoFechas_2_2" );
    QPBRangoFechas_2_2->setMinimumSize( QSize( 0, 80 ) );
    layout9->addWidget( QPBRangoFechas_2_2 );

    QPBRangoFechas_2_3 = new QPushButton( this, "QPBRangoFechas_2_3" );
    QPBRangoFechas_2_3->setMinimumSize( QSize( 0, 80 ) );
    layout9->addWidget( QPBRangoFechas_2_3 );
    layout15->addLayout( layout9 );
    spacer2 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout15->addItem( spacer2 );

    AdministracionCajasLayout->addLayout( layout15, 0, 0 );

    QTWOCajas = new QTabWidget( this, "QTWOCajas" );

    tab = new QWidget( QTWOCajas, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( tab, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QTCajasRegistradas = new QTable( tab, "QTCajasRegistradas" );
    QTCajasRegistradas->setNumCols( QTCajasRegistradas->numCols() + 1 );
    QTCajasRegistradas->horizontalHeader()->setLabel( QTCajasRegistradas->numCols() - 1, tr( "Caja" ) );
    QTCajasRegistradas->setNumCols( QTCajasRegistradas->numCols() + 1 );
    QTCajasRegistradas->horizontalHeader()->setLabel( QTCajasRegistradas->numCols() - 1, tr( "Estado" ) );
    QTCajasRegistradas->setNumRows( 0 );
    QTCajasRegistradas->setNumCols( 2 );
    QTCajasRegistradas->setReadOnly( TRUE );
    layout1->addWidget( QTCajasRegistradas );

    tabLayout->addMultiCellLayout( layout1, 0, 0, 0, 2 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel4 = new QLabel( tab, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( textLabel4 );

    QLEImporteCaja = new QLineEdit( tab, "QLEImporteCaja" );
    QLEImporteCaja->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEImporteCaja->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( QLEImporteCaja );

    tabLayout->addLayout( layout11, 1, 0 );

    QPBRegistrarImporte = new QPushButton( tab, "QPBRegistrarImporte" );
    QPBRegistrarImporte->setEnabled( TRUE );
    QPBRegistrarImporte->setMinimumSize( QSize( 0, 40 ) );

    tabLayout->addWidget( QPBRegistrarImporte, 1, 1 );

    QPBActualizar = new QPushButton( tab, "QPBActualizar" );
    QPBActualizar->setEnabled( TRUE );
    QPBActualizar->setMinimumSize( QSize( 0, 40 ) );

    tabLayout->addWidget( QPBActualizar, 1, 2 );
    QTWOCajas->insertTab( tab, QString::fromLatin1("") );

    AdministracionCajasLayout->addWidget( QTWOCajas, 0, 1 );
    languageChange();
    resize( QSize(686, 424).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AdministracionCajas::~AdministracionCajas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AdministracionCajas::languageChange()
{
    setCaption( tr( "Administracion De Cajas" ) );
    QPBRangoFechas->setText( tr( "Inicia\n"
"Caja" ) );
    QPBRangoFechas_2->setText( tr( "Captura Rango\n"
"    De Fechas" ) );
    QPBRangoFechas_2_2->setText( tr( "Captura Rango\n"
"    De Fechas" ) );
    QPBRangoFechas_2_3->setText( tr( "Captura Rango\n"
"    De Fechas" ) );
    textLabel1->setText( tr( "Cajas" ) );
    QTCajasRegistradas->horizontalHeader()->setLabel( 0, tr( "Caja" ) );
    QTCajasRegistradas->horizontalHeader()->setLabel( 1, tr( "Estado" ) );
    textLabel4->setText( tr( "Importe Caja" ) );
    QPBRegistrarImporte->setText( tr( "Registrar \n"
"Importe" ) );
    QPBActualizar->setText( tr( "Actualizar\n"
"Informacion" ) );
    QTWOCajas->changeTab( tab, tr( "Inicia Caja" ) );
}

