BUILD_DIR := Build

main:
ifneq ("$(wildcard $(BUILD_DIR))","")

else
	mkdir $(BUILD_DIR)
endif
	cd $(BUILD_DIR); cmake ..; make; ./Project

clean:
	rm -rf $(BUILD_DIR)

debug:
ifneq ("$(wildcard $(BUILD_DIR))","")

else
	mkdir $(BUILD_DIR)
endif
	cd $(BUILD_DIR); cmake -DCMAKE_BUILD_TYPE=Debug ..; make; gdb ./Project
	
test:
ifneq ("$(wildcard $(BUILD_DIR))","")

else
	mkdir $(BUILD_DIR)
endif
	cd $(BUILD_DIR); cmake -D BUILD_TESTS=ON ..; make; ./Testing

setup:
	sudo apt-get update
	sudo apt install libfreetype6-dev libxrandr-dev libudev-dev libogg-dev libflac-dev libvorbis-dev libopenal-dev libgl1-mesa-dev