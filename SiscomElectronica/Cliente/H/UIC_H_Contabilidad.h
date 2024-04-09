/****************************************************************************
** Form interface generated from reading ui file 'UI/Contabilidad.ui'
**
** Created: lun abr 1 18:57:46 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONTABILIDAD_H
#define CONTABILIDAD_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class QTabWidget;
class QTextEdit;
class QLineEdit;
class QLCDNumber;

class Contabilidad : public QWidget
{
    Q_OBJECT

public:
    Contabilidad( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Contabilidad();

    QLabel* textLabel5;
    QTable* QTFacturas;
    QLabel* textLabel5_2;
    QTable* QTFacturas_2;
    QPushButton* QPBPFacturasC;
    QPushButton* pushButton16_3_2;
    QPushButton* pushButton16;
    QPushButton* QPBEjecutaContabilidad;
    QPushButton* pushButton16_2_2;
    QTabWidget* tabWidget3;
    QWidget* tab;
    QLabel* textLabel7;
    QTable* table8;
    QWidget* tab_2;
    QLabel* textLabel8;
    QTextEdit* textEdit3;
    QLabel* textLabel6;
    QLineEdit* lineEdit18;
    QLabel* textLabel6_2;
    QLCDNumber* lCDNumber3;
    QLabel* textLabel6_2_3;
    QLCDNumber* lCDNumber3_3;
    QLabel* textLabel6_2_2;
    QLCDNumber* lCDNumber3_2;
    QLabel* textLabel6_2_3_2;
    QLCDNumber* lCDNumber3_3_2;

protected:
    QGridLayout* ContabilidadLayout;
    QHBoxLayout* layout51;
    QVBoxLayout* layout49;
    QVBoxLayout* layout49_2;
    QHBoxLayout* layout58;
    QGridLayout* tabLayout;
    QVBoxLayout* layout55;
    QVBoxLayout* layout67;
    QVBoxLayout* layout76;
    QVBoxLayout* layout52;
    QVBoxLayout* layout75;
    QHBoxLayout* layout74;
    QVBoxLayout* layout69;
    QVBoxLayout* layout69_2;
    QHBoxLayout* layout73;
    QVBoxLayout* layout70;
    QVBoxLayout* layout69_2_2;

protected slots:
    virtual void languageChange();

};

#endif // CONTABILIDAD_H
