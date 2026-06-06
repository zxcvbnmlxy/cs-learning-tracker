# grep — 文本搜索命令参考

## 基本语法
```bash
grep [选项] "搜索内容" 文件名
```

## 常用选项

| 选项 | 作用 | 示例 |
|------|------|------|
| (无) | 显示匹配的行 | `grep "北京" file.txt` |
| `-i` | 忽略大小写 | `grep -i "hello" file.txt` |
| `-v` | 反向匹配（不包含的） | `grep -v "北京" file.txt` |
| `-n` | 显示行号 | `grep -n "北京" file.txt` |
| `-c` | 只计数，不显示内容 | `grep -c "北京" file.txt` |
| `-r` | 递归搜索目录 | `grep -r "main" ./src/` |
| `-w` | 精确匹配整个单词 | `grep -w "the" file.txt` |
| `-E` | 扩展正则表达式 | `grep -E "北京\|上海" file.txt` |
| `-l` | 只显示匹配的文件名 | `grep -l "main" *.cpp` |

## 组合用法

```bash
# 搜索并显示行号
grep -n "北京" score_data.txt

# 统计匹配行数
grep -c "北京" score_data.txt

# 跳过表头 + 搜索（用 tail 跳过第一行）
tail -n +2 score_data.txt | grep "北京"

# 多文件搜索
grep "main" *.cpp

# 递归搜索目录
grep -r "TODO" ./src/

# 结合管道
ps aux | grep "bash"
history | grep "git"
ls -la | grep "\.txt"
```
