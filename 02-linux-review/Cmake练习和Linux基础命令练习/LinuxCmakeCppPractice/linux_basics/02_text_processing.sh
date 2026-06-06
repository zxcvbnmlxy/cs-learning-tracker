#!/bin/bash
# =============================================
# Linux 基础命令练习 — 文本处理三剑客
#   grep   — 搜索文本
#   sed    — 流编辑
#   awk    — 文本分析
# =============================================
# 使用方法: bash 02_text_processing.sh

echo "========================================="
echo "  文本处理三剑客 练习"
echo "========================================="

# ---------- 准备示例数据 ----------
echo ""
echo ">>> 准备示例数据..."
cat > ./sample.txt << 'EOF'
Alice   25   Engineer    Beijing
Bob     30   Designer    Shanghai
Charlie 22   Student     Guangzhou
Diana   28   Engineer    Shenzhen
Eve     35   Manager     Beijing
Frank   26   Designer    Shanghai
Grace   23   Student     Beijing
EOF

cat ./sample.txt
echo ""

# ============= grep =============
echo "========================================="
echo "  grep — 文本搜索"
echo "========================================="

echo "[grep 1] 基本搜索 — 查找包含 Engineer 的行:"
grep "Engineer" sample.txt

echo ""
echo "[grep 2] -i 忽略大小写:"
grep -i "engineer" sample.txt

echo ""
echo "[grep 3] -v 反向匹配 (不含 Engineer 的行):"
grep -v "Engineer" sample.txt

echo ""
echo "[grep 4] -c 计数:"
echo "    包含 Beijing 的行数: $(grep -c "Beijing" sample.txt)"
echo "    总行数: $(wc -l < sample.txt)"

echo ""
echo "[grep 5] -n 显示行号:"
grep -n "Shanghai" sample.txt

echo ""
echo "[grep 6] 正则表达式: 查找名字以 C 开头或年龄大于 30 的行"
grep -E "^C|3[1-9]" sample.txt

# ============= sed =============
echo ""
echo "========================================="
echo "  sed — 流编辑器 (不修改原文件)"
echo "========================================="

echo "[sed 1] p — 打印特定行（第 3 行）:"
sed -n '3p' sample.txt

echo ""
echo "[sed 2] d — 删除第 2 行:"
sed '2d' sample.txt

echo ""
echo "[sed 3] s — 替换文本 (Beijing → 北京):"
sed 's/Beijing/北京/g' sample.txt

echo ""
echo "[sed 4] 行范围替换 (1-3行的 Engineer 替换为 工程师):"
sed '1,3s/Engineer/工程师/g' sample.txt

echo ""
echo "[sed 5] -i 直接修改文件（谨慎！本例备份）:"
cp sample.txt sample.txt.bak
sed -i 's/Shanghai/上海/g' sample.txt
echo "    修改后的文件:"
cat sample.txt
mv sample.txt.bak sample.txt  # 恢复

# ============= awk =============
echo ""
echo "========================================="
echo "  awk — 文本分析与格式化输出"
echo "========================================="

echo "[awk 1] 打印第 1 列和第 3 列（默认空格分隔）:"
awk '{print $1, $3}' sample.txt

echo ""
echo "[awk 2] 格式化输出 (printf):"
awk '{printf "%-10s %-10s %-10s\n", $1, $2, $3}' sample.txt

echo ""
echo "[awk 3] BEGIN/END 块:"
awk 'BEGIN {print "=== 人员列表 ==="; print "----------------"}
     {print NR": "$1" - "$4}
     END {print "----------------"; print "共 "NR" 人"}' sample.txt

echo ""
echo "[awk 4] 条件过滤 — 年龄大于 27 的:"
awk '$2 > 27 {print $1, $2, $4}' sample.txt

echo ""
echo "[awk 5] 统计功能 — 按城市分组计数:"
awk '{count[$4]++} END {for (city in count) print city, count[city]"人"}' sample.txt

echo ""
echo "[awk 6] 统计平均年龄:"
awk '{sum += $2} END {print "平均年龄:", sum/NR}' sample.txt

# ---------- 清理 ----------
rm -f ./sample.txt
echo ""
echo "✅ 文本处理练习完成！"
