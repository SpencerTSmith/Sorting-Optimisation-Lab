#!/usr/bin/env python3
import pandas as pd
from matplotlib import pyplot as plt

df = pd.read_csv('example.csv')
plt.plot(df['size'], df['throughput'])
plt.show()

