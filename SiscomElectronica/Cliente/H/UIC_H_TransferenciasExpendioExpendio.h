/****************************************************************************
** Form interface generated from reading ui file 'UI/TransferenciasExpendioExpendio.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TRANSFERENCIASEXPENDIOEXPENDIO_H
#define TRANSFERENCIASEXPENDIOEXPENDIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLCDNumber;

class TransferenciasExpendioExpendio : public QWidget
{
    Q_OBJECT

public:
    TransferenciasExpendioExpendio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TransferenciasExpendioExpendio();

    QTable* QTDatos;
    QLabel* textLabel1;
    QLCDNumber* QLCDNCantidad;

protected:
    QGridLayout* TransferenciasExpendioExpendioLayout;
    QHBoxLayout* layout32;
    QVBoxLayout* layout30;

protected slots:
    virtual void languageChange();

};

#endif // TRANSFERENCIASEXPENDIOEXPENDIO_H
