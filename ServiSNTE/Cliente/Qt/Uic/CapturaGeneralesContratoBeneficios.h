/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaGeneralesContratoBeneficios.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAGENERALESCONTRATOBENEFICIOS_H
#define CAPTURAGENERALESCONTRATOBENEFICIOS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaGeneralesContratoBeneficios : public QDialog
{
    Q_OBJECT

public:
    CapturaGeneralesContratoBeneficios( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaGeneralesContratoBeneficios();

    QLabel* textLabel6;
    QLineEdit* QLELugar;
    QLabel* textLabel5_2_2_2_2_2;
    QLineEdit* QLEFecha;
    QPushButton* QPBRegistrar;
    QPushButton* QPBActualizar;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaGeneralesContratoBeneficiosLayout;
    QHBoxLayout* layout67;
    QVBoxLayout* layout22;
    QVBoxLayout* layout16_2_2_2_2_2;
    QHBoxLayout* layout6;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAGENERALESCONTRATOBENEFICIOS_H
