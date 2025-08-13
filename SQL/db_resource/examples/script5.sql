select c.course_id, title, s.sec_id, s.semester, s.year, id, capacity
from takes as tk, course as c, section as s, classroom as cl
where tk.course_id = c.course_id
and s.course_id = tk.course_id
and s.sec_id = tk.sec_id
and cl.building = s.building
and s.semester = tk.semester
and s.year = tk.year
and s.room_number = cl.room_number;

select course_id, title, sec_id, semester, year, id, capacity
from course natural join takes natural join section natural join classroom;
-- -----------------------------------------------
select *
from takes as tk, course as c, section as s, classroom as cl, student as st
where tk.course_id = c.course_id
and s.course_id = tk.course_id
and s.sec_id = tk.sec_id
and cl.building = s.building
and s.semester = tk.semester
and s.year = tk.year
and s.room_number = cl.room_number
and st.ID = tk.ID;


select *
from course natural join takes natural join section natural join classroom natural join student;
-- -----------------------------------------------
select *
from (select * from student natural join takes) as st, (select * from teaches natural join instructor) as it
where st.course_id = it.course_id
and st.sec_id = it.sec_id
and st.semester = it.semester
and st.year = it.year;

select *
from student natural join takes, teaches natural join instructor
where takes.course_id = teaches.course_id
and takes.sec_id = teaches.sec_id
and takes.semester = teaches.semester
and takes.year = teaches.year;
-- -----------------------------------------------
select *
from student join takes using (ID);

select *
from student join takes on (student.ID = takes.ID);


select *
from student join advisor using (ID);

select *
from student join advisor on (student.ID = advisor.s_ID);
-- -----------------------------------------------
select *
from student natural join takes;

select *
from student natural left outer join takes
where course_id is null;


select * from student where id not in (select id from takes);
-- -----------------------------------------------
select ID, count(course_id)
from student natural left outer join takes
group by ID;

select ID, count(*)
from student natural left outer join takes
group by ID;

(select s.ID, count(*)
from student as s, takes as t
where s.id = t.id
group by s.ID)
union
(select ID, 0
from student where id not in (select id from takes));
-- -----------------------------------------------
select * from takes join teaches using (course_id, sec_id, semester, year);