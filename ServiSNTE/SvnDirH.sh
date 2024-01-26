#!/bin/bash
echo 'Escribe tu ususario UNIX:'
read User
Home=/home/$User
PreparacionDir()
{
    cd $HOME/
    mkdir ProgramasServiSNTE
    cd ProgramasServiSNTE
    mkdir SiscomDesarrollo4++ SiscomComunicaciones++ SiscomDesarrollo4 SiscomDesarrollo4Qt++
}
IniciaSVN()
{
    echo 'Subversion'
    echo 'USER:'
    read SVNUser
    echo 'PASSWORD:'
    read SVNPsswd
    cd $Home
    svn co svn://10.8.1.1/ServiSNTE --username $SVNUser --password $SVNPsswd
    cd ProgramasServiSNTE
    svn co svn://10.8.1.1/SiscomControles --username $SVNUser --password $SVNPsswd
    cd SiscomDesarrollo4
    svn co svn://10.8.1.1/SiscomDesarrollo4/H --username $SVNUser --password $SVNPsswd
    svn co svn://10.8.1.1/SiscomDesarrollo4/PostgresSql --username $SVNUser --password $SVNPsswd
    cd ../SiscomDesarrollo4++
    svn co svn://10.8.1.1/SiscomDesarrollo4++/H --username $SVNUser --password $SVNPsswd
    cd ../SiscomComunicaciones++
    svn co svn://10.8.1.1/SiscomComunicaciones++/H --username $SVNUser --password $SVNPsswd
    cd ../SiscomDesarrollo4Qt++
    svn co svn://10.8.1.1/SiscomDesarrollo4Qt++/H --username $SVNUser --password $SVNPsswd
}
CreaEnlaces()
{
    cd $Home/ProgramasServiSNTE
    ln -s $Home/ServiSNTE ServiSNTE
    cd SiscomControles
    ln -s $Home/SoporteSiscomDesarrollo/Cliente/libSiscomControles.so .
    cd ../SiscomDesarrollo4++
    ln -s $Home/SoporteSiscomDesarrollo/Cliente/libSiscomDesarrollo4++.so.1 libSiscomDesarrollo4++.so
    ln -s $Home/SoporteSiscomDesarrollo/Cliente/libSiscomDesarrollo4++.so.1.0.0 .
    ln -s $Home/SoporteSiscomDesarrollo/Cliente/libSiscomDesarrollo4++.so.1.0.0 libSiscomDesarrollo4++.so.1
    cd ../SiscomComunicaciones++
    ln -s $Home/SoporteSiscomDesarrollo/Cliente/libSiscomComunicaciones++.so.1 libSiscomComunicaciones++.so
    ln -s $Home/SoporteSiscomDesarrollo/Cliente/libSiscomComunicaciones++.so.1.0.0 .
    ln -s $Home/SoporteSiscomDesarrollo/Cliente/libSiscomComunicaciones++.so.1.0.0 libSiscomComunicaciones++.so.1
    cd ../SiscomDesarrollo4
    ln -s $Home/SoporteSiscomDesarrollo/Servidor/libSiscomDesarrollo4.so . 
    ln -s $Home/SoporteSiscomDesarrollo/Servidor/libSiscomOperaciones.so .
    ln -s $Home/SoporteSiscomDesarrollo/Servidor/libSiscomPostgresSql.so .
    ln -s $Home/SoporteSiscomDesarrollo/Servidor/ServidorSiscom .
    cd ../SiscomDesarrollo4Qt++
    ln -s $Home/SoporteSiscomDesarrollo/Cliente/libSiscomDesarrollo4Qt++.so.1.0.0 .
    ln -s $Home/SoporteSiscomDesarrollo/Cliente/libSiscomDesarrollo4Qt++.so.1 .
    ln -s $Home/SoporteSiscomDesarrollo/Cliente/libSiscomDesarrollo4Qt++.so.1.0.0 libSicomDesarrollo4Qt++.so
    cd
    cd $Home/Qt-3.3.8/plugins/designer
    ln -s $Home/ServiSNTE/Cliente/libServiSNTEPlugin.so .

}
PreparacionDir
IniciaSVN
CreaEnlaces

echo '----Fin Script----'
