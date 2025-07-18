import sys
import os
sys.path.append(os.path.abspath("./python"))

from foo_binding import Foo

f = Foo()
f.bar()
