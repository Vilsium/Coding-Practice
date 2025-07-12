-- Leetcode question 180

-- Table: Logs

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | num         | varchar |
-- +-------------+---------+
-- In SQL, id is the primary key for this table.
-- id is an autoincrement column starting from 1.
 

-- Find all numbers that appear at least three times consecutively.

-- Return the result table in any order.

# Write your MySQL query statement below
SELECT
    DISTINCT L1.num AS ConsecutiveNums
FROM
    Logs L1,
    Logs L2,
    Logs L3
WHERE
    L1.num = L2.num AND
    L2.num = L3.num AND
    L1.id = L2.id - 1 AND
    L2.id = L3.id - 1;