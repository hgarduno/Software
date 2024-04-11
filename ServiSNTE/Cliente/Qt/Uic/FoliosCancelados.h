/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/FoliosCancelados.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FOLIOSCANCELADOS_H
#define FOLIOSCANCELADOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlTiendasEntrega;
class QLineEdit;
class QTable;
class QPushButton;

class FoliosCancelados : public QWidget
{
    Q_OBJECT

public:
    FoliosCancelados( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~FoliosCancelados();

    QLabel* textLabel1;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel2;
    QLineEdit* QLEFechaInicio;
    QLabel* textLabel2_2;
    QLineEdit* QLEFechaFinal;
    QLabel* textLabel1_2;
    QTable* QTFoliosCancelados;
    QPushButton* QPBMostrar;
    QPushButton* QPBBorrar;

protected:
    QGridLayout* FoliosCanceladosLayout;
    QVBoxLayout* layout13;
    QVBoxLayout* layout11;
    QVBoxLayout* layout2;
    QHBoxLayout* layout10;
    QVBoxLayout* layout8;
    QVBoxLayout* layout9;
    QVBoxLayout* layout12;
    QHBoxLayout* layout9_2;

protected slots:
    virtual void languageChange();

};

#endif // FOLIOSCANCELADOS_H
