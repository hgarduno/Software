/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaCamiones.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURACAMIONES_H
#define CAPTURACAMIONES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QFrame;
class QLabel;
class QLineEdit;
class QCheckBox;
class QPushButton;

class CapturaCamiones : public QWidget
{
    Q_OBJECT

public:
    CapturaCamiones( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CapturaCamiones();

    QFrame* frame33;
    QLabel* textLabel22;
    QLineEdit* QLEClaveCamion;
    QLabel* textLabel23;
    QLineEdit* QLENombre;
    QCheckBox* QCBActivo;
    QLabel* textLabel24;
    QLineEdit* QLEMarca;
    QLabel* textLabel25;
    QLineEdit* QLETipo;
    QLabel* textLabel26;
    QLineEdit* QLEModelo;
    QLabel* textLabel27;
    QLineEdit* QLEPlacas;
    QPushButton* QPBCrear;
    QPushButton* QPBCancelar;
    QPushButton* pushButton11;
    QPushButton* pushButton61;

protected:
    QGridLayout* CapturaCamionesLayout;
    QVBoxLayout* layout44;
    QGridLayout* frame33Layout;
    QHBoxLayout* layout392;
    QVBoxLayout* layout386;
    QVBoxLayout* layout387;
    QHBoxLayout* layout393;
    QVBoxLayout* layout388;
    QVBoxLayout* layout389;
    QVBoxLayout* layout390;
    QVBoxLayout* layout391;
    QHBoxLayout* layout43;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURACAMIONES_H
