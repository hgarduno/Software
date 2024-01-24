#!/bin/sh

killall -9 psql
dropdb	Trampolin 
createdb Trampolin

psql Trampolin < $HOME/SISCOMClasesGenerales/SQL/TablasClasesGenerales.sql 
psql Trampolin < SQL/InsertaTiposPersona.sql
psql Trampolin < SQL/TablasTrampolin.sql
psql Trampolin < SQL/InsertaDatos.sql
psql Trampolin < $HOME/Sepomex/SQL/InformacionSepomex.sql 
psql Trampolin < $HOME/SISCOMSeguridad3/EsquemaSeguridad3.sql 
psql Trampolin < $HOME/SISCOMSeguridad3/SQL/AlgunosObjetos.sql

#/home/hgarduno/SISCOMSeguridad3/
