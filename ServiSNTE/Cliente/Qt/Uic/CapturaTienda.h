/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaTienda.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURATIENDA_H
#define CAPTURATIENDA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTable;
class QCtrlTipoVentas;
class QCtrlFinanciadoras;

class CapturaTienda : public QWidget
{
    Q_OBJECT

public:
    CapturaTienda( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CapturaTienda();

    QLabel* textLabel13;
    QLineEdit* lineEdit75;
    QLabel* textLabel14;
    QLineEdit* lineEdit76;
    QLabel* textLabel15;
    QLineEdit* lineEdit77;
    QLabel* textLabel16;
    QLineEdit* lineEdit78;
    QPushButton* pushButton46;
    QLabel* textLabel18;
    QTable* table1;
    QLabel* textLabel17;
    QTable* table2;
    QPushButton* pushButton40;
    QPushButton* pushButton41;
    QPushButton* pushButton39;
    QPushButton* pushButton50;
    QPushButton* pushButton51;
    QPushButton* pushButton42;
    QLabel* textLabel12;
    QLineEdit* lineEdit74;
    QCtrlTipoVentas* QCtrTipoVentas;
    QCtrlFinanciadoras* QCtrFinanciadoras;

protected:
    QHBoxLayout* layout311;
    QVBoxLayout* layout306;
    QVBoxLayout* layout307;
    QVBoxLayout* layout308;
    QHBoxLayout* layout136;
    QVBoxLayout* layout24;
    QVBoxLayout* layout25;
    QHBoxLayout* layout146;
    QHBoxLayout* layout145;
    QHBoxLayout* layout13;
    QVBoxLayout* layout309;
    QHBoxLayout* layout12;
    QSpacerItem* spacer9;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURATIENDA_H
