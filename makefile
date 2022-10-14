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
	g++ -g -c *.cpp
	g++ -g -o main *.o
	mkdir "build"
	mv *.o build/
	gdb main

test:
ifneq ("$(wildcard $(BUILD_DIR))","")
	rm -d -r $(BUILD_DIR)
endif
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR); cmake -D BUILD_TESTS=ON ..; make; ./Testing