/****************************************************************************
** Form interface generated from reading ui file 'UI/DatosClienteF.ui'
**
** Created: Wed Jan 31 10:57:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DATOSCLIENTEF_H
#define DATOSCLIENTEF_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QPushButton;
class QLabel;
class QLineEdit;

class DatosClienteF : public QWidget
{
    Q_OBJECT

public:
    DatosClienteF( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~DatosClienteF();

    QTable* QTDatos;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegistrar;
    QPushButton* QPBEliminar;
    QPushButton* QPBActualizar;
    QLabel* textLabel6;
    QLineEdit* QLELInferior;
    QLabel* textLabel6_2;
    QLineEdit* QLELSuperior;
    QLabel* textLabel6_2_2;
    QLineEdit* QLEDescuento;
    QLabel* textLabel6_2_2_2;
    QLineEdit* QLENumDias;

protected:
    QGridLayout* DatosClienteFLayout;
    QHBoxLayout* layout39;
    QHBoxLayout* layout42;
    QVBoxLayout* layout35;
    QVBoxLayout* layout35_2;
    QVBoxLayout* layout35_2_2;
    QVBoxLayout* layout35_2_2_2;

protected slots:
    virtual void languageChange();

};

#endif // DATOSCLIENTEF_H
