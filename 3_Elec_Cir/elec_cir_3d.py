import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
from mpl_toolkits import mplot3d
import magpylib as magpy
from magpylib.source.current import Circular

mpl.rcParams['text.usetex'] = True

N_less = 20
N_more = 200

cir = Circular(curr=1, dim=5, pos=[0, 0, 0])

x_less = np.linspace(-10, 10, N_less)
y_less = np.linspace(-10, 10, N_less)
z_less = np.linspace(-10, 10, N_less)
x_more = np.linspace(-10, 10, N_more)
y_more = np.linspace(-10, 10, N_more)
z_more = np.linspace(-10, 10, N_more)

fig = plt.figure("3D Electric Circuit Magnet",figsize=(10,10))

B_3dplot = fig.add_subplot(1, 1, 1, projection='3d')
pos_3d = X, Y, Z = np.meshgrid(x_more, y_more, z_more)
for z_item in z_more:
    for y_item in y_more:
        B_y_list = []
        for x_item in x_more:
            B_item = cir.getB([x_item, 0, z_item])
            B_y_list.append(np.linalg.norm(B_item))
        if y_item == np.min(y_more):
            B_xy = np.array([B_y_list])
        else:
            B_y_list = np.array([B_y_list])
            B_xy = np.concatenate([B_xy, B_y_list], axis=1)
    if z_item == np.min(z_more):
        B_3d = np.array([B_xy])
    else:
        B_xy = np.array([B_xy])
        B_3d = np.concatenate([B_3d, B_xy], axis=2)

B = B_3dplot.scatter3D(X, Y, Z, c=np.log10(B_3d), cmap='rainbow')

clb = fig.colorbar(B)
clb.set_label(r'$\log_{10}B$')

fig.savefig('Elec_Cir_3D.png')
plt.show()