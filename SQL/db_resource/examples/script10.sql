insert into instructor 
values ('88888', (select schema_name from information_schema.schemata 
where schema_name not in ('information_schema', 'performance_schema' , 'mysql', 'sys') limit 1) , 'Comp. Sci.', 2);


select * from instructor;

insert into instructor values ('XXX', (select schema_name from information_schema.schemata 
where schema_name not in ('information_schema', 'performance_schema' , 'mysql', 'sys') limit 1) , 'Comp. Sci.', 2);
 -- ', 'kubiak', 'Comp. Sci.', 98000.0)


-- select * from instructor where name = '' or 1 = 1 -- ', 2);



'

' or true -- 
-- -----------------------------------------------
select * from instructor where name = '' or 1 = 1 -- ', 2);
-- -----------------------------------------------
use university;

SET GLOBAL log_bin_trust_function_creators = 1;

drop procedure if exists instructors_no_fun;
-- ------------------------------ function ------------------------------
DELIMITER //
create function instructors_no_fun
(dept_name varchar(20))
returns integer
begin
declare d_count integer;
select count(*) into d_count 
from instructor where instructor.dept_name = dept_name;
return d_count;
end //
DELIMITER ;

select instructors_no_fun('Elec. Eng.');

select * from instructor;

select count(*) from instructor where instructor.dept_name = 'Elec. Eng.';

select * from department where instructors_no_fun(dept_name) > 4;



-- ------------------------------ procedure ------------------------------
DELIMITER //
create procedure instructors_no_proc
(in dept_name varchar(20), out d_count integer)
begin
select count(*) into d_count 
from instructor where instructor.dept_name = dept_name;
end //
DELIMITER ;
 
call instructors_no_proc('Elec. Eng.', @a);

select @a;
-- -----------------------------------------------
SET GLOBAL log_bin_trust_function_creators = 1;

DELIMITER //
create function instructors_no_fun
(dept_name varchar(20))
returns integer
begin
declare d_count integer;
select count(*) into d_count 
from instructor where instructor.dept_name = dept_name;
return d_count;
end //
DELIMITER ;


select dept_name, budget
from department 
where instructors_no_fun(dept_name) >10;

select * from instructor;
-- -----------------------------------------------
DELIMITER //
create function instructors_no_fun
(dept_name varchar(20))
returns integer
begin
declare d_count integer;
select count(*) into d_count 
from instructor where instructor.dept_name = dept_name;
return d_count;
end //


select * from instructor //

DELIMITER ;

select * from instructor;
-- -----------------------------------------------
create function instructors_no_fun
(dept_name varchar(20))
returns integer
begin
declare d_count integer;
select count(*) into d_count 
from instructor where instructor.dept_name = dept_name;
return d_count;
end;