import pandas as pd
import matplotlib.pyplot as plt


df = pd.read_csv('times.csv')

plt.figure(figsize=(10,6))
plt.plot('size', 'selection', data=df, label='Selection', marker='o')
plt.plot('size', 'shaker', data=df, label='Shaker', marker='s')
plt.plot('size', 'quicksort', data=df, label='Quicksort', marker='^')
plt.plot('size', 'stdsort', data=df, label='std::sort', marker='d')

plt.xscale('log')
plt.yscale('log')
plt.xlabel('Размер выборки N')
plt.ylabel('Time (ms)')
plt.legend()
plt.grid(True)
plt.title('Сравнение сортировок ЗАГСа')

plt.savefig('sort_times.png')
plt.show()
