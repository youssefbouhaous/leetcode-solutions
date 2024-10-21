# Write your MySQL query statement below
select distinct visits.customer_id,count(*) as count_no_trans from visits left join 
Transactions on Transactions.visit_id= visits.visit_id where transaction_id is null GROUP BY visits.customer_id;