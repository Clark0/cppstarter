BUILD_DIR := build

# Default target
all: clean configure build run

configure:
	cmake -DCMAKE_BUILD_TYPE=DEBUG -B $(BUILD_DIR)

build:
	cmake --build $(BUILD_DIR)

run: build
	 MallocNanoZone=0 ./$(BUILD_DIR)/main < input.txt

# Clean build artifacts
clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all configure build run clean
