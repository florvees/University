# Ex 1

# import numpy as np
# import scipy.special as sp
# import matplotlib.pyplot as plt
#
# x = np.linspace(-1, 1, 400)
# plt.figure()
#
# for n in range(1, 8):
#     y = sp.eval_legendre(n, x)
#     plt.plot(x, y, label=f'n = {n}')
#
# plt.title('Legendre polynomials')
# plt.legend()
# plt.show()

# Ex 2

# import numpy as np
# import matplotlib.pyplot as plt
#
# parameter = np.linspace(0, 2 * np.pi, 1000)
# ratios = [(3, 2), (3, 4), (5, 4), (5, 6)]
# plt.figure(figsize=(10, 10))
#
# counter = 1
# for elem in ratios:
#     x = np.sin(elem[0] * parameter)
#     y = np.sin(elem[1] * parameter)
#     plt.subplot(2, 2, counter)
#     plt.plot(x, y)
#     plt.title(f'Ratio: {elem[0]}:{elem[1]}')
#     plt.xlabel(f'sin(' + str(elem[0]) + 't)')
#     plt.ylabel(f'sin(' + str(elem[1]) + 't)')
#     counter += 1
#
# plt.show()

# Ex 3

# import numpy as np
# import matplotlib.pyplot as plt
# from matplotlib.animation import FuncAnimation
#
# figure, ax = plt.subplots()
#
# parameter = np.linspace(-5, 5, 100)
# line, = ax.plot(np.sin(parameter), np.sin(parameter))
#
# def animate(i):
#     line.set_xdata(np.sin((i+1) * parameter))
#     line.set_ydata(np.sin((i+2) * parameter))
#     return line,
#
# animation = FuncAnimation(figure, animate, frames=100, interval=10)
#
# plt.show()

# Ex 4
