/****************************************************************************
** Form interface generated from reading ui file 'UI/DispositivosVendidos.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DISPOSITIVOSVENDIDOS_H
#define DISPOSITIVOSVENDIDOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;
class QPushButton;
class QTable;

class DispositivosVendidos : public QWidget
{
    Q_OBJECT

public:
    DispositivosVendidos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~DispositivosVendidos();

    QLabel* textLabel1;
    CQControlFecha* QCFInicio;
    QLabel* textLabel2;
    CQControlFecha* QCFFin;
    QPushButton* pushButton14;
    QPushButton* pushButton15;
    QLabel* textLabel1_2;
    QTable* table10;

protected:
    QGridLayout* DispositivosVendidosLayout;
    QSpacerItem* spacer2;
    QHBoxLayout* layout3;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QHBoxLayout* layout34;
    QVBoxLayout* layout33;

protected slots:
    virtual void languageChange();

};

#endif // DISPOSITIVOSVENDIDOS_H
