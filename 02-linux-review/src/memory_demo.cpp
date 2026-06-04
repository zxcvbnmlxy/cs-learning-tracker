#include <cstdio>
#include <cstddef>
#include <memory>
#include <utility>
#include <iostream>
#include "memory_demo.h"

// ============================================================
// 1. Raw pointer -- new / delete
// ============================================================
void demo_raw_pointer() {
    std::cout << "\n========== 1. Raw Pointer new/delete ==========\n";
    int* p = new int(42);
    std::cout << "  *p = " << *p << std::endl;
    delete p;
    p = nullptr;

    int* arr = new int[5];
    for (int i = 0; i < 5; ++i) arr[i] = i * 10;
    std::cout << "  array:";
    for (int i = 0; i < 5; ++i) std::cout << " " << arr[i];
    std::cout << std::endl;
    delete[] arr;
    std::cout << "  need manual delete\n";
}

// ============================================================
// 2. unique_ptr
// ============================================================
void demo_unique_ptr() {
    std::cout << "\n========== 2. unique_ptr ==========\n";
    auto u1 = std::make_unique<int>(100);
    std::cout << "  *u1 = " << *u1 << std::endl;
    auto u2 = std::move(u1);
    std::cout << "  moved, *u2 = " << *u2 << std::endl;
    std::cout << "  u1 is " << (u1 ? "non-null" : "null") << std::endl;

    auto arr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; ++i) arr[i] = i;
    std::cout << "  unique_ptr<int[]>:";
    for (int i = 0; i < 5; ++i) std::cout << " " << arr[i];
    std::cout << std::endl;
}

// ============================================================
// 3. shared_ptr
// ============================================================
void demo_shared_ptr() {
    std::cout << "\n========== 3. shared_ptr ==========\n";
    auto s1 = std::make_shared<int>(200);
    {
        auto s2 = s1;
        auto s3 = s1;
        std::cout << "  inner scope: use_count = " << s1.use_count() << std::endl;
    }
    std::cout << "  outer scope: use_count = " << s1.use_count() << std::endl;

    std::weak_ptr<int> w = s1;
    std::cout << "  weak_ptr: use_count = " << s1.use_count() << std::endl;
    if (auto locked = w.lock()) {
        std::cout << "  weak_ptr.lock() = " << *locked << std::endl;
    }
}

// ============================================================
// 4. RAII -- Buffer class
// ============================================================
Buffer::Buffer(size_t n) : data_(new int[n]), size_(n) {
    std::cout << "  Buffer(" << n << ") ctor\n";
}
Buffer::~Buffer() {
    delete[] data_;
    std::cout << "  ~Buffer() dtor\n";
}
Buffer::Buffer(Buffer&& other) noexcept
    : data_(other.data_), size_(other.size_) {
    other.data_ = nullptr;
    other.size_ = 0;
    std::cout << "  Buffer(move) ctor\n";
}
Buffer& Buffer::operator=(Buffer&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}
void Buffer::fill(int val) {
    for (size_t i = 0; i < size_; ++i) data_[i] = val + i;
}
void Buffer::print() const {
    std::cout << "  Buffer:";
    for (size_t i = 0; i < size_; ++i) std::cout << " " << data_[i];
    std::cout << std::endl;
}

// ============================================================
// 5. Practice exercises
// ============================================================
void practice_unique_ptr() {
    std::cout << "\n--- unique_ptr practice ---\n";
    auto p = std::make_unique<int>(42);
    std::cout << "  Q1: *p = " << *p << std::endl;
    auto q = std::move(p);
    std::cout << "  Q2: after move, p is " << (p ? "non-null" : "null") << std::endl;
    std::cout << "  Q3: *q = " << *q << std::endl;
}

void practice_shared_ptr() {
    std::cout << "\n--- shared_ptr practice ---\n";
    auto a = std::make_shared<int>(100);
    auto b = a;
    auto c = a;
    std::cout << "  Q1: use_count = " << a.use_count() << " (expect 3)\n";
    { auto d = a; std::cout << "  Q2: inner scope: " << a.use_count() << std::endl; }
    std::cout << "  Q3: outer scope: " << a.use_count() << std::endl;
}

// ============================================================
// 6. Memory leak: bad vs correct
// ============================================================
void demo_memory_leak() {
    std::cout << "\n========== BAD: memory leak ==========\n";
    int* p = new int(999);             // ← 实际分配，但没有 delete
    std::cout << "  leaked *p = " << *p << "  ← memory NOT freed!\n";
    std::cout << "  (run with valgrind to see the leak)\n";
    // 故意不写 delete p;   ← 这就是内存泄露！
}

void demo_correct_way() {
    std::cout << "\n========== GOOD: RAII ==========\n";
    {
        Buffer buf(5);
        buf.fill(100);
        buf.print();
    }
    {
        auto ptr = std::make_unique<Buffer>(3);
        ptr->fill(200);
        ptr->print();
    }
}
