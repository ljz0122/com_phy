import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits import mplot3d

fig = plt.figure()
ax = fig.gca(projection='3d')

x = np.linspace(-1, 1, 10)
z = y = x
X, Y, Z = np.meshgrid(x, y, z)

u = np.sqrt((np.sin(np.pi * x))**2 + (np.cos(np.pi * y))**2)
v = np.sqrt((np.cos(np.pi * x))**2 + (np.sin(np.pi * y))**2)
w = np.cos(np.pi * z)

ax.quiver3D(X, Y, Z, u, v, w, length=0.2, normalize=True)

fig.savefig('plot_vector.png')
plt.show()
