# awk — 文本分析命令参考

## 基本语法
```bash
awk '{print $1, $2}' 文件名
```
默认按空格/制表符拆分成列。

## 核心概念

```
$1      $2    $3    $4    $5
姓名    语文  数学  英语  城市
张三    85    92    78    北京
```

| 变量 | 含义 |
|------|------|
| `$1` | 第 1 列 |
| `$2` | 第 2 列 |
| `$5` | 第 5 列 |
| `$0` | 整行 |
| `NR` | 当前行号（从 1 开始） |
| `NF` | 当前行的列数 |

## 常用模式

### 1. 打印指定列
```bash
awk '{print $1, $5}' score_data.txt
```

### 2. 条件筛选
```bash
awk '$5 == "北京" {print $1}' score_data.txt
awk '$2 > 90 {print $1, $2}' score_data.txt
```

### 3. 跳过表头 (NR>1)
```bash
awk 'NR>1 && $5 == "北京" {print $1, $2}' score_data.txt
```

### 4. BEGIN / END 块
BEGIN //表头
```bash
awk 'BEGIN {print "=== 开始 ==="} {print $1} END {print "=== 结束 ==="}' score_data.txt
```
BEGIN 在读取文件前执行一次，END 在读完所有行后执行一次。

### 5. 统计求和
```bash
# 计算语文总分
awk '{sum += $2} END {print "总分:", sum}' score_data.txt

# 计算语文平均分
awk 'NR>1 {sum += $2; count++} END {print "平均分:", sum/count}' score_data.txt
```

### 6. 分组统计（数组）
```bash
# 统计每个城市出现次数
awk 'NR>1 {count[$5]++} END {for(c in count) print c, count[c]}' score_data.txt

# 按城市统计语文平均分
awk 'NR>1 {sum[$5] += $2; count[$5]++}
     END {for(c in sum) print c, sum[c]/count[c]}' score_data.txt
```

### 7. 格式化输出（printf）
```bash
awk '{printf "%-10s %-5s\n", $1, $2}' score_data.txt
# %-10s 左对齐宽度10，%-5s 左对齐宽度5
```

## 速查表

| 写法 | 含义 |
|------|------|
| `{print $1}` | 打印第 1 列 |
| `{print $1, $3}` | 打印第 1 和 第 3 列 |
| `NR>1 {print $1}` | 从第 2 行开始打印 |
| `$5=="北京" {print $1}` | 城市=北京时才打印 |
| `$2>90 {print $1}` | 语文>90 才打印 |
| `{sum+=$2} END{print sum}` | 计算第 2 列总和 |
| `{count++} END{print count}` | 统计行数 |
| `{count[$5]++} END{...}` | 按第 5 列分组计数 |
