/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CreditosBeneficiosIntegrales.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CREDITOSBENEFICIOSINTEGRALES_H
#define CREDITOSBENEFICIOSINTEGRALES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;

class CreditosBeneficiosIntegrales : public QDialog
{
    Q_OBJECT

public:
    CreditosBeneficiosIntegrales( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CreditosBeneficiosIntegrales();

    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel1;
    QTable* QTCreditos;

protected:
    QGridLayout* CreditosBeneficiosIntegralesLayout;
    QHBoxLayout* layout48;
    QVBoxLayout* layout49;

protected slots:
    virtual void languageChange();

};

#endif // CREDITOSBENEFICIOSINTEGRALES_H
