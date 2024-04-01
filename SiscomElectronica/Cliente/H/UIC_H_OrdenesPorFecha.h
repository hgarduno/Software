/****************************************************************************
** Form interface generated from reading ui file 'UI/OrdenesPorFecha.ui'
**
** Created: Wed Jan 31 10:56:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENESPORFECHA_H
#define ORDENESPORFECHA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class QLCDNumber;

class OrdenesPorFecha : public QDialog
{
    Q_OBJECT

public:
    OrdenesPorFecha( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~OrdenesPorFecha();

    QLabel* textLabel6;
    QTable* QTDatos;
    QPushButton* QPBSOrdenes;
    QPushButton* pushButton44_2;
    QPushButton* pushButton44_2_2;
    QLabel* textLabel7;
    QLCDNumber* QLCDTotal;
    QLabel* textLabel7_2;
    QLCDNumber* QLCDTotIVA;

protected:
    QGridLayout* OrdenesPorFechaLayout;
    QHBoxLayout* layout80;
    QVBoxLayout* layout75;
    QVBoxLayout* layout79;
    QVBoxLayout* layout78;

protected slots:
    virtual void languageChange();

};

#endif // ORDENESPORFECHA_H
