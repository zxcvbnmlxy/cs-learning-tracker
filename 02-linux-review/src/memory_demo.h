#ifndef MEMORY_DEMO_H
#define MEMORY_DEMO_H

#include <cstddef>   // size_t

// ======== 1. 原始指针 —— new / delete ========
void demo_raw_pointer();

// ======== 2. 智能指针 —— unique_ptr ========
void demo_unique_ptr();

// ======== 3. 共享所有权 —— shared_ptr / weak_ptr ========
void demo_shared_ptr();

// ======== 4. RAII 类 —— 资源获取即初始化 ========
class Buffer {
    int* data_;
    size_t size_;
public:
    Buffer(size_t n);
    ~Buffer();

    // 禁止拷贝
    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;

    // 允许移动
    Buffer(Buffer&& other) noexcept;
    Buffer& operator=(Buffer&& other) noexcept;

    void fill(int val);
    void print() const;
};

// ======== 5. 练习题 ========
void practice_unique_ptr();
void practice_shared_ptr();

// ======== 6. 正确 vs 错误的内存管理 ========
void demo_memory_leak();   // 有问题的代码（反面教材）
void demo_correct_way();   // 正确做法

#endif
