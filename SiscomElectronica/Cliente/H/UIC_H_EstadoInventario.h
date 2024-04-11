/****************************************************************************
** Form interface generated from reading ui file 'UI/EstadoInventario.ui'
**
** Created: Wed Apr 10 21:12:27 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ESTADOINVENTARIO_H
#define ESTADOINVENTARIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;

class EstadoInventario : public QWidget
{
    Q_OBJECT

public:
    EstadoInventario( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EstadoInventario();

    QLabel* textLabel4;
    QTable* table6;

protected:
    QGridLayout* EstadoInventarioLayout;

protected slots:
    virtual void languageChange();

};

#endif // ESTADOINVENTARIO_H
