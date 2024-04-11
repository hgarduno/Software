/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RepListaPreciosComprador.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPLISTAPRECIOSCOMPRADOR_H
#define REPLISTAPRECIOSCOMPRADOR_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProveedoresSS;
class QTable;
class QPushButton;

class RepListaPreciosComprador : public QWidget
{
    Q_OBJECT

public:
    RepListaPreciosComprador( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RepListaPreciosComprador();

    QLabel* textLabel1;
    QCtrlProveedoresSS* QCtrProveedores;
    QTable* QTListaPrecios;
    QPushButton* QPBConsulta;
    QPushButton* QPBImprimir;

protected:
    QGridLayout* RepListaPreciosCompradorLayout;
    QVBoxLayout* layout38;
    QHBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // REPLISTAPRECIOSCOMPRADOR_H
