/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RepProveedores.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPPROVEEDORES_H
#define REPPROVEEDORES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProveedoresSS;
class QPushButton;
class QTable;
class QTextEdit;

class RepProveedores : public QWidget
{
    Q_OBJECT

public:
    RepProveedores( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RepProveedores();

    QLabel* textLabel1;
    QCtrlProveedoresSS* QCtrProveedores;
    QPushButton* QPBConsultar;
    QPushButton* QPBImprimir;
    QTable* QTProveedores;
    QLabel* textLabel2;
    QTextEdit* textEdit1;

protected:
    QGridLayout* RepProveedoresLayout;
    QVBoxLayout* layout2;
    QHBoxLayout* layout3;
    QVBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // REPPROVEEDORES_H
