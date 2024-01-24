/****************************************************************************
** Form interface generated from reading ui file 'UI/EmpleadosExpendio.ui'
**
** Created: Thu Dec 21 13:55:38 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef EMPLEADOSEXPENDIO_H
#define EMPLEADOSEXPENDIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QIconView;
class QIconViewItem;
class QPushButton;

class EmpleadosExpendio : public QWidget
{
    Q_OBJECT

public:
    EmpleadosExpendio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EmpleadosExpendio();

    QLabel* textLabel3;
    QTable* QTDatos;
    QLabel* textLabel5;
    QIconView* QIVExpendios;
    QPushButton* QPBValEmpleado;
    QPushButton* QPBAsignaEmpleado;

protected:
    QGridLayout* EmpleadosExpendioLayout;
    QVBoxLayout* layout27;
    QVBoxLayout* layout29;
    QHBoxLayout* layout30;

protected slots:
    virtual void languageChange();

};

#endif // EMPLEADOSEXPENDIO_H
