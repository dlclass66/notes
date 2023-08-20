SELECT device_id, university, gpa
FROM (SELECT device_id, university, gpa,
        RANK() OVER (PARTITION BY university ORDER BY gpa) as r
        FROM user_profile) as up
WHERE r = 1
order by university;

`#要求 按照学校分组，找到每个学校gpa最低的学生
#使用窗口函数创建一个新表，然后筛选出gpa最低的学生
