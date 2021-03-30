import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np

x = []

data_flist = []
time_flist = []
y_flist = []

for i in range(10000, 500001, 10000):
    x.append(i)

fig, ax = plt.subplots()
with open('pop_front_forwlist.txt', 'r') as reading:
    file_input = reading.read().split('\n')

for row in file_input:
    data_flist.append(row.split())

for i in range(len(data_flist)-1):
    if (data_flist[i] != []):
        y_flist.append(int(data_flist[i][0]))
    else:
        time_flist.append(np.mean(y_flist))
        y_flist = []

data_sflist = []
time_sflist = []
y_sflist = []

fig, ax = plt.subplots()
with open('pop_front_subforwlist.txt', 'r') as reading:
    file_input = reading.read().split('\n')

for row in file_input:
    data_sflist.append(row.split())

for i in range(len(data_sflist)-1):
    if (data_sflist[i] != []):
        y_sflist.append(int(data_sflist[i][0]))
    else:
        time_sflist.append(np.mean(y_sflist))
        y_sflist = []

plt.xlabel('size of flist', fontsize = 15)
plt.ylabel('time of erasing, mcs', fontsize = 15)

ax.plot(x, time_flist, label = 'forward_list')
ax.plot(x, time_sflist, label = 'subforward_list')

ax.legend(fontsize = 15)

plt.title('Pop_forward', fontsize = 20)

plt.grid()
plt.show()

