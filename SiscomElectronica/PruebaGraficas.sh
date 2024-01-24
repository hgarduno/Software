#!/bin/sh

LD_LIBRARY_PATH=$QTDIR/lib:Cliente/SO:$DIRLIBSISCOM2:$QTDIR/plugins/designer
PATH=Cliente

export	LD_LIBRARY_PATH \
	PATH

PruebasGrafica
