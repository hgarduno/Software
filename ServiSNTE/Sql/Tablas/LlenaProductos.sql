update productos set nombreproducto='LIBRERO 1.40 X 1.80 BAJA' where idproducto=866;
delete from productos where idproducto>=967 AND idproducto<=969;
insert into Empresas values(345,'CANON DE MEXICO S.A. DE C.V.','');
insert into Productos values(54321,1,'IMPRESORA MULTIFUNCIONAL CANON','IMAGE CLASS MF4890DW');

INSERT INTO Productos values(87654,2,'CAMARA FOTOGRAFICA 10 MEGA PIXELES','FOCUS REFLEX 2000');
insert into ProductoProveedor values(345,54321);
insert into ProductoProveedor values(345,87654);
insert into estatusproducto(idproducto,idestatus) (select idproducto,7 from productos where nombreproducto ilike '%BAJA%');
insert into estatusproducto(idproducto,idestatus) (select idproducto,9 from productos where nombreproducto ilike '%LIQUI%');
insert into estatusproducto(idproducto,idestatus) (select idproducto,3 from productos where nombreproducto ilike '%DESC%');
insert into estatusproducto(idproducto,idestatus) (select idproducto,1 from productos where nombreproducto not ilike '%baja%' AND nombreproducto not ilike '%desc%' AND nombreproducto not ilike '%liqui%');
update productos set nombreproducto=replace(substring(nombreproducto from 1 for strpos(UPPER(nombreproducto),'BAJA')-1),'@','') where nombreproducto ilike '%baja%';
update productos set nombreproducto=replace(substring(nombreproducto from 1 for strpos(UPPER(nombreproducto),'DESC')-1),'@','') where nombreproducto ilike '%desc%';
update productos set modelo=replace(substring(modelo from 1 for strpos(UPPER(modelo),'BAJA')-1),'@','') where modelo ilike '%baja%';
update productos set modelo=replace(substring(modelo from 1 for strpos(UPPER(modelo),'DESC')-1),'@','') where modelo ilike '%desc%';
update productos set nombreproducto=replace(nombreproducto,'@','') where nombreproducto ilike '%@%';
update productos set modelo=replace(modelo,'@','') where modelo ilike '%@%';
insert into productocodigobarras(codigobarras,idproducto) (select lpad(lpad(idproducto::varchar(11),11,'0')||lpad(idempresa::varchar(3),3,'0'), 14, '0'), idproducto from productoproveedor as e inner join productos as p using(idproducto));
--#insert into ProductoCodigoBarras values('CMF12345-DFX','1234554321CMF12345-DXF',54321,1);
INSERT INTO DepartamentoProducto values (54321,3);
insert into PrecioGeneral values(1,3000.00,0.00,0.00,'2015/01/18',54321);
insert into PrecioGeneral values(2,3500.00,0.00,0.00,'2015/03/18',54321);

--insert into ProductoCodigoBarras values('678-XFS-003','12345987654678-XFS-003',987654,1);
insert into DepartamentoProducto values(87654,3);
insert into PrecioGeneral values(3,9300.00,0.00,0.00,'2015/01/18',87654);
insert into PrecioGeneral values(4,9500.00,0.00,0.00,'2015/03/18',87654);

