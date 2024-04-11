/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/AbonosApartado.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ABONOSAPARTADO_H
#define ABONOSAPARTADO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;
class QLineEdit;

class AbonosApartado : public QWidget
{
    Q_OBJECT

public:
    AbonosApartado( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~AbonosApartado();

    QPushButton* QPBCancelarFolio;
    QPushButton* QPBCancelarAbono;
    QPushButton* QPBCancelarApartado;
    QPushButton* QPBCapturaAbono;
    QLabel* textLabel2;
    QTable* QTApartados;
    QLabel* textLabel2_2;
    QTable* QTAbonos;
    QLabel* QLAFolioApartado;
    QLineEdit* QLEFolioApartado;
    QLabel* textLabel1_2;
    QLineEdit* QLECliente;
    QPushButton* QPBImprimir;

protected:
    QGridLayout* AbonosApartadoLayout;
    QGridLayout* layout48;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;
    QHBoxLayout* layout4;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;

protected slots:
    virtual void languageChange();

};

#endif // ABONOSAPARTADO_H
