/****************************************************************************
** Form interface generated from reading ui file 'UI/SeleccionaInventario.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SELECCIONAINVENTARIO_H
#define SELECCIONAINVENTARIO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class SeleccionaInventario : public QDialog
{
    Q_OBJECT

public:
    SeleccionaInventario( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SeleccionaInventario();

    QLabel* textLabel4;
    QTable* QTDatos;
    QPushButton* pushButton5;
    QPushButton* pushButton5_2;

protected:
    QGridLayout* SeleccionaInventarioLayout;
    QVBoxLayout* layout11;
    QHBoxLayout* layout13;

protected slots:
    virtual void languageChange();

};

#endif // SELECCIONAINVENTARIO_H
