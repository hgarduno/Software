create table Familia(
	idFamilia	integer unique,
	Familia		varchar(50) primary key,
	Dsc		text);



create table Precios(
	idPrecio	integer	unique,
	Nombre		varchar(25) primary key,
	Dsc		text);


create table Producto(
	idProducto	integer unique,
	clave		varchar(50) primary key,	
	dsc		text
	);


create table FamProducto(
	idProducto	integer references Producto(IdProducto),
	idFamilia	integer references Familia(idFamilia));

create table PreciosProducto(
	idProducto	integer references Producto(IdProducto),
	idPrecio	integer references Precios(IdPrecio),
	Precio		numeric(10,2),
	Cantidad	numeric(10,2),
	primary key(idProducto,idPrecio));


create table Empresas(
		idEmpresa	integer unique,
		RazonSocial	varchar(256) primary key);

create table EmpresaNormalizada(
		idEmpresa 	integer references Empresas(IdEmpresa),
		RazonSocial	varchar(256));

create table ContactosEmpresa(
		idempresa	integer references Empresas(idEmpresa),
		idpersona	integer references personas(idPersona) unique);

create table Proveedores(
		idempresa	integer references Empresas(idEmpresa) unique
		);
create table ClientesFisica(
		idPersona integer references Personas(idPersona)
		);
create table ClientesMoral(
		idEmpresa	integer references Empresas(idEmpresa)
		);
create table Expendios(
		idExpendio	integer references Empresas(idEmpresa) unique,
		Puerto		integer,
		DirIp		varchar(25),
		primary key(Puerto,DirIp)
		);
create table FormaPago(
		idFormaPago	integer unique,
		Nombre		varchar(50),
		DiasSigPago	integer);
-- Se debe considerar desglozar la tabla de compras
-- en dos partes, una con los dato de las compras
-- y la otra con la informacion de cada uno de los
-- productos de la compra ( Como en el apartado de
-- Ventas 
--
create table Compras(
		idCompra	integer,
		idProducto	integer references Producto(idProducto),
		Cantidad	numeric(10,2),
		PrecioCompra	numeric(10,2),
		Factura		varchar(50),
		IdEmpresa	integer references Proveedores(idEmpresa),
		IdContacto	integer references ContactosEmpresa(IdPersona),
		idFormaPago	integer references FormaPago(IdFormaPago),
		Fecha		timestamp,
		idExpendio 	integer references Expendios(IdExpendio));

create table Inventario(
		idExpendio	integer references Expendios(idExpendio),
		idProducto	integer references Producto(idProducto),
		Existencia	numeric(10,2),
		ExistenciaMin	numeric(10,2),
		primary key(idExpendio,idProducto)
		);
-- EdoVenta Tendra como objetivo saber
-- el estado de la venta, es decir si fue pago de
-- contado, si es un pedido, etc, esto sera importante
-- cuando se desarrolle la caja.
-- Entonces:
-- Si EdoVenta 0 indicara venta con pago de contado
--
create table Ventas(
		idVenta		integer unique,
		idExpendio	integer references Expendios(idExpendio),
		idFormaPago	integer references FormaPago(idFormaPago),
		TipoCliente	varchar(10),
		Fecha		timestamp,
		Importe		numeric(10,2),
		EdoVenta	integer,
		IdCliente 	integer references personas(idpersona));
create table VentasFisicas(
		idVenta		integer references Ventas(idVenta),
		idPersona	integer references Personas(idPersona)
		);

create table VentasMorales(
		idVenta		integer	references Ventas(idVenta),
		idEmpresa	integer	references Empresas(idEmpresa)
		);
		

		
create table DetalleVenta(
		idVenta		integer references Ventas(idVenta),
		idProducto	integer	references Producto(idProducto),
		Cantidad	numeric(10,2),
		idPrecio 	integer, 
		Total		numeric(10,2)
		);


create table Devoluciones(
		idDevolucion	integer unique,
		idVenta		integer references Ventas(idVenta),
		Total		numeric(10,2),
		Fecha		timestamp,
		Motivo		text);
create table DetalleDevolucion(
		idDevolucion	integer references Devoluciones(idDevolucion),
		idProducto	integer references Producto(IdProducto),
		Cantidad	numeric(10,2),
		Precio		numeric(10,2),
		Importe		numeric(10,2));

-- Esta tabla nos permitira llevar el control de los productos
-- que e encuentran en cotizacion, para iniciar este seguimiento
-- la tabla solo contiene 3 campos, en el futuro se podra agregar
-- la informacion de quien tien el producto cotizando etc.


create table ProductosCotizando(
		idProducto 	integer references Producto(IdProducto),
		idExpendio	integer references Expendios(IdExpendio),
		Cantidad	numeric(10,2),
		primary key(idProducto));

-- Se crean las tablas que para el manejo de los paquetes

create table Paquetes(
		idPaquete	integer unique,
		Clave		varchar(25) primary key,
		Descripcion	text,
		Precio 		numeric(10,2));
	
create table ProductosPaquete(
		idPaquete	integer references Paquetes(idPaquete),
		idProducto	integer references Producto(idProducto),
		Cantidad	numeric(10,2),
		primary key(idPaquete,idProducto));

insert into FormaPago values(1,'Contado',0);
insert into FormaPago values(2,'Credito 15 Dias',15);
insert into FormaPago values(3,'Credito 30 Dias',30);
insert into FormaPago values(4,'Credito 45 Dias',30);
insert into FormaPago values(5,'Credito 60 Dias',60);

insert into Empresas values(0,'Matriz');
insert into Expendios values(0,2645,'127.0.0.1');

insert into Personas values(0,'Publico','General','');
insert into ClientesFisica values(0);
		
