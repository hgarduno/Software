/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaDepartamentos.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADEPARTAMENTOS_H
#define CAPTURADEPARTAMENTOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCheckBox;
class QPushButton;

class CapturaDepartamentos : public QWidget
{
    Q_OBJECT

public:
    CapturaDepartamentos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CapturaDepartamentos();

    QLabel* textLabel19;
    QLineEdit* QLEDepartamento;
    QLabel* textLabel21;
    QLineEdit* QLEAbreviatura;
    QCheckBox* checkBox12;
    QLabel* textLabel20;
    QLineEdit* QLENombreDepartamento;
    QPushButton* QPBCrear;
    QPushButton* QPBCancelar;
    QPushButton* pushButton28;
    QPushButton* pushButton48;

protected:
    QGridLayout* CapturaDepartamentosLayout;
    QVBoxLayout* layout92;
    QHBoxLayout* layout91;
    QSpacerItem* spacer3;
    QHBoxLayout* layout330;
    QVBoxLayout* layout326;
    QVBoxLayout* QLayoutDepartamento;
    QVBoxLayout* layout329;
    QHBoxLayout* layout90;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADEPARTAMENTOS_H
