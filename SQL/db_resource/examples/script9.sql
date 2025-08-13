select * from department;

select * from instructor;

insert into instructor 
values ('222', ''+(select schema_name from information_schema.schemata 
where schema_name not in ('information_schema', 'performance_schema' , 'mysql', 'sys') limit 1) + '', 'Comp. Sci.', 2);

show schemas;

select schema_name from information_schema.schemata where schema_name not in ('information_schema', 'performance_schema' , 'mysql', 'sys') limit 1;


select ''+(select schema_name from information_schema.schemata 
where schema_name not in ('information_schema', 'performance_schema' , 'mysql', 'sys') limit 1);

select ''+'Green';
-- -----------------------------------------------
create database chameleon;


select * from brand;

select * from product;

select * from product_type;

select * from packaging;


delete from product where id = 1;
delete from product_type where id = 1;
delete from brand where id = 1;
