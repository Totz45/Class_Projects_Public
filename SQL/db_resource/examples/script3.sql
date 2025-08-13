select i.id, name, count(*)
from instructor as i, teaches as tc
where i.ID = tc.id
group by i.id, name;

select count(*)
from instructor as i, teaches as tc
where i.ID = tc.id;


select course_id, semester, count(*)
from section
group by course_id, semester;



select * from section;

-- -----------------------------------------------
select course_id, count(*)
from section
group by course_id;

select course_id, semester, count(*)
from section
group by course_id, semester;

insert into section values ('CS-101', '1', 'Fall', '2024', 'Packard', '101', 'H');
insert into section values ('CS-101', '2', 'Fall', '2024', 'Packard', '101', 'H');

insert into section values ('CS-101', '1', 'Summer', '2024', 'Packard', '101', 'H');
insert into section values ('CS-101', '2', 'Summer', '2024', 'Packard', '101', 'H');
insert into section values ('CS-101', '3', 'Summer', '2024', 'Packard', '101', 'H');



select * from section where course_id = 'CS-101';
-- -----------------------------------------------
select course_id, count(*)
from section
group by course_id
union
select course_id, 0 
from course where course_id not in (select course_id from section);
-- -----------------------------------------------
select * 
from course where course_id in ( 
select course_id -- , semester, year, count(*)
from section
group by course_id, semester, year
having count(*) >= 2);

select course_id semester, year, count(*)
from section
group by course_id, semester, year
having count(*) >= 2;



select course_id, semester, year, count(*)
from section
group by course_id, semester, year
having count(*)=1;
-- -----------------------------------------------
select * 
from course where course_id in ( 
select course_id -- , semester, year, count(*)
from section
group by course_id, semester, year
having count(*) >= 2);

select * 
from course as c where exists ( 
select course_id -- , semester, year, count(*)
from section as s
where s.course_id = c.course_id
group by course_id, semester, year
having count(*) >= 2);
-- -----------------------------------------------
select s.ID, sum(c.credits)
from student as s, takes as tk, course as c
where s.id = tk.id
and tk.course_id = c.course_id
and tk.grade is not null and grade <> 'F'
group by s.ID;




select s.ID, count(*)
from student as s, takes as tk, course as c
where s.id = tk.id
and tk.course_id = c.course_id
and tk.grade is not null and grade <> 'F'
group by s.ID;

select *
from student as s, takes as tk, course as c
where s.id = tk.id
and tk.course_id = c.course_id;
-- -----------------------------------------------
select * 
from student;

select s.ID, sum(c.credits)
from student as s, takes as tk, course as c
where s.id = tk.id
and tk.course_id = c.course_id
and tk.grade is not null and grade <> 'F'
group by s.ID;