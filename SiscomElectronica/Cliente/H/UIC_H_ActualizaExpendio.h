/****************************************************************************
** Form interface generated from reading ui file 'UI/ActualizaExpendio.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZAEXPENDIO_H
#define ACTUALIZAEXPENDIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class ActualizaExpendio : public QWidget
{
    Q_OBJECT

public:
    ActualizaExpendio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ActualizaExpendio();

    QLabel* textLabel1;
    QTable* QTExpendios;
    QLabel* textLabel1_2;
    QTable* QTProdsNoExpendio;
    QPushButton* QPBProductos;
    QPushButton* pushButton6_2;

protected:
    QGridLayout* ActualizaExpendioLayout;
    QVBoxLayout* layout10;
    QVBoxLayout* layout17;
    QHBoxLayout* layout19;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZAEXPENDIO_H
