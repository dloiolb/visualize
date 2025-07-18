import ctypes

_lib = ctypes.CDLL("../lib/linalg.so")

_lib.Foo_new.restype = ctypes.c_void_p
_lib.Foo_bar.argtypes = [ctypes.c_void_p]
_lib.Foo_delete.argtypes = [ctypes.c_void_p]

class Foo:
  def __init__(self):
    self.obj = _lib.Foo_new()

  def bar(self):
    _lib.Foo_bar(self.obj)

  def __del__(self):
    if self.obj:
      _lib.Foo_delete(self.obj)
      self.obj = None
