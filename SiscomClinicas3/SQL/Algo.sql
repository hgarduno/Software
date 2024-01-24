select idConsulta,
       idSerProd,
       b.Clave,
       b.Descripcion,
       IdEmpleado,
       c.Nombre,
       c.APaterno,
       c.AMaterno,
       fecha,
       cantidad
from	RegistroProductoServicio as a inner join 
	servicios as b	on idSerProd=idservicio inner join
	personas  as c  on  idEmpleado=idpersona
where idConsulta=1213794349
union
select idConsulta,
       idSerProd,
       b.Clave,
       b.Descripcion,
       IdEmpleado,
       c.Nombre,
       c.APaterno,
       c.AMaterno,
       fecha,
       cantidad
from	RegistroProductoServicio as a inner join 
	serviciomedico as b	on idSerProd=idservicio inner join
	personas  as c  on  idEmpleado=c.idpersona
where idConsulta=1213794349
union
select idConsulta,
       idSerProd,
       b.Clave,
       b.Dsc,
       IdEmpleado,
       c.Nombre,
       c.APaterno,
       c.AMaterno,
       fecha,
       cantidad
from	RegistroProductoServicio as a inner join 
	producto  as b	on idSerProd=idproducto inner join
	personas  as c  on  idEmpleado=c.idpersona
where idConsulta=1213794349
order by fecha desc
