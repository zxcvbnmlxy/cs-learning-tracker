# sed — 流编辑器命令参考

## 基本语法
```bash
sed [选项] '命令' 文件名
```

## 常用操作

### 1. s — 替换
```bash
# 替换第一个匹配
sed 's/北京/Beijing/' score_data.txt

# 替换全部匹配（g = global）
sed 's/北京/Beijing/g' score_data.txt

# 替换第2个匹配
sed 's/北京/Beijing/2' score_data.txt

# 只替换第3-5行
sed '3,5s/北京/Beijing/g' score_data.txt
```

### 2. p — 打印
```bash
# 打印第 3 行
sed -n '3p' score_data.txt

# 打印第 3-6 行
sed -n '3,6p' score_data.txt

# 打印匹配"北京"的行
sed -n '/北京/p' score_data.txt
```
> `-n` 是关闭默认输出，只打印 p 指定的行

### 3. d — 删除
```bash
# 删除第 2 行
sed '2d' score_data.txt

# 删除第 3-5 行
sed '3,5d' score_data.txt

# 删除包含"北京"的行
sed '/北京/d' score_data.txt

# 删除空行
sed '/^$/d' score_data.txt
```

### 4. a / i — 追加 / 插入
```bash
# 在第 3 行后面追加一行
sed '3a\这是新行' score_data.txt

# 在第 3 行前面插入一行
sed '3i\这是新行' score_data.txt
```

### 5. -i — 直接修改文件（谨慎！）
```bash
# 直接修改原文件（备份为 .bak）
sed -i.bak 's/北京/Beijing/g' score_data.txt

# 直接修改（不备份）
sed -i 's/北京/Beijing/g' score_data.txt
```

## 速查表

| 命令 | 含义 |
|------|------|
| `sed 's/旧/新/g'` | 替换全部 |
| `sed -n '3p'` | 打印第 3 行 |
| `sed -n '3,6p'` | 打印第 3-6 行 |
| `sed '3,5d'` | 删除第 3-5 行 |
| `sed '/北京/d'` | 删除含"北京"的行 |
| `sed '/北京/p'` | 打印含"北京"的行 |
| `sed -i 's/旧/新/g' file` | 直接修改文件 |
