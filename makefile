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
	rm -d -r $(BUILD_DIR)
endif
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR); cmake -DCMAKE_BUILD_TYPE=Debug ..; make; gdb ./Project
	
test:
ifneq ("$(wildcard $(BUILD_DIR))","")

else
	mkdir $(BUILD_DIR)
endif
	cd $(BUILD_DIR); cmake -D BUILD_TESTS=ON ..; make; ./Testing