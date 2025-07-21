import ctypes
import time

_lib = ctypes.CDLL("../lib/visualize.so")

_lib.Foo_new.restype = ctypes.c_void_p
_lib.Foo_bar.argtypes = [ctypes.c_void_p]
_lib.Foo_delete.argtypes = [ctypes.c_void_p]

class Foo:
  def __init__(self):
    self.obj = _lib.Foo_new()

  def bar(self):
    start_time = time.time()
    _lib.Foo_bar(self.obj)
    total_time = time.time() - start_time
    print(f"Done in {total_time:.9f} seconds.")
    
  def g(self):
    start_time = time.time()
    print("Hello from C++!")
    a = 123456 * 123456
    print(a)
    total_time = time.time() - start_time
    print(f"Done in {total_time:.9f} seconds.")

  def __del__(self):
    if self.obj:
      _lib.Foo_delete(self.obj)
      self.obj = None
