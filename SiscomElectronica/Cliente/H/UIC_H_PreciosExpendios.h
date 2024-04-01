/****************************************************************************
** Form interface generated from reading ui file 'UI/PreciosExpendios.ui'
**
** Created: Wed Jan 31 10:48:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRECIOSEXPENDIOS_H
#define PRECIOSEXPENDIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QLineEdit;
class QPushButton;

class PreciosExpendios : public QWidget
{
    Q_OBJECT

public:
    PreciosExpendios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PreciosExpendios();

    QLabel* textLabel1;
    QTable* QTPreciosE;
    QLabel* textLabel1_2;
    QLineEdit* QLEExpendioO;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEExpendioD;
    QPushButton* QPBExpendioO;
    QPushButton* QPBExpendioD;
    QPushButton* QPBConsultaPrecios;

protected:
    QGridLayout* PreciosExpendiosLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout3;
    QVBoxLayout* layout3_2;

protected slots:
    virtual void languageChange();

};

#endif // PRECIOSEXPENDIOS_H
