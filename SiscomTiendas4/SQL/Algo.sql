select clave,
	idproducto,
	a.dsc,
	existencia,
	precio,
	nombre,
	c.cantidad
from producto as a inner join 
     inventario as b using(idproducto) inner join
     preciosproducto as c using(idproducto) inner join 
     precios as d using(idprecio)
where clave like '%DB%' 
order by clave,nombre

