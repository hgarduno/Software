ALTER TABLE empresas add column RFC varchar(25);
---alter table telefonos drop telefono;
---alter table telefonos add column telefono varchar(100);

create table Contactos(idPersona integer,
		       idEmpresa integer );

alter table compras drop column idPersona;
alter table compras drop column idEmpresa;


alter table compras add column Proveedor integer;
alter table compras add column ConProveedor integer;
alter table compras add column Respondable integer ;
alter table compras add column idExpendio integer;
alter table compras add column FormaPago varchar(25);
alter table compras add column NumFactura varchar(50);
alter table compras add column Precio numeric(10,2);


create table CuentasPorPagar(
				NumFactura varchar(50),
				FechaPago timestamp without time zone
			     );
insert into TiposPersona values(2,'Contactos Empresa','Contactos Empresa');

alter table existencias add column idExpendio integer;

alter table cuentasporpagar add column importe numeric(10,2);
alter table existencias add constraint  ss_d unique(CveProducto,idExpendio);
alter table estadodelpedido add constraint  Pedido unique(NumPedido,idedopedido);

create table Matriz(idEmpresa integer references Empresas(idEmpresa) primary key);
		   
alter table pedidos add column FormaDePago varchar(50);
alter table pedidos add column idPersonaRevisoChofer integer ;


 ALTER TABLE personas drop constraint personas_pkey;
  ALTER TABLE personas add constraint personas_pkey unique(nombre,apaterno,amaterno,tipopersona);

create table CuentasPorCobrar(NumPedido integer primary key,
			      Fecha timestamp without time zone,
			      Importe numeric(10,2));

alter table pedidos add column ContactoCliente varchar(125);
ALTER table apodos add constraint no_rep primary key(idPersona);

create table CorteExistencia(
                        CveProducto varchar(25) references productos(CveProducto),
			                        FechaHoraCorte timestamp without time zone,
						                        Existencia numeric(7,2)
									                        );
