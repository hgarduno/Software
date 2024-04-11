/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaDescuentos.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADESCUENTOS_H
#define CAPTURADESCUENTOS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaDescuentos : public QDialog
{
    Q_OBJECT

public:
    CapturaDescuentos( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDescuentos();

    QLabel* textLabel1;
    QLineEdit* QLEDescuento1;
    QLabel* textLabel1_2;
    QLineEdit* QLEDescuento2;
    QLabel* textLabel1_3;
    QLineEdit* QLEDescuento3;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEDescuento4;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaDescuentosLayout;
    QVBoxLayout* layout34;
    QHBoxLayout* layout33;
    QVBoxLayout* layout28;
    QVBoxLayout* layout28_2;
    QVBoxLayout* layout28_3;
    QVBoxLayout* layout28_2_2;
    QHBoxLayout* layout32;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADESCUENTOS_H
