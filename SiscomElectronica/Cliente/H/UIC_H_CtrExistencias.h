/****************************************************************************
** Form interface generated from reading ui file 'UI/CtrExistencias.ui'
**
** Created: Thu Apr 11 21:53:20 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CTREXISTENCIAS_H
#define CTREXISTENCIAS_H

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

class CtrExistencias : public QWidget
{
    Q_OBJECT

public:
    CtrExistencias( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CtrExistencias();

    QLabel* textLabel2;
    QComboBox* QCBProductos;
    QLabel* textLabel1;
    QLineEdit* lineEdit1;
    QTable* QTDatos;
    QLabel* textLabel1_2;
    QTextEdit* QLEDescripcion;
    QPushButton* QPBExExpendio;
    QPushButton* QPBExistenciaM;
    QPushButton* QPBPExistencia;
    QPushButton* QPBProdsBodega;
    QPushButton* pushButton3;
    QPushButton* QPBAAnexarP;

protected:
    QGridLayout* CtrExistenciasLayout;
    QHBoxLayout* layout13;
    QVBoxLayout* layout12;
    QVBoxLayout* layout7;
    QVBoxLayout* layout66;
    QHBoxLayout* layout22;

protected slots:
    virtual void languageChange();

};

#endif // CTREXISTENCIAS_H
