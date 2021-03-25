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
with open('iteration_vec.txt', 'r') as reading:
    file_input = reading.read().split('\n')

for row in file_input:
    data_vec.append(row.split())

for i in range(len(data_vec)-1):
    if (data_vec[i] != []):
        y_vec.append(int(data_vec[i][0]))
    else:
        time_vec.append(np.mean(y_vec))
        y_vec = []

data_flist = []
time_flist = []
y_flist = []

with open('iteration_forwlist.txt', 'r') as reading:
    file_input = reading.read().split('\n')

for row in file_input:
    data_flist.append(row.split())

for i in range(len(data_flist)-1):
    if (data_flist[i] != []):
        y_flist.append(int(data_flist[i][0]))
    else:
        time_flist.append(np.mean(y_flist))
        y_flist = []
        
data_list = []
time_list = []
y_list = []

with open('iteration_list.txt', 'r') as reading:
    file_input = reading.read().split('\n')

for row in file_input:
    data_list.append(row.split())

for i in range(len(data_list)-1):
    if (data_list[i] != []):
        y_list.append(int(data_list[i][0]))
    else:
        time_list.append(np.mean(y_list))
        y_list = []
        
data_set = []
time_set = []
y_set = []

with open('iteration_set.txt', 'r') as reading:
    file_input = reading.read().split('\n')

for row in file_input:
    data_set.append(row.split())

for i in range(len(data_set)-1):
    if (data_set[i] != []):
        y_set.append(int(data_set[i][0]))
    else:
        time_set.append(np.mean(y_set))
        y_set = []
        
data_map = []
time_map = []
y_map = []

with open('iteration_map.txt', 'r') as reading:
    file_input = reading.read().split('\n')

for row in file_input:
    data_map.append(row.split())

for i in range(len(data_map)-1):
    if (data_map[i] != []):
        y_map.append(int(data_map[i][0]))
    else:
        time_map.append(np.mean(y_map))
        y_map = []

plt.xlabel('size of container', fontsize = 15)
plt.ylabel('time, ns', fontsize = 15)

ax.plot(x, time_vec, label = 'vector')
ax.plot(x, time_flist, label = 'forward list')
ax.plot(x, time_list, label = 'list')
ax.plot(x, time_map, label = 'map')
ax.plot(x, time_set, label = 'set')

ax.legend(fontsize = 15)

plt.title('Iteration', fontsize = 20)

plt.grid()
plt.show()
