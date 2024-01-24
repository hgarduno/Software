insert into tipoproductos values(4,'Circuito Impreso');
-- Cambia la Entrenadora 4550 de Kit a Producto Siscom
update productoportipoproducto set idtipoproducto=3 where idproducto=1488141064;
-- Revisar la forma de extraer de la base de desarrollo
-- la definicion de los productos que se agreguen durante
-- la construccion para poder insertarlos en las bases de
-- datos de produccion, sin necesidad de registrar desde
-- la interfaz

insert into preciocliente values(1153257207);
insert into tipospersona values(2,'CliMayoreo','Cliente de mayoreo');
insert into personas values('Gabriel','Luna','','',-1200,2,'');
-- Elimina el registro de Ivan
delete from alumnoescuela where idpersona = 1527254357; 
delete from ordencliente where idpersona = 1527254357;
update personas set idpersona=-1201,tipopersona=2  where nombre='Ivan' and apaterno='Alvarez';
insert into preciocliente values(-1200);
insert into preciocliente values(-1201);

insert into precios   (select cveproducto,-1200,0,idprecio,precio,nmbtipoprecio from precios where idpersona=1153257207);
insert into precios   (select cveproducto,-1201,0,idprecio,precio,nmbtipoprecio from precios where idpersona=1153257207);


