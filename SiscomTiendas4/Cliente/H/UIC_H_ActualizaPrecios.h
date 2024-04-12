/****************************************************************************
** Form interface generated from reading ui file 'UI/ActualizaPrecios.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZAPRECIOS_H
#define ACTUALIZAPRECIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlFamilias;
class QTable;
class QPushButton;

class ActualizaPrecios : public QWidget
{
    Q_OBJECT

public:
    ActualizaPrecios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ActualizaPrecios();

    QLabel* textLabel1;
    QCtrlFamilias* QCtrFamilias;
    QTable* QTProductos;
    QPushButton* QPBConsulta;
    QPushButton* pushButton5_3;
    QPushButton* pushButton5_4;
    QPushButton* pushButton5_2;

protected:
    QGridLayout* ActualizaPreciosLayout;
    QVBoxLayout* layout13;
    QVBoxLayout* layout9;
    QHBoxLayout* layout10;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZAPRECIOS_H
