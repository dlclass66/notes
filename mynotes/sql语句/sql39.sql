SELECT COUNT(DISTINCT device_id) AS did_cnt,
COUNT(id) AS question_cnt
FROM question_practice_detail
WHERE year(date) = '2021' AND month(date) = '08';

`#题目要求 统计2021年8月份的做题人数和做题数量
注意时间函数的使用 以及去重的方法
