/****************************************************************************
** Form interface generated from reading ui file 'UI/EjecutaInventario.ui'
**
** Created: Wed Jan 31 10:59:04 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef EJECUTAINVENTARIO_H
#define EJECUTAINVENTARIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QPushButton;

class EjecutaInventario : public QWidget
{
    Q_OBJECT

public:
    EjecutaInventario( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EjecutaInventario();

    QTable* table1;
    QPushButton* pushButton1;

protected:
    QGridLayout* EjecutaInventarioLayout;

protected slots:
    virtual void languageChange();

};

#endif // EJECUTAINVENTARIO_H
