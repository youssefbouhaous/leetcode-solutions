-- Write your PostgreSQL query statement below
WITH D AS (
    SELECT * FROM RequestAccepted
)
,DD AS (
SELECT requester_id AS ID FROM D
UNION ALL SELECT accepter_id AS ID FROM D
)
SELECT ID,COUNT(*) AS NUM FROM DD GROUP BY ID ORDER BY NUM DESC LIMIT 1;