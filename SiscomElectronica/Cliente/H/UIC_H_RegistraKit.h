/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistraKit.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTRAKIT_H
#define REGISTRAKIT_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QTextEdit;
class QPushButton;

class RegistraKit : public QDialog
{
    Q_OBJECT

public:
    RegistraKit( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RegistraKit();

    QLabel* textLabel1_2;
    QComboBox* QCBProductos;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;
    QPushButton* QPBAceptar;
    QPushButton* pushButton5_2;

protected:
    QGridLayout* RegistraKitLayout;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout2;
    QHBoxLayout* layout12;

protected slots:
    virtual void languageChange();

};

#endif // REGISTRAKIT_H
