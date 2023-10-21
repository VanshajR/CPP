import math

# Define the function g(x)
def g(x):
    return -3*x + math.tan(x)

# Initial guess
x = 1

# Tolerance (desired accuracy)
tolerance = 1e-3

# Perform iterations
while True:
    x_new = g(x)
    if abs(x_new - x) < tolerance:
        break
    x = x_new

# Print the approximate solution
print("Approximate solution:", x)
