/****************************************************************************
** Form interface generated from reading ui file 'UI/ExpendioOrigen.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef EXPENDIOORIGEN_H
#define EXPENDIOORIGEN_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlExpendios;
class QPushButton;

class ExpendioOrigen : public QDialog
{
    Q_OBJECT

public:
    ExpendioOrigen( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ExpendioOrigen();

    QLabel* textLabel2;
    QCtrlExpendios* QCtrExpendios;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* ExpendioOrigenLayout;
    QVBoxLayout* layout6;
    QVBoxLayout* layout5;
    QHBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // EXPENDIOORIGEN_H
