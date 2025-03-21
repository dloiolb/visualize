## Library Directory Structure
```
project_example/
├── src/	  # source files (.cpp, .h)
│   ├── foo.cpp
│   └── bar/
│       └── bar.cpp
├── include/	  # public headers (.h)
│   └── foo.h
├── obj/	  # compiled oject files (.o)
│   └── foo.o
├── lib/	  # compiled libraries
│   ├── libfoo.a  # static library
│   └── libbar.so # dynamic library
│
│
├── tests/	  # test files (.cpp)
│   ├── test1.cpp
│   └── test2.cpp
├── testbin/	  # compiled test executables
│   ├── test1 
│   └── test2 
│
│
├── docs/	  # documentation
│   └── project_overview.md
├── data/
│   ├── input.txt
│   └── config.json
├── scripts/
│   └── myscript.sh
├── Makefile
└── README.md
```
