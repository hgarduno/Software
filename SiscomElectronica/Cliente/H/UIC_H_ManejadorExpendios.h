/****************************************************************************
** Form interface generated from reading ui file 'UI/ManejadorExpendios.ui'
**
** Created: Fri Apr 12 21:25:57 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MANEJADOREXPENDIOS_H
#define MANEJADOREXPENDIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCtrlExpendios;
class QPushButton;

class ManejadorExpendios : public QWidget
{
    Q_OBJECT

public:
    ManejadorExpendios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ManejadorExpendios();

    QLabel* textLabel2;
    QLineEdit* QLERazonSocial;
    QLabel* textLabel2_2;
    QLineEdit* QLERFC;
    QLabel* textLabel2_2_2;
    QLineEdit* QLEDireccionIp;
    QLabel* textLabel2_2_2_2;
    QLineEdit* QLEPuerto;
    QLabel* textLabel2_2_2_2_2;
    QLineEdit* QLEBase;
    QLabel* textLabel4;
    QCtrlExpendios* QCtrExpendios;
    QPushButton* QPBRegistra;
    QPushButton* QPBIniciar;
    QPushButton* QPBActualiza;
    QPushButton* QPBElimina;

protected:
    QGridLayout* ManejadorExpendiosLayout;
    QVBoxLayout* layout30;
    QHBoxLayout* layout28;
    QVBoxLayout* layout19;
    QVBoxLayout* layout19_2;
    QHBoxLayout* layout29;
    QVBoxLayout* layout19_2_2;
    QVBoxLayout* layout19_2_2_2;
    QVBoxLayout* layout19_2_2_2_2;
    QVBoxLayout* layout31;
    QHBoxLayout* layout47;

protected slots:
    virtual void languageChange();

};

#endif // MANEJADOREXPENDIOS_H
