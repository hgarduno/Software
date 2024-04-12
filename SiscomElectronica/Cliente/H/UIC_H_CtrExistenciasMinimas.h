/****************************************************************************
** Form interface generated from reading ui file 'UI/CtrExistenciasMinimas.ui'
**
** Created: Thu Apr 11 21:53:23 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CTREXISTENCIASMINIMAS_H
#define CTREXISTENCIASMINIMAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QTable;
class QTextEdit;
class QPushButton;

class CtrExistenciasMinimas : public QWidget
{
    Q_OBJECT

public:
    CtrExistenciasMinimas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CtrExistenciasMinimas();

    QLabel* textLabel2;
    QComboBox* QCBProductos;
    QLabel* textLabel1;
    QLineEdit* QLEExistenciaM;
    QTable* QTDatos;
    QLabel* textLabel1_2;
    QTextEdit* QLEDescripcion;
    QPushButton* QPBAELista;
    QPushButton* QPBEliminar;
    QPushButton* QPBActualizar;

protected:
    QGridLayout* CtrExistenciasMinimasLayout;
    QHBoxLayout* layout13;
    QVBoxLayout* layout12;
    QVBoxLayout* layout7;
    QVBoxLayout* layout72;
    QHBoxLayout* layout13_2;

protected slots:
    virtual void languageChange();

};

#endif // CTREXISTENCIASMINIMAS_H
