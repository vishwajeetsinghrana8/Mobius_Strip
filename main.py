import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D  # Required for 3D plotting

# Define parameters
theta = np.linspace(0, 2 * np.pi, 150)     # Angle around the circle
w = np.linspace(-0.3, 0.3, 20)             # Width of the strip

# Create 2D grids of parameters
theta, w = np.meshgrid(theta, w)

# Möbius strip parametric equations
# Radius of central circle = 1
R = 1

X = (R + w * np.cos(theta / 2)) * np.cos(theta)
Y = (R + w * np.cos(theta / 2)) * np.sin(theta)
Z = w * np.sin(theta / 2)

# Plotting
fig = plt.figure(figsize=(10, 6))
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap='viridis', edgecolor='k', alpha=0.9)

# Customizing the view
ax.set_title("3D Möbius Strip", fontsize=14, weight='bold')
ax.set_xlabel("X-axis")
ax.set_ylabel("Y-axis")
ax.set_zlabel("Z-axis")
ax.view_init(elev=20, azim=120)
plt.tight_layout()
plt.show()
