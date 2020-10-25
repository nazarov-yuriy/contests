from typing import List
from functools import wraps
from functools import reduce

def coroutine(func):
    @wraps(func)
    def primer(*args,**kwargs):
        gen = func(*args,**kwargs)
        next(gen)
        return gen
    return primer

@coroutine
def coro_summer():
    total = yield None
    while True:
        val = yield total
        total += val

@coroutine
def coro_minifier():
    min_val = yield None
    while True:
        val = yield min_val
        min_val = min(val, min_val)

@coroutine
def coro_maxifier():
    max_val = yield None
    while True:
        val = yield max_val
        max_val = max(val, max_val)

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        coro_min = coro_minifier()
        coro_max = coro_maxifier()
        coro_sum = coro_summer()

        return reduce(
            lambda x, y: coro_max.send(- coro_min.send(coro_sum.send(0)) + coro_sum.send(y)),
            nums,
            0
        )