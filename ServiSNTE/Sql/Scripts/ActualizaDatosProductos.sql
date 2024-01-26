
update productos set nombreproducto=replace(substring(nombreproducto from 1 for strpos(UPPER(nombreproducto), 'BAJA')-1), '@','') where nombreproducto ilike '%baja%';
update productos set nombreproducto=replace(substring(nombreproducto from 1 for strpos(UPPER(nombreproducto),'DESC')-1),'@','') where nombreproducto ilike '%desc%';
update productos set modelo=replace(substring(modelo from 1 for strpos(UPPER(modelo),'BAJA')-1),'@','') where modelo ilike '%baja%';
update productos set modelo=replace(substring(modelo from 1 for strpos(UPPER(modelo),'DESC')-1),'@','') where modelo ilike '%desc%';
update productos set nombreproducto=replace(nombreproducto,'@','') where nombreproducto ilike '%@%';
update productos set modelo=replace(modelo,'@','') where modelo ilike '%@%';
