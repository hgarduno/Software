/****************************************************************************
** Form interface generated from reading ui file 'UI/ActualizaInventario.ui'
**
** Created: Fri Apr 12 21:35:09 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZAINVENTARIO_H
#define ACTUALIZAINVENTARIO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class ActualizaInventario : public QDialog
{
    Q_OBJECT

public:
    ActualizaInventario( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ActualizaInventario();

    QLabel* textLabel2;
    QLineEdit* lineEdit4;
    QLabel* textLabel1_2;
    QLineEdit* QLECantidad_2;
    QLabel* textLabel1_2_2;
    QLineEdit* QLECantidad_2_2;
    QLabel* textLabel1;
    QLineEdit* QLECantidad;
    QPushButton* pushButton3;
    QPushButton* pushButton4;

protected:
    QGridLayout* ActualizaInventarioLayout;
    QVBoxLayout* layout20;
    QHBoxLayout* layout18;
    QVBoxLayout* layout10;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout1_2_2;
    QHBoxLayout* layout19;
    QSpacerItem* spacer3;
    QVBoxLayout* layout1;
    QHBoxLayout* layout16;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZAINVENTARIO_H
