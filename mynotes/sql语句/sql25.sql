SELECT device_id, gender, age, gpa
FROM user_profile
WHERE university = '山东大学'
UNION ALL
SELECT device_id, gender, age, gpa
FROM user_profile
WHERE gender = 'male';

`要求 找出山东大学的用户或者男性用户 并且不去重
使用union 或者 or 都会去重 只能用union all
```
