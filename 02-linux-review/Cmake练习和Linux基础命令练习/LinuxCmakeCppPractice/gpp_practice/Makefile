# ============================================
# Makefile — g++ 项目构建示例
# ============================================
# 使用方法:
#   make          # 编译（默认目标）
#   make run      # 编译并运行
#   make clean    # 清理
#   make debug    # 调试模式编译
#   make release  # 发布模式编译
# ============================================

# 编译器
CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Wpedantic

# 目录
SRCDIR   := multi_file
BUILDDIR := build

# 源文件
SRCS     := $(SRCDIR)/main.cpp $(SRCDIR)/greet.cpp
OBJS     := $(SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)
TARGET   := greet_app

# 默认目标
all: $(TARGET)

# 链接
$(TARGET): $(OBJS)
	$(CXX) $^ -o $@
	@echo "✅ 编译完成: ./$(TARGET)"

# 编译模式匹配规则
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 创建构建目录
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# 运行
run: $(TARGET)
	./$(TARGET)

# 调试模式
debug: CXXFLAGS += -g -O0 -DDEBUG
debug: all

# 发布模式
release: CXXFLAGS += -O2 -DNDEBUG
release: all

# 清理
clean:
	rm -rf $(BUILDDIR) $(TARGET)
	@echo "🧹 清理完成"

# 伪目标（防止和目标文件重名）
.PHONY: all run debug release clean
