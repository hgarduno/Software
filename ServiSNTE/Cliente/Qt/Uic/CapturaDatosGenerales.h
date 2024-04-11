/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaDatosGenerales.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADATOSGENERALES_H
#define CAPTURADATOSGENERALES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QButtonGroup;
class QRadioButton;
class QPushButton;

class CapturaDatosGenerales : public QDialog
{
    Q_OBJECT

public:
    CapturaDatosGenerales( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDatosGenerales();

    QLabel* textLabel6;
    QLineEdit* QLERFCHomoclave;
    QLabel* textLabel5;
    QLineEdit* QLECurp;
    QLabel* textLabel5_2;
    QLineEdit* QLEEstadoNacimiento;
    QLabel* textLabel6_2;
    QLineEdit* QLEPaisNacimiento;
    QButtonGroup* QGBSexo;
    QRadioButton* QRBMasculino;
    QRadioButton* QRBFemenino;
    QButtonGroup* buttonGroup1_2;
    QRadioButton* QRBCasado;
    QRadioButton* QRBSoltero;
    QLabel* textLabel5_2_2_2;
    QLineEdit* QLEEdad;
    QLabel* textLabel5_2_2_2_2;
    QLineEdit* QLEFechaNacimiento;
    QLabel* textLabel2_5;
    QLineEdit* QLEIdentificacion;
    QLabel* textLabel2_6;
    QLineEdit* QLENoIdentificacion;
    QLabel* textLabel2_6_2;
    QLineEdit* QLEOcupacion;
    QLabel* textLabel2_6_2_2;
    QLineEdit* QLENacionalidad;
    QPushButton* QPBRegistrar;
    QPushButton* QPBActualizar;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaDatosGeneralesLayout;
    QHBoxLayout* layout17;
    QVBoxLayout* layout22;
    QVBoxLayout* layout16;
    QVBoxLayout* layout16_2;
    QHBoxLayout* layout21;
    QVBoxLayout* layout22_2;
    QHBoxLayout* QGBSexoLayout;
    QHBoxLayout* buttonGroup1_2Layout;
    QVBoxLayout* layout16_2_2_2;
    QVBoxLayout* layout16_2_2_2_2;
    QHBoxLayout* layout22_3;
    QGridLayout* layout13_5;
    QGridLayout* layout13_6;
    QGridLayout* layout13_6_2;
    QGridLayout* layout13_6_2_2;
    QHBoxLayout* layout15;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADATOSGENERALES_H
