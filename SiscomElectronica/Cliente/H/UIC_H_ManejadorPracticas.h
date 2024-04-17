/****************************************************************************
** Form interface generated from reading ui file 'UI/ManejadorPracticas.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MANEJADORPRACTICAS_H
#define MANEJADORPRACTICAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProductosSE;
class QLineEdit;
class QTable;
class QCtrlEscuelasSE;
class QPushButton;
class QTextEdit;

class ManejadorPracticas : public QWidget
{
    Q_OBJECT

public:
    ManejadorPracticas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ManejadorPracticas();

    QLabel* textLabel4;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel3_2;
    QLineEdit* QLECantidad;
    QTable* QTProductos;
    QLabel* textLabel1;
    QCtrlEscuelasSE* QCtrEscuelas;
    QLabel* textLabel2_3;
    QLineEdit* QLECvePractica;
    QLabel* textLabel2_2;
    QLineEdit* QLEMateria;
    QPushButton* QPBSeleccionaPractica;
    QPushButton* QPBRegistraPractica;
    QPushButton* QPBAnexar;
    QPushButton* QPBEliminaProducto;
    QPushButton* QPBRegistraProductos;
    QLabel* textLabel2;
    QLineEdit* QLENombrePractica;
    QLabel* textLabel3;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel3_3;
    QTextEdit* QTEObservaciones;
    QLabel* textLabel2_4;
    QLineEdit* QLENombre;
    QLabel* textLabel2_4_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel2_4_2_2;
    QLineEdit* QLEAMaterno;

protected:
    QGridLayout* ManejadorPracticasLayout;
    QHBoxLayout* layout20;
    QVBoxLayout* layout18;
    QVBoxLayout* layout8;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2_3;
    QVBoxLayout* layout2_2;
    QHBoxLayout* layout25;
    QVBoxLayout* layout2;
    QVBoxLayout* layout4;
    QVBoxLayout* layout4_2;
    QHBoxLayout* layout14;
    QVBoxLayout* layout2_4;
    QVBoxLayout* layout2_4_2;
    QVBoxLayout* layout2_4_2_2;

protected slots:
    virtual void languageChange();

};

#endif // MANEJADORPRACTICAS_H
