-- Buildings at the University.
select building from department
union 
select building from classroom
union
select building from section;

select building from department
union 
select building from classroom;
-- ---------------------------------------------------------------------------------
select * from instructor;

select *
from instructor as T, instructor as S;


select T.salary
from instructor as T, instructor as S
where T.salary < S.salary;

insert into instructor values ('10101', 'Srinivasan', null, '65000');
insert into department values ('Finance', 'Painter', '120000');
insert into instructor values ('12121', 'Wu', 'Finance', '90000');
-- ---------------------------------------------------------------------------------
select * from course;
insert into course values ('BIO-101', 'Intro. to Biology', null, '4');

select * from prereq;

insert into prereq values ('BIO-101','BIO-101');
-- ---------------------------------------------------------------------------------
create table prereq
(course_id		varchar(8), 
prereq_id		varchar(8),
primary key (course_id),
foreign key (course_id) references course(course_id) on delete cascade,
foreign key (prereq_id) references course(course_id)
);

insert into prereq values ('3300','2700');
insert into prereq values ('3300','2400');

create table prereq
(course_id		varchar(8), 
prereq_id		varchar(8) not null,
primary key (course_id, prereq_id),
foreign key (course_id) references course(course_id) on delete cascade,
foreign key (prereq_id) references course(course_id)
);

insert into prereq values ('3300','2700');
insert into prereq values ('3300','2400');
-- ---------------------------------------------------------------------------------
select s_id from advisor where i_id is not null;

select s_id from advisor;



select * from advisor;

insert into advisor values ('19991', null);

select * from student where id not in (select s_id from advisor);


select * from advisor;
-- ---------------------------------------------------------------------------------
select (select 5 < null) is unknown;