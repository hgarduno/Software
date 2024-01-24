#!/bin/sh 
DirTrabajo=$HOME/Sepomex
LD_LIBRARY_PATH=$DIRLIBSISCOM2:$QTDIR/lib:$DirTrabajo/Cliente/SO
PATH=$DirTrabajo/Cliente


PruebaSepomex $*
