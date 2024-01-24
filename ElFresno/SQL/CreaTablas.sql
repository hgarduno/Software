create table TiposPersona(
			TipoPersona integer primary key,
			NmbTipoPersona varchar(250),
			DscTipoPersona varchar(250)
			);
create table EstadosPedido(
			idEdoPedido integer primary key,
			DscEdoPedido varchar(50)
			);
create table Familias(
			idFamilia integer primary key,
			NmbFamilia varchar(50),
			DscFamilia varchar(250)
		     );
create table Personas(
			Nombre varchar (25),
			APaterno varchar(25),
			AMaterno varchar(25),
			RFC varchar(25),
			idPersona integer,
			TipoPersona  integer references TiposPersona(TipoPersona),
			primary key (Nombre,APaterno,AMaterno));

create table Firmas(
			Firma varchar(25),
			idPersona integer 
		   );
create table Empresas(
			RazonSocial varchar (50),
			idEmpresa integer primary key,
			RFC varchar(15)
		     );

create table Direcciones(
			idPersona integer ,
			idEmpresa integer ,
			Calle varchar(50),
			Numero varchar(10),
			Colonia varchar(40),
			CP integer,
			Municipio varchar(50),
			Estado varchar(25),
			Referencias text
			);
			
create table Apodos(
			idPersona integer ,
			Apodo varchar(25)
		   );

create table Vehiculos(
			idVehiculo integer primary key,
			Placas varchar(25),
			DscVehiculo varchar(50)
			);
create table Telefonos(
			idPersona integer ,
			idEmpresa integer ,
			Telefono varchar(15)
			);
create table Correos(
			idPersona integer ,
			idEmpresa integer ,
			Correo varchar(256)
			);
create table Unidades(
			Unidad integer primary key,
			NmbUnidad varchar(25),
			Abreviatura varchar(10)
			);

create table Productos(
			CveProducto varchar(50),
			DscProducto varchar(50),
			Unidad integer  references Unidades(Unidad),
			idFamilia integer references Familias(idFamilia),
			primary key (CveProducto,idFamilia)
		      );			
			
create table TipoPrecio(
			NmbTipoPrecio varchar(25) primary key,
			Descripcion varchar(256),
			Tipo	varchar(10)
			);
create table Precios(
			CveProducto varchar(50),
			idPersona integer ,
			idEmpresa integer ,
			idPrecio integer ,
			Precio numeric(10,2),
			NmbTipoPrecio varchar(25) References TipoPrecio(NmbTipoPrecio)
			);
	
create table Pedidos(
			idCliente integer ,
			idVendedor integer ,
			idChofer integer ,
			idAutorizo integer ,
			idEmpresa integer ,
			idVehiculo integer ,
			NumPedido integer primary key,
			FechaRegistro timestamp without time zone,
			FechaEntrega timestamp without time zone,
			Importe numeric(10,2));
create table FormaPago(
			NumPedido integer,
			NmbTipoPrecio varchar(25)
		      );
create table EstadoDelPedido(
			NumPedido integer ,
			idEdoPedido integer ,
			FechaHoraEdo timestamp without time zone
			);	
create table DetallePedido(
			NumPedido integer,
			CveProducto varchar(50),
			Cantidad numeric(10,2),
			Importe numeric(10,2),	
			NmbTipoPrecio varchar(25)
			);

create table Compras(
			Fecha timestamp without time zone,
			CveProducto varchar(50),
			Cantidad numeric(10,2),
			Importe numeric(10,2),
			idPersona integer,
			idEmpresa integer
			);
create table Existencias(
			CveProducto varchar(50),
			Existencia numeric(10,2)
			);
			
create table Ventas(
			idExpendio integer references Empresas(idEmpresa),
		    	idVenta  integer ,
		    	FechaHora timestamp without time zone,
		    	CveProducto varchar(50),
		    	Cantidad numeric(10,2),
		    	Importe  numeric(10,2),
			Precio   numeric(10,2),
		    	Vendedor integer ,
		    	Cliente  integer
		    );
create table ImporteOrden(idVenta integer ,
			  Importe numeric(10,2));
		    
		      
		    
		      
			
insert into EstadosPedido values(1,'Levantado');
insert into EstadosPedido values(2,'Autorizado');
insert into EstadosPedido values(3,'EnCamino');
insert into EstadosPedido values(4,'Pendiente De Pago');

insert into EstadosPedido values(20,'Entregado');

