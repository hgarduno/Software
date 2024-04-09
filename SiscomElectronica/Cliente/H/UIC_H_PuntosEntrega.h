/****************************************************************************
** Form interface generated from reading ui file 'UI/PuntosEntrega.ui'
**
** Created: lun abr 1 18:57:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PUNTOSENTREGA_H
#define PUNTOSENTREGA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
class QTable;

class PuntosEntrega : public QWidget
{
    Q_OBJECT

public:
    PuntosEntrega( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PuntosEntrega();

    QPushButton* QPBRegistrar;
    QPushButton* pushButton1_2;
    QPushButton* pushButton1_3;
    QLabel* textLabel1;
    QLineEdit* QLEPuntoEntrega;
    QLabel* textLabel1_2;
    QLineEdit* QLECalle;
    QLabel* textLabel1_2_2;
    QLineEdit* QLENumExterior;
    QLabel* textLabel1_2_2_2;
    QLineEdit* QLENumInterior;
    QLabel* textLabel1_2_2_2_2;
    QLineEdit* QLEMunicipio;
    QLabel* textLabel1_2_2_2_2_2;
    QLineEdit* QLEColonia;
    QLabel* textLabel1_2_2_2_2_2_2;
    QLineEdit* QLECP;
    QLabel* textLabel1_2_2_2_2_2_2_2;
    QLineEdit* QLEEstado;
    QLabel* textLabel4;
    QTextEdit* QTEReferencias;
    QLabel* textLabel3;
    QTable* table1;

protected:
    QGridLayout* PuntosEntregaLayout;
    QHBoxLayout* layout11;
    QVBoxLayout* layout14;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QHBoxLayout* layout9;
    QVBoxLayout* layout1_2_2;
    QVBoxLayout* layout1_2_2_2;
    QVBoxLayout* layout1_2_2_2_2;
    QVBoxLayout* layout1_2_2_2_2_2;
    QVBoxLayout* layout1_2_2_2_2_2_2;
    QVBoxLayout* layout1_2_2_2_2_2_2_2;
    QVBoxLayout* layout13;
    QVBoxLayout* layout12;

protected slots:
    virtual void languageChange();

};

#endif // PUNTOSENTREGA_H
