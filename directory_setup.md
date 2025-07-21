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
│   ├── foo_binding.py # required to use for python binding
│   ├── libfoo.a  # static library
│   └── linalg.so # dynamic library: to use for python binding
├── python/
│   └── extra.py
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
