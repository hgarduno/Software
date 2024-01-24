#!/bin/sh

#killall -9 psql
#dropdb	Tiendas4
#createdb Tiendas4




#psql $1 < $HOME/SISCOMClasesGenerales/SQL/TablasClasesGenerales.sql 
psql $1 < $DIRDesarrolloHGE/SiscomTiendas4/SQL/TablasTiendas4.sql
#psql $1 < $DIRDesarrolloHGE/SiscomTiendas4/SQL/InsertaDatos.sql
psql $1 < $DIRDesarrolloHGE/Sepomex/SQL/InformacionSepomex.sql 
