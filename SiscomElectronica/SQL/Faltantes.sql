#!/bin/bash

source $HOME/bin/FuncionesComunesBash

cat << SQL |  psql -h 192.168.1.106 SiscomElectronica

select sum(a.cantidad),
	a.cveproducto,
	existencia,
	exbodegas
from ventas as a inner join
	existenciaexpendiobodegas as b on a.cveproducto=b.cveproducto and 
			    a.idexpendio=b.idexpendio 
where fechahora::date='$1'  
group by a.cveproducto,
	existencia,
	exbodegas
order by cveproducto desc


SQL

