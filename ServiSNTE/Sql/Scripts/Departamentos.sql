#!/bin/sh 

mdb-export -H  $HOME/ServiSNTE.mdb TGCDep |sed s/\"//g |awk -F',' '{printf "insert into  Departamentos values(%s,\"%s\",\"%s\");\n", $2, $3, $4}' |sed s/\"/\'/g


mdb-export -H  $HOME/ServiSNTE.mdb TGCDep |sed s/\"//g |awk -F',' '{printf "insert into  EstatusDepartamento values(%s,1);\n", FNR}' |sed s/\"/\'/g
