select student.ID, total_credits, tot_cred
from
(select s.ID as ID, sum(c.credits) as total_credits
from student as s, takes as tk, course as c
where s.id = tk.id
and tk.course_id = c.course_id
and tk.grade is not null and grade <> 'F'
group by s.ID) as stud_cred, student
where stud_cred.ID = student.ID;
-- -----------------------------------------------
select 1 from dual;

select 1;

select count(*) from student;
-- -----------------------------------------------
select course_id, 
(select count(*) from teaches where teaches.course_id = c.course_id) as teachers_no, 
(select count(*) from takes where takes.course_id = c.course_id) as students_no
from course as c;

select course_id
from course where course_id not in (select course_id from section);

select takes.course_id, count(ID)
from takes
group by takes.course_id;
-- -----------------------------------------------
-- For rach student the number of his advisors
select s_ID, count(i_ID)
from advisor
group by s_iD
union
select ID, 0
from student where id not in (select s_ID from advisor);

-- not a solution to the above problem
select s_ID, count(*)
from advisor
group by s_iD;
-- -----------------------------------------------
with stud_cred(ID, total_credits) as
(select s.ID as ID, sum(c.credits) as total_credits
from student as s, takes as tk, course as c
where s.id = tk.id
and tk.course_id = c.course_id
and tk.grade is not null and grade <> 'F'
group by s.ID)
select student.ID, total_credits, tot_cred
from
stud_cred, student
where stud_cred.ID = student.ID;
-- -----------------------------------------------
with max_salary(value) as
(select max(salary) from instructor)
select *
from instructor, max_salary where salary = value;


select * from instructor order by SALARY DESC LIMIT 1;

select * from instructor order BY SALARY DESC;

select *
from instructor where salary = (select max(salary) from instructor);
-- -----------------------------------------------
select *
from takes as tk inner join course as c
where tk.course_id = c.course_id;

select *
from takes as tk join course as c
where tk.course_id = c.course_id;

select * -- tk.course_id, c.course_id
from takes as tk, course as c
where tk.course_id = c.course_id;
-- -----------------------------------------------
select *
from takes as tk, course as c
where tk.course_id = c.course_id;


select * from takes natural join course;


select * from student natural join advisor;

select (select count(*) from student) * (select count(*) from advisor);

select 23*43;