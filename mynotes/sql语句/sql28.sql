SELECT day(date) AS day, COUNT(question_id) AS question_cnt
FROM question_practice_detail
WHERE year(date) = '2021' AND month(date) = '08'
GROUP BY day;
`要求 输出2021年8月每天的用户做题数量`
