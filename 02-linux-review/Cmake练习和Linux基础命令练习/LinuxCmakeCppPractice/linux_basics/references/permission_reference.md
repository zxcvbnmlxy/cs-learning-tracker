# chmod — 权限管理命令参考

## 权限字符串解读

```
-rw-r--r-- 1 lixianyu 197610 321 Jun 6 18:06 score_data.txt
↑↑↑↑↑↑↑↑↑↑
││││││││││
│││││││││└ 第9位: 其他人-执行 (x/-)
││││││││└─ 第8位: 其他人-写   (w/-)
│││││││└── 第7位: 其他人-读   (r/-)
││││││└─── 第6位: 同组-执行   (x/-)
│││││└──── 第5位: 同组-写     (w/-)
││││└───── 第4位: 同组-读     (r/-)
│││└────── 第3位: 所有者-执行 (x/-)
││└─────── 第2位: 所有者-写   (w/-)
│└──────── 第1位: 所有者-读   (r/-)
└───────── 第0位: **文件类型** (-=文件, d=目录, l=链接)
```

### rwx 含义

| 字母 | 含义 | 数字值 |
|------|------|--------|
| `r`  | 读取 | 4 |
| `w`  | 写入 | 2 |
| `x`  | 执行 | 1 |
| `-`  | 无权限 | 0 |

### 常见权限值

| 数字 | 权限 | 说明 |
|------|------|------|
| `644` | `rw-r--r--` | 文件默认，所有者可读写，其他人只读 |
| `755` | `rwxr-xr-x` | 可执行文件/目录，所有人可执行 |
| `700` | `rwx------` | 仅所有者可读写执行 |
| `600` | `rw-------` | 仅所有者可读写（如 SSH 密钥） |

## 修改权限 — chmod

### 数字模式
```bash
chmod 755 script.sh   # rwxr-xr-x
chmod 644 file.txt    # rw-r--r--
chmod 600 id_rsa      # rw-------  （SSH 私钥必须 600）
```

### 字母模式
```bash
chmod +x script.sh      # 所有用户加执行权限
chmod u+x script.sh     # 仅所有者加执行权限
chmod a+x script.sh     # 所有人加执行权限 (a=all)
chmod g-w file.txt      # 同组去掉写权限
chmod o=r file.txt      # 其他人设为只读
```

### 常用场景
```bash
# 新写的脚本无法运行
chmod +x myscript.sh

# 下载的私钥权限太开放，SSH 报错
chmod 600 ~/.ssh/id_rsa

# 整个目录开放访问
chmod -R 755 my_folder/
```

## 修改所有者 — chown

```bash
chown user:group file.txt   # 修改所有者和组
chown user file.txt         # 仅修改所有者
chown :group file.txt       # 仅修改组
chown -R user:group dir/    # 递归修改
```

> ⚠️ `chown` 通常需要 `sudo`

## 链接 — ln

### 硬链接
```bash
ln target.txt link.txt      # 创建硬链接
```
- 两个文件名指向**同一个 inode**（同一份数据）
- 删除原文件不影响硬链接
- **不能跨文件系统**，**不能链接目录**

### 软链接（符号链接）
```bash
ln -s target.txt symlink.txt   # 创建软链接
```
- 类似 Windows 快捷方式
- 可以跨文件系统，可以链接目录
- **原文件删除则软链接失效**（变红/闪烁）
