/****************************************************************************
** Form interface generated from reading ui file 'UI/ConExpendiosVenta.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONEXPENDIOSVENTA_H
#define CONEXPENDIOSVENTA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;

class ConExpendiosVenta : public QDialog
{
    Q_OBJECT

public:
    ConExpendiosVenta( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ConExpendiosVenta();

    QLabel* textLabel3;
    QLineEdit* QLEPrincipal;
    QLabel* textLabel2;
    QTable* QTExpendios;
    QPushButton* QPBOExpendio;
    QPushButton* QPBDejaPrecios;
    QPushButton* QPBElimina;
    QPushButton* QPBAceptar;

protected:
    QGridLayout* ConExpendiosVentaLayout;
    QVBoxLayout* layout22;
    QVBoxLayout* layout20;
    QHBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // CONEXPENDIOSVENTA_H
