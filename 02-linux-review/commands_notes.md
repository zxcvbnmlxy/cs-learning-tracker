Linux文件基本属性
    我们可以使用 chown：修改所属用户与组 chmod：修改用户权限
    通过ls -l可以显示一个文件的属性以及文件所属的用户和组
Linux文件与目录管理
    处理目录常用命令：
    ls（英文全拼：list files）: 列出目录及文件名
    cd（英文全拼：change directory）：切换目录
    pwd（英文全拼：print work directory）：显示目前的目录
        pwd [-P] -P显示真实路径
    mkdir（英文全拼：make directory）：创建一个新的目录
        -m 配置文件权限
        -p 递归创建目录
    rmdir（英文全拼：remove directory）：删除一个空的目录
        -p 从当前目录开始递归删除空目录（多级空目录）
        可以添加rm 删除非空目录
    cp（英文全拼：copy file）: 复制文件或目录

    rm（英文全拼：remove）: 删除文件或目录
        -f 强制删除不会出现警告信息
        -i 互动模式，询问是否删除(安全)
        -r 递归删除（最危险）
    mv（英文全拼：move file）: 移动文件与目录，或修改文件与目录的名称
        mv [-fiu] source destination 
        -f 若目标文件已经存在，强制覆盖
        -i 询问是否覆盖
Linux文件内容查看
    cat  由第一行开始显示文件内容
        -b 对非空白文本列行号
        -E 将结尾的断行字节$显示出来 
            比如 cat -E  test.txt 
            woo$
                00ishh$就是将非空行的换行符显示出来
        -n 列行号，全部都列（不分空白）
    tac  从最后一行开始显示，可以看出 tac 是 cat 的倒着写！
    nl   显示的时候，顺道输出行号！
    more 一页一页的显示文件内容
    less 与 more 类似，但是比 more 更好的是，他可以往前翻页！
    head 只看头几行
        -n 后面接数字,就是查看几行
    tail 只看尾巴几行
        -n 
Linux 磁盘管理 
    df 列出文件系统整体磁盘使用量
    df [选项] [目录或者文件]
        -h 人类可读
        -T 显示文件系统类型
    du 检查磁盘空间使用量
        -h 人类可读
        -s 仅显示指定目录和文件的总和的大小，不显示其子目录的大小
        -S 包括子目录下的总和
    fdisk 磁盘分区
    磁盘格式化 
    mkfs [-t 文件系统格式] 装置文件名
        -t 可以接文件系统格式，例如ext3，ext2等
        查看mkfs支持的文件格式
        mkfs [tab][tab]
    磁盘挂载与卸载（需要sudo root）
    mount [-t 文件系统] [-L Lable名] [-o 额外选项] [-n] 装置文件名 挂载点
    umount [-fn] 装置文件名或挂载点
    挂载：Linux 里面没有符盘的概念，所有硬盘，都需要先接到，把磁盘分区与目录绑在一起，通过该目录访问磁盘入口的过程叫做挂载