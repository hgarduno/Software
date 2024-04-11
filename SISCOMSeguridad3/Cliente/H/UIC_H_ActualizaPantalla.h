/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_ActualizaPantalla.ui'
**
** Created: Sat Jan 27 16:42:44 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZAPANTALLA_H
#define ACTUALIZAPANTALLA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class ActualizaPantalla : public QWidget
{
    Q_OBJECT

public:
    ActualizaPantalla( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ActualizaPantalla();

    QLabel* textLabel1_2_2_2;
    QLineEdit* lineEdit8_2_2_2;
    QLabel* textLabel1;
    QLineEdit* QLENmbAplicacion;
    QLabel* textLabel1_2;
    QLineEdit* QLEArchivoUI;
    QPushButton* QPBSArchivo;
    QPushButton* QPBCopiaP_2_2;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEClase;
    QLabel* textLabel1_2_2_3;
    QLineEdit* QLEPantalla;

protected:
    QGridLayout* ActualizaPantallaLayout;
    QHBoxLayout* layout18;
    QSpacerItem* spacer4;
    QVBoxLayout* layout13_2_2_2;
    QHBoxLayout* layout19;
    QVBoxLayout* layout13;
    QVBoxLayout* layout13_2;
    QHBoxLayout* layout20;
    QHBoxLayout* layout22;
    QSpacerItem* spacer3;
    QVBoxLayout* layout13_2_2;
    QVBoxLayout* layout13_2_2_3;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZAPANTALLA_H
