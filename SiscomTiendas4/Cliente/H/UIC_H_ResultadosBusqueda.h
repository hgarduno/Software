/****************************************************************************
** Form interface generated from reading ui file 'UI/ResultadosBusqueda.ui'
**
** Created: Wed Sep 24 15:45:50 2025
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef RESULTADOSBUSQUEDA_H
#define RESULTADOSBUSQUEDA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class ResultadosBusqueda : public QDialog
{
    Q_OBJECT

public:
    ResultadosBusqueda( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ResultadosBusqueda();

    QLabel* textLabel1;
    QTable* QTDatos;
    QPushButton* pushButton1;

protected:
    QGridLayout* ResultadosBusquedaLayout;
    QVBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // RESULTADOSBUSQUEDA_H
