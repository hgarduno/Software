/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/VisorTransferencias.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef VISORTRANSFERENCIAS_H
#define VISORTRANSFERENCIAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QFrame;
class QPushButton;
class QGroupBox;
class QLabel;
class QLineEdit;
class QTable;
class QTextEdit;
class QDateEdit;

class VisorTransferencias : public QWidget
{
    Q_OBJECT

public:
    VisorTransferencias( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~VisorTransferencias();

    QFrame* frame14;
    QPushButton* QPBRecibir;
    QPushButton* pushButton4_2;
    QPushButton* pushButton4_3;
    QFrame* frame13;
    QGroupBox* groupBox3;
    QLabel* textLabel2;
    QLineEdit* QLETienda;
    QLabel* textLabel2_2;
    QLineEdit* QLEResponsable;
    QLabel* textLabel2_4;
    QLineEdit* QLECamion;
    QLabel* textLabel2_3;
    QLineEdit* QLEChofer;
    QTable* QTDetalleTransferencias;
    QGroupBox* groupBox4;
    QTextEdit* QTEObservacionGeneral;
    QFrame* frame4;
    QDateEdit* dateEdit1;
    QGroupBox* groupBox2;
    QTable* QTTransferencias;

protected:
    QGridLayout* VisorTransferenciasLayout;
    QHBoxLayout* frame14Layout;
    QGridLayout* frame13Layout;
    QGridLayout* groupBox3Layout;
    QHBoxLayout* layout6;
    QHBoxLayout* layout7;
    QHBoxLayout* layout8;
    QHBoxLayout* layout9;
    QGridLayout* groupBox4Layout;
    QGridLayout* frame4Layout;
    QGridLayout* groupBox2Layout;

protected slots:
    virtual void languageChange();

};

#endif // VISORTRANSFERENCIAS_H
