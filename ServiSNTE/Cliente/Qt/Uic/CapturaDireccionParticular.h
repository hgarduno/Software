/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaDireccionParticular.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADIRECCIONPARTICULAR_H
#define CAPTURADIRECCIONPARTICULAR_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTextEdit;
class QGroupBox;
class QCtrlTipoViviendaSS;
class QPushButton;

class CapturaDireccionParticular : public QDialog
{
    Q_OBJECT

public:
    CapturaDireccionParticular( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDireccionParticular();

    QLabel* textLabel6;
    QLineEdit* QLECalle;
    QLabel* textLabel5;
    QLineEdit* QLENoExterior;
    QLabel* textLabel5_2;
    QLineEdit* QLENoInterior;
    QLabel* textLabel6_2;
    QLineEdit* QLEColonia;
    QLabel* textLabel6_2_2;
    QLineEdit* QLEDelegacionMunicipio;
    QLabel* textLabel5_2_2;
    QLineEdit* QLEEstado;
    QLabel* textLabel5_2_2_2;
    QLineEdit* QLECodigoPostal;
    QLabel* textLabel7;
    QTextEdit* QTEReferencias;
    QGroupBox* groupBox2;
    QLabel* textLabel1;
    QLineEdit* QLEViviendaOtra;
    QCtrlTipoViviendaSS* QCtrTipoVivienda;
    QLabel* textLabel2_5;
    QLineEdit* QLETiempoResidir;
    QPushButton* QPBRegistrar;
    QPushButton* QPBActualizar;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaDireccionParticularLayout;
    QHBoxLayout* layout25;
    QVBoxLayout* layout22;
    QVBoxLayout* layout16;
    QVBoxLayout* layout16_2;
    QHBoxLayout* layout36;
    QVBoxLayout* layout22_2;
    QVBoxLayout* layout22_2_2;
    QVBoxLayout* layout16_2_2;
    QVBoxLayout* layout16_2_2_2;
    QVBoxLayout* layout12;
    QVBoxLayout* layout27;
    QGridLayout* groupBox2Layout;
    QGridLayout* layout13_5;
    QHBoxLayout* layout14;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADIRECCIONPARTICULAR_H
