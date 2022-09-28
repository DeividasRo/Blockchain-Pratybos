make:
	g++ src/main.cpp src/myhash.cpp src/tests.cpp -o prog
clear: 
	-del prog.exe