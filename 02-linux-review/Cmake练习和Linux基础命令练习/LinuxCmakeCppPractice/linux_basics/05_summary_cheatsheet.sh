#!/bin/bash
# =============================================
# Linux 命令速查表 — 分类汇总
# =============================================
# 使用方法: bash 05_summary_cheatsheet.sh
# 显示所有常用命令的分类汇总

echo "=============================================="
echo "  Linux 基础命令速查表"
echo "=============================================="

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  📁 文件与目录操作"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  pwd         # 显示当前路径
  ls [-la]    # 列出文件
  cd <dir>    # 切换目录
  mkdir -p    # 创建目录（含父目录）
  rmdir       # 删除空目录
  rm -rf      # 强制递归删除 ⚠️
  cp [-r]     # 复制（递归）
  mv          # 移动/重命名
  touch       # 创建空文件/更新时间戳
  tree        # 显示目录树
  find . -name "*.cpp"    # 查找文件
  locate <file>           # 快速定位文件
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  👀 文件查看与编辑"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  cat <file>      # 查看全部内容
  less <file>     # 分页查看（↑↓翻页，q退出）
  head -n 5       # 查看前5行
  tail -n 5       # 查看后5行
  tail -f <file>  # 实时跟踪（日志）
  wc -l <file>    # 统计行数
  vim <file>      # Vim编辑器
  nano <file>     # Nano编辑器
  diff f1 f2      # 比较文件差异
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  🔧 文本处理三剑客"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  grep [-ivn] "pattern" file
    # 搜索文本（-i忽略大小写 -v反向 -n显示行号）
  sed 's/old/new/g' file
    # 流式替换（不修改原文件，-i才修改）
  awk '{print $1, $NF}' file
    # 列处理，默认按空格分割
  sort [-n] [-r] [-k2]
    # 排序（-n数字排序 -r逆序 -k指定列）
  uniq [-c]
    # 去重并计数（需先sort）
  cut -d',' -f1,3
    # 按分隔符截取列
  tr 'a-z' 'A-Z'
    # 字符转换
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  🔐 权限与链接"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  chmod 755 <file>      # 数字模式修改权限
  chmod u+x <file>      # 符号模式添加执行权限
  chown user:group file # 修改所有者/组
  umask                 # 查看/设置默认权限掩码
  ln source target      # 硬链接（同一inode）
  ln -s source target   # 软链接（快捷方式）
  stat <file>           # 查看inode等详细信息
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  ⚙️  进程与系统管理"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  ps aux                # 查看所有进程
  top                   # 实时进程监控
  kill -15 <PID>        # 优雅终止
  kill -9  <PID>        # 强制杀死
  jobs                  # 查看后台任务
  bg / fg               # 切换到后台/前台
  nohup cmd &           # 持久后台运行
  watch -n 1 cmd        # 周期性执行
  df -h                 # 磁盘使用情况
  du -sh <dir>          # 目录大小
  free -h               # 内存使用
  uname -a              # 系统信息
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  🔗 管道与重定向"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  cmd1 | cmd2            # 管道：cmd1的输出作为cmd2的输入
  > file                 # 覆盖重定向
  >> file                # 追加重定向
  2>&1                   # 错误重定向到标准输出
  &> file                # 所有输出重定向到文件
  cmd < file             # 从文件读取输入
  tee file               # 同时输出到屏幕和文件
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  📦 压缩与归档"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  tar -czf archive.tar.gz dir/    # 打包压缩
  tar -xzf archive.tar.gz         # 解压
  tar -tf archive.tar.gz          # 查看包内容
  zip -r archive.zip dir/         # ZIP压缩
  unzip archive.zip               # 解压ZIP
  gzip file                       # 压缩文件（.gz）
  gunzip file.gz                  # 解压
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  🌐 网络命令"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  ping <host>           # 网络连通性测试
  curl <url>            # HTTP请求
  wget <url>            # 下载文件
  netstat -tlnp         # 查看端口监听
  ss -tlnp              # 现代版netstat
  ifconfig / ip addr    # 查看网络配置
  ssh user@host         # SSH远程连接
  scp file user@host:/path/  # 远程复制
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  🛠  实用工具"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  man <cmd>     # 查看命令手册（最最重要！）
  which <cmd>   # 查找命令路径
  alias         # 设置别名
  history       # 命令历史
  !!            # 执行上一条命令
  !$            # 上一条命令的最后一个参数
  clear / Ctrl+L   # 清屏
  Ctrl+C        # 中断当前命令
  Ctrl+Z        # 暂停当前命令
  Ctrl+R        # 搜索命令历史
EOF

echo ""
echo "=============================================="
echo "  提示：使用 man <命令名> 查看详细手册"
echo "  例如: man ls  |  man grep  |  man awk"
echo "=============================================="
