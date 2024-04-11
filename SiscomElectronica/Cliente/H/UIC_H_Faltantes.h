/****************************************************************************
** Form interface generated from reading ui file 'UI/Faltantes.ui'
**
** Created: Wed Apr 10 20:52:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FALTANTES_H
#define FALTANTES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class QTabWidget;
class QWidget;
class QLineEdit;
class QTextEdit;

class Faltantes : public QDialog
{
    Q_OBJECT

public:
    Faltantes( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Faltantes();

    QLabel* textLabel3;
    QTable* table4;
    QPushButton* pushButton3;
    QPushButton* pushButton3_2;
    QPushButton* pushButton3_2_2;
    QTabWidget* QTWTipoProducto;
    QWidget* tab;
    QLabel* textLabel1;
    QLineEdit* QLEProducto;
    QLabel* textLabel4;
    QLineEdit* QLECantidad;
    QLabel* textLabel5;
    QTextEdit* textEdit3;
    QLabel* textLabel5_3;
    QTextEdit* QTEDescripcion;
    QWidget* tab_2;
    QLabel* textLabel1_2;
    QLineEdit* QLENvoProducto;
    QLabel* textLabel5_2;
    QTextEdit* QTEDescripcionNvo;
    QLabel* textLabel5_2_2;
    QTextEdit* textEdit3_2_2;

protected:
    QGridLayout* FaltantesLayout;
    QVBoxLayout* layout7;
    QHBoxLayout* layout26;
    QGridLayout* tabLayout;
    QHBoxLayout* layout24;
    QVBoxLayout* layout5;
    QVBoxLayout* layout22;
    QVBoxLayout* layout23;
    QVBoxLayout* layout23_3;
    QGridLayout* tabLayout_2;
    QVBoxLayout* layout5_2;
    QVBoxLayout* layout23_2;
    QVBoxLayout* layout23_2_2;

protected slots:
    virtual void languageChange();

};

#endif // FALTANTES_H
