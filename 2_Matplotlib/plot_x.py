import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-10, 10, 2000)

ax = plt.subplot(131)
ax.plot(x, x)

bx = plt.subplot(132)
bx.plot(x, x**2)

cx = plt.subplot(133)
cx.plot(x, x**3)

plt.show()
