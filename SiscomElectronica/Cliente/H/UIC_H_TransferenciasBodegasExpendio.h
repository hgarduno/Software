/****************************************************************************
** Form interface generated from reading ui file 'UI/TransferenciasBodegasExpendio.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TRANSFERENCIASBODEGASEXPENDIO_H
#define TRANSFERENCIASBODEGASEXPENDIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLCDNumber;

class TransferenciasBodegasExpendio : public QWidget
{
    Q_OBJECT

public:
    TransferenciasBodegasExpendio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TransferenciasBodegasExpendio();

    QTable* QTDatos;
    QLabel* textLabel1;
    QLCDNumber* QLCDNCantidad;

protected:
    QGridLayout* TransferenciasBodegasExpendioLayout;
    QHBoxLayout* layout32;
    QVBoxLayout* layout30;

protected slots:
    virtual void languageChange();

};

#endif // TRANSFERENCIASBODEGASEXPENDIO_H
