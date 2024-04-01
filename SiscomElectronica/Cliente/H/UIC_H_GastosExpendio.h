/****************************************************************************
** Form interface generated from reading ui file 'UI/GastosExpendio.ui'
**
** Created: Wed Jan 31 10:48:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef GASTOSEXPENDIO_H
#define GASTOSEXPENDIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlGastosSE;
class QPushButton;
class QTable;

class GastosExpendio : public QWidget
{
    Q_OBJECT

public:
    GastosExpendio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~GastosExpendio();

    QLabel* textLabel1;
    QCtrlGastosSE* QCtrGastos;
    QPushButton* pushButton1;
    QLabel* textLabel2;
    QTable* table1;

protected:
    QGridLayout* GastosExpendioLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // GASTOSEXPENDIO_H
