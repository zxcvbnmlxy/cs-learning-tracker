#!/bin/bash
# =============================================
# Linux 基础命令练习 — 权限与链接
#   chmod, chown, ln (硬链接/软链接), umask
# =============================================
# 使用方法: bash 03_permission_and_links.sh

echo "========================================="
echo "  权限与链接 练习"
echo "========================================="

# ---------- 准备 ----------
mkdir -p ./link_example
cd ./link_example

# ---------- 1. 文件权限基础 ----------
echo ""
echo "========================================="
echo "  1. 文件权限基础"
echo "========================================="

echo "创建测试文件..."
echo "Hello World" > original.txt
echo "ls -l 查看权限:"
ls -l original.txt

echo ""
echo "权限说明:"
echo "  -rw-r--r--  1 user group  size date filename"
echo "  │││││││││"
echo "  │││││││└└ 其他用户权限 (r--) → 可读"
echo "  │││││└└└ 同组用户权限 (r--) → 可读"
echo "  │││└└└└ 文件所有者权限 (rw-) → 可读写"
echo "  │└└└└└└ 文件类型 (- 普通文件, d 目录, l 链接)"

# ---------- 2. chmod — 修改权限 ----------
echo ""
echo "========================================="
echo "  2. chmod — 修改权限"
echo "========================================="

echo "符号模式: u=所有者, g=组, o=其他, a=全部"
chmod u+x original.txt
echo "  chmod u+x original.txt  → 添加执行权限: $(ls -l original.txt)"

chmod g-w original.txt
echo "  chmod g-w original.txt  → 移除组写入:   $(ls -l original.txt)"

chmod a=r original.txt
echo "  chmod a=r original.txt  → 全部只读:     $(ls -l original.txt)"

chmod 644 original.txt
echo "  chmod 644 original.txt  → 数字模式:     $(ls -l original.txt)"
echo "    644 含义: 所有者=6(rw-) 组=4(r--) 其他=4(r--)"
echo "    r=4, w=2, x=1  →  6=4+2 (rw-)  4=4 (r--)  1=1 (--x)"

chmod 755 original.txt
echo "  chmod 755 original.txt  → 数字模式:     $(ls -l original.txt)"

echo ""
echo "常用权限数字:"
echo "  600 (rw-------)  — 仅所有者可读写"
echo "  644 (rw-r--r--)  — 所有者读写，其他人只读"
echo "  755 (rwxr-xr-x)  — 所有者全部，其他人读+执行"
echo "  777 (rwxrwxrwx)  — 全部开放（不安全，慎用）"

# ---------- 3. 默认权限与 umask ----------
echo ""
echo "========================================="
echo "  3. umask — 默认权限掩码"
echo "========================================="

touch newfile.txt
mkdir newdir
echo "  当前 umask: $(umask)"
echo "  新建文件权限: $(ls -l newfile.txt | awk '{print $1}')"
echo "  新建目录权限: $(ls -ld newdir | awk '{print $1}')"
echo ""
echo "  原理解释:"
echo "    文件最大默认: 666 (rw-rw-rw-)"
echo "    目录最大默认: 777 (rwxrwxrwx)"
echo "    umask 022 → 文件: 666-022=644, 目录: 777-022=755"
rm -f newfile.txt newdir

# ---------- 4. ln — 链接 ----------
echo ""
echo "========================================="
echo "  4. ln — 链接 (硬链接 vs 软链接)"
echo "========================================="

# 准备文件
echo "链接练习数据" > source.txt

# 硬链接
ln source.txt hardlink.txt
echo "创建硬链接: ln source.txt hardlink.txt"
ls -l source.txt hardlink.txt
echo "  inode 相同: $(stat -c "%i" source.txt) == $(stat -c "%i" hardlink.txt)"
echo "  链接计数: $(stat -c "%h" source.txt)"

# 软链接
ln -s source.txt softlink.txt
echo ""
echo "创建软链接: ln -s source.txt softlink.txt"
ls -l source.txt softlink.txt
echo "  软链接文件大小很小，只是指向源文件的路径"

# 区别演示
echo ""
echo "删除源文件后的区别:"
rm source.txt
echo "  删除 source.txt 后..."
echo "  硬链接内容: $(cat hardlink.txt 2>/dev/null || echo '❌ 丢失')"
echo "  软链接状态: $(ls -l softlink.txt 2>/dev/null | awk '{print $NF}') → 漂移(dangling)"

# 清理
cd ..
rm -rf ./link_example

echo ""
echo "✅ 权限与链接练习完成！"
