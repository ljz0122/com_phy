import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
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

fig = plt.figure("2D Electric Circuit Magnet", figsize=(10, 10))

B_2dplot = fig.add_subplot(1, 1, 1)
for z_item in z_less:
    for x_item in x_less:
        B_item = cir.getB([x_item, 0, z_item])
        B_x = B_item[0]
        B_z = B_item[2]
        B_2dplot.quiver(x_item, z_item, B_x, B_z, color='grey', width=0.005, pivot='mid')

pos_2d = X, Z = np.meshgrid(x_more, z_more)
for z_item in z_more:
    B_z_list = []
    for x_item in x_more:
        B_item = cir.getB([x_item, 0, z_item])
        B_z_list.append(np.linalg.norm(B_item))
    if z_item == np.min(z_more):
        B_2d = np.array([B_z_list])
    else:
        B_z_list = np.array([B_z_list])
        B_2d = np.concatenate([B_2d, B_z_list], axis=1)
B = B_2dplot.scatter(X, Z, c=np.log10(B_2d), cmap='rainbow', alpha=0.2)

clb = fig.colorbar(B)
clb.set_label(r'$\log_{10}B$')

fig.savefig('Elec_Cir_2D.png')
plt.show()
