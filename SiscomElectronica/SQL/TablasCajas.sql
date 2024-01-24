create table Cajas(idCaja 		integer unique,
		    DireccionIp		varchar(25) primary key,
		    Descripcion		text);

create table ventasCaja(idCaja		integer references Cajas(idCaja) ,
			idVenta		integer,
			Total		numeric(10,2),
			Recibio		numeric(10,2),
			Cambio		numeric(10,2),
			fecha		timestamp without time zone);


create table cortecaja(idCaja		integer,
		       idReporte	integer unique,
		       fechahora 	timestamp without time zone,
		       idEmpleado	integer,
		       ImporteCorte	numeric(10,2)
		       );
create table detalleCorteCaja(
		       idReporte	integer references CorteCaja(idReporte),
		       Importe 		numeric(10,2),
		       Denominacion 	integer,
		       Cantidad		integer);


			
create table estadocaja(idCaja 		integer references Cajas(idCaja),
		       Importe 		numeric(10,2),
		       fecha		date,
		       primary key(idCaja,fecha));
		
create table ControlesVenta(
			idControl	integer unique,
			NombreQT	varchar(128),
			Nombre		varchar(128),
			primary key (Nombreqt,nombre));

create table EstadoControlesCaja(idCaja		integer references Cajas(idCaja),
				 idControl 	integer references ControlesVenta(idControl),
				 Estado		integer);

