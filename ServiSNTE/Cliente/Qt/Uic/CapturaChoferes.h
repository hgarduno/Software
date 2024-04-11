/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaChoferes.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURACHOFERES_H
#define CAPTURACHOFERES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTable;

class CapturaChoferes : public QWidget
{
    Q_OBJECT

public:
    CapturaChoferes( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CapturaChoferes();

    QLabel* textLabel1_2;
    QLineEdit* lineEdit32;
    QLabel* pushButton60;
    QLineEdit* lineEdit33;
    QLabel* textLabel2;
    QLineEdit* lineEdit34;
    QLabel* textLabel3;
    QLineEdit* lineEdit35;
    QPushButton* pushButton28;
    QPushButton* pushButton29;
    QLabel* textLabel4;
    QTable* QTTelefono;
    QPushButton* pushButton30;
    QPushButton* pushButton26;
    QPushButton* pushButton27;
    QPushButton* pushButton11;
    QPushButton* pushButton61;

protected:
    QGridLayout* CapturaChoferesLayout;
    QVBoxLayout* layout17;
    QHBoxLayout* layout81;
    QSpacerItem* spacer7;
    QVBoxLayout* layout79;
    QVBoxLayout* layout80;
    QHBoxLayout* layout15;
    QVBoxLayout* layout14;
    QHBoxLayout* layout74;
    QHBoxLayout* layout75;
    QVBoxLayout* layout13;
    QHBoxLayout* layout16;
    QVBoxLayout* layout12;
    QHBoxLayout* layout72;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURACHOFERES_H
