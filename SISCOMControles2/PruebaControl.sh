#!/bin/sh 

DirEjecucion=$HOME/SISCOMControles2

PATH=$DirEjecucion
LD_LIBRARY_PATH=$DirEjecucion:$QTDIR/lib:.:$DIRLIBSISCOM2


PruebaControl $*
