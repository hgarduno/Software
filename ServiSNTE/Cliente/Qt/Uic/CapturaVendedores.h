/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaVendedores.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAVENDEDORES_H
#define CAPTURAVENDEDORES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCtrlTiendasEntrega;
class QPushButton;
class QTable;

class CapturaVendedores : public QWidget
{
    Q_OBJECT

public:
    CapturaVendedores( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CapturaVendedores();

    QLabel* textLabel2;
    QLineEdit* lineEdit26;
    QLabel* textLabel6;
    QLineEdit* lineEdit31;
    QLabel* textLabel5;
    QCtrlTiendasEntrega* QCtrTienda;
    QLabel* textLabel2_2;
    QLineEdit* lineEdit51;
    QLabel* textLabel3;
    QLineEdit* lineEdit52;
    QPushButton* pushButton47;
    QPushButton* pushButton48;
    QLabel* textLabel4;
    QTable* QTTelefono;
    QPushButton* pushButton49;
    QPushButton* pushButton11;
    QPushButton* pushButton39;
    QPushButton* pushButton40;
    QPushButton* pushButton12;

protected:
    QGridLayout* CapturaVendedoresLayout;
    QVBoxLayout* layout21;
    QHBoxLayout* layout20;
    QVBoxLayout* layout80;
    QVBoxLayout* layout92;
    QVBoxLayout* layout19;
    QHBoxLayout* layout16;
    QVBoxLayout* layout15;
    QHBoxLayout* layout138;
    QHBoxLayout* layout139;
    QVBoxLayout* layout14;
    QHBoxLayout* layout18;
    QSpacerItem* spacer1;
    QVBoxLayout* layout13;
    QHBoxLayout* layout125;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAVENDEDORES_H
