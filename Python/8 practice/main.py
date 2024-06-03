import numpy as np
import scipy.special as sp
import matplotlib.pyplot as plt

# Ex 1

x = np.linspace(-1, 1, 400)
plt.figure()

for n in range(1, 8):
    y = sp.eval_legendre(n, x)
    plt.plot(x, y, label=f'n = {n}')

plt.title('Legendre polynomials')
plt.legend()
plt.show()
