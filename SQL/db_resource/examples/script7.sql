create table BOOK 
(title varchar(100) not null,  -- book title
genre_id numeric(2,0), -- id of the book genre
ISBN varchar(20), -- ISBN of a book
date_published date,  -- date the book was published
publisher varchar(40), -- name of the publisher
edition numeric(2,0), -- edition number
description varchar(300), -- concise description of the book 
primary key (ISBN),
unique(title),
foreign key (genre_id) references GENRE(genre_id) 
);
-- -----------------------------------------------
delete from course;

delete from course where course_id = 'BIO-101';
delete from course where course_id = 'CS-101';
delete from course where course_id = 'PHY-101';

select * from section where course_id = 'CS-101';
select * from takes where course_id = 'CS-101';
select * from teaches where course_id = 'CS-101';

SET SQL_SAFE_UPDATES = 0;

select distinct prereq_id from prereq;

delete from prereq where prereq_id = 'CS-101';
