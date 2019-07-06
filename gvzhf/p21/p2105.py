from sys import stdin
from collections import namedtuple

L, T, Va, Vb = [int(x) for x in stdin.readline().split()]

n = int(stdin.readline())

Event = namedtuple('Event', ['time', 'dVa', 'dVb'])
events = []
for _ in range(n):
    type_, t, d = [int(x) for x in stdin.readline().split()]
    if type_ == 1:
        events.append(Event(t, -Va, 0))
        events.append(Event(t + d, Va, 0))
    elif type_ == 2:
        events.append(Event(t, 0, -Vb))
        events.append(Event(t + d, 0, Vb))
    else:
        assert False
events.sort()
events.append(Event(T, -Va, -Vb))

distance = 0
prev_time = 0
for event in events:
    dt = event.time - prev_time
    prev_time = event.time
    distance += dt * (Va + Vb)
    Va += event.dVa
    Vb += event.dVb

print(distance // L)
