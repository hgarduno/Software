/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroEmpleados.ui'
**
** Created: Wed Apr 10 21:12:03 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroEmpleados.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a RegistroEmpleados as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroEmpleados::RegistroEmpleados( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroEmpleados" );
    RegistroEmpleadosLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroEmpleadosLayout"); 

    layout29 = new QHBoxLayout( 0, 0, 6, "layout29"); 

    layout27 = new QVBoxLayout( 0, 0, 6, "layout27"); 

    textLabel8 = new QLabel( this, "textLabel8" );
    textLabel8->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel8->sizePolicy().hasHeightForWidth() ) );
    layout27->addWidget( textLabel8 );

    QCBTelefonos = new QComboBox( FALSE, this, "QCBTelefonos" );
    QCBTelefonos->setMinimumSize( QSize( 150, 0 ) );
    QCBTelefonos->setEditable( TRUE );
    QCBTelefonos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBTelefonos->setAutoCompletion( TRUE );
    QCBTelefonos->setDuplicatesEnabled( FALSE );
    layout27->addWidget( QCBTelefonos );
    layout29->addLayout( layout27 );

    layout21_2 = new QVBoxLayout( 0, 0, 6, "layout21_2"); 

    textLabel8_2 = new QLabel( this, "textLabel8_2" );
    layout21_2->addWidget( textLabel8_2 );

    QLECElectronico = new QLineEdit( this, "QLECElectronico" );
    layout21_2->addWidget( QLECElectronico );
    layout29->addLayout( layout21_2 );

    RegistroEmpleadosLayout->addLayout( layout29, 3, 0 );

    layout186 = new QHBoxLayout( 0, 0, 6, "layout186"); 

    layout27_2 = new QVBoxLayout( 0, 0, 6, "layout27_2"); 

    textLabel8_3 = new QLabel( this, "textLabel8_3" );
    textLabel8_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel8_3->sizePolicy().hasHeightForWidth() ) );
    layout27_2->addWidget( textLabel8_3 );

    QCBPerfiles = new QComboBox( FALSE, this, "QCBPerfiles" );
    QCBPerfiles->setMinimumSize( QSize( 150, 0 ) );
    QCBPerfiles->setEditable( TRUE );
    QCBPerfiles->setInsertionPolicy( QComboBox::NoInsertion );
    QCBPerfiles->setAutoCompletion( TRUE );
    QCBPerfiles->setDuplicatesEnabled( FALSE );
    layout27_2->addWidget( QCBPerfiles );
    layout186->addLayout( layout27_2 );

    layout6_5 = new QVBoxLayout( 0, 0, 6, "layout6_5"); 

    textLabel3_5 = new QLabel( this, "textLabel3_5" );
    layout6_5->addWidget( textLabel3_5 );

    QLEFirma = new QLineEdit( this, "QLEFirma" );
    QLEFirma->setMinimumSize( QSize( 150, 0 ) );
    QLEFirma->setMaximumSize( QSize( 150, 32767 ) );
    layout6_5->addWidget( QLEFirma );
    layout186->addLayout( layout6_5 );

    layout6_5_3 = new QVBoxLayout( 0, 0, 6, "layout6_5_3"); 

    textLabel3_5_3 = new QLabel( this, "textLabel3_5_3" );
    layout6_5_3->addWidget( textLabel3_5_3 );

    QLEPassword = new QLineEdit( this, "QLEPassword" );
    QLEPassword->setMinimumSize( QSize( 150, 0 ) );
    QLEPassword->setMaximumSize( QSize( 150, 32767 ) );
    QLEPassword->setEchoMode( QLineEdit::Password );
    layout6_5_3->addWidget( QLEPassword );
    layout186->addLayout( layout6_5_3 );

    layout6_5_2 = new QVBoxLayout( 0, 0, 6, "layout6_5_2"); 

    textLabel3_5_2 = new QLabel( this, "textLabel3_5_2" );
    layout6_5_2->addWidget( textLabel3_5_2 );

    QLECPassword = new QLineEdit( this, "QLECPassword" );
    QLECPassword->setMinimumSize( QSize( 150, 0 ) );
    QLECPassword->setMaximumSize( QSize( 150, 32767 ) );
    QLECPassword->setEchoMode( QLineEdit::Password );
    layout6_5_2->addWidget( QLECPassword );
    layout186->addLayout( layout6_5_2 );

    RegistroEmpleadosLayout->addLayout( layout186, 4, 0 );

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    layout6_4 = new QVBoxLayout( 0, 0, 6, "layout6_4"); 

    textLabel3_4 = new QLabel( this, "textLabel3_4" );
    textLabel3_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_4->sizePolicy().hasHeightForWidth() ) );
    layout6_4->addWidget( textLabel3_4 );

    QLECalle = new QLineEdit( this, "QLECalle" );
    QLECalle->setMinimumSize( QSize( 250, 0 ) );
    QLECalle->setMaximumSize( QSize( 1000, 32767 ) );
    layout6_4->addWidget( QLECalle );
    layout32->addLayout( layout6_4 );

    layout11_2 = new QVBoxLayout( 0, 0, 6, "layout11_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( textLabel4_2 );

    QLENumero = new QLineEdit( this, "QLENumero" );
    QLENumero->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLENumero->sizePolicy().hasHeightForWidth() ) );
    QLENumero->setMinimumSize( QSize( 50, 0 ) );
    QLENumero->setMaximumSize( QSize( 50, 32767 ) );
    layout11_2->addWidget( QLENumero );
    layout32->addLayout( layout11_2 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( textLabel4 );

    QLECP = new QLineEdit( this, "QLECP" );
    QLECP->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLECP->sizePolicy().hasHeightForWidth() ) );
    QLECP->setMinimumSize( QSize( 50, 0 ) );
    QLECP->setMaximumSize( QSize( 50, 32767 ) );
    layout11->addWidget( QLECP );
    layout32->addLayout( layout11 );

    RegistroEmpleadosLayout->addLayout( layout32, 1, 0 );

    layout187 = new QHBoxLayout( 0, 0, 6, "layout187"); 

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout14->addWidget( textLabel5 );

    QLEColonia = new QLineEdit( this, "QLEColonia" );
    QLEColonia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEColonia->sizePolicy().hasHeightForWidth() ) );
    QLEColonia->setMinimumSize( QSize( 200, 0 ) );
    layout14->addWidget( QLEColonia );
    layout18->addLayout( layout14 );

    layout14_2 = new QVBoxLayout( 0, 0, 6, "layout14_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    layout14_2->addWidget( textLabel5_2 );

    QLEMunicipio = new QLineEdit( this, "QLEMunicipio" );
    QLEMunicipio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEMunicipio->sizePolicy().hasHeightForWidth() ) );
    QLEMunicipio->setMinimumSize( QSize( 200, 0 ) );
    layout14_2->addWidget( QLEMunicipio );
    layout18->addLayout( layout14_2 );

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout17->addWidget( textLabel6 );

    QCBEstados = new QComboBox( FALSE, this, "QCBEstados" );
    QCBEstados->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCBEstados->sizePolicy().hasHeightForWidth() ) );
    QCBEstados->setMinimumSize( QSize( 150, 0 ) );
    QCBEstados->setEditable( TRUE );
    QCBEstados->setInsertionPolicy( QComboBox::NoInsertion );
    QCBEstados->setAutoCompletion( TRUE );
    QCBEstados->setDuplicatesEnabled( FALSE );
    layout17->addWidget( QCBEstados );
    layout18->addLayout( layout17 );
    layout187->addLayout( layout18 );
    spacer18 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout187->addItem( spacer18 );

    RegistroEmpleadosLayout->addLayout( layout187, 2, 0 );

    layout42 = new QHBoxLayout( 0, 0, 6, "layout42"); 

    layout33 = new QHBoxLayout( 0, 0, 6, "layout33"); 

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel7 = new QLabel( this, "textLabel7" );
    layout19->addWidget( textLabel7 );

    QLERFC = new QLineEdit( this, "QLERFC" );
    QLERFC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLERFC->sizePolicy().hasHeightForWidth() ) );
    QLERFC->setMinimumSize( QSize( 100, 0 ) );
    QLERFC->setMaximumSize( QSize( 100, 32767 ) );
    QLERFC->setReadOnly( FALSE );
    layout19->addWidget( QLERFC );
    layout33->addLayout( layout19 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout6->addWidget( textLabel3 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    QLENombre->setMinimumSize( QSize( 150, 0 ) );
    QLENombre->setMaximumSize( QSize( 150, 32767 ) );
    layout6->addWidget( QLENombre );
    layout33->addLayout( layout6 );

    layout6_2 = new QVBoxLayout( 0, 0, 6, "layout6_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout6_2->addWidget( textLabel3_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    QLEAPaterno->setMinimumSize( QSize( 150, 0 ) );
    QLEAPaterno->setMaximumSize( QSize( 150, 32767 ) );
    layout6_2->addWidget( QLEAPaterno );
    layout33->addLayout( layout6_2 );

    layout6_3 = new QVBoxLayout( 0, 0, 6, "layout6_3"); 

    textLabel3_3 = new QLabel( this, "textLabel3_3" );
    layout6_3->addWidget( textLabel3_3 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    QLEAMaterno->setMinimumSize( QSize( 150, 0 ) );
    QLEAMaterno->setMaximumSize( QSize( 150, 32767 ) );
    layout6_3->addWidget( QLEAMaterno );
    layout33->addLayout( layout6_3 );
    layout42->addLayout( layout33 );
    spacer9 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout42->addItem( spacer9 );

    RegistroEmpleadosLayout->addLayout( layout42, 0, 0 );

    layout108 = new QHBoxLayout( 0, 0, 6, "layout108"); 

    QPBModificar = new QPushButton( this, "QPBModificar" );
    QPBModificar->setEnabled( FALSE );
    QPBModificar->setMinimumSize( QSize( 0, 40 ) );
    layout108->addWidget( QPBModificar );

    QPBMDireccion = new QPushButton( this, "QPBMDireccion" );
    QPBMDireccion->setEnabled( FALSE );
    QPBMDireccion->setMinimumSize( QSize( 0, 40 ) );
    layout108->addWidget( QPBMDireccion );

    layout88 = new QVBoxLayout( 0, 0, 6, "layout88"); 

    textLabel4_3 = new QLabel( this, "textLabel4_3" );
    layout88->addWidget( textLabel4_3 );

    layout87 = new QHBoxLayout( 0, 0, 6, "layout87"); 

    QPBAETelefono = new QPushButton( this, "QPBAETelefono" );
    QPBAETelefono->setEnabled( TRUE );
    QPBAETelefono->setMinimumSize( QSize( 0, 16 ) );
    QPBAETelefono->setMaximumSize( QSize( 40, 32767 ) );
    layout87->addWidget( QPBAETelefono );

    QPBMTelefono = new QPushButton( this, "QPBMTelefono" );
    QPBMTelefono->setEnabled( FALSE );
    QPBMTelefono->setMinimumSize( QSize( 0, 16 ) );
    QPBMTelefono->setMaximumSize( QSize( 40, 32767 ) );
    layout87->addWidget( QPBMTelefono );

    QPBETelefono = new QPushButton( this, "QPBETelefono" );
    QPBETelefono->setEnabled( FALSE );
    QPBETelefono->setMinimumSize( QSize( 0, 16 ) );
    QPBETelefono->setMaximumSize( QSize( 40, 32767 ) );
    layout87->addWidget( QPBETelefono );
    layout88->addLayout( layout87 );
    layout108->addLayout( layout88 );

    layout88_2 = new QVBoxLayout( 0, 0, 6, "layout88_2"); 

    textLabel4_3_2 = new QLabel( this, "textLabel4_3_2" );
    layout88_2->addWidget( textLabel4_3_2 );

    layout87_2 = new QHBoxLayout( 0, 0, 6, "layout87_2"); 

    QPBACorreo = new QPushButton( this, "QPBACorreo" );
    QPBACorreo->setEnabled( FALSE );
    QPBACorreo->setMinimumSize( QSize( 0, 16 ) );
    QPBACorreo->setMaximumSize( QSize( 40, 32767 ) );
    layout87_2->addWidget( QPBACorreo );

    QPBMCorreo = new QPushButton( this, "QPBMCorreo" );
    QPBMCorreo->setEnabled( FALSE );
    QPBMCorreo->setMinimumSize( QSize( 0, 16 ) );
    QPBMCorreo->setMaximumSize( QSize( 40, 32767 ) );
    layout87_2->addWidget( QPBMCorreo );

    QPBECorreo = new QPushButton( this, "QPBECorreo" );
    QPBECorreo->setEnabled( FALSE );
    QPBECorreo->setMinimumSize( QSize( 0, 16 ) );
    QPBECorreo->setMaximumSize( QSize( 40, 32767 ) );
    layout87_2->addWidget( QPBECorreo );
    layout88_2->addLayout( layout87_2 );
    layout108->addLayout( layout88_2 );

    layout103 = new QVBoxLayout( 0, 0, 6, "layout103"); 

    textLabel5_3 = new QLabel( this, "textLabel5_3" );
    textLabel5_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_3->sizePolicy().hasHeightForWidth() ) );
    layout103->addWidget( textLabel5_3 );

    layout102 = new QHBoxLayout( 0, 0, 6, "layout102"); 

    QPBSiguiente = new QPushButton( this, "QPBSiguiente" );
    QPBSiguiente->setEnabled( FALSE );
    QPBSiguiente->setMinimumSize( QSize( 0, 16 ) );
    QPBSiguiente->setMaximumSize( QSize( 30, 32767 ) );
    layout102->addWidget( QPBSiguiente );

    QPBAnterior = new QPushButton( this, "QPBAnterior" );
    QPBAnterior->setEnabled( FALSE );
    QPBAnterior->setMinimumSize( QSize( 0, 16 ) );
    QPBAnterior->setMaximumSize( QSize( 30, 32767 ) );
    layout102->addWidget( QPBAnterior );
    layout103->addLayout( layout102 );
    layout108->addLayout( layout103 );

    layout107 = new QVBoxLayout( 0, 0, 6, "layout107"); 

    textLabel6_2 = new QLabel( this, "textLabel6_2" );
    layout107->addWidget( textLabel6_2 );

    layout106 = new QHBoxLayout( 0, 0, 6, "layout106"); 

    QPBERegistro = new QPushButton( this, "QPBERegistro" );
    QPBERegistro->setEnabled( FALSE );
    QPBERegistro->setMinimumSize( QSize( 0, 16 ) );
    QPBERegistro->setMaximumSize( QSize( 30, 32767 ) );
    layout106->addWidget( QPBERegistro );

    QPBETodo = new QPushButton( this, "QPBETodo" );
    QPBETodo->setEnabled( FALSE );
    QPBETodo->setMinimumSize( QSize( 0, 16 ) );
    QPBETodo->setMaximumSize( QSize( 30, 32767 ) );
    layout106->addWidget( QPBETodo );

    QPBSiguiente_2_3_2 = new QPushButton( this, "QPBSiguiente_2_3_2" );
    QPBSiguiente_2_3_2->setEnabled( FALSE );
    QPBSiguiente_2_3_2->setMinimumSize( QSize( 0, 16 ) );
    QPBSiguiente_2_3_2->setMaximumSize( QSize( 30, 32767 ) );
    layout106->addWidget( QPBSiguiente_2_3_2 );

    QPBSiguiente_2_2 = new QPushButton( this, "QPBSiguiente_2_2" );
    QPBSiguiente_2_2->setEnabled( FALSE );
    QPBSiguiente_2_2->setMinimumSize( QSize( 0, 16 ) );
    QPBSiguiente_2_2->setMaximumSize( QSize( 30, 32767 ) );
    layout106->addWidget( QPBSiguiente_2_2 );
    layout107->addLayout( layout106 );
    layout108->addLayout( layout107 );

    RegistroEmpleadosLayout->addLayout( layout108, 6, 0 );

    layout104 = new QHBoxLayout( 0, 0, 6, "layout104"); 

    QPBSExpendio = new QPushButton( this, "QPBSExpendio" );
    QPBSExpendio->setMinimumSize( QSize( 0, 40 ) );
    QPBSExpendio->setMaximumSize( QSize( 32767, 90 ) );
    layout104->addWidget( QPBSExpendio );

    QPBREmpleado = new QPushButton( this, "QPBREmpleado" );
    QPBREmpleado->setEnabled( FALSE );
    QPBREmpleado->setMinimumSize( QSize( 0, 40 ) );
    QPBREmpleado->setMaximumSize( QSize( 32767, 90 ) );
    layout104->addWidget( QPBREmpleado );

    QPBConsultaEmpleados = new QPushButton( this, "QPBConsultaEmpleados" );
    QPBConsultaEmpleados->setMinimumSize( QSize( 0, 40 ) );
    QPBConsultaEmpleados->setMaximumSize( QSize( 32767, 90 ) );
    layout104->addWidget( QPBConsultaEmpleados );

    RegistroEmpleadosLayout->addLayout( layout104, 5, 0 );
    languageChange();
    resize( QSize(700, 373).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroEmpleados::~RegistroEmpleados()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroEmpleados::languageChange()
{
    setCaption( tr( "Registro De Empleados" ) );
    textLabel8->setText( tr( "Telefonos" ) );
    textLabel8_2->setText( tr( "Correo Electronico" ) );
    QLECElectronico->setText( QString::null );
    textLabel8_3->setText( tr( "Perfil" ) );
    textLabel3_5->setText( tr( "Firma" ) );
    QLEFirma->setText( QString::null );
    textLabel3_5_3->setText( tr( "Password" ) );
    QLEPassword->setText( QString::null );
    textLabel3_5_2->setText( tr( "Confirma Password" ) );
    QLECPassword->setText( QString::null );
    textLabel3_4->setText( tr( "Calle" ) );
    QLECalle->setText( QString::null );
    textLabel4_2->setText( tr( "Numero" ) );
    QLENumero->setText( QString::null );
    textLabel4->setText( tr( "Codigo Postal" ) );
    QLECP->setText( QString::null );
    textLabel5->setText( tr( "Colonia" ) );
    QLEColonia->setText( QString::null );
    textLabel5_2->setText( tr( "Municipio" ) );
    QLEMunicipio->setText( QString::null );
    textLabel6->setText( tr( "Estado" ) );
    QCBEstados->clear();
    QCBEstados->insertItem( tr( "Estado De Mexico" ) );
    textLabel7->setText( tr( "RFC" ) );
    QLERFC->setText( QString::null );
    textLabel3->setText( tr( "Nombre" ) );
    QLENombre->setText( QString::null );
    textLabel3_2->setText( tr( "Apellido Paterno" ) );
    QLEAPaterno->setText( QString::null );
    textLabel3_3->setText( tr( "Apellido Materno" ) );
    QLEAMaterno->setText( QString::null );
    QPBModificar->setText( tr( "Modificar \n"
"Generales" ) );
    QPBMDireccion->setText( tr( "Modificar \n"
"Direccion" ) );
    textLabel4_3->setText( tr( "Telefono" ) );
    QPBAETelefono->setText( tr( "+" ) );
    QPBMTelefono->setText( tr( "?" ) );
    QPBETelefono->setText( tr( "-" ) );
    textLabel4_3_2->setText( tr( "Correo" ) );
    QPBACorreo->setText( tr( "+" ) );
    QPBMCorreo->setText( tr( "?" ) );
    QPBECorreo->setText( tr( "-" ) );
    textLabel5_3->setText( tr( "Navegacion" ) );
    QPBSiguiente->setText( tr( ">" ) );
    QPBAnterior->setText( tr( "<" ) );
    textLabel6_2->setText( tr( "Operaciones Registro" ) );
    QPBERegistro->setText( tr( "-" ) );
    QPBETodo->setText( tr( "*" ) );
    QPBSiguiente_2_3_2->setText( tr( ">" ) );
    QPBSiguiente_2_2->setText( tr( ">" ) );
    QPBSExpendio->setText( tr( "Selecciona\n"
" Expendio" ) );
    QPBREmpleado->setText( tr( "Registra\n"
"Empleado" ) );
    QPBConsultaEmpleados->setText( tr( "Consulta\n"
"Empleado" ) );
}

