ALTER table ventas drop constraint ventas_idexpendio_fkey;
ALTER table matriz drop constraint matriz_idempresa_fkey;
ALTER table empresas drop constraint empresas_pkey;

ALTER TABLE empresas add constraint empresa_pkey unique(razonsocial,rfc);
