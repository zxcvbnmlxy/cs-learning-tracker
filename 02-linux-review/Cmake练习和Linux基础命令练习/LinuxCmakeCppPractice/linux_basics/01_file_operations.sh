#!/bin/bash
# =============================================
# Linux 基础命令练习 — 文件与目录操作
# =============================================
# 使用方法: bash 01_file_operations.sh
# 建议先阅读每个命令的 man 手册:
#   man ls | man cp | man mv | man rm | man mkdir | man touch

echo "========================================="
echo "  文件与目录操作练习"
echo "========================================="

# ---------- 1. pwd — 显示当前工作目录 ----------
echo ""
echo "[1] pwd — 打印当前工作目录"
echo "    当前目录: $(pwd)"

# ---------- 2. ls — 列出目录内容 ----------
echo ""
echo "[2] ls — 列出文件"
echo "    简洁列表:  $(ls)"
echo "    详细列表:  $(ls -l)"
echo "    含隐藏文件: $(ls -la)"
echo "    按时间排序: $(ls -lt)"

# ---------- 3. mkdir — 创建目录 ----------
echo ""
echo "[3] mkdir — 创建目录"
mkdir -p ./tmp_example/{documents,images,scripts,archive}
echo "    已创建目录树:"
find ./tmp_example -type d | sed 's/^/    /'

# ---------- 4. touch — 创建空文件 / 更新时间戳 ----------
echo ""
echo "[4] touch — 创建空文件"
touch ./tmp_example/documents/readme.txt
touch ./tmp_example/documents/notes.md
touch ./tmp_example/images/logo.png
touch ./tmp_example/scripts/run.sh
echo "    已创建文件:"
find ./tmp_example -type f | sed 's/^/    /'

# ---------- 5. cp — 复制文件/目录 ----------
echo ""
echo "[5] cp — 复制"
cp ./tmp_example/documents/readme.txt ./tmp_example/documents/readme_backup.txt
cp -r ./tmp_example/documents ./tmp_example/archive/   # -r 递归复制目录
echo "    复制完成。archive 目录内容:"
ls -l ./tmp_example/archive/documents/

# ---------- 6. mv — 移动/重命名 ----------
echo ""
echo "[6] mv — 移动与重命名"
mv ./tmp_example/documents/notes.md ./tmp_example/documents/日记.md    # 重命名
mv ./tmp_example/images/logo.png ./tmp_example/archive/                # 移动
echo "    移动/重命名完成。"
echo "    documents 目录: $(ls ./tmp_example/documents)"
echo "    archive 目录:   $(ls ./tmp_example/archive)"

# ---------- 7. rm — 删除 ----------
echo ""
echo "[7] rm — 删除"
rm ./tmp_example/documents/readme_backup.txt
echo "    已删除 readme_backup.txt"
echo "    当前 documents 内容: $(ls ./tmp_example/documents)"

# ---------- 8. tree / find — 查看目录树 ----------
echo ""
echo "[8] find — 查找文件"
echo "    查找所有 .txt 文件:"
find ./tmp_example -name "*.txt" | sed 's/^/    /'
echo "    查找所有目录:"
find ./tmp_example -type d | sed 's/^/    /'

# ---------- 9. du — 查看磁盘使用 ----------
echo ""
echo "[9] du — 磁盘使用量"
du -sh ./tmp_example

# ---------- 清理 ----------
echo ""
echo "========================================="
echo "  清理临时文件"
echo "========================================="
rm -rf ./tmp_example
echo "  已删除 tmp_example"

echo ""
echo "✅ 文件操作练习完成！"
