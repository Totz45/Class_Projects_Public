select i.id as i_id, i.name as i_name, s.id as s_id, s.name as s_name
from instructor as i, student as s, advisor as a
where i.id = a.i_ID and s.id = a.s_id;


select *
from instructor as i, student as s, advisor as a
where i.id = a.i_ID and s.id = a.s_id;


select *
from instructor as i, student as s, advisor as a
where i.id = a.i_ID and s.id = a.s_id and i.dept_name = s.dept_name;

insert into advisor values ('Hola', '22222');

insert into advisor values ('007', null);

select * from advisor;
-- ---------------------------------------------------------------------------------
create table emp
(
person varchar(10),
sup varchar(10)
);

insert into emp values ('Bob', 'Alice');
insert into emp values ('Mary', 'Susan');
insert into emp values ('Alice', 'David');
insert into emp values ('David', 'Mary');

select sup from emp where person = 'Bob';

select e2.sup
from emp as e1, emp as e2
where e1.sup = e2.person
and e1.person = 'Bob';

select e3.sup
from emp as e1, emp as e2, emp as e3
where e1.sup = e2.person
and e1.person = 'Bob' and e2.sup = e3.person;
-- ---------------------------------------------------------------------------------
use university;

select id, name, dept_name, tot_cred from student where name = 'Brown';

insert into student values ('7', 'Brown', 'Comp. Sci.', '58');

insert into student values ('Hola', 'Brown', 'Comp. Sci.', '58');

select id, name, dept_name, tot_cred from student where id = '7';


insert into student values ('007', 'Brown', 'Comp. Sci.', '58');
-- ---------------------------------------------------------------------------------
select building from department
union 
select building from classroom
union
select building from section;
-- ---------------------------------------------------------------------------------
insert into instructor values ('null', 'Crick', 'Biology', '72000');
