/****************************************************************************
** Form interface generated from reading ui file 'UI/QControlDireccion.ui'
**
** Created: Thu Apr 11 21:36:44 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef QCONTROLDIRECCION_H
#define QCONTROLDIRECCION_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;

class QControlDireccion : public QWidget
{
    Q_OBJECT

public:
    QControlDireccion( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QControlDireccion();

    QLabel* textLabel2;
    QLineEdit* QLECalle;
    QLabel* textLabel3;
    QLineEdit* QLENumero;
    QLabel* textLabel4;
    QLineEdit* QLEColonia;
    QLabel* textLabel5;
    QComboBox* QCBEstado;
    QLabel* textLabel4_2_2;
    QLineEdit* QLEMunicipio;
    QLabel* textLabel3_2;
    QLineEdit* QLECP;

protected:
    QGridLayout* QControlDireccionLayout;
    QHBoxLayout* layout11;
    QVBoxLayout* layout4;
    QVBoxLayout* layout5;
    QVBoxLayout* layout7;
    QVBoxLayout* layout15;
    QVBoxLayout* layout7_2_2;
    QVBoxLayout* layout5_2;

protected slots:
    virtual void languageChange();

};

#endif // QCONTROLDIRECCION_H
