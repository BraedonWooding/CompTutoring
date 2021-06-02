import pandas as pd
import plotly.express as px

df = pd.read_csv('generatedFibData_Recursive.csv')

fig = px.scatter(df, x = 'N', y = 'Time', title='Recursive Times for Fib')
fig.show()

df = pd.read_csv('generatedFibData_Iterative.csv')

fig = px.scatter(df, x = 'N', y = 'Time', title='Iterative Times for Fib')
fig.show()

df = pd.read_csv('generatedFibData_Memo.csv')

fig = px.scatter(df, x = 'N', y = 'Time', title='Memo Times for Fib')
fig.show()
