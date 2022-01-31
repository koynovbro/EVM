# папка куда упадут .o файлы все
BUILD_DIR = ./build

# папка где лежат все .cpp файлы (они могут быть во вложенных папках тоже)
SRC_DIR   = ./src

# компилятор
COMPILER = gcc

# флаги компилятора
CFLAGS   = -I src

# название бинарника на выходе
LIB_NAME = libmemory

# === DO NOT EDIT UNDER THIS LINE ===
.RECIPEPREFIX=>
CPP_FILES = $(shell cd $(SRC_DIR) && find * -name "*.c")
OBJ_FILES = $(CPP_FILES:%.c=$(BUILD_DIR)/%.o)
OBJ_DIRS  = $(sort $(dir $(OBJ_FILES)))

all: $(BINARY_NAME)

$(OBJ_FILES): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
> $(COMPILER) $(CFLAGS) -c $< -o $@

$(LIB_NAME): $(OBJ_DIRS) $(OBJ_FILES)
> ar -crs $@ $(OBJ_FILES)

$(OBJ_DIRS):
> mkdir -p $@

clean:
> rm -rf $(BUILD_DIR)
> rm -f  $(BINARY_NAME)

.PHONY: all clean
