/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_Aplicaciones.ui'
**
** Created: Thu Apr 11 21:36:10 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef APLICACIONES_H
#define APLICACIONES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class Aplicaciones : public QWidget
{
    Q_OBJECT

public:
    Aplicaciones( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Aplicaciones();

    QLabel* textLabel3;
    QLineEdit* QLENombre;
    QLineEdit* QLERutaQQt;
    QLabel* textLabel3_2;
    QLineEdit* QLEIdentificador;
    QLabel* textLabel3_3;
    QLineEdit* QLEDescripcion;
    QPushButton* QPBSDirectorio;
    QPushButton* QPBRAplicacion;
    QPushButton* pushButton12_2;

protected:
    QGridLayout* AplicacionesLayout;
    QVBoxLayout* layout23;
    QVBoxLayout* layout23_2;
    QVBoxLayout* layout23_3;
    QHBoxLayout* layout26;

protected slots:
    virtual void languageChange();

};

#endif // APLICACIONES_H
