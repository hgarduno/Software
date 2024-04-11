/****************************************************************************
** Form interface generated from reading ui file 'UI/PedidosOtrosExpendios.ui'
**
** Created: Wed Apr 10 20:52:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PEDIDOSOTROSEXPENDIOS_H
#define PEDIDOSOTROSEXPENDIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class PedidosOtrosExpendios : public QWidget
{
    Q_OBJECT

public:
    PedidosOtrosExpendios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PedidosOtrosExpendios();

    QLabel* textLabel1_2_2;
    QTable* QTDatos;
    QPushButton* QPBActualizar;
    QPushButton* QPBImprimir;

protected:
    QGridLayout* PedidosOtrosExpendiosLayout;
    QVBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // PEDIDOSOTROSEXPENDIOS_H
