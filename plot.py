# Farid Farajli
import matplotlib.pyplot as plt

steps = []
seconds = []

file = open('data.txt', 'r')
lines = file.readlines()
file.close()

for line in lines:
    splited = line.split()
    steps.append(int(splited[0]))
    seconds.append(float(splited[1]))

plt.xlim(0, steps[-1] + 1)
plt.ylim(0, seconds[-1] + 1)
plt.plot(steps, seconds, linewidth = 2.0)
plt.ylabel('Seconds')
plt.xlabel('Steps or rectangles')
plt.grid(True)
plt.show()
