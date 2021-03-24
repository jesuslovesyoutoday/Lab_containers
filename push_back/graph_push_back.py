import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

x = []
y = []
data = []

fig, ax = plt.subplots()
with open('push_back.txt', 'r') as reading:
    file_input = reading.read().split('\n')

for row in file_input:
    data.append(row.split(' '))

for i in range(int((len(data)-1))):
    x.append(data[i][0])
    y.append(data[i][1])
x = [0] + x
y = [0] + y
ax.xaxis.set_major_locator(ticker.MultipleLocator(50000))
plt.xlabel('size', fontsize = 15)
plt.ylabel('capacity', fontsize = 15)

ax.plot(x, y)
ax.grid()
plt.show()

