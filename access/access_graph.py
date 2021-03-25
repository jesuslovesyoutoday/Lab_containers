import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np

x = []

data_vec = []
time_vec = []
y_vec = []

for i in range(10000, 10000001, 10000):
    x.append(i)

fig, ax = plt.subplots()
with open('access_vec.txt', 'r') as reading:
    file_input = reading.read().split('\n')

for row in file_input:
    data_vec.append(row.split())

for i in range(len(data_vec)-1):
    if (data_vec[i] != []):
        y_vec.append(int(data_vec[i][0]))
    else:
        time_vec.append(np.mean(y_vec))
        y_vec = []

data_subvec = []
time_subvec = []
y_subvec = []

fig, ax = plt.subplots()
with open('access_subvec.txt', 'r') as reading:
    file_input = reading.read().split('\n')

for row in file_input:
    data_subvec.append(row.split())

for i in range(len(data_subvec)-1):
    if (data_subvec[i] != []):
        y_subvec.append(int(data_subvec[i][0]))
    else:
        time_subvec.append(np.mean(y_subvec))
        y_subvec = []

plt.xlabel('size of vector', fontsize = 15)
plt.ylabel('time, ns', fontsize = 15)

ax.plot(x, time_vec, label = 'vector')
ax.plot(x, time_subvec, label = 'subvector')

ax.legend(fontsize = 15)

plt.title('Access', fontsize = 20)

plt.grid()
plt.show()
