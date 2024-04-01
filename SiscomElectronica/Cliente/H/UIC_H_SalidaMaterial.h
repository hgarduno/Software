/****************************************************************************
** Form interface generated from reading ui file 'UI/SalidaMaterial.ui'
**
** Created: Wed Jan 31 10:48:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SALIDAMATERIAL_H
#define SALIDAMATERIAL_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTextEdit;
class QPushButton;
class QTable;
class QComboBox;
class QLineEdit;
class QLCDNumber;

class SalidaMaterial : public QWidget
{
    Q_OBJECT

public:
    SalidaMaterial( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SalidaMaterial();

    QLabel* textLabel1_2;
    QTextEdit* QLEDescripcion;
    QPushButton* QPBAnexar;
    QPushButton* QPBElimina;
    QPushButton* QPBRegistrar;
    QTable* QTDatos;
    QLabel* textLabel2_2;
    QComboBox* QCBMotivos;
    QLabel* textLabel1;
    QLineEdit* QLECantidad;
    QLabel* textLabel2;
    QComboBox* QCBProductos;
    QLabel* textLabel3;
    QLCDNumber* QLCDNExistencia;
    QLabel* textLabel3_2;
    QLCDNumber* QLCDNExistenciaBodega;

protected:
    QGridLayout* SalidaMaterialLayout;
    QVBoxLayout* layout72;
    QHBoxLayout* layout18;
    QHBoxLayout* layout22;
    QVBoxLayout* layout16;
    QVBoxLayout* layout13;
    QVBoxLayout* layout12;
    QVBoxLayout* layout19;
    QVBoxLayout* layout19_2;

protected slots:
    virtual void languageChange();

};

#endif // SALIDAMATERIAL_H
