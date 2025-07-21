# Info
The library is written in C++ and compiled into a shared object (visualize.so).
There are python files available that provide the python interface to the library using ctypes (foo_binding.py, tensor_binding.py, etc). 
Once compiled, the only files needed to use the library are the onces mentioned above.
They are stored in the ./lib/ directory.
See the 'How to use library' below.

# Setup
Make library:
```
make 
make clean
```
Testing:
```
make make_test
make run_test
make clean_test
```
# How to use library
How to use library: use the following directory structure:
```
new_project/
├── lib/
│   ├── foo_binding.py
│   ├── tensor_binding.py
│   └── visualize.so
├── run_basic.py   // script that uses the library
```
Then in run_basic.py use the following basic structure:
```
import sys
import os
sys.path.append(os.path.abspath("./lib/"))

from foo_binding import Foo
f = Foo()
f.bar()

from tensor_binding import tensor
T = tensor([1,2,3,4,5,6.1],[2,3])
T.show()
```
