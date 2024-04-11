/****************************************************************************
** Form interface generated from reading ui file 'UI/AvisoNoAlcanza.ui'
**
** Created: Wed Apr 10 20:52:10 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef AVISONOALCANZA_H
#define AVISONOALCANZA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QLCDNumber;

class AvisoNoAlcanza : public QDialog
{
    Q_OBJECT

public:
    AvisoNoAlcanza( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~AvisoNoAlcanza();

    QLabel* textLabel2_2;
    QLineEdit* QLEDescripcion;
    QPushButton* QPBEliminar;
    QPushButton* QPBVende;
    QPushButton* QPBCCantidad;
    QLCDNumber* QLCNExistencia;
    QLabel* textLabel2;
    QLineEdit* QLEProducto;
    QLabel* textLabel2_3;
    QLineEdit* QLECantidad;

protected:
    QGridLayout* AvisoNoAlcanzaLayout;
    QVBoxLayout* layout19_2;
    QVBoxLayout* layout25;
    QVBoxLayout* layout19;
    QVBoxLayout* layout19_3;

protected slots:
    virtual void languageChange();

};

#endif // AVISONOALCANZA_H
