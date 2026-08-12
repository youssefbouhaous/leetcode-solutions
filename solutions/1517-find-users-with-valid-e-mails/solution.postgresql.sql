-- Write your PostgreSQL query statement below
SELECT * FROM USERS 
WHERE MAIL ~ '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\.com$';