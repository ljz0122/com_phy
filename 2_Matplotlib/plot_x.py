import matplotlib.pyplot as plt
import numpy as np
import matplotlib
import scipy.special as spec
from math import e

matplotlib.rcParams['text.usetex'] = True

x = np.linspace(-5, 5, 10000)


def one_d(x, c):
    y = (spec.eval_hermite(c, x)**2) * (e**(-(x**2)))
    return y


fig, axs = plt.subplots(2, 2, constrained_layout=True)

fig.suptitle('One-dimensional Harmonic Oscillator', fontsize=16)

axs[0, 0].plot(x, one_d(x, 5))
axs[0, 0].set_xlabel('x')
axs[0, 0].set_ylabel(r'$|\psi_5(x)|^2$')
axs[0, 0].set_title(r'$n=5$')

axs[0, 1].plot(x, one_d(x, 10))
axs[0, 1].set_xlabel('x')
axs[0, 1].set_ylabel(r'$|\psi_{10}(x)|^2$')
axs[0, 1].set_title(r'$n=10$')

axs[1, 0].plot(x, one_d(x, 15))
axs[1, 0].set_xlabel('x')
axs[1, 0].set_ylabel(r'$|\psi_{15}(x)|^2$')
axs[1, 0].set_title(r'$n=15$')

axs[1, 1].plot(x, one_d(x, 20))
axs[1, 1].set_xlabel('x')
axs[1, 1].set_ylabel(r'$|\psi_{20}(x)|^2$')
axs[1, 1].set_title(r'$n=20$')

plt.show()
