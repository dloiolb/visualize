## Library Directory Structure
```
project_example/
├── src/	  # source files (.cpp, .h)
│   ├── vector.cpp
│   └── extra/
│       └── bar.cpp
├── inc/	  # public headers (.h)
│   └── Linalg.h
├── obj/	  # compiled oject files (.o)
│   └── vector.o
├── lib/	  # compiled libraries
│   ├── libfoo.a  # static library
│   └── linalg.so # dynamic library
│
│
├── tests/	  # test files (.cpp)
│   ├── test1.cpp
│   └── test2.cpp
├── bin_test/	  # compiled test executables
│   ├── test1 
│   └── test2 
│
│
├── docs/	  # documentation
│   └── overview.md
├── data/
│   ├── input.txt
│   └── config.json
├── scripts/
│   └── myscript.sh
├── Makefile
└── README.md
```
