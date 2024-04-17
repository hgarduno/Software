/****************************************************************************
** Form interface generated from reading ui file 'UI/RangoPorcentaje.ui'
**
** Created: Fri Apr 12 21:35:56 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef RANGOPORCENTAJE_H
#define RANGOPORCENTAJE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class RangoPorcentaje : public QDialog
{
    Q_OBJECT

public:
    RangoPorcentaje( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RangoPorcentaje();

    QLabel* textLabel4;
    QLineEdit* QLEBajo;
    QLabel* textLabel4_2;
    QLineEdit* QLEAlto;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* RangoPorcentajeLayout;
    QVBoxLayout* layout36;
    QVBoxLayout* layout36_2;
    QHBoxLayout* layout38;

protected slots:
    virtual void languageChange();

};

#endif // RANGOPORCENTAJE_H
