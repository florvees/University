# Ex 1

# import numpy as np
# import scipy.special as sp
# import matplotlib.pyplot as plt
#
# x = np.linspace(-1, 1, 100)
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
# parameter = np.linspace(1, 10, 1000)
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
# parameter = np.linspace(1, 10, 1000)
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

# import matplotlib.pyplot as plt
# import numpy as np
# from matplotlib.widgets import Slider
#
# amplitude_1 = 1
# frequency_1 = 1
#
# fig, ax = plt.subplots(3, 1)
#
# x1 = np.linspace(-10, 10, 500)
# y1 = amplitude_1 * np.sin(frequency_1 * x1)
# line1, = ax[0].plot(x1, y1)
#
# ax_amplitude_1 = plt.axes((0.3, 0.9, 0.1, 0.1))
# ax_frequency_1 = plt.axes((0.1, 0.9, 0.1, 0.1))
# amplitude_1 = Slider(ax_amplitude_1, 'amplitude', valmin=0, valmax=10)
# frequency_1 = Slider(ax_frequency_1, 'frequency', valmin=0, valmax=10)
#
# x2 = np.linspace(-10, 10, 500)
# y2 = np.cos(x2)
# line2, = ax[1].plot(x2, y2)
#
# ax_amplitude_2 = plt.axes((0.8, 0.9, 0.1, 0.1))
# ax_frequency_2 = plt.axes((0.6, 0.9, 0.1, 0.1))
# amplitude_2 = Slider(ax_amplitude_2, 'amplitude', valmin=0, valmax=10)
# frequency_2 = Slider(ax_frequency_2, 'frequency', valmin=0, valmax=10)
#
# line3, = ax[2].plot(x1 + x2, y1 + y2)
#
#
# def update(val):
#     n_frequency_1 = frequency_1.val
#     n_amplitude_1 = amplitude_1.val
#     line1.set_ydata(n_amplitude_1 * np.sin(n_frequency_1 * x1))
#
#     n_frequency_2 = frequency_2.val
#     n_amplitude_2 = amplitude_2.val
#     line2.set_ydata(n_amplitude_2 * np.sin(n_frequency_2 * x2))
#
#     line3.set_ydata(n_amplitude_1 * np.sin(n_frequency_1 * x1) +
#                     n_amplitude_2 * np.sin(n_frequency_2 * x2))
#
#
# frequency_1.on_changed(update)
# amplitude_1.on_changed(update)
#
# frequency_2.on_changed(update)
# amplitude_2.on_changed(update)
#
# plt.show()

# Ex 5

# import numpy as np
# import matplotlib.pyplot as plt
#
# x = np.random.rand(1000)
# y = np.random.rand(1000)
# z = np.random.rand(1000)
#
# MSE = pow((x - y), 2)
#
# figure = plt.figure()
#
# ax1 = figure.add_subplot(121, projection='3d')
# ax2 = figure.add_subplot(122, projection='3d')
#
# ax1.scatter(x, y, z)
# ax2.scatter(x, y, MSE)
#
# ax2.set_yscale('log')
#
# plt.show()