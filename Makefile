build: 
	mkdir ./build
	cd ./build && cmake ..
	cmake --build ./build

minesweeper: build
	./build/minesweeper