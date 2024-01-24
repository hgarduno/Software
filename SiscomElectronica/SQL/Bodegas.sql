--- Lunes 3 Enero 2011
--- Para integrar la funcionalidad de bodegas al sistema actual SISCOM
--- es necesario crear las siguientes tablas.
--- Despues sera necesario ejecutar inicializar la tabla MaterialBodega
--- lo cual se realiza con la siguiente instruccion.
--- INSERT INTO materialbodega select 0,cveproducto,0,0 from productos ;
--- Lo anterior tiene el siguiente problema, si en el transcurso de la 
--- operacion se agrega un nuevo producto, este no se inicializar de 
--- forma correcta en la bodega, por lo que sera necesario modificar 
--- considerar este escenario.

create  table Bodegas(idbodega integer unique,
		   bodega   varchar(125) primary key);
		   	

create table MaterialBodega(idbodega integer references bodegas(idbodega),
			    CveProducto varchar(30) references productos(cveproducto),
			    existencia numeric(10,2),
			    idcompra integer ,
			    primary key(idbodega,cveproducto));


create table BodegaAExpendio(idbodega integer references bodegas(idbodega),
			     idexpendio integer references empresas(idempresa),
			     fecha timestamp without time zone,
			     idempleado integer references personas(idpersona),
			     cantidad numeric(10,2),
			     CveProducto varchar(30) references productos(CveProducto));


create table InventarioBodega(idbodega integer references bodegas(idbodega),
			      fecha timestamp without time zone,
			      CveProducto varchar(30) references Productos(CveProducto),
			      Cantidad numeric(10,2),
			      Existencia numeric(10,2),
			      idPersona integer references personas(IdPersona));



