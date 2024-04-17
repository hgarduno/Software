/****************************************************************************
** Form interface generated from reading ui file 'UI/DescripcionCompraImportacion.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DESCRIPCIONCOMPRAIMPORTACION_H
#define DESCRIPCIONCOMPRAIMPORTACION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTextEdit;
class QPushButton;

class DescripcionCompraImportacion : public QDialog
{
    Q_OBJECT

public:
    DescripcionCompraImportacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DescripcionCompraImportacion();

    QLabel* textLabel1;
    QTextEdit* textEdit1;
    QPushButton* pushButton1;
    QPushButton* pushButton1_2;
    QPushButton* pushButton1_2_2;

protected:
    QVBoxLayout* layout1;
    QHBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // DESCRIPCIONCOMPRAIMPORTACION_H
