#!/bin/bash
# =============================================
# Linux 基础命令练习 — 进程与系统管理
#   ps, top, kill, jobs, bg, fg, nohup, watch
# =============================================
# 使用方法: bash 04_process_management.sh

echo "========================================="
echo "  进程与系统管理 练习"
echo "========================================="

# ---------- 1. ps — 查看进程 ----------
echo ""
echo "========================================="
echo "  1. ps — 进程快照"
echo "========================================="

echo "[ps 1] 当前终端进程:"
ps

echo ""
echo "[ps 2] 所有进程 (BSD风格):"
ps aux  | head -15

echo ""
echo "[ps 3] 所有进程 (标准风格):"
ps -ef | head -15

echo ""
echo "[ps 4] 树状结构:"
ps auxf | head -20

echo ""
echo "[ps 5] 搜索特定进程 (如 bash):"
ps aux | grep bash | grep -v grep

echo ""
echo "[ps 6] 自定义输出列:"
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head -10

# ---------- 2. top/htop — 实时监控 ----------
echo ""
echo "========================================="
echo "  2. top — 实时进程监控 (非交互演示)"
echo "========================================="

echo "top 命令说明:"
echo "  top      — 实时进程监控 (按 q 退出)"
echo "    快捷键: P=按CPU排序, M=按内存排序, k=杀死进程, u=查看用户"
echo "    输出字段: PID USER PR NI VIRT RES SHR S %CPU %MEM TIME+ COMMAND"
echo ""
echo "  单次快照 (batch模式):"
top -bn1 | head -20

# ---------- 3. kill — 终止进程 ----------
echo ""
echo "========================================="
echo "  3. kill — 发送信号"
echo "========================================="

echo "常见信号:"
echo "  SIGTERM (15) — 终止 (默认，优雅退出)"
echo "  SIGKILL (9)  — 强制杀死"
echo "  SIGHUP  (1)  — 挂起/重载配置"
echo "  SIGSTOP (19) — 暂停进程"
echo "  SIGCONT (18) — 继续暂停的进程"
echo ""
echo "用法示例:"
echo "  kill -15 <PID>     # 优雅终止"
echo "  kill -9  <PID>     # 强制终止"
echo "  killall -15 <name> # 按名称杀进程"

# ---------- 4. 前后台任务 ----------
echo ""
echo "========================================="
echo "  4. jobs / bg / fg — 前后台任务控制"
echo "========================================="

echo "创建临时脚本..."
cat > sleep_demo.sh << 'EOF'
#!/bin/bash
for i in 1 2 3; do
    echo "后台任务 - 第 ${i} 秒"
    sleep 1
done
EOF
chmod +x sleep_demo.sh

echo ""
echo "后台运行: ./sleep_demo.sh &"
./sleep_demo.sh &
JOB_PID=$!
echo "  任务 PID = $JOB_PID"

echo ""
echo "查看后台任务: jobs"
jobs

echo ""
echo "等待后台任务完成..."
wait $JOB_PID
echo "  后台任务完成！"

rm -f sleep_demo.sh

# ---------- 5. nohup — 后台持久运行 ----------
echo ""
echo "========================================="
echo "  5. nohup — 退出终端后继续运行"
echo "========================================="

echo "nohup 用法:"
echo "  nohup ./long_running.sh &"
echo "  nohup 的输出写入 nohup.out 文件"
echo "  即使关闭终端，进程仍然运行"

# ---------- 6. 系统信息命令 ----------
echo ""
echo "========================================="
echo "  6. 系统信息命令"
echo "========================================="

echo "  uname -a    : $(uname -a)"
echo "  whoami      : $(whoami)"
echo "  hostname    : $(hostname)"
echo "  date        : $(date)"
echo "  uptime      : $(uptime)"
echo "  磁盘使用 df -h :"
df -h | head -5
echo ""
echo "  内存使用 free -h : $(free -h | grep Mem)"

# ---------- 7. watch — 周期性执行 ----------
echo ""
echo "========================================="
echo "  7. watch — 周期性执行命令"
echo "========================================="

echo "watch 用法:"
echo "  watch -n 1 'date'              # 每秒显示时间"
echo "  watch -n 5 'ls -l'             # 每5秒查看文件变化"
echo "  watch -d 'ps aux | wc -l'      # 高亮变化 (进程数变化)"

# ---------- 8. 管道与重定向 ----------
echo ""
echo "========================================="
echo "  8. 管道 | 与重定向 > >> < 2>&1"
echo "========================================="

echo "管道示例:"
echo "  command1 | command2        # 将命令1的输出传给命令2"
echo "  ls -la | grep '.txt' | wc -l"

echo ""
echo "重定向示例:"
echo "  echo 'hello' > file.txt    # 覆盖写入"
echo "  echo 'world' >> file.txt   # 追加写入"
echo "  cat < file.txt              # 从文件读取输入"
echo "  cmd 2>&1                    # 将stderr合并到stdout"
echo "  cmd &> file.txt             # 将stdout和stderr都写入文件"

echo ""
echo "综合管道练习:"
echo "  统计 /usr/bin 下可执行文件数量: $(ls /usr/bin 2>/dev/null | wc -l)"
echo ""
echo "  管道链示例:"
echo "    ps aux | grep bash | grep -v grep | awk '{print $2}' | head -5"

echo ""
echo "✅ 进程与系统管理练习完成！"
