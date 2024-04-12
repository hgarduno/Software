/****************************************************************************
** Form interface generated from reading ui file 'UI/Devoluciones.ui'
**
** Created: Thu Apr 11 22:09:35 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DEVOLUCIONES_H
#define DEVOLUCIONES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QTextEdit;
class QLCDNumber;
class QPushButton;

class Devoluciones : public QWidget
{
    Q_OBJECT

public:
    Devoluciones( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Devoluciones();

    QLabel* textLabel1;
    QLineEdit* QLENOrden;
    QLabel* textLabel1_2;
    QTable* QTDatos;
    QLabel* textLabel1_3;
    QTextEdit* QTEDsc;
    QLabel* textLabel1_4;
    QLCDNumber* QLCDNTotal;
    QLabel* textLabel1_4_2;
    QLCDNumber* QLCDNTotalD;
    QLabel* textLabel1_2_2;
    QTable* QTPADevolver;
    QPushButton* QPBAnexar;
    QPushButton* QPBEliminar;
    QPushButton* QPBDevuelve;

protected:
    QGridLayout* DevolucionesLayout;
    QHBoxLayout* layout25;
    QSpacerItem* spacer1;
    QVBoxLayout* layout23;
    QHBoxLayout* layout33;
    QVBoxLayout* layout26;
    QVBoxLayout* layout32;
    QVBoxLayout* layout27;
    QVBoxLayout* layout28;
    QVBoxLayout* layout28_2;
    QVBoxLayout* layout26_2;
    QHBoxLayout* layout35;

protected slots:
    virtual void languageChange();

};

#endif // DEVOLUCIONES_H
