explain select * from student where id = '12345';

explain select * from student where name = 'Snow';

select count(*) from student;

select * from student;



explain select * from student where id = 7;


insert into student values ('7', 'Brown', 'Physics', '0');
insert into student values ('07', 'Green', 'Physics', '0');
-- -----------------------------------------------
select title from course where dept_name = 'Comp. Sci.';


select title from course where course_id like 'CS%';

insert into course values ('3300', 'DBMS', 'Comp. Sci.', '3');

insert into course values ('', 'Game Design', 'Comp. Sci.', '4');

select * from course;



SHOW INDEXES FROM student;




create table student_temp
(ID	varchar(5), 
name varchar(20) not null, 
dept_name varchar(20), 
tot_cred numeric(3,0) check (tot_cred >= 0),
foreign key (dept_name) references department(dept_name) on delete set null
);

SHOW INDEXES FROM student_temp;



insert into student_temp values ('12345', 'Shankar', 'Comp. Sci.', '32');
insert into student_temp values ('19991', 'Brandt', 'History', '80');
insert into student_temp values ('23121', 'Chavez', 'Finance', '110');

explain select * from student_temp where id = '12345';

create index studentID_index on student_temp(ID);


 show engines;
-- -----------------------------------------------
select * from instructor;


insert into instructor values ('724', 
(select dept_name from department 
where budget = (select max(budget) from department))  , 'Finance', 98000);

select dept_name from department 
where budget = (select max(budget) from department);