import ctypes

_lib = ctypes.CDLL("../lib/visualize.so")

_lib.tensor_new.argtypes = [
    ctypes.POINTER(ctypes.c_double), ctypes.c_size_t,
    ctypes.POINTER(ctypes.c_int), ctypes.c_size_t
]
_lib.tensor_new.restype = ctypes.c_void_p
_lib.tensor_show.argtypes = [ctypes.c_void_p]
_lib.tensor_delete.argtypes = [ctypes.c_void_p]

class tensor:
    # def __init__(self, data, shape):
    #     self.obj = _lib.tensor_new()
    def __init__(self, data, shape):
        if not all(isinstance(x, (int, float)) for x in data):
            raise TypeError("All elements of `data` must be int or float")
        if not all(isinstance(x, int) for x in shape):
            raise TypeError("All elements of `shape` must be int")
        data_arr = (ctypes.c_double * len(data))(*data)
        shape_arr = (ctypes.c_int * len(shape))(*shape)
        self.obj = _lib.tensor_new_from_data(
            data_arr, len(data),
            shape_arr, len(shape)
        )
        if not self.obj:
            raise MemoryError("Failed to create tensor")

    def show(self):
        _lib.tensor_show(self.obj)

    def __del__(self):
        if self.obj:
            _lib.tensor_delete(self.obj)
            self.obj = None

