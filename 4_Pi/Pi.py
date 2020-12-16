from ctypes import *
import numpy as np
import matplotlib.pyplot as plt
from scipy import optimize

pi = CDLL("./Pi_calc.so")

pi_lei_count = pi.pi_lei_calc_count
pi_lei_n = pi.pi_lei_calc_n
pi_lei_count.argtypes = pi_lei_n.argtypes = [c_int]
pi_lei_count.restype = pi_lei_n.restype = c_longdouble

pi_euler_count = pi.pi_euler_calc_count
pi_euler_n = pi.pi_euler_calc_n
pi_euler_count.argtypes = pi_euler_n.argtypes = [c_int]
pi_euler_count.restype = pi_euler_n.restype = c_longdouble

Min = 10**1
Max = 10**5
Step = 10**4
n = np.arange(Min, Max, Step)
x = np.arange(0, Max, Step)
pi_n = []

for item in n:
    pi_n.append(pi_euler_n(item))

#print(pi_n)


def func(x, a, b, c):
    return a * np.exp(-b * x) + c


popt, pcov = optimize.curve_fit(func, n, pi_n)

a = popt[0]
b = popt[1]
c = popt[2]

#print(a, b, c)

pi_y = func(n, a, b, c)

#print(pi_y)
print(func(10**8, a, b, c))

plt.plot(n, pi_n, '*')
plt.plot(x, pi_y, 'r')
#plt.xscale('log')

plt.show()
