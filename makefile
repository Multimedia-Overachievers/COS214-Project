BUILD_DIR := Build

main:
ifneq ("$(wildcard $(BUILD_DIR))","")
	rm -d -r $(BUILD_DIR)
endif
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR); cmake ..; make; ./Project

run: 
	main

clean:
	rm main
	rm -d -r build

reset:
	make clean
	make
	make run

debug:
ifneq ("$(wildcard $(BUILD_DIR))","")
	rm -d -r $(BUILD_DIR)
endif
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR); cmake -DCMAKE_BUILD_TYPE=Debug ..; make; gdb ./Project
	

test:
ifneq ("$(wildcard $(BUILD_DIR))","")
	rm -d -r $(BUILD_DIR)
endif
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR); cmake -D BUILD_TESTS=ON ..; make; ./Testing