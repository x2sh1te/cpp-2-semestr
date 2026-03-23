import csv
import matplotlib.pyplot as plt
import numpy as np

N = []
time = []

with open('resultss.csv', 'r') as f:
    reader = csv.DictReader(f)
    for row in reader:
        N.append(int(row['N']))
        time.append(float(row['Time(seconds)']))

plt.plot(N, time, 'o-', label='Реальные данные', color='green')

coeffs = np.polyfit(N, time, 2)
predict_func = np.poly1d(coeffs)


N_predict = np.linspace(min(N), max(N), 100)
time_predict = predict_func(N_predict)

plt.plot(N_predict, time_predict, '--', label='Прогноз O(N²)', color='red')

# Оформление
plt.xlabel('N')
plt.ylabel('Время (сек)')
plt.title('Зависимость времени от N')
plt.legend()
plt.grid(True)
plt.show()