/****************************************************************************
** Form interface generated from reading ui file 'UI/ReporteExistencias.ui'
**
** Created: Thu Apr 11 20:30:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPORTEEXISTENCIAS_H
#define REPORTEEXISTENCIAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProductos;
class QCtrlFamilias;
class QTextEdit;
class QTable;
class QPushButton;

class ReporteExistencias : public QWidget
{
    Q_OBJECT

public:
    ReporteExistencias( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ReporteExistencias();

    QLabel* textLabel4;
    QCtrlProductos* QCtrProductos;
    QLabel* textLabel4_2;
    QCtrlFamilias* QCtrFamilias;
    QLabel* textLabel1;
    QTextEdit* QTEDsc;
    QLabel* textLabel5;
    QTable* QTDatos;
    QPushButton* pushButton27;
    QPushButton* QPBTodos;
    QPushButton* pushButton27_2_2;

protected:
    QGridLayout* ReporteExistenciasLayout;
    QVBoxLayout* layout33;
    QHBoxLayout* layout82;
    QSpacerItem* spacer2;
    QHBoxLayout* layout80;
    QVBoxLayout* layout78;
    QVBoxLayout* layout79;
    QVBoxLayout* layout32;
    QVBoxLayout* layout81;
    QHBoxLayout* layout31;

protected slots:
    virtual void languageChange();

};

#endif // REPORTEEXISTENCIAS_H
