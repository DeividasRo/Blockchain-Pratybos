make:
	g++ src/main.cpp src/myhash.cpp src/tests.cpp src/sha256.cpp -o prog
clear: 
	-del prog.exe