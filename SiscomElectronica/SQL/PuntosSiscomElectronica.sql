create table ValorPuntos(PesosPPunto numeric(10,3));
--- Domingo 21 De Agosto 2011 
--- Recordar que hay que poner como unique IdPromocion
--- al crear la tabla 
--- Si la tabla ya esta creado se usa la siguiente sentencia SQL
-- ALTER TABLE promocion add constraint uniqui_ippromocion unique(idpromocion) ;
create table Promocion(IdPromocion integer unique,nombre varchar(100) primary key,Inicia date,Termina date,puntos numeric(10,3),Descripcion text);

create table ComprasClientes(idpersona integer references personas(idpersona) primary key,
			    Total numeric(10,3),
			    FechaRegistro date);
create table SeguimientoComprasClientes(
		IdPersona integer references personas(idpersona),
		Fecha timestamp without time zone,
		total numeric(10,2),
		idventa integer);

create table SeguimientoPuntosClientes(
		IdPersona integer references personas(idpersona),
		IdOperacion integer unique,
		PuntosTotalesTomados numeric(10,2),
		Fecha timestamp without time zone);

create table DetalleOperacionPuntosClientes(
	     IdOperacion integer references SeguimientoPuntosClientes(idOperacion),
	     idPromocion integer references Promocion(idPromocion),
		PuntosPromocion numeric(10,2));



insert into ValorPuntos values(1);		
	
		
