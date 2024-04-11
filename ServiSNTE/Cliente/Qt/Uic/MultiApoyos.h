/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/MultiApoyos.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MULTIAPOYOS_H
#define MULTIAPOYOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTextEdit;
class QPushButton;

class MultiApoyos : public QWidget
{
    Q_OBJECT

public:
    MultiApoyos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~MultiApoyos();

    QTextEdit* QTEFormato;
    QPushButton* QPBImprimeAArchivo;
    QPushButton* QPBImprimeFrente;
    QPushButton* QPBDomicilioParticular;
    QPushButton* QPBImprimir;
    QPushButton* QPBReferenciasPersonales;
    QPushButton* QPBImprimeAtras;
    QPushButton* QPBDatosGenerales;
    QPushButton* QPBDatosEmpleo;
    QPushButton* QPBIngresosMensuales;
    QPushButton* QPBRFCCliente;
    QPushButton* QPBDomicilioEmpleo;

protected:
    QGridLayout* MultiApoyosLayout;
    QGridLayout* layout32;

protected slots:
    virtual void languageChange();

};

#endif // MULTIAPOYOS_H
