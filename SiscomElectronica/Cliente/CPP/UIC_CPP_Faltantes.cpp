/****************************************************************************
** Form implementation generated from reading ui file 'UI/Faltantes.ui'
**
** Created: Wed Apr 10 20:52:38 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Faltantes.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a Faltantes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Faltantes::Faltantes( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "Faltantes" );
    FaltantesLayout = new QGridLayout( this, 1, 1, 11, 6, "FaltantesLayout"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout7->addWidget( textLabel3 );

    table4 = new QTable( this, "table4" );
    table4->setNumCols( table4->numCols() + 1 );
    table4->horizontalHeader()->setLabel( table4->numCols() - 1, tr( "1" ) );
    table4->setNumCols( table4->numCols() + 1 );
    table4->horizontalHeader()->setLabel( table4->numCols() - 1, tr( "2" ) );
    table4->setNumCols( table4->numCols() + 1 );
    table4->horizontalHeader()->setLabel( table4->numCols() - 1, tr( "3" ) );
    table4->setNumRows( 0 );
    table4->setNumCols( 3 );
    layout7->addWidget( table4 );

    FaltantesLayout->addLayout( layout7, 1, 0 );

    layout26 = new QHBoxLayout( 0, 0, 6, "layout26"); 

    pushButton3 = new QPushButton( this, "pushButton3" );
    pushButton3->setAutoDefault( FALSE );
    layout26->addWidget( pushButton3 );

    pushButton3_2 = new QPushButton( this, "pushButton3_2" );
    pushButton3_2->setAutoDefault( FALSE );
    layout26->addWidget( pushButton3_2 );

    pushButton3_2_2 = new QPushButton( this, "pushButton3_2_2" );
    pushButton3_2_2->setAutoDefault( FALSE );
    layout26->addWidget( pushButton3_2_2 );

    FaltantesLayout->addLayout( layout26, 2, 0 );

    QTWTipoProducto = new QTabWidget( this, "QTWTipoProducto" );
    QTWTipoProducto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTWTipoProducto->sizePolicy().hasHeightForWidth() ) );

    tab = new QWidget( QTWTipoProducto, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout24 = new QHBoxLayout( 0, 0, 6, "layout24"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1 = new QLabel( tab, "textLabel1" );
    layout5->addWidget( textLabel1 );

    QLEProducto = new QLineEdit( tab, "QLEProducto" );
    QLEProducto->setReadOnly( FALSE );
    layout5->addWidget( QLEProducto );
    layout24->addLayout( layout5 );

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel4 = new QLabel( tab, "textLabel4" );
    layout22->addWidget( textLabel4 );

    QLECantidad = new QLineEdit( tab, "QLECantidad" );
    layout22->addWidget( QLECantidad );
    layout24->addLayout( layout22 );

    tabLayout->addMultiCellLayout( layout24, 0, 0, 0, 1 );

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel5 = new QLabel( tab, "textLabel5" );
    layout23->addWidget( textLabel5 );

    textEdit3 = new QTextEdit( tab, "textEdit3" );
    layout23->addWidget( textEdit3 );

    tabLayout->addLayout( layout23, 1, 1 );

    layout23_3 = new QVBoxLayout( 0, 0, 6, "layout23_3"); 

    textLabel5_3 = new QLabel( tab, "textLabel5_3" );
    layout23_3->addWidget( textLabel5_3 );

    QTEDescripcion = new QTextEdit( tab, "QTEDescripcion" );
    layout23_3->addWidget( QTEDescripcion );

    tabLayout->addLayout( layout23_3, 1, 0 );
    QTWTipoProducto->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( QTWTipoProducto, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel1_2 = new QLabel( tab_2, "textLabel1_2" );
    layout5_2->addWidget( textLabel1_2 );

    QLENvoProducto = new QLineEdit( tab_2, "QLENvoProducto" );
    QLENvoProducto->setReadOnly( TRUE );
    layout5_2->addWidget( QLENvoProducto );

    tabLayout_2->addLayout( layout5_2, 0, 0 );

    layout23_2 = new QVBoxLayout( 0, 0, 6, "layout23_2"); 

    textLabel5_2 = new QLabel( tab_2, "textLabel5_2" );
    layout23_2->addWidget( textLabel5_2 );

    QTEDescripcionNvo = new QTextEdit( tab_2, "QTEDescripcionNvo" );
    layout23_2->addWidget( QTEDescripcionNvo );

    tabLayout_2->addLayout( layout23_2, 1, 0 );

    layout23_2_2 = new QVBoxLayout( 0, 0, 6, "layout23_2_2"); 

    textLabel5_2_2 = new QLabel( tab_2, "textLabel5_2_2" );
    layout23_2_2->addWidget( textLabel5_2_2 );

    textEdit3_2_2 = new QTextEdit( tab_2, "textEdit3_2_2" );
    layout23_2_2->addWidget( textEdit3_2_2 );

    tabLayout_2->addMultiCellLayout( layout23_2_2, 0, 1, 1, 1 );
    QTWTipoProducto->insertTab( tab_2, QString::fromLatin1("") );

    FaltantesLayout->addWidget( QTWTipoProducto, 0, 0 );
    languageChange();
    resize( QSize(600, 434).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Faltantes::~Faltantes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Faltantes::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel3->setText( tr( "Lista de Faltantes" ) );
    table4->horizontalHeader()->setLabel( 0, tr( "1" ) );
    table4->horizontalHeader()->setLabel( 1, tr( "2" ) );
    table4->horizontalHeader()->setLabel( 2, tr( "3" ) );
    pushButton3->setText( tr( "Agregar Faltante" ) );
    pushButton3_2->setText( tr( "pushButton3" ) );
    pushButton3_2_2->setText( tr( "pushButton3" ) );
    textLabel1->setText( tr( "Producto Siscom" ) );
    textLabel4->setText( tr( "Cantidad" ) );
    textLabel5->setText( tr( "Observaciones" ) );
    textLabel5_3->setText( tr( "Descripcion" ) );
    QTWTipoProducto->changeTab( tab, tr( "Producto Registrado" ) );
    textLabel1_2->setText( tr( "Producto Siscom" ) );
    textLabel5_2->setText( tr( "Descripcion" ) );
    textLabel5_2_2->setText( tr( "Observaciones" ) );
    QTWTipoProducto->changeTab( tab_2, tr( "Nuevo Producto" ) );
}

