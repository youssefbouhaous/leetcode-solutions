# Write your MySQL query statement below
select DISTINCT author_id as id from views where author_id=viewer_id ORDER BY author_id;