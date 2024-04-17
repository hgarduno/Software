/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaExistenciaFisica.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAEXISTENCIAFISICA_H
#define CAPTURAEXISTENCIAFISICA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaExistenciaFisica : public QDialog
{
    Q_OBJECT

public:
    CapturaExistenciaFisica( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaExistenciaFisica();

    QLabel* textLabel1_3;
    QLineEdit* QLEExistenciaFisica;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaExistenciaFisicaLayout;
    QVBoxLayout* layout13;
    QVBoxLayout* layout7;
    QHBoxLayout* layout12;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAEXISTENCIAFISICA_H
