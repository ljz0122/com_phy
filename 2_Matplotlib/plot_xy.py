from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import matplotlib
import numpy as np
matplotlib.rcParams['text.usetex'] = True


def f(x, y):
    return np.sqrt(x**2 + y**2)


def g(x, y):
    return x**2 + y**2


fig = plt.figure(figsize=plt.figaspect(0.5))
ax = fig.add_subplot(211, projection='3d')
bx = fig.add_subplot(212, projection='3d')

xline = np.linspace(-10, 10, 2000)
yline = np.linspace(-10, 10, 2000)
X, Y = np.meshgrid(xline, yline)
azline = f(X, Y)
bzline = g(X, Y)

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel(r'$\sqrt{X^2+Y^2}$')

surfa = ax.plot_surface(X, Y, azline, cmap='hot')
ax.view_init(60, 35)
fig.colorbar(surfa, shrink=0.5, aspect=10)

bx.set_xlabel('X')
bx.set_ylabel('Y')
bx.set_zlabel(r'$X^2+Y^2$')

surfb = bx.plot_surface(X, Y, bzline, cmap='hot')
bx.view_init(60, 35)

fig.savefig('plot_xy.png')
plt.show()
