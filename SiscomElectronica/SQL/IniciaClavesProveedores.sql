insert into clavesproveedores
select distinct 
	proveedor,
	'',
	cveproducto,
	''
from compras  
where proveedor!=0
order by cveproducto

