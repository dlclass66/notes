SELECT
    substring_index(substring_index(profile, ',', -2), ',', 1) AS age,
    COUNT(device_id) AS number
FROM user_submit
GROUP BY age
```#要求 统计每个年龄段的用户数量 年龄是在profile字段中的第二个逗号后面的数字


