
# 装饰器

# 可迭代和迭代器

# 生成器

# 将输出保存到指定文件但不影响命令行输出

```python
class Logger(object):
    def __init__(self, log_filename):
        self.terminal = sys.stdout
        self.log = open(log_filename, "a", 1)

    def write(self, message):
        self.terminal.write(message)
        self.log.write(message)

    def flush(self):
        # this flush method is needed for python 3 compatibility.
        # this handles the flush command by doing nothing.
        # you might want to specify some extra behavior here.
        pass
sys.stdout() = Logger()
```

新建了一个类 
