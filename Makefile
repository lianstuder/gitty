.POSIX:

# cmake generator
GENERATOR = "Visual Studio 16 2019"
# cmake target architecture
ARCH = "x64"

default:
	rm -rf build
	mkdir build
	cd build && cmake .. -G $(GENERATOR) -A $(ARCH)
    
.PHONY: default