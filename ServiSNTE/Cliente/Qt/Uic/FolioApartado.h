/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/FolioApartado.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FOLIOAPARTADO_H
#define FOLIOAPARTADO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QLineEdit;
class QPushButton;
class QCtrlTiposFolio;
class QCtrlTiendasEntrega;

class FolioApartado : public QWidget
{
    Q_OBJECT

public:
    FolioApartado( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~FolioApartado();

    QLabel* textLabel4;
    QTable* table1;
    QLabel* textLabel3;
    QLineEdit* QLERangoFechas;
    QPushButton* QPBRegistrar;
    QPushButton* pushButton2;
    QLabel* textLabel5;
    QCtrlTiposFolio* QCtrTiposFolio;
    QLabel* textLabel1_3;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel2;
    QLineEdit* QLEFolioInicio;
    QLabel* textLabel2_2;
    QLineEdit* QLEFolioFin;

protected:
    QGridLayout* FolioApartadoLayout;
    QVBoxLayout* layout9;
    QVBoxLayout* layout6;
    QHBoxLayout* layout10;
    QHBoxLayout* layout8;
    QVBoxLayout* layout7;
    QVBoxLayout* layout2;
    QVBoxLayout* layout9_2;
    QVBoxLayout* layout11;

protected slots:
    virtual void languageChange();

};

#endif // FOLIOAPARTADO_H
