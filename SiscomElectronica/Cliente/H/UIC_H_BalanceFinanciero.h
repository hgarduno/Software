/****************************************************************************
** Form interface generated from reading ui file 'UI/BalanceFinanciero.ui'
**
** Created: Thu Apr 11 21:39:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef BALANCEFINANCIERO_H
#define BALANCEFINANCIERO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTextBrowser;
class QPushButton;
class QLabel;
class CQControlFecha;

class BalanceFinanciero : public QWidget
{
    Q_OBJECT

public:
    BalanceFinanciero( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~BalanceFinanciero();

    QTextBrowser* QTBBalanceFinanciero;
    QPushButton* QPBCargaArchivoHtml;
    QPushButton* pushButton5_2;
    QLabel* textLabel1;
    CQControlFecha* cQControlFecha1;
    QLabel* textLabel1_2;
    CQControlFecha* cQControlFecha1_2;

protected:
    QGridLayout* BalanceFinancieroLayout;
    QHBoxLayout* layout7;
    QHBoxLayout* layout8;
    QSpacerItem* spacer1;
    QHBoxLayout* layout3;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;

protected slots:
    virtual void languageChange();

};

#endif // BALANCEFINANCIERO_H
