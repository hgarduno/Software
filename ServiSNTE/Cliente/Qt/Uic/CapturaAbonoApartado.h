/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaAbonoApartado.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAABONOAPARTADO_H
#define CAPTURAABONOAPARTADO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaAbonoApartado : public QDialog
{
    Q_OBJECT

public:
    CapturaAbonoApartado( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaAbonoApartado();

    QLabel* textLabel4_2;
    QLineEdit* QLEFolio;
    QLabel* textLabel4;
    QLineEdit* QLECantidad;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaAbonoApartadoLayout;
    QHBoxLayout* layout14;
    QVBoxLayout* layout12_2;
    QVBoxLayout* layout12;
    QHBoxLayout* layout15;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAABONOAPARTADO_H
