create view faculty as 
select ID, name, dept_name
from instructor;


select * from faculty;

select * from (select ID, name, dept_name
from instructor) as temp;


CREATE USER 'brown'@'localhost' IDENTIFIED BY 'db123';

GRANT SELECT ON university.history_instructors TO 'brown'@'localhost';
GRANT INSERT ON university.history_instructors TO 'brown'@'localhost';
GRANT UPDATE ON university.faculty TO 'brown'@'localhost';

insert into instructor values ('12', 'Kubiak', 'Elec. Eng.', '80000');


select * from instructor;
-- -----------------------------------------------
create view history_instructors as 
select *
from instructor
where dept_name='History';

insert into history_instructors values ('3', 'Adams', 'Biology', 100000);

select * from history_instructors;
-- -----------------------------------------------
create view better_history_instructors as 
select *
from instructor
where dept_name='History'
WITH CHECK OPTION;

insert into better_history_instructors values ('15', 'Cyanide', 'Biology', 100000);
-- -----------------------------------------------
select @@autocommit; -- FROM DUAL;

set autocommit = 0;


insert into instructor values ('18', 'XXXXXXX', 'Comp. Sci.',10000); 

select * from instructor;

commit;

SELECT @@GLOBAL.transaction_isolation, @@GLOBAL.transaction_read_only;
SELECT @@SESSION.transaction_isolation, @@SESSION.transaction_read_only;
-- -----------------------------------------------
update department set budget = budget - 1000 where dept_name = 'Comp. Sci.';
update instructor set salary = salary + 1000 where name = 'Kubiak';



update department as d, instructor as i
set d.budget = d.budget - 1000,
    i.salary = i.salary + 1000
Where d.dept_name = 'Comp. Sci.' and i.name = 'Kubiak';
