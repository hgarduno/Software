/****************************************************************************
** Form interface generated from reading ui file 'UI/AvisoNoAlcanza4.ui'
**
** Created: Wed Jan 31 10:48:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef AVISONOALCANZA4_H
#define AVISONOALCANZA4_H

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
class QTextEdit;

class AvisoNoAlcanza4 : public QDialog
{
    Q_OBJECT

public:
    AvisoNoAlcanza4( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~AvisoNoAlcanza4();

    QLabel* textLabel2_3;
    QLineEdit* QLECantidad;
    QLabel* textLabel2;
    QLineEdit* QLEProducto;
    QPushButton* QPBEliminar;
    QPushButton* QPBVende;
    QPushButton* QPBCCantidad;
    QLCDNumber* QLCNExistencia;
    QLabel* textLabel2_2;
    QTextEdit* QTEDescripcion;

protected:
    QGridLayout* AvisoNoAlcanza4Layout;
    QVBoxLayout* layout19_3;
    QVBoxLayout* layout19;
    QVBoxLayout* layout25;
    QVBoxLayout* layout9;

protected slots:
    virtual void languageChange();

};

#endif // AVISONOALCANZA4_H
