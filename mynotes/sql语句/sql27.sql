SELECT
    device_id,
    gender,
    CASE
        WHEN age >= 25 THEN '25岁及以上'
        WHEN age >= 20 THEN '20-24岁'
        WHEN age < 20 THEN '20岁以下'
        ELSE '其他'
    END AS age_cut
FROM user_profile;

`要求 将用户按照年龄分组 分组规则是 20岁以下 20-24岁 25岁及以上 其他
使用 case when then end 语句`
```
