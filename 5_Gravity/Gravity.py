import matplotlib.pyplot as plt
import numpy as np
from math import pi, inf


def r_elli(theta, a, e, omega):
    r = a * (1 - e**2) / (1 + e * np.cos(theta - omega))
    return r


def r_para(theta, p):
    r = 2 * p / (1 + np.cos(theta))
    return r


ax1 = plt.subplot(221, projection='polar')
ax2 = plt.subplot(222, projection='polar')
ax3 = plt.subplot(223, projection='polar')
ax4 = plt.subplot(224, projection='polar')

a = 10
theta = np.linspace(0, 2 * pi, 10**4)

ax1.plot(theta, r_elli(theta, a, 0.5, 0))
ax2.plot((theta - pi) / 2, r_para((theta - pi) / 2, a))
ax3.plot((theta - pi) / 2, r_elli((theta - pi) / 2, -a, 2, 0))
ax4.plot(theta, r_elli(theta, a, 0.5, pi / 4))

plt.savefig('two-body.png')
plt.show()
