#!/usr/bin/env python3
import os
import pandas as pd
from matplotlib import pyplot as plt

file_names = os.listdir('./')

file_names = [file for file in file_names if '.csv' in file]

for file in file_names:
    df = pd.read_csv('./' + file)
    plt.plot(df['size'], df['throughput'], label = str(file))
plt.legend(loc = "best")
plt.show()

