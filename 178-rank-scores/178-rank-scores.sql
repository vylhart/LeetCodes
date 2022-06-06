# Write your MySQL query statement below
SELECT score, 
(SELECT  COUNT(DISTINCT score)+1 FROM Scores WHERE score > s.score) 'Rank'
FROM Scores s
ORDER BY score DESC