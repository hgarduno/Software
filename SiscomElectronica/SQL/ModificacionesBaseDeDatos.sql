

-- Se agrego el campo idExpendio, para poder hacer 
-- referencias a los usuarios que se registraran 
-- en cada expendio 

ALTER TABLE firmas add column idexpendio integer;
alter table CuentasPorPagar add column idExpendio integer references Empresas(idEmpresa);
alter table CuentasPorPagar add column Empleado integer;
alter table CuentasPorPagar add column FechaRegistro timestamp without time zone;
alter table CuentasPorPagar add column IdProveedor integer;
alter table CuentasPorPagar add constraint num_factura_key primary key(NumFactura,FechaPago,IdProveedor);

alter table Personas add column Departamento varchar(30);
alter table Telefonos add column Departamenteo varchar(30);

alter table empresas drop constraint empresas_pkey;
alter table empresas add constraint razon_social_key primary key(razonSocial);

alter table compras add column PrecioSinIva numeric(7,2);



alter table tipospersona drop constraint tipospersona_pkey;
alter table existencias add column eximinima numeric(7,2);



------------ Modificacion para la base de datos de seguridad 3


alter table firmas add column edofirma integer ;



------- Modificacion 02-02-2008

-- Agregar el campo edoventa en la tabla de ventas.
-- En este punto, no se porque no habia consideraro
-- realizar esta modificacion en la base de datos
-- Apartir de este momendo deberemos realizar esta actualizacion



alter table Ventas add edoventa integer;
