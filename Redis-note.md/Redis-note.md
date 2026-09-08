Redis:开源的内存数据库，数据主要放在内存区，读写速度快；可以持久化落磁盘
    全称：Remote Dictionary Server 远程字典服务器；key-value数据库，NoSQL
特点：
    内存为主，高性能
    支持多种数据结构
    持久化

List双向链表

LPUSH key m 从头部插入 
RPUSH key m
LRANGE key start stop 读取从start 到stop 的元素
LLEN key 查看长度
LPOP key 从左边出队
RPOP key 
LINDEX key IDX 获取单个元素
LTRIM key start stop 仅保留区间内的元素

Set集合(无序，去重)哈希表

SADD key m1 m2 添加成员
SMEMBERS key 查看集合元素
SISMEMBER key m 判断m是否存在集合里面
SCARD key 查看大小
SREM key m1 指定删除
SPOP key [count] 随机弹出count个元素

集合运算
SDIFFsetA setB 属于A不属于B
SUNION 并集
SINTRE setA setB 交集

