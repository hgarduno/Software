/****************************************************************************
** Form interface generated from reading ui file 'UI/SePagaOrdenImpreso.ui'
**
** Created: Thu Dec 21 12:53:40 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SEPAGAORDENIMPRESO_H
#define SEPAGAORDENIMPRESO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLCDNumber;
class QLineEdit;
class QPushButton;

class SePagaOrdenImpreso : public QDialog
{
    Q_OBJECT

public:
    SePagaOrdenImpreso( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SePagaOrdenImpreso();

    QLabel* textLabel1_4;
    QLCDNumber* QLCDNNImpresos;
    QLabel* textLabel1_4_2;
    QLCDNumber* QLCDNumImporte;
    QLabel* textLabel2;
    QLineEdit* QLEAdelanto;
    QPushButton* QPBSePagaCompleto;
    QPushButton* QPBSeDaAdelanto;
    QPushButton* QPBAceptar;

protected:
    QGridLayout* SePagaOrdenImpresoLayout;
    QVBoxLayout* layout85;
    QVBoxLayout* layout65;
    QVBoxLayout* layout65_2;
    QVBoxLayout* layout86;
    QHBoxLayout* layout88;

protected slots:
    virtual void languageChange();

};

#endif // SEPAGAORDENIMPRESO_H
