import numpy
import scipy
import matplotlib.pyplot as plt
import random
from sklearn.datasets import load_boston
dataset = load_boston()
x, y = dataset['data'], dataset['target']
x_rm = x[:,5]
def price(rm_size, k, b):
    return rm_size * k + b

def loss(y,y_hat):
    return sum((y_hat_i - y_i)**2 for y_hat_i, y_i in zip(list(y_hat), list(y))) / len(y)

def partial_derivative_k(x, y, y_hat):
    n = len(y)
    gradient = 0
    for x_i, y_i, y_hat_i in zip(list(x), list(y), list(y_hat)):
        gradient += (y_hat_i - y_i) * x_i
    return 2/n * gradient

def partial_derivative_b(y, y_hat):
    n = len(y)
    gradient = 0
    for y_i, y_hat_i in zip(list(y), list(y_hat)):
        gradient += (y_hat_i - y_i)
    return 2/n * gradient

k = random.random() * 10  #initialization problem 初始化问题
b = random.random() * 10

learning_rate = 0.015

iteration_n = 50000
losses = []

for i in range(iteration_n):
    y_hat = [price(r, k, b) for r in x_rm]
    current_loss = loss(y, y_hat)  #supervised learning 监督学习
    losses.append(current_loss)
    if i % 1000 == 0:
        print("Iteration {}, the loss is {}, parameters k is {} and b is {}".format(i, current_loss, k, b))
    k = k - partial_derivative_k(x_rm, y, y_hat) * learning_rate  #optimizer 优化器  
    b = b - partial_derivative_b(y, y_hat) * learning_rate

best_k = k # is 9.102108
best_b = b # is -34.670619
#min_loss is 43.600551771169556