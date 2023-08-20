SELECT
    CASE
        WHEN age >= 25 THEN '25岁及以上'
        ELSE '25岁以下'
    END AS age_cut,
    COUNT(id) AS number
FROM user_profile
GROUP BY age_cut;

`要求 统计每个年龄段的用户数量 年龄段是 25岁及以上 25岁以下（空也视为25以下）
```
