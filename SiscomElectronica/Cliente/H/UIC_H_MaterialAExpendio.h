/****************************************************************************
** Form interface generated from reading ui file 'UI/MaterialAExpendio.ui'
**
** Created: Wed Apr 10 21:12:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MATERIALAEXPENDIO_H
#define MATERIALAEXPENDIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QTable;
class QTextEdit;
class QPushButton;

class MaterialAExpendio : public QWidget
{
    Q_OBJECT

public:
    MaterialAExpendio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~MaterialAExpendio();

    QLabel* textLabel1;
    QLineEdit* QLEMatriz;
    QLabel* textLabel1_2;
    QLineEdit* QLEExpendio;
    QLabel* textLabel3;
    QComboBox* QCBProductos;
    QLabel* textLabel2;
    QLineEdit* QLECantidad;
    QLabel* textLabel2_2;
    QLineEdit* QLEExistencia;
    QTable* QTDatos;
    QLabel* textLabel1_2_2;
    QTextEdit* QLEDescripcion;
    QPushButton* QPBSelExpendio;
    QPushButton* QPBRegistraEnvio;
    QPushButton* QPBAnexar;
    QPushButton* QPBEliminar;
    QPushButton* QPBCambiaCantidad;

protected:
    QGridLayout* MaterialAExpendioLayout;
    QVBoxLayout* layout67;
    QVBoxLayout* layout67_2;
    QVBoxLayout* layout71;
    QVBoxLayout* layout70;
    QVBoxLayout* layout70_2;
    QVBoxLayout* layout60;

protected slots:
    virtual void languageChange();

};

#endif // MATERIALAEXPENDIO_H
