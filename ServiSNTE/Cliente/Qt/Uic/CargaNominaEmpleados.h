/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CargaNominaEmpleados.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CARGANOMINAEMPLEADOS_H
#define CARGANOMINAEMPLEADOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CargaNominaEmpleados : public QWidget
{
    Q_OBJECT

public:
    CargaNominaEmpleados( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CargaNominaEmpleados();

    QLabel* textLabel1;
    QLineEdit* QLEArchivoNomina;
    QPushButton* QPBSelArchivo;

protected:
    QGridLayout* CargaNominaEmpleadosLayout;
    QVBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // CARGANOMINAEMPLEADOS_H
