#!/usr/bin/env python3
import matplotlib.pyplot as plt

f = open("out.txt", "r")
data = f.read()
f.close()

data = data.split("\n")
data = [d.split(" = ") for d in data]
v1 = [d[1].split(" : ")[1] for d in data if d[0] == 'u1']
v2 = [d[1].split(" : ")[1] for d in data if d[0] == 'u2']
vAND = [d[1].split(" : ")[1] for d in data if d[0] == 'uAND']
vOR = [d[1].split(" : ")[1] for d in data if d[0] == 'uOR']
u = [x/20.0 for x in range(20, 81)]

plt.plot(u, v1)
plt.plot(u, v2)
plt.plot(u, vAND)
plt.plot(u, vOR)
plt.show()
