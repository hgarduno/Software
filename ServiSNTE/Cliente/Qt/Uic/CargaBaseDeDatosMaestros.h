/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CargaBaseDeDatosMaestros.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CARGABASEDEDATOSMAESTROS_H
#define CARGABASEDEDATOSMAESTROS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CargaBaseDeDatosMaestros : public QWidget
{
    Q_OBJECT

public:
    CargaBaseDeDatosMaestros( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CargaBaseDeDatosMaestros();

    QLabel* textLabel1;
    QLineEdit* QLEArchivoNomina;
    QPushButton* QPBSelArchivo;

protected:
    QGridLayout* CargaBaseDeDatosMaestrosLayout;
    QVBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // CARGABASEDEDATOSMAESTROS_H
