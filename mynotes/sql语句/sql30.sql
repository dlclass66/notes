SELECT
    substring_index(profile, ',', -1) AS gender,
    COUNT(device_id) AS number
FROM user_submit
GROUP BY gender;
`要求 统计每个性别的用户数量 性别是在profile字段中的最后一个逗号后面的数字`
