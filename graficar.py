import matplotlib.pylab as plt
import numpy as np
datos=np.loadtxt("datos.dat")*1E5
plt.subplot(2,2,1)
plt.imshow(datos,aspect="auto")
plt.title("Nx=100, Ntc")
plt.xlabel("Posición")
plt.ylabel("Tiempo")
plt.colorbar()
plt.savefig("evolve.png")