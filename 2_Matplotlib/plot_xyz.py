import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits import mplot3d
from math import sqrt

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

N = 30
x = np.arange(0, N, 1)
y = np.arange(0, N, 1)
z = np.arange(0, N, 1)
X, Y, Z = np.meshgrid(x, y, z)

colors = []
for item_x in x:
    for item_y in x:
        for item_z in z:
            colors.append(sqrt(item_x**2 + item_y**2 + item_z**2) / (3 * N))

ax.scatter3D(X, Y, Z, c=colors, cmap='rainbow')

fig.savefig('plot_xyz.png')
plt.show()
