import sys
import os
sys.path.append(os.path.abspath("../lib/"))


from foo_binding import Foo
f = Foo()
f.bar()
f.g()

from tensor_binding import tensor
T = tensor([1,2,3,4,5,6.1],[2,3])
T.show()
