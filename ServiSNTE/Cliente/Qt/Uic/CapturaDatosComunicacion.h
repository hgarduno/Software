/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaDatosComunicacion.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADATOSCOMUNICACION_H
#define CAPTURADATOSCOMUNICACION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaDatosComunicacion : public QDialog
{
    Q_OBJECT

public:
    CapturaDatosComunicacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDatosComunicacion();

    QGroupBox* groupBox3;
    QLabel* textLabel2;
    QLineEdit* QLETelefonoParticular;
    QLabel* textLabel2_2;
    QLineEdit* QLETelefonoCelular;
    QLabel* textLabel2_3;
    QLineEdit* QLETelefonoRecados;
    QLabel* textLabel2_6_2;
    QLineEdit* QLECorreo;
    QPushButton* QPBRegistrar;
    QPushButton* QPBActualizar;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaDatosComunicacionLayout;
    QGridLayout* groupBox3Layout;
    QGridLayout* layout13;
    QGridLayout* layout13_2;
    QGridLayout* layout13_3;
    QVBoxLayout* layout37;
    QHBoxLayout* layout6;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADATOSCOMUNICACION_H
