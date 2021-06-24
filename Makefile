.POSIX:

# cmake generator
GENERATOR = "Visual Studio 16 2019"
# cmake target architecture
ARCH = "x64"

CC = MSBuild.exe
TARGET = gitty.sln

compile:
	cd build && \
	$(CC) $(TARGET)

rebuild:
	mkdir -p build
	cd build && \
	cmake .. -G $(GENERATOR) -A $(ARCH)
	$(MAKE) compile

run:
	build/Debug/gitty.exe

.PHONY: run rebuild