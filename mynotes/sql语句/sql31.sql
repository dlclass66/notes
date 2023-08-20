SELECT device_id, substr(blog_url, 11) AS user_name
FROM user_submit;

```#要求 找到所有用户的用户名（在url中是固定的后缀）
```
substring_index(blog_url, '/', -1) AS user_name  # substring_index()函数的使用 切割 正数从左往右数 负数从右往左数
