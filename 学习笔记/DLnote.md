# 一、预备知识

## 1.数据操作

按运算

```python
import torch
x = torch.tensor([2,2,1,4,5])
y = torch.tensor([1,1,3,9,5])
print(x, y)

z = x ** y
print(z)
```

广播机制

```python
import torch
a = torch.arange(3).reshape((3, 1))
b = torch.arange(2).reshape((1, 2))
print(a, b)

c = a + b
print(c)
```

索引和切片

```python
import torch
x = torch.arange(12, dtype=torch.float).reshape((3, 4))
y = torch.tensor([[2.0, 1, 4, 3], [1, 2, 3, 4], [4, 3, 2, 1]])

# 索引
print(x[1,2], y[1:2])

# 切片
print(x[0:2,:])
```

节省内存

```python
import torch
x = torch.arange(12, dtype=torch.float).reshape((3, 4))
y = torch.tensor([[2.0, 1, 4, 3], [1, 2, 3, 4], [4, 3, 2, 1]])

# 首先计算Y + X，为结果分配新的内存，然后使Y指向内存中的这个新位置
before = id(y)
y = y + x
print(before == id(y))

# 方案一：使用 z[:] = z + y 方式，原地址操作 z 地址的数值
z = torch.zeros_like(y)
before = id(z)
z[:] = x + y
print(before == id(z))


# 方案二：使用 z += x 方式，原地址操作 z 地址的数值
before = id(z)
z += x
print(before == id(z))
```

## 2.数据预处理

创建一个csv数据表

```python
# 创建一个csv数据表
import os

os.makedirs(os.path.join('..', 'data'), exist_ok=True)
datafile = os.path.join('..', 'data', 'house_tiny.csv')
with open(datafile, 'w') as f:
    f.write('NumRooms,Alley,Price\n') # 列名
    f.write('1,Pave,3000\n') # 每行代表一个数据样本
    f.write('4,NA,6000\n')
    f.write('NA,NA,9000\n')
```

读取创建的csv数据

```python
# 读取创建的csv数据
import pandas as pd
data = pd.read_csv(datafile)
print(data)
```

## 3.线性代数

多维矩阵按特定轴求和

```python
import torch

a = torch.ones((2, 5, 4))
print(a.shape)

# 按轴做求和运算，axis=1 表示 维度1 消失，keepdim=True 表示消失维度不消失，而变成1
b = a.sum(axis=1)
print(b.shape)

b = a.sum(axis=[0,2])
print(b.shape)

b = a.sum(axis=1,keepdim=True)
print(b.shape)

b = a.sum(axis=[0,2], keepdim=True)
print(b.shape)
```

注：求哪一维和就消除了哪一维

## 4.矩阵计算

微积分

（1）标量y 对 向量x 求导

（2）向量y 对 标量x 求导

（3）向量y 对 向量x 求导

（4）矩阵 与 向量， 矩阵 与 矩阵 之间的求导运算

## 5.自动求导

向量链式法则







# 二、线性神经网络

## 1.线性回归

从零开始实现

```python
import random
import torch
from d2l import torch as d2l

# 使用线性模型，构造人造数据集
def synthetic_data(w, b, num_examples):
    """生成 y = Xw + b + 噪声"""
    X = torch.normal(0, 1, (num_examples, len(w))) # X 是 均值为 0，方差为 1 的随机数矩阵
    y = torch.matmul(X, w) + b                     # y = Xw + b
    y += torch.normal(0, 0.01, y.shape)            # y = y + 均值为 0，方差为 0.01 的噪声
    return X, y.reshape((-1, 1))                   # 返回 原始数据X 和 列向量y

true_w = torch.tensor([2, -3.4])
true_b = 4.2
features, labels = synthetic_data(true_w, true_b, 1000)

# 打印第一个 特征值 和 对应的标签值
print('feature:', features[0], '\nlabel:', labels[0])

# 以特征值的第1列 和 对应的标签值 分别作为 X轴和Y轴 绘图
d2l.set_figsize()
d2l.plt.scatter(features[:, 1].detach().numpy(), labels.detach().numpy(), 1)




# 定义一个函数，用于接收批量大小、特征矩阵和标签向量作为输入，生成大小为 batch_size 的小批量
def data_iter(batch_size, features, labels):
    num_examples = len(features)
    indices = list(range(num_examples))
    # 这些样本是随机读取的，没有特定的顺序
    random.shuffle(indices)
    for i in range(0, num_examples, batch_size):
        batch_indices = torch.tensor(
            indices[i : min(i + batch_size, num_examples)])
        yield features[batch_indices], labels[batch_indices]

batch_size = 10
for X, y in data_iter(batch_size, features, labels):
    print(X, '\n', y)
    break




# 定义初始化模型参数
w = torch.normal(0, 0.01, size=(2, 1), requires_grad=True) # w为2行1列的随机数矩阵
b = torch.zeros(1, requires_grad=True)                     # b为值为0的标量

# 定义模型
def linreg(X, w, b):
    """线性回归模型"""
    return torch.matmul(X, w) + b

# 定义损失函数
def squared_loss(y_hat, y):
    """均方损失"""
    return (y_hat - y.reshape(y_hat.shape))**2 / 2

# 定义优化函数
def sgd(params, lr, batch_size):
    """小批量随机梯度下降"""
    with torch.no_grad():                  # 更新的时候不要参与梯度计算
        for param in params:
            param -= lr * param.grad / batch_size
            param.grad.zero_()             # 下一次梯度不与上一次梯度相关，下一次梯度重新求解




# 训练过程
lr = 0.03
num_epochs = 3
net = linreg
loss = squared_loss

for epoch in range(num_epochs):
    for X, y in data_iter(batch_size, features, labels):
        l = loss(net(X, w, b), y) # "l"的形状是[batch_size, 1]，不是标量，要把所有的元素加到一起
        # 并以此计算关于[w, b]的梯度
        l.sum().backward()
        sgd([w,b], lr, batch_size) # 使用参数的梯度更新参数

    # 评价w,b 参数的性能
    with torch.no_grad():
        train_l = loss(net(features, w, b), labels)
        print(f'epoch {epoch + 1}, loss {float(train_l.median()):f}') # 返回训练次数和loss均值

# 比较真实参数和通过训练学到的参数来评估训练的成功程度
print(f'w的估计误差：{true_w - w.reshape(true_w.shape)}')
print(f'b的估计误差：{true_b - b}')
```

深度学习框架实现

```python
import numpy as np
import torch
from torch.utils import data
from d2l import torch as d2l

# 通过使用深度学习框架来简洁地实现 线性回归模型 生成数据集
true_w = torch.tensor([2, -3.4])
true_b = 4.2
features, labels = d2l.synthetic_data(true_w, true_b, 1000)

#调用框架中现有的API来读取数据
def load_array(data_arrays, batch_size, is_train = True):
    """构造一个PyTorch数据迭代器"""
    dataset = data.TensorDataset(*data_arrays)
    return data.DataLoader(dataset, batch_size, shuffle=is_train) # 生成小批量数据

batch_size = 10
data_iter = load_array((features, labels), batch_size)

next(iter(data_iter)) # 使用迭代器读取小批量数据
# print(next(iter(data_iter)))




# 使用框架的预定义好的层
# 'nn' 是神经网络的缩写
from torch import nn


net = nn.Sequential(nn.Linear(2, 1)) # 输入的维度为2， 输出的维度为1

# 初始化模型参数
net[0].weight.data.normal_(0, 0.01) # 均值为0 ，方差为1的随机数
net[0].bias.data.fill_(0)

# 计算均方误差使用的是 MSELoss 类，也称为平方范数，
# 定义损失函数
loss = nn.MSELoss()

# 实例化 SGD 实例，优化函数,
# 定义优化器
trainer = torch.optim.SGD(net.parameters(), lr=0.03)

# 训练过程代码 与 我们从零开始实现时 所做的非常相似
num_epochs = 3
for epoch in range(num_epochs):
    for X, y in data_iter:
        l = loss(net(X), y)
        trainer.zero_grad() # 优化器梯度清零
        l.backward()
        trainer.step() # 梯度更新参数，进行自动模型更新
    l = loss(net(features), labels)
    print(f'epoch {epoch + 1}, loss {l:f}')
```

## 2.Softmax 回归 + 损失函数 + 图片分类数据集

图片分类数据集

```python
import torch
import torchvision
from torch.utils import data
from torchvision import transforms
from d2l import torch as d2l

# 用 svg格式 显示高清图片
d2l.use_svg_display()

# 定义load_data_fashion_mnist函数
def load_data_fashion_mnist(batch_size, resize=None):
    """下载Fashion-MNIST数据集下载并加载到内存中"""
    trans  = [transforms.ToTensor()] 
    # 重塑图片大小
    if resize:
        trans.insert(0, transforms.Resize(resize))
    trans = transforms.Compose(trans)
    mnist_train = torchvision.datasets.FashionMNIST(root="./data", train=True,
                                                 transform=trans, 
                                                 download=True)
    mnist_test = torchvision.datasets.FashionMNIST(root='./data', train=False,
                                                transform=trans, 
                                                download=True)
    return (data.DataLoader(mnist_train, batch_size, shuffle=True,
                              num_workers=get_dataloader_workers()), 
            data.DataLoader(mnist_test, batch_size, shuffle=True,
                              num_workers=get_dataloader_workers()))


# 分配进程读取数据，控制读取时间
def get_dataloader_workers():
    """使用4个进程来读取数据"""
    return 4


# 读取一小批量数据
batch_size = 256
train_iter, train_test = load_data_fashion_mnist(batch_size)

# 读取数据，并打印花费时间
timer = d2l.Timer()
for X, y in train_iter:
    continue
for X, y in train_test:
    continue
print(f'{timer.stop():.2f} sec')
```

softmax 回归 从零开始实现

```python
import torch
from IPython import display
from d2l import torch as d2l
import matplotlib.pyplot as plt



# 定义 softmax 函数
def softmax(X):
    X_exp = torch.exp(X)
    partition = X_exp.sum(1, keepdim=True)
    return X_exp / partition # 这里应用了广播机制



# 实现 softmax 回归模型
def net(X):
    return softmax(torch.matmul(X.reshape((-1, w.shape[0])), w) + b)



# 实现交叉熵损失函数
def cross_entropy(y_hat, y):
    return -torch.log(y_hat[range(len(y_hat)), y]) # 对y_hat的每一行拿出对应y真实标号的预测值，对应真实标号的预测值越大，返回的交叉熵值越小



# 将预测类别与真实y元素进行比较
def accuracy(y_hat, y):
    """计算预测正确的数量"""
    if len(y_hat.shape) > 1 and y_hat.shape[1] > 1:
        y_hat = y_hat.argmax(axis=1) # 取每行的最大值作为新的行
        cmp = y_hat.type(y.dtype) == y # 与y的数据格式保持一致
        return float(cmp.type(y.dtype).sum()) # 返回预测正确的个数

# 评估在任意模型net的准确率
def evaluate_accuracy(net, data_iter):
    """计算在指定数据集上模型的精度"""
    if isinstance(net, torch.nn.Module):
        net.eval() # 将模型设置为评估模式
    metric = Accumulator(2) # 正确预测数，预测总数，迭代器
    for X, y in data_iter:
        metric.add(accuracy(net(X), y), y.numel())
    return metric[0] / metric[1] # 返回准确率

# Accumulator 实例中创建了2个变量，用于分别存储正确预测的数量和预测总数量
# Accumulator 类
class Accumulator:
    """在 n 个变量上累加"""
    def __init__(self, n):
        self.data = [0.0] * n

    def add(self, *args):
        self.data = [a + float(b) for a, b in zip(self.data, args)]

    def reset(self):
        self.data = [0.0] * len(self.data)

    def __getitem__(self, idx):
        return self.data[idx]





# softmax 回归的训练
def train_epoch_ch3(net, train_iter, loss, updater):
    if isinstance(net, torch.nn.Module):
        net.train()
    metric = Accumulator(3) # 累计：总损失、正确预测数、样本总数
    for X, y in train_iter:
        y_hat = net(X)
        l = loss(y_hat, y)

        if isinstance(updater, torch.optim.Optimizer):
            updater.zero_grad()

            # 选择：使用总损失还是平均损失？这里以总损失为例
            total_loss = l.sum()
            total_loss.backward()
            updater.step()

            # 记录指标
            metric.add(total_loss.detach().item(), accuracy(y_hat, y), y.size().numel())
        else:
            l.sum().backward()
            updater(X.shape[0])
            metric.add(l.sum().detach().item(), accuracy(y_hat, y), y.numel())
    return metric[0] / metric[2], metric[1] / metric[2]



# 训练函数
def train_ch3(net, train_iter, test_iter, loss, num_epochs, updater):
    for epoch in range(num_epochs):
        train_metrics = train_epoch_ch3(net, train_iter, loss, updater)
        test_acc = evaluate_accuracy(net, test_iter)
        # 打印单次训练记录
        print(f'epoch {epoch + 1}, train_loss {float(train_metrics[0]):f}, train_acc {float(train_metrics[1]):f}, test_acc {float(test_acc):f}')
    # 存储训练损失值和训练精度
    train_loss, train_acc =  train_metrics




# 对图像进行分类预测
def predict_ch3(net, test_iter, n=6):
    """预测标签"""
    # 取一小批数据
    for X, y in test_iter:
        break
    trues = d2l.get_fashion_mnist_labels(y)
    preds = d2l.get_fashion_mnist_labels(net(X).argmax(axis=1))
    titles = [true + '\n' + pred for true, pred in zip(trues, preds)]
    d2l.show_images(X[0:n].reshape((n, 28, 28)), 1, n, titles=titles[0:n])




# 主程序
if __name__ == '__main__':
    # 数据准备
    batch_size = 256
    train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)

    # 将展平每个图像，将它们视为长度为784的向量。因为我们的数据集有10个类别，所以网络输出维度为10
    # 参数初始化
    num_inputs = 784
    num_outputs = 10
    w = torch.normal(0, 0.01, size=(num_inputs, num_outputs), requires_grad=True)
    b = torch.zeros(num_outputs, requires_grad=True)

    # 打印 模型net 预测测试值的准确率
    print(evaluate_accuracy(net, test_iter))



    # 小批量随机梯度下降来优化模型的损失函数
    lr = 0.1

    def updater(batch_size):
        return d2l.sgd([w, b], lr, batch_size)

    # 训练模型10个迭代周期
    num_epochs = 10
    train_ch3(net, train_iter, test_iter, cross_entropy, num_epochs, updater)


    # 对图像进行分类预测
    predict_ch3(net, test_iter)
    plt.show()
```

深度学习框架实现

```python
import torch
from torch import nn
from d2l import torch as d2l


# 将预测类别与真实y元素进行比较
def accuracy(y_hat, y):
    """计算预测正确的数量"""
    if len(y_hat.shape) > 1 and y_hat.shape[1] > 1:
        y_hat = y_hat.argmax(axis=1) # 取每行的最大值作为新的行
        cmp = y_hat.type(y.dtype) == y # 与y的数据格式保持一致
        return float(cmp.type(y.dtype).sum()) # 返回预测正确的个数

# 评估在任意模型net的准确率
def evaluate_accuracy(net, data_iter):
    """计算在指定数据集上模型的精度"""
    if isinstance(net, torch.nn.Module):
        net.eval() # 将模型设置为评估模式
    metric = Accumulator(2) # 正确预测数，预测总数，迭代器
    for X, y in data_iter:
        metric.add(accuracy(net(X), y), y.numel())
    return metric[0] / metric[1] # 返回准确率

# Accumulator 实例中创建了2个变量，用于分别存储正确预测的数量和预测总数量
# Accumulator 类
class Accumulator:
    """在 n 个变量上累加"""
    def __init__(self, n):
        self.data = [0.0] * n

    def add(self, *args):
        self.data = [a + float(b) for a, b in zip(self.data, args)]

    def reset(self):
        self.data = [0.0] * len(self.data)

    def __getitem__(self, idx):
        return self.data[idx]





# softmax 回归的训练
def train_epoch_ch3(net, train_iter, loss, updater):
    if isinstance(net, torch.nn.Module):
        net.train()
    metric = Accumulator(3) # 累计：总损失、正确预测数、样本总数
    for X, y in train_iter:
        y_hat = net(X)
        l = loss(y_hat, y)

        if isinstance(updater, torch.optim.Optimizer):
            updater.zero_grad()
            l.backward()
            updater.step()
            metric.add(l.detach().item() * len(y), accuracy(y_hat, y), y.size().numel())
        else:
            l.sum().backward()
            updater(X.shape[0])
            metric.add(l.sum().detach().item(), accuracy(y_hat, y), y.numel())
    return metric[0] / metric[2], metric[1] / metric[2]



# 训练函数
def train_ch3(net, train_iter, test_iter, loss, num_epochs, updater):
    for epoch in range(num_epochs):
        train_metrics = train_epoch_ch3(net, train_iter, loss, updater)
        test_acc = evaluate_accuracy(net, test_iter)
        # 打印单次训练记录
        print(f'epoch {epoch + 1}, train_loss {float(train_metrics[0]):f}, train_acc {float(train_metrics[1]):f}, test_acc {float(test_acc):f}')
    # 存储训练损失值和训练精度
    train_loss, train_acc =  train_metrics




# 主程序
if __name__ == '__main__':
    # 数据拿进数据迭代器
    batch_size = 256
    train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)

    # softmax 回归的输出层是一个全连接层
    # PyTorch不会隐式地调整输入的形状
    # 因此，我们定义了展平层（flatten）在线性层前调整网络输入的形状
    net = nn.Sequential(nn.Flatten(), nn.Linear(784, 10))


    # 初始化网络权重
    def init_weights(m):
        if type(m) == nn.Linear:
            nn.init.normal_(m.weight, std=0.01)

    net.apply(init_weights)



    # 在交叉熵损失函数中传递未归一化的预测，并同时计算softmax及其对数
    loss = nn.CrossEntropyLoss()

    # 使用学习率为0.1的小批量随机梯度下降作为优化算法
    trainer = torch.optim.SGD(net.parameters(), lr=0.1)


    # 调用 之前 定义的训练函数来训练模型
    num_epochs = 10
    train_ch3(net, train_iter, test_iter, loss, num_epochs, trainer)
```

# 三、多层感知机

## 1.从零开始实现

```python
import torch
from torch import nn
from d2l import torch as d2l



# 实现ReLU函数
def relu(X):
    a = torch.zeros_like(X)
    return torch.max(X, a)


# 实现模型
def net(X):
    X = X.reshape((-1, num_inputs))
    H = relu(X @ W1 + b1)
    return (H @ W2 + b2)

loss = nn.CrossEntropyLoss()



# 将预测类别与真实y元素进行比较
def accuracy(y_hat, y):
    """计算预测正确的数量"""
    if len(y_hat.shape) > 1 and y_hat.shape[1] > 1:
        y_hat = y_hat.argmax(axis=1) # 取每行的最大值作为新的行
        cmp = y_hat.type(y.dtype) == y # 与y的数据格式保持一致
        return float(cmp.type(y.dtype).sum()) # 返回预测正确的个数




# 评估在任意模型net的准确率
def evaluate_accuracy(net, data_iter):
    """计算在指定数据集上模型的精度"""
    if isinstance(net, torch.nn.Module):
        net.eval() # 将模型设置为评估模式
    metric = Accumulator(2) # 正确预测数，预测总数，迭代器
    for X, y in data_iter:
        metric.add(accuracy(net(X), y), y.numel())
    return metric[0] / metric[1] # 返回准确率




# Accumulator 实例中创建了2个变量，用于分别存储正确预测的数量和预测总数量
# Accumulator 类
class Accumulator:
    """在 n 个变量上累加"""
    def __init__(self, n):
        self.data = [0.0] * n

    def add(self, *args):
        self.data = [a + float(b) for a, b in zip(self.data, args)]

    def reset(self):
        self.data = [0.0] * len(self.data)

    def __getitem__(self, idx):
        return self.data[idx]



# softmax 回归的训练
def train_epoch_ch3(net, train_iter, loss, updater):
    if isinstance(net, torch.nn.Module):
        net.train()
    metric = Accumulator(3) # 累计：总损失、正确预测数、样本总数
    for X, y in train_iter:
        y_hat = net(X)
        l = loss(y_hat, y)

        if isinstance(updater, torch.optim.Optimizer):
            updater.zero_grad()
            l.backward()
            updater.step()
            metric.add(l.detach().item() * len(y), accuracy(y_hat, y), y.size().numel())
        else:
            l.sum().backward()
            updater(X.shape[0])
            metric.add(l.sum().detach().item(), accuracy(y_hat, y), y.numel())
    return metric[0] / metric[2], metric[1] / metric[2]



# 训练函数
def train_ch3(net, train_iter, test_iter, loss, num_epochs, updater):
    for epoch in range(num_epochs):
        train_metrics = train_epoch_ch3(net, train_iter, loss, updater)
        test_acc = evaluate_accuracy(net, test_iter)
        # 打印单次训练记录
        print(f'epoch {epoch + 1}, train_loss {float(train_metrics[0]):f}, train_acc {float(train_metrics[1]):f}, test_acc {float(test_acc):f}')
    # 存储训练损失值和训练精度
    train_loss, train_acc =  train_metrics



# 主程序
if __name__ == '__main__':
    # 数据准备
    batch_size = 256
    train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)



    # 实现一个单隐藏层的多层感知机，包含256个隐藏单元
    num_inputs, num_outputs, num_hiddens = 784, 10, 256

    W1 = nn.Parameter(torch.randn(num_inputs, num_hiddens, requires_grad=True))
    b1 = nn.Parameter(torch.zeros(num_hiddens, requires_grad=True))

    W2 = nn.Parameter(torch.randn(num_hiddens, num_outputs, requires_grad=True))
    b2 = nn.Parameter(torch.zeros(num_outputs, requires_grad=True))

    params = [W1, b1, W2, b2]


    # 多层感知机的训练过程 和 Softmax回归的训练过程完全相同
    num_epochs , lr = 10, 0.1
    updater = torch.optim.SGD(params, lr=lr)
    train_ch3(net, train_iter, test_iter, loss, num_epochs, updater)


```







## 2.学习框架实现

```python
import torch
from torch import nn
from d2l import torch as d2l




# 将预测类别与真实y元素进行比较
def accuracy(y_hat, y):
    """计算预测正确的数量"""
    if len(y_hat.shape) > 1 and y_hat.shape[1] > 1:
        y_hat = y_hat.argmax(axis=1) # 取每行的最大值作为新的行
        cmp = y_hat.type(y.dtype) == y # 与y的数据格式保持一致
        return float(cmp.type(y.dtype).sum()) # 返回预测正确的个数




# 评估在任意模型net的准确率
def evaluate_accuracy(net, data_iter):
    """计算在指定数据集上模型的精度"""
    if isinstance(net, torch.nn.Module):
        net.eval() # 将模型设置为评估模式
    metric = Accumulator(2) # 正确预测数，预测总数，迭代器
    for X, y in data_iter:
        metric.add(accuracy(net(X), y), y.numel())
    return metric[0] / metric[1] # 返回准确率




# Accumulator 实例中创建了2个变量，用于分别存储正确预测的数量和预测总数量
# Accumulator 类
class Accumulator:
    """在 n 个变量上累加"""
    def __init__(self, n):
        self.data = [0.0] * n

    def add(self, *args):
        self.data = [a + float(b) for a, b in zip(self.data, args)]

    def reset(self):
        self.data = [0.0] * len(self.data)

    def __getitem__(self, idx):
        return self.data[idx]



# softmax 回归的训练
def train_epoch_ch3(net, train_iter, loss, updater):
    if isinstance(net, torch.nn.Module):
        net.train()
    metric = Accumulator(3) # 累计：总损失、正确预测数、样本总数
    for X, y in train_iter:
        y_hat = net(X)
        l = loss(y_hat, y)

        if isinstance(updater, torch.optim.Optimizer):
            updater.zero_grad()
            l.backward()
            updater.step()
            metric.add(l.detach().item() * len(y), accuracy(y_hat, y), y.size().numel())
        else:
            l.sum().backward()
            updater(X.shape[0])
            metric.add(l.sum().detach().item(), accuracy(y_hat, y), y.numel())
    return metric[0] / metric[2], metric[1] / metric[2]



# 训练函数
def train_ch3(net, train_iter, test_iter, loss, num_epochs, updater):
    for epoch in range(num_epochs):
        train_metrics = train_epoch_ch3(net, train_iter, loss, updater)
        test_acc = evaluate_accuracy(net, test_iter)
        # 打印单次训练记录
        print(f'epoch {epoch + 1}, train_loss {float(train_metrics[0]):f}, train_acc {float(train_metrics[1]):f}, test_acc {float(test_acc):f}')
    # 存储训练损失值和训练精度
    train_loss, train_acc =  train_metrics




# 隐藏层包含256个隐藏单元，并使用ReLU激活函数
net = nn.Sequential(nn.Flatten(), 
                    nn.Linear(784, 256), 
                    nn.ReLU(), 
                    nn.Linear(256, 10))

# 初始化网络权重
def init_weights(m):
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, std=0.01)

net.apply(init_weights)




# 主程序
if __name__ == '__main__':
    batch_size, lr, num_epochs = 256, 0.1, 10
    loss = nn.CrossEntropyLoss()
    trainer = torch.optim.SGD(net.parameters(), lr=lr)

    train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)
    train_ch3(net, train_iter, test_iter, loss, num_epochs, trainer)
```

## 3.模型选择+过拟合和欠拟合

模型选择：训练数据集和验证数据集的选择，一般使用K则交叉验证：将一组数据划分成K组，选择一组数据作为验证数据集，其余K-1组数据作为训练数据集

过拟合和欠拟合：模型的容量要匹配数据集的复杂度，不然会到导致过拟合和欠拟合。过拟合：使用大容量的模型去训练低复杂度的数据，导致完全记住了训练数据；

欠拟合：使用小容量的模型去训练高复杂度的数据，导致无法较好的拟合数据。

实验

```python
import math
import numpy as np
import torch
from torch import nn
from d2l import torch as d2l

# 将预测类别与真实y元素进行比较（分类专用，回归中不使用）
def accuracy(y_hat, y):
    """计算预测正确的数量（仅用于分类）"""
    if len(y_hat.shape) > 1 and y_hat.shape[1] > 1:
        y_hat = y_hat.argmax(axis=1)
        cmp = y_hat.type(y.dtype) == y
        return float(cmp.type(y.dtype).sum())
    # 回归任务中不应调用此函数，故此处可返回0或抛出异常
    return 0.0  # 或 raise ValueError("accuracy not for regression")

# 评估在任意模型net的准确率（分类专用）
def evaluate_accuracy(net, data_iter):
    """计算在指定数据集上模型的精度（仅用于分类）"""
    if isinstance(net, torch.nn.Module):
        net.eval()
    metric = Accumulator(2)
    for X, y in data_iter:
        metric.add(accuracy(net(X), y), y.numel())
    return metric[0] / metric[1]

# Accumulator 类
class Accumulator:
    """在 n 个变量上累加"""
    def __init__(self, n):
        self.data = [0.0] * n

    def add(self, *args):
        self.data = [a + float(b) for a, b in zip(self.data, args)]

    def reset(self):
        self.data = [0.0] * len(self.data)

    def __getitem__(self, idx):
        return self.data[idx]

# 修改后的训练函数（适配回归任务）
def train_epoch_ch3(net, train_iter, loss, updater):
    """训练一个epoch（回归版本）"""
    if isinstance(net, torch.nn.Module):
        net.train()
    metric = Accumulator(2)  # 累计：总损失、样本总数
    for X, y in train_iter:
        y_hat = net(X)
        l = loss(y_hat, y)   # l 是每个样本的损失向量 (reduction='none')

        if isinstance(updater, torch.optim.Optimizer):
            updater.zero_grad()
            l.sum().backward()   # 对总损失求导
            updater.step()
            metric.add(l.sum().detach().item(), y.numel())
        else:
            # 对于自定义updater（如d2l.sgd），同样处理
            l.sum().backward()
            updater(X.shape[0])
            metric.add(l.sum().detach().item(), y.numel())
    return metric[0] / metric[1]  # 返回平均损失

def evaluate_loss(net, data_iter, loss):
    """评估给定数据集上模型的损失"""
    metric = d2l.Accumulator(2)  # 损失的总和,样本数量
    for X, y in data_iter:
        out = net(X)
        y = y.reshape(out.shape)
        l = loss(out, y)
        metric.add(l.sum(), l.numel())
    return metric[0] / metric[1]

def train(train_features, test_features, train_labels, test_labels,
          num_epochs=400):
    # 关键修改：使用 reduction='none' 的 MSE 损失
    loss = nn.MSELoss(reduction='none')
    input_shape = train_features.shape[-1]
    net = nn.Sequential(nn.Linear(input_shape, 1, bias=False))
    batch_size = min(10, train_labels.shape[0])
    train_iter = d2l.load_array((train_features, train_labels.reshape(-1,1)),
                                batch_size)
    test_iter = d2l.load_array((test_features, test_labels.reshape(-1,1)),
                               batch_size, is_train=False)
    trainer = torch.optim.SGD(net.parameters(), lr=0.01)
    animator = d2l.Animator(xlabel='epoch', ylabel='loss', yscale='log',
                            xlim=[1, num_epochs], ylim=[1e-3, 1e2],
                            legend=['train', 'test'])
    for epoch in range(num_epochs):
        train_epoch_ch3(net, train_iter, loss, trainer)  # 训练一个epoch
        if epoch == 0 or (epoch + 1) % 20 == 0:
            animator.add(epoch + 1, (evaluate_loss(net, train_iter, loss),
                                     evaluate_loss(net, test_iter, loss)))
    print('weight:', net[0].weight.data.numpy())

# 生成数据集（与之前相同）
max_degree = 20
n_train, n_test = 100, 100
true_w = np.zeros(max_degree)
true_w[0:4] = np.array([5, 1.2, -3.4, 5.6])

features = np.random.normal(size=(n_train+n_test, 1))
np.random.shuffle(features)
poly_features = np.power(features, np.arange(max_degree).reshape(1, -1))
for i in range(max_degree):
    poly_features[:, i] /= math.gamma(i+1)

labels = np.dot(poly_features, true_w)
labels += np.random.normal(scale=0.1, size=labels.shape)

true_w, features, poly_features, labels = [torch.tensor(x, dtype=torch.float32) 
                                           for x in [true_w, features, poly_features, labels]]

# 实验1：使用前4个特征（正确模型）
train(poly_features[:n_train, :4], poly_features[n_train:, :4],
      labels[:n_train], labels[n_train:])

# 实验2：使用前2个特征（欠拟合）
train(poly_features[:n_train, :2], poly_features[n_train:, :2],
      labels[:n_train], labels[n_train:])

# 实验3：使用所有20个特征（过拟合）
train(poly_features[:n_train, :], poly_features[n_train:, :],
      labels[:n_train], labels[n_train:], num_epochs=1500)
```

## 4.权重衰退（避免过拟合）

均方范数作为柔性限制（L2正则惩罚）：使用均方范数作为柔性限制，将W的值往原点附近的方向拉，减小W值的范围，降低模型复杂度容量，从而降低过拟合的概率。

![屏幕截图 2026-03-04 155307](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-04 155307.png)



梯度衰退的理解：W在更新时，原始W的值要乘一个小于1的正值，然后再减去一个余项值。

![屏幕截图 2026-03-04 160059](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-04 160059.png)

实验

从零开始实现

~~~python
import torch
from torch import nn
from d2l import torch as d2l
import matplotlib.pyplot as plt


# 手动生成数据
n_train, n_test, num_inputs, batch_size = 20, 100, 200, 5
true_w ,true_b = torch.ones((num_inputs, 1))*0.01, 0.05
train_data = d2l.synthetic_data(true_w, true_b, n_train)
train_iter = d2l.load_array(train_data, batch_size)
test_data = d2l.synthetic_data(true_w, true_b, n_test)
test_iter = d2l.load_array(test_data, batch_size, is_train=False)


# 从零开始实现

# 初始化模型参数
def init_params():
    w = torch.normal(0, 1, size=(num_inputs, 1), requires_grad=True)
    b = torch.zeros(1, requires_grad=True)
    return [w, b]




# 定义L2范数惩罚
def l2_penalty(w):
    return torch.sum(w.pow(2)) / 2




# 定义训练代码实现
def train(lambd):
    w, b = init_params()
    net, loss = lambda X: d2l.linreg(X, w, b), d2l.squared_loss
    num_epochs, lr = 100, 0.003
    animtor = d2l.Animator(xlabel='epochs', ylabel='loss', yscale='log',
    xlim=[5, num_epochs], legend=['train', 'test'])

    for epoch in range(num_epochs):
        for X, y in train_iter:
            # 增加了L2范数惩罚项
            # 广播机制使L2_penalty(w)成为一个长度为batch_size的向量
            l = loss(net(X), y) + lambd * l2_penalty(w)
            l.sum().backward()
            d2l.sgd([w, b], lr, batch_size)
        if (epoch + 1) % 5 == 0:
            animtor.add(epoch + 1, (d2l.evaluate_loss(net, train_iter, loss),
            d2l.evaluate_loss(net, test_iter, loss)))
    print('w的L2范数是：', torch.norm(w).item())


# 忽略正则化直接训练
train(lambd=0)



# 使用权重衰减
train(lambd=3)

plt.show()
~~~

学习框架实现

~~~python
import torch
from torch import nn
from d2l import torch as d2l
import matplotlib.pyplot as plt



# 手动生成数据
n_train, n_test, num_inputs, batch_size = 20, 100, 200, 5
true_w ,true_b = torch.ones((num_inputs, 1))*0.01, 0.05
train_data = d2l.synthetic_data(true_w, true_b, n_train)
train_iter = d2l.load_array(train_data, batch_size)
test_data = d2l.synthetic_data(true_w, true_b, n_test)
test_iter = d2l.load_array(test_data, batch_size, is_train=False)


# 简洁实现

# 初始化模型参数
def init_params():
    w = torch.normal(0, 1, size=(num_inputs, 1), requires_grad=True)
    b = torch.zeros(1, requires_grad=True)
    return [w, b]




# 定义L2范数惩罚
def l2_penalty(w):
    return torch.sum(w.pow(2)) / 2




# 定义训练代码实现
def train(lambd):
    w, b = init_params()
    net, loss = lambda X: d2l.linreg(X, w, b), d2l.squared_loss
    num_epochs, lr = 100, 0.003
    animtor = d2l.Animator(xlabel='epochs', ylabel='loss', yscale='log',
    xlim=[5, num_epochs], legend=['train', 'test'])

    for epoch in range(num_epochs):
        for X, y in train_iter:
            # 增加了L2范数惩罚项
            # 广播机制使L2_penalty(w)成为一个长度为batch_size的向量
            l = loss(net(X), y) + lambd * l2_penalty(w)
            l.sum().backward()
            d2l.sgd([w, b], lr, batch_size)
        if (epoch + 1) % 5 == 0:
            animtor.add(epoch + 1, (d2l.evaluate_loss(net, train_iter, loss),
            d2l.evaluate_loss(net, test_iter, loss)))
    print('w的L2范数是：', torch.norm(w).item())


# 忽略正则化直接训练
train(lambd=0)



# 使用权重衰减
train(lambd=3)

plt.show()
~~~

## 5.丢弃法（避免过拟合）

原理：通过随机概率P使得隐藏层的输出部分为0，这样等价于每次在训练模型时，抽取子神经网路，最后模型参数取子网络训练得到的平均值。从而达到降低模型的过拟合概率。

![屏幕截图 2026-03-05 150457](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-05 150457.png)

实验

从零开始实现

~~~python
import torch
from torch import nn
from d2l import torch as d2l
import matplotlib.pyplot as plt

# 实现dropout_layer函数
def dropout_layer(X, dropout):
    assert 0 <= dropout <= 1
    if dropout == 0:
        return X
    if dropout == 1:
        return torch.zeros_like(X)
    mask = (torch.rand(X.shape) > dropout).float()
    return mask * X / (1.0-dropout)


# 测试dropout_layer函数
# X = torch.arange(16, dtype=torch.float32).reshape((2, 8))
# print(X)
# print(dropout_layer(X, 0))
# print(dropout_layer(X, 0.5))
# print(dropout_layer(X, 1))



# 定义模型参数，2个隐藏层，每层256隐藏单元
num_inputs , num_outputs, num_hiddens1, num_hiddens2 = 784, 10, 256, 256


# 定义模型
dropout1, dropout2 = 0.2, 0.5

class Net(nn.Module):
    def __init__(self, num_inputs, num_outputs, num_hiddens1, num_hiddens2, is_training = True):
        super(Net, self).__init__()
        self.num_inputs = num_inputs
        self.training = is_training
        self.lin1 = nn.Linear(num_inputs, num_hiddens1)
        self.lin2 = nn.Linear(num_hiddens1, num_hiddens2)
        self.lin3 = nn.Linear(num_hiddens2, num_outputs)
        self.relu = nn.ReLU()

    def forward(self, X):
        H1 = self.relu(self.lin1(X.reshape(-1, self.num_inputs)))
        # 只在训练模型时才使用dropout
        if self.training == True:
            H1 = dropout_layer(H1, dropout1)
        H2 = self.relu(self.lin2(H1))
        if self.training == True:
            H2 = dropout_layer(H2, dropout2)
        out = self.lin3(H2)
        return out

net = Net(num_inputs, num_outputs, num_hiddens1, num_hiddens2)



# 训练和测试
num_epochs, lr, batch_size = 10, 0.5, 256
loss = nn.CrossEntropyLoss()
train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)
trainer = torch.optim.SGD(net.parameters(), lr=lr)
d2l.train_ch3(net, train_iter, test_iter, loss, num_epochs,  trainer)

plt.show()
~~~



学习框架实现

~~~python
import torch
from torch import nn
from d2l import torch as d2l
import matplotlib.pyplot as plt


# 定义模型参数，2个隐藏层，每层256隐藏单元
num_inputs , num_outputs, num_hiddens1, num_hiddens2 = 784, 10, 256, 256


# 定义模型
dropout1, dropout2 = 0.2, 0.5

net = nn.Sequential(nn.Flatten(),
                    nn.Linear(num_inputs, num_hiddens1),
                    nn.ReLU(),
                    nn.Dropout(dropout1),
                    nn.Linear(num_hiddens1, num_hiddens2),
                    nn.ReLU(),
                    nn.Dropout(dropout2),
                    nn.Linear(num_hiddens2, num_outputs))

# 初始化权重
def init_weights(m):
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, mean=0, std=0.01)

net.apply(init_weights)


# 训练和测试模型
num_epochs, lr, batch_size = 10, 0.5, 256

loss = nn.CrossEntropyLoss()
train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)
trainer = torch.optim.SGD(net.parameters(), lr=lr)
d2l.train_ch3(net, train_iter, test_iter, loss, num_epochs, trainer)


plt.show()
~~~

## 6.数值稳定性+权重初始化和激活函数的选取

问题：在正向推理中，网络的每一层的输入值会影响输出值的大小；在反向训练中，网络的每一层的输出值会影响梯度的大小。在深层网络中，梯度太大会导致数值超大，梯度太小会导致数值超小，都会导致数值的爆炸。

数值的稳定性会影响梯度值，进而影响模型的训练。



解决方法：合理初始化权重和选取激活函数。

权重初始化：权重参数的方差等于2/(输入的维度大小+输出的维度大小)

![屏幕截图 2026-03-08 150722](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-08 150722.png)



激活函数的选择：一般使用在定义域0值范围内时，函数类似于y=x的激活函数。如tanh，ReLU激活函数，或者调整后的sigmoid函数（4*sigmoid-2）。

![屏幕截图 2026-03-08 151322](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-08 151322.png)





# 四、深度学习计算

## 1.Pytorch神经网络基础

### 自定义网络

模型构造

~~~python
import torch
from torch import nn
from torch.nn import functional as F


# 非自定义层
net = nn.Sequential(nn.Linear(20, 256), nn.ReLU(), nn.Linear(256, 10))

X = torch.rand(2, 20)
Y = net(X)
print(Y)






# 自定义层
class MLP(nn.Module):
    # 用模型参数声明层
    def __init__(self):
        # 初始化
        super().__init__()
        self.hidden = nn.Linear(20, 256)
        self.out = nn.Linear(256, 10)

    def forward(self, X):
        # 这里使用ReLU的函数版本，其在nn.functional已定义
        return self.out(F.relu(self.hidden(X)))
    
net = MLP()

X = torch.rand(2, 20)
Y = net(X)
print(Y)






# 自定义Sequential函数
class MySequential(nn.Module):
    def __init__(self, *args):
        super().__init__()
        for idx, module in enumerate(args):
            self._modules[str(idx)] = module

    def forward(self, X):
        for block in self._modules.values():
            X = block(X)
        return X

# 当MySequential的前向传播函数被调用时， 每个添加的块都按照它们被添加的顺序执行
net = MySequential(nn.Linear(20, 256), nn.ReLU(), nn.Linear(256, 10))

X = torch.rand(2, 20)
Y = net(X)

print(Y)





# 在前向传播函数中执行代码
class FixedHiddenMLP(nn.Module):
    def __init__(self):
        super().__init__()
        # 不计算梯度的随机权重参数。因此其在训练期间保持不变
        self.rand_weight = torch.rand((20, 20), requires_grad=False)
        self.linear = nn.Linear(20, 20)

    def forward(self, X):
        X = self.linear(X)
        # 使用创建的常量参数以及relu和mm函数
        X = F.relu(torch.mm(X, self.rand_weight) + 1)
        # 复用全连接层。这相当于两个全连接层共享参数
        X = self.linear(X)
        # 控制流
        while X.abs().sum() > 1:
            X /= 2
        return X.sum()
    
net = FixedHiddenMLP()

X = torch.rand(2, 20)
Y = net(X)

print(Y)







# 混合自定义的层
class NestMLP(nn.Module):
    def __init__(self):
        super().__init__()
        self.net = nn.Sequential(nn.Linear(20, 64), nn.ReLU(),
                                 nn.Linear(64, 32), nn.ReLU())
        self.linear = nn.Linear(32, 16)

    def forward(self, X):
        return self.linear(self.net(X))

chimera = nn.Sequential(NestMLP(), nn.Linear(16, 20), FixedHiddenMLP())
Y = chimera(X)
print(Y)
~~~







参数管理

~~~python
import torch
from torch import nn

# 构建单隐藏层的多层感知机
net = nn.Sequential(nn.Linear(4, 8), nn.ReLU(), nn.Linear(8, 1))
X = torch.rand(size=(2, 4))
Y = net(X)
print(Y)

# 访问第二个全连接层的参数
print(net[2].state_dict())

# 访问目标参数
print(type(net[2].bias))
print(net[2].bias)
print(net[2].bias.data)

# 未反向求梯度，梯度为空
net[2].weight.grad == None

# 一次性访问所有参数
print(*[(name, param.shape) for name, param in net[0].named_parameters()])
print(*[(name, param.shape) for name, param in net.named_parameters()])

# 访问参数的特殊形式
net.state_dict()['2.bias'].data

# 从嵌套块中收集参数
def block1():
    return nn.Sequential(nn.Linear(4, 8), nn.ReLU(), nn.Linear(8, 4), nn.ReLU())

def block2():
    net = nn.Sequential()
    for i in range(4):
        # 在这里开始嵌套
        net.add_module(f'block{i}', block1())
    return net

rgnet = nn.Sequential(block2(), nn.Linear(4, 1))
Y = rgnet(X)
print(Y)

print(rgnet)

# 访问特定层
print(rgnet[0][1][0].bias.data)







# 参数初始化
def init_module(m):
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, mean=0, std=0.01)
        nn.init.zeros_(m.bias)

net.apply(init_module)
print(net[0].weight.data, net[0].bias.data)



# 针对不同的块使用不同的初始化
def init_xavier(m):
    if type(m) == nn.Linear:
        nn.init.xavier_uniform_(m.weight)

def init42(m):
    if type(m) == nn.Linear:
        # 全都初始化为42
        nn.init.constant_(m.weight, 42)

net[0].apply(init_xavier)
net[2].apply(init42)
print(net[0].weight.data[0])
print(net[2].weight.data)







# 自定义初始化
def my_init(m):
    if type(m) == nn.Linear:
        print("Init", *[(name, param.shape)
                        for name, param in m.named_parameters()][0])
        nn.init.uniform_(m.weight, -10, 10)
        m.weight.data *= m.weight.data.abs() >= 5

net.apply(my_init)
print(net[0].weight[:2])


# 共享参数
shared = nn.Linear(8, 8)
net = nn.Sequential(nn.Linear(4, 8), nn.ReLU(),
                    shared, nn.ReLU(),
                    shared, nn.ReLU(),
                    nn.Linear(8, 1))
net(X)
# 检查参数是否相同
print(net[2].weight.data[0] == net[4].weight.data[0])
net[2].weight.data[0, 0] = 100
# 确保它们实际上是同一个对象，而不只是有相同的值
print(net[2].weight.data[0] == net[4].weight.data[0])

~~~







### 自定义层

~~~python
import torch
import torch.nn.functional as F
from torch import nn



# 自定义不带参数的层
class CenteredLayer(nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, X):
        return X - X.mean()
    
layer = CenteredLayer()
X = torch.FloatTensor([1, 2, 3, 4, 5])
Y = layer(X)
print(Y)


# 组合层
net = nn.Sequential(nn.Linear(8, 128), CenteredLayer())
X = torch.rand(4, 8)
Y = net(X)
print(Y.mean())







# 自定义带参数的层
class MyLinear(nn.Module):
    def __init__(self, in_units, units):
        super().__init__()
        self.weight = nn.Parameter(torch.randn(in_units, units))
        self.bias = nn.Parameter(torch.randn(units,))
    def forward(self, X):
        linear = torch.matmul(X, self.weight.data) + self.bias.data
        return F.relu(linear)
    
Linear = MyLinear(5, 3)
print(Linear.weight)

X = torch.rand(2, 5)
Y = Linear(X)
print(Y)

net = nn.Sequential(MyLinear(64, 8), MyLinear(8, 1))
X = torch.rand(2, 64)
print(Y)
~~~







### 模型参数的存储和读取

~~~python
import torch
from torch import nn
from torch.nn import functional as F


# 存储张量
x = torch.arange(4)
torch.save(x, 'x-file')

# 读取张量
x2 = torch.load('x-file')
print(x2)




# 存储张量列表
y = torch.zeros(4)
torch.save([x, y],'x-files')
x2, y2 = torch.load('x-files')
print(x2, y2)




# 存储张量字典
mydict = {'x': x, 'y': y}
torch.save(mydict, 'mydict')
mydict2 = torch.load('mydict')
mydict2








# 加载和保存模型参数
class MLP(nn.Module):
    def __init__(self):
        super().__init__()
        self.hidden = nn.Linear(20, 256)
        self.output = nn.Linear(256, 10)

    def forward(self, x):
        return self.output(F.relu(self.hidden(x)))

net = MLP()
X = torch.randn(size=(2, 20))
Y = net(X)

# 将模型的参数存储在一个叫做“mlp.params”的文件中
torch.save(net.state_dict(), 'mlp.params')

# 实例化了原始多层感知机模型的一个备份
clone = MLP()
# 不需要随机初始化模型参数，而是直接读取文件中存储的参数
clone.load_state_dict(torch.load('mlp.params'))
print(clone.eval())
# 由于两个实例具有相同的模型参数，在输入相同的X时， 两个实例的计算结果应该相同
Y_clone = clone(X)
Y_clone == Y
~~~





## 2.使用GPU

### 查看GPU个数

~~~python
import torch
from torch import nn


# 返回GPU
print(torch.device('cpu'), torch.device('cuda'), torch.device('cuda:1'))
print(torch.cuda.device_count())
~~~





# 五、卷积神经网络

## 1.图像卷积（卷积层）









## 2.填充和步幅

填充：在应用多层卷积时，我们常常会丢失边缘像素。随着我们使用许多的连续卷积层，累计丢失的像素就越多。为了解决以上问题，我们在输入的图像边界填充多个0，简称填充。



步幅：为了高效计算或缩减采样次数，我们使用卷积窗口每次滑动多个元素，加快卷积速度，我们将每次滑动元素的数量称为步幅。







## 3.多输入多输出通道

多输入通道：当输入包含多个通道时，我们需要构造一个与输入数据具有相同通道数的卷积核。



多输出通道：我们把不同的输出通道看作对不同特征的响应，在对一个输入进行卷积运算时可以设置多个卷积核，得到的输出是多通道的，简称多通道输出。







## 4.汇聚层（池化层）

池化：将卷积层得到的结果用窗口进行滑动分割，类似于卷积层中的窗口里的元素进行运算和窗口的滑动，但是池化层中的窗口里的元素是取最大值或平均值，不进行运算，然后得到一个新的多维矩阵。

最大汇聚层：在进行池化时，取窗口里的元素最大值作为新的元素，最后得到一个多维矩阵；经过卷积层和最大汇聚层得到的图像边界区分明显。



平均汇聚层：在进行池化时，取窗口里的元素平均值作为新的元素，最后得到一个多维矩阵；经过卷积层和平均汇聚层得到的图像边界区分不明显。





## 5.经典卷积神经网络——LeNet

主要区别：激活函数使用sigmoid，池化层使用AvgPooling（平均池化层），最后全连接层做Softmax回归输出。

![image-20260309215901727](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260309215901727.png)

![image-20260309215931168](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260309215931168.png)



代码实现

LeNet.py

~~~python
import torch
from torch import nn
from d2l import torch as d2l



class LeNet(nn.Module):
    def __init__(self):
        super(LeNet, self).__init__()
        self.conv1 = nn.Conv2d(1, 6, 5, 2)
        self.pool = nn.AvgPool2d(2, 2)
        self.conv2 = nn.Conv2d(6, 16, 5)
        self.fc1 = nn.Linear(16 * 1 * 1, 120)
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)
        self.sgd = nn.Sigmoid()
        self.flt = nn.Flatten()

    def forward(self, x):
        x = self.conv1(x)
        x = self.sgd(x)
        x = self.pool(x)
        x = self.conv2(x)
        x = self.sgd(x)
        x = self.pool(x)
        x = self.flt(x)
        x = self.fc1(x)
        x = self.sgd(x)
        x = self.fc2(x)
        x = self.sgd(x)
        x = self.fc3(x)
        return x


~~~



train.py

~~~python
import torch
from torch import nn
from d2l import torch as d2l
from LeNet import LeNet


def evaluate_accuracy_gpu(net, data_iter, device=None): #@save
    """使用GPU计算模型在数据集上的精度"""
    if isinstance(net, nn.Module):
        net.eval()  # 设置为评估模式
        if not device:
            device = next(iter(net.parameters())).device
    # 正确预测的数量，总预测的数量
    metric = d2l.Accumulator(2)
    with torch.no_grad():
        for X, y in data_iter:
            if isinstance(X, list):
                # BERT微调所需的（之后将介绍）
                X = [x.to(device) for x in X]
            else:
                X = X.to(device)
            y = y.to(device)
            metric.add(d2l.accuracy(net(X), y), y.numel())
    return metric[0] / metric[1]



def train_ch6(net, train_iter, test_iter, num_epochs, lr, device):
    """用GPU训练模型(在第六章定义)"""
    def init_weights(m):
        if type(m) == nn.Linear or type(m) == nn.Conv2d:
            nn.init.xavier_uniform_(m.weight)
    net.apply(init_weights)
    print('training on', device)
    net.to(device)
    optimizer = torch.optim.SGD(net.parameters(), lr=lr)
    loss = nn.CrossEntropyLoss()
    animator = d2l.Animator(xlabel='epoch', xlim=[1, num_epochs],
                            legend=['train loss', 'train acc', 'test acc'])
    timer, num_batches = d2l.Timer(), len(train_iter)
    for epoch in range(num_epochs):
        # 训练损失之和，训练准确率之和，样本数
        metric = d2l.Accumulator(3)
        net.train()
        for i, (X, y) in enumerate(train_iter):
            timer.start()
            optimizer.zero_grad()
            X, y = X.to(device), y.to(device)
            y_hat = net(X)
            l = loss(y_hat, y)
            l.backward()
            optimizer.step()
            with torch.no_grad():
                metric.add(l * X.shape[0], d2l.accuracy(y_hat, y), X.shape[0])
            timer.stop()
            train_l = metric[0] / metric[2]
            train_acc = metric[1] / metric[2]
            if (i + 1) % (num_batches // 5) == 0 or i == num_batches - 1:
                animator.add(epoch + (i + 1) / num_batches,
                             (train_l, train_acc, None))
        test_acc = evaluate_accuracy_gpu(net, test_iter)
        animator.add(epoch + 1, (None, None, test_acc))
    print(f'loss {train_l:.3f}, train acc {train_acc:.3f}, '
          f'test acc {test_acc:.3f}')
    print(f'{metric[2] * num_epochs / timer.sum():.1f} examples/sec '
          f'on {str(device)}')






if __name__ == '__main__':
    batch_size = 256
    train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size=batch_size)

    net = LeNet()

    lr, num_epochs = 0.9, 10
    train_ch6(net, train_iter, test_iter, num_epochs, lr, d2l.try_gpu())


~~~















# 六、现代卷积神经网络

## 1.深度卷积神经网络——AlexNet

主要区别：激活函数使用ReLu，池化层使用MaxPooling（最大池化层），训练模型使用Dropout（丢弃法）。

![image-20260310094743473](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260310094743473.png)

总结：AlexNet是更大更深的LeNet，新进入了丢弃法、ReLu和数据增强；架构区别在于在LeNet架构基础上多加入了3个卷积层。





代码实现

AlexNet.py

~~~python
import torch
from torch import nn
from d2l import torch as d2l

class AlexNet(nn.Module):
    def __init__(self, num_classes=10):
        super(AlexNet, self).__init__()
        self.features = nn.Sequential(
            nn.Conv2d(1, 96, kernel_size=11, stride=4, padding=1),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(kernel_size=3, stride=2),
            nn.Conv2d(96, 256, kernel_size=5, padding=2),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(kernel_size=3, stride=2),

            nn.Conv2d(256, 384, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(384, 384, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(384, 256, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(kernel_size=3, stride=2),
            nn.Flatten()
        )

        self.classifier = nn.Sequential(
            nn.Linear(6400, 4096),
            nn.ReLU(inplace=True),
            nn.Dropout(p=0.5),
            nn.Linear(4096, 4096),
            nn.ReLU(inplace=True),
            nn.Dropout(p=0.5),
            nn.Linear(4096, num_classes),
        )

    def forward(self, x):
        x = self.features(x)
        x = x.view(x.size(0), -1)
        x = self.classifier(x)
        return x
~~~



train.py

~~~python
import torch
from torch import nn
from d2l import torch as d2l
from AlexNet import AlexNet


device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(device)

if __name__ == '__main__':

    net = AlexNet()

    batch_size = 128
    train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size, resize=224)

    lr, num_epochs = 0.01, 10
    d2l.train_ch6(net, train_iter, test_iter, num_epochs, lr, device)
~~~















## 2.使用块的网络——VGG

VGG块的思想：将AlexNet中连续不规则的卷积层替换成规则的卷积块，即将多个连续的卷积层组合成一个块，然后替换原来连续不规则的卷积层。同时每个卷积块中有n个卷积层，每个卷积块的超参数（卷积层个数和输出通道数）自定义。

架构

![image-20260310101626571](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260310101626571.png)

总结：将卷积层组合成块，通过组合卷积块，最后连接3个全连接层，构建深度卷积神经网络。



代码实现

VGG.py

~~~python
import torch
from torch import nn
from d2l import torch as d2l


def vgg_block(num_convs, in_channels, out_channels):
    layers = []
    for _ in range(num_convs):
        layers.append(nn.Conv2d(in_channels, out_channels, kernel_size=3, padding=1))
        layers.append(nn.ReLU(inplace=True))
        in_channels = out_channels
    layers.append(nn.MaxPool2d(kernel_size=2, stride=2))
    return nn.Sequential(*layers)


def vgg(conv_arch):
    conv_blks = []
    in_channels = 1
    for (num_convs, out_channels) in conv_arch:
        conv_blks.append(vgg_block(num_convs, in_channels, out_channels))
        in_channels = out_channels
    return nn.Sequential(*conv_blks)


def vgg11():
    conv_arch = ((1, 64), (1, 128), (2, 256), (2, 512), (2, 512))

    ratio = 4
    small_conv_arch = [(pair[0], pair[1] // ratio) for pair in conv_arch]
    return vgg(small_conv_arch)


class VGG(nn.Module):
    def __init__(self, num_classes=10):
        super(VGG, self).__init__()
        self.features = nn.Sequential(
            vgg11(),
            nn.AdaptiveAvgPool2d((7, 7))
        )
        self.classifier = nn.Sequential(
            nn.Linear(128 * 7 * 7, 4096),
            nn.ReLU(True),
            nn.Dropout(p=0.5),
            nn.Linear(4096, 4096),
            nn.ReLU(True),
            nn.Dropout(p=0.5),
            nn.Linear(4096, num_classes),
        )

    def forward(self, x):
        x = self.features(x)
        x = torch.flatten(x, 1)
        x = self.classifier(x)
        return x

~~~



train.py

~~~python
import torch
from torch import nn
from d2l import torch as d2l
from VGG import VGG
import matplotlib.pyplot as plt


device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(device)

if __name__ == '__main__':
    net = VGG()

    lr, num_epochs, batch_size = 0.05, 10, 128
    train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size, resize=224)
    d2l.train_ch6(net, train_iter, test_iter, num_epochs, lr, device)

    plt.show()

~~~











## 3.网络中的网络——NiN

NiN块的思想：由于AlexNet和VGG的全连接层的参数数目较大，加大了对内存的占用，十分昂贵；NiN块的思想是为了解决全连接层的问题，通过将1个卷积层与2个1x1的卷积层（等效于2个全连接层）组合成一个NiN块，替代全连接层的使用，从而解决全连接层占用庞大内存的问题。

架构：每个NiN块后连接一个MaxPooling（最大池化层），最后的NiN块后连接一个全局AvgPooling（全局平均池化层）。

![image-20260310121621326](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260310121621326.png)





代码实现

NiN.py

~~~python
import torch
from torch import nn
from d2l import torch as d2l


def nin_block(in_channels, out_channels, kernel_size, stride, padding):
    return nn.Sequential(
        nn.Conv2d(in_channels, out_channels, kernel_size, stride=stride, padding=padding),
        nn.ReLU(inplace=True),
        nn.Conv2d(out_channels, out_channels, kernel_size=1, stride=1, padding=0),
        nn.ReLU(inplace=True),
        nn.Conv2d(out_channels, out_channels, kernel_size=1, stride=1, padding=0),
        nn.ReLU(inplace=True)
    )


class NiN(nn.Module):
    def __init__(self):
        super(NiN, self).__init__()
        self.features = nn.Sequential(nin_block(1, 96, 11,4,0),
            nn.MaxPool2d(3, 2),
            nin_block(96, 256, 5,1,2),
            nn.MaxPool2d(3, 2),
            nin_block(256, 384, 3,1,1),
            nn.MaxPool2d(3, 2),
            nn.Dropout2d(0.5),
            nin_block(384, 10, 3,1,1),
            nn.AdaptiveAvgPool2d((1, 1)),
            nn.Flatten()
        )

        # 没有全连接层

    def forward(self, x):
        return self.features(x)
~~~



train.py

~~~python
import torch
from torch import nn
from d2l import torch as d2l
from NiN import NiN
import matplotlib.pyplot as plt


device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(device)

if __name__ == '__main__':
    net = NiN()

    lr, num_epochs, batch_size = 0.1, 10, 128
    train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size, resize=224)
    d2l.train_ch6(net, train_iter, test_iter, num_epochs, lr, device)

    plt.show()
~~~



## 4.含并行连接的网络——GoogLeNet

Inception块：在GoogLeNet中，基本的卷积块被称为Inception块。

Inception块由4条并行路径组成，每条路径是不同设计的卷积层组合，这4条路径都使用合适的填充使得输入和输出的高和宽一致，最后将4条路线的输出在输出通道维度上连接，作为Inception块的输出。

在Inception块中，通常调整的超参数为每条路径的输出通道数。

![image-20260310150018094](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260310150018094.png)







架构：整个网络由5个stage组成，前2个stage是2个（卷积层+池化层），中间有个1x1卷积层进行通道融合，后面3个stage是3个（Inception块+池化层），其中最后一层池化层是AvgPooling；最后在末尾加1层全连接层进行分类处理。

![image-20260310150158076](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260310150158076.png)

总结：使用GoogLeNet是为了降低模型的Paramters（参数数量）和Flops（计算量）



代码实现

GoogLeNet.py

~~~python
import torch
from torch import nn
from torch.nn import functional as F
from d2l import torch as d2l


class Inception(nn.Module):
    def __init__(self, in_channels, c1, c2, c3, c4, **kwargs):
        super(Inception, self).__init__(**kwargs)
        self.p1_1 = nn.Conv2d(in_channels, c1, kernel_size=1)
        self.p2_1 = nn.Conv2d(in_channels, c2[0], kernel_size=1)
        self.p2_2 = nn.Conv2d(c2[0], c2[1], kernel_size=3, padding=1)
        self.p3_1 = nn.Conv2d(in_channels, c3[0], kernel_size=1)
        self.p3_2 = nn.Conv2d(c3[0], c3[1], kernel_size=5, padding=2)
        self.p4_1 = nn.MaxPool2d(kernel_size=3, stride=1, padding=1)
        self.p4_2 = nn.Conv2d(in_channels, c4, kernel_size=1)


    def forward(self, x):
        p1 = F.relu(self.p1_1(x))
        p2 = F.relu(self.p2_2(F.relu(self.p2_1(x))))
        p3 = F.relu(self.p3_2(F.relu(self.p3_1(x))))
        p4 = F.relu(self.p4_2(F.relu(self.p4_1(x))))

        return torch.cat((p1, p2, p3, p4), dim=1)


class GoogLeNet(nn.Module):
    def __init__(self, num_classes=10):
        super(GoogLeNet, self).__init__()
        self.b1 = nn.Sequential(nn.Conv2d(1, 64, kernel_size=7, stride=2, padding=3),
                           nn.ReLU(),
                           nn.MaxPool2d(kernel_size=3, stride=2, padding=1))
        self.b2 = nn.Sequential(nn.Conv2d(64, 64, kernel_size=1),
                           nn.ReLU(),
                           nn.Conv2d(64, 192, kernel_size=3, padding=1),
                           nn.ReLU(),
                           nn.MaxPool2d(kernel_size=3, stride=2, padding=1))
        self.b3 = nn.Sequential(Inception(192, 64, (96, 128), (16, 32), 32),
                   Inception(256, 128, (128, 192), (32, 96), 64),
                   nn.MaxPool2d(kernel_size=3, stride=2, padding=1))
        self.b4 = nn.Sequential(Inception(480, 192, (96, 208), (16, 48), 64),
                           Inception(512, 160, (112, 224), (24, 64), 64),
                           Inception(512, 128, (128, 256), (24, 64), 64),
                           Inception(512, 112, (144, 288), (32, 64), 64),
                           Inception(528, 256, (160, 320), (32, 128), 128),
                           nn.MaxPool2d(kernel_size=3, stride=2, padding=1))
        self.b5 = nn.Sequential(Inception(832, 256, (160, 320), (32, 128), 128),
                           Inception(832, 384, (192, 384), (48, 128), 128),
                           nn.AdaptiveAvgPool2d((1, 1)),
                           nn.Flatten())

        self.net = nn.Sequential(self.b1, self.b2, self.b3, self.b4, self.b5, nn.Linear(1024, num_classes))


    def forward(self, x):
        x = self.net(x)
        return x

~~~



train.py

~~~python
import torch
from torch import nn
from d2l import torch as d2l
from GoogLeNet import GoogLeNet
import matplotlib.pyplot as plt


device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(device)

if __name__ == '__main__':
    net = GoogLeNet()

    lr, num_epochs, batch_size = 0.1, 10, 128
    train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size, resize=96)
    d2l.train_ch6(net, train_iter, test_iter, num_epochs, lr, device)

    plt.show()
~~~



## 5.批量归一化——Batch Normal

问题：在训练深层神经网络时，存在收敛速度慢的问题；

在进行数据预处理时，通常采用归一化，将参数的量级进行统一；在进行深层神经网络训练时，中间的参数可变化的范围较大，这些变量分布中的这种偏移可能会阻碍网络的收敛；深层网络复杂，训练容易过拟合，必须采用正则化（归一化）。

![屏幕截图 2026-03-10 155741](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-10 155741.png)

![屏幕截图 2026-03-10 155840](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-10 155840.png)

总结：使用批量归一化固定小批量中的均值和方差，然后学习出合适的偏移和缩放；可以加快训练收敛速度，但一般不改变模型精度。





## 6.残差网络——ResNet

问题：深层神经网络过深，会导致在训练中存在梯度消失的问题。

残差块：将一个正常的卷积块计算结果和输入（或做1x1卷积之后）同时合并作为下一层的输入。在残差块中，输入可通过跨层数据线路更快的向前传播。

![image-20260310181449077](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260310181449077.png)



需要保证卷积块运算之后的通道数与输入（或做1x1卷积之后）的通道数相同

![image-20260310182049113](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260310182049113.png)



架构：与GoogLeNet类似，区别在于ResNet的每层卷积层之后加入Batch Normal（批量归一化层），并且将GoogLeNet中的4个Inception块替换成4个残差块，最后接入AvgPooling（全局平均池化层）+全连接层。

![image-20260310183044651](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260310183044651.png)

总结：ResNet使用残差块可以解决梯度消失的问题，可以使很深的神经网络更加容易训练。





代码实现

ResNet.py

~~~python
import torch
from torch import nn
from torch.nn import functional as F
from d2l import torch as d2l

class Residual(nn.Module):
    def __init__(self, input_channels, num_channels,
                 use_1x1conv=False, strides=1):
        super(Residual, self).__init__()
        self.conv1 = nn.Conv2d(input_channels, num_channels, kernel_size=3, stride=strides, padding=1)
        self.conv2 = nn.Conv2d(num_channels, num_channels, kernel_size=3, padding=1)

        if use_1x1conv:
            self.conv3 = nn.Conv2d(input_channels, num_channels, kernel_size=1, stride=strides, padding=0)
        else:
            self.conv3 = None

        self.bn1 = nn.BatchNorm2d(num_features=num_channels)
        self.bn2 = nn.BatchNorm2d(num_features=num_channels)

    def forward(self, x):
        Y = F.relu(self.bn1(self.conv1(x)))
        Y = self.bn2(self.conv2(Y))
        if self.conv3:
            x = self.conv3(x)
        Y += x
        return F.relu(Y)


def resnet_block(input_channels, num_channels, num_residuals,
                 first_block=False):
    blk = []
    for i in range(num_residuals):
        if i == 0 and not first_block:
            blk.append(Residual(input_channels, num_channels,
                                use_1x1conv=True, strides=2))
        else:
            blk.append(Residual(num_channels, num_channels))
    return blk


class ResNet(nn.Module):
    def __init__(self):
        super(ResNet, self).__init__()
        self.b1 = nn.Sequential(nn.Conv2d(1, 64, kernel_size=7, stride=2, padding=3),
                   nn.BatchNorm2d(64), nn.ReLU(),
                   nn.MaxPool2d(kernel_size=3, stride=2, padding=1))

        self.b2 = nn.Sequential(*resnet_block(64, 64, 2, first_block=True))
        self.b3 = nn.Sequential(*resnet_block(64, 128, 2))
        self.b4 = nn.Sequential(*resnet_block(128, 256, 2))
        self.b5 = nn.Sequential(*resnet_block(256, 512, 2))

        self.net = nn.Sequential(self.b1, self.b2, self.b3, self.b4, self.b5,
                            nn.AdaptiveAvgPool2d((1, 1)),
                            nn.Flatten(), nn.Linear(512, 10))
    def forward(self, x):
        return self.net(x)

~~~





train.py

~~~python
import torch
from torch import nn
from d2l import torch as d2l
from ResNet import ResNet
import matplotlib.pyplot as plt

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(device)

if __name__ == '__main__':
    net = ResNet()

    lr, num_epochs, batch_size = 0.05, 10, 256
    train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size, resize=96)
    d2l.train_ch6(net, train_iter, test_iter, num_epochs, lr, device)

    plt.show()

~~~





# 七、计算性能

## 1.深度学习硬件——CUP和GPU、TPU和其他

## 2.单机多卡并行

## 3.多GPU训练实现

## 4.分布式训练

## 







# 八、计算机视觉

## 1.数据增广

数据增广通过变形数据来获取多样性从而使模型泛化性能更好

常见图片增广包括翻转、切割、变色





## 2.微调

微调通过使用在大数据上得到的预训练好的模型来初始化模型权重，完成精度提升；预训练模型质量很重要，一般使用较大较好的数据训练；微调通常速度更快，精度更高。

固定一些层：在已经预训练好的模型中，低层次的特征更加通用，高层次的特征则更加依赖数据集。微调时，可以固定底部一些层的参数，不参与更新。





## 3.目标检测和边界框

目标检测识别图片里的多个物体的类别和位置，位置通常用边缘框表示，而图片分类一张图片只有一个主体目标。







## 4.锚框

意图：以每个像素为中心，生成多个缩放比和宽高比（aspect ratio）不同的边界框，这些边界框被称为锚框。然后设计一个基于锚框的目标检测模型。



在训练数据集中标注锚框：在训练模型时，通常在训练数据集的每个图片中生成多个锚框，然后计算每个锚框与真实边界框的loU（交并比），然后每次选出所有锚框中最大loU值的锚框，并为其标注类别号和与真实边界框的偏移量，然后认为该锚框对应于该标注的类别，去除该锚框与其他类别的loU值，以及去除该锚框所对应的类别与其他锚框的loU值，再次选出剩余锚框中的最大loU值的锚框，以此循环操作。

![image-20260310210632068](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260310210632068.png)



使用非极大值抑制预测边界框：在预测时，我们先为图像生成多个锚框，这些锚框标注有预测类别和偏移量；当有许多锚框时，可能会输出许多相似的具有明显重叠的预测边界框，都围绕着同一目标。 为了简化输出，我们可以使用非极大值抑制（NMS）合并属于同一目标的类似的预测边界框。

![image-20260310210650833](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260310210650833.png)![image-20260310210708579](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260310210708579.png)

总结：一类目标检测算法是基于锚框来预测；首先生成大量锚框，并赋予标号，每个锚框作为一个样本进行训练；在预测时，使用NMS来去除冗余的预测。











## 5.物体检测算法——R-CNN、SSD、YOLO

R-CNN：先选取锚框，然后对每个锚框抽取特征，最后对每个锚框进行分类。

![image-20260311154103058](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260311154103058.png)

![屏幕截图 2026-03-11 154147](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-11 154147.png)



Fast R-CNN：先对整个图片做卷积层抽取特征，而不是对每个锚框抽取特征。

![屏幕截图 2026-03-11 154308](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-11 154308.png)



Faster R-CNN：在Fast-RCNN的基础上，将Selective search层替换成一个（Region proposal network）网络，通过该网络对生成的锚框进行选择，选择出好的锚框（锚框圈住了物体），然后进入Rol pooling层。

![image-20260311154911667](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260311154911667.png)



Mask R-CNN：在Faster-RCNN的基础上，将Rol pooling层替换成Rol align层，进行像素级别的标号。

![屏幕截图 2026-03-11 155632](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-11 155632.png)





单发多框检测——SSD

![屏幕截图 2026-03-11 160621](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-11 160621.png)

实验：



YOLO

![屏幕截图 2026-03-11 161641](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-11 161641.png)







## 6.语义分割和数据集

语义分割：对图片中的每个像素分类到对应的类别。

![屏幕截图 2026-03-11 162244](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-11 162244.png)



实验：





## 7.转置卷积

问题：输入通过卷积运算之后，一般会降低高和宽或者不变，但是可以通过转置卷积运算，使得高和宽增大。



原理：将输入的每一个元素与卷积核整体中的每一个元素做乘法运算，最后得到一个与卷积核同样大小的张量，最后输入的每一个元素与卷积核做运算之后得到的张量合并在一起，得到转置卷积的结果。

![image-20260311163951655](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260311163951655.png)



目的：使用转置卷积可以将每一个像素点的特征都提取到和做深层的网络特征特征提取，避免像素点信息的丢失。



## 8.全连接卷积神经网络——FCN

问题与解决：语义分割是对图片中的每个像素进行分类，而之前的图像分类和目标检测的卷积神经网络会将输入的图像的高宽变小使得像素的信息丢失，无法对每个像素进行分类预测。采用全连接卷积神经网络，通过转置卷积，将中间层特征图的高和宽变换回输入图像的尺寸，避免输入图像像素信息的损失，并且输出的类别预测与输入图像的每个像素一一对应。



架构

![屏幕截图 2026-03-11 193620](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-11 193620.png)







## 9.样式迁移

理解：输入一个内容图片和一个样式图片，我们希望提取内容图片中的内容和样式图片的样式融合成一个图片。

方法：利用同一个CNN模型分别做两个图像的特征提取，使得提取内容特征的损失和提取样式特征的损失达到最小，并且噪声最小，进而找到在该情形下预测生成的图片。

![image-20260311194350432](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260311194350432.png)







# 九、循环神经网络

## 1.序列模型

理解：时序模型中，当前数据跟之前观察的数据相关。



自回归模型：使用历史数据来预测未来数据。

![image-20260311202721725](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260311202721725.png)



马尔科夫模型：假设当前数据只跟最近少数数据相关，从而简化了模型。

![image-20260311202804334](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260311202804334.png)



潜变量模型：使用潜变量来概括历史信息。

![屏幕截图 2026-03-11 202947](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-11 202947.png)









## 2.文本预处理

实验：













## 3.语言模型

理解：语言模型是用来估计文本序列的联合概率，就是根据之前的语言来预测下一个语言会是某个句子或者词的概率。

![image-20260311210922665](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260311210922665.png)





使用计数来建模

![屏幕截图 2026-03-11 211053](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-11 211053.png)



N元语法：不是所有的句子都会组合在一起，总会有一个最大值。

![image-20260311211327082](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260311211327082.png)







## 4.循环神经网络——RNN

理解：循环神经网络的输出取决于当下输入和前一时间的隐变量。应用到语言模型中时，是根据当前的输入词来预测下一时刻词。

区别：与之前的MLP不同之处在于加入了隐藏层的状态更新处理，并且当前的隐藏层状态更新依赖于之前的隐藏层的状态，通过添加参数Whh（存储时序信息）来更新当前隐藏层。

![image-20260312145536072](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312145536072.png)





使用困惑度来衡量语言模型的好坏

理解：困惑度可以理解为给定当前输入词预测下输出词出现的种类个数，如果种类太多表示预测不能精确到一个词，模型不好。

![image-20260312152300958](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312152300958.png)



梯度裁剪

理解：由于RNN是根据时间步的长度来确定隐藏层的长度，所以如果时间步太长，会导致隐藏层变长，反向传播求梯度时会造成梯度爆炸的问题。需要梯度裁剪，将梯度的长度控制在一定范围内，有效预防梯度爆炸问题。

![image-20260312152409804](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312152409804.png)





RNN的应用

![image-20260312152834172](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312152834172.png)



RNN的实现

从零开始实现









学习框架实现











# 十、现代循环神经网络

## 1.门控循环单元——GRU

理解：由于RNN需要保存之前的隐藏层状态，但是有些状态出现的概率较小，有些状态出现的概率较大，所以之后在更新隐藏层的时候就可以侧重的保存之前的状态。这里使用类似门控电路来决策新隐藏层的产生。

![image-20260312155506474](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312155506474.png)



门：分为重置门Rt和更新门Zt，重置门Rt的每一个元素都为0则表示需要重置，更新门Zt的每一个元素都为0则表示需要更新。

![image-20260312155606104](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312155606104.png)





候选隐状态：通过重置门Rt来决定保留之前隐状态中的哪些元素，最后通过激活函数tanh来产生新的候选隐状态。

![image-20260312160124808](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312160124808.png)





隐状态：通过更新门Zt来决定保留原始隐状态中的哪些元素，以及来决定需要保留候选隐状态的哪些元素。

![image-20260312160445474](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312160445474.png)



整体架构

![image-20260312160817320](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312160817320.png)



实验

~~~python
import torch
from torch import nn
from d2l import torch as d2l
import matplotlib.pyplot as plt


device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(device)

if __name__ == '__main__':
    batch_size, num_steps = 32, 35
    train_iter, vocab = d2l.load_data_time_machine(batch_size, num_steps)

    vocab_size, num_hiddens = len(vocab), 256
    num_epochs, lr = 500, 1

    num_inputs = vocab_size
    gru_layer = nn.GRU(num_inputs, num_hiddens)
    model = d2l.RNNModel(gru_layer, len(vocab))
    model = model.to(device)
    d2l.train_ch8(model, train_iter, vocab, lr, num_epochs, device)

    plt.show()
~~~





## 2.长短期记忆网络——LSTM

理解：与门控循环单元（GRU）的功能类似，都是为了保留出现次数多的隐状态的元素来生成新的隐状态，只是LSTM比GRU复杂。



3个门：忘记门Ft，输入门It，输出门Ot。

![image-20260312162707516](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312162707516.png)



候选记忆单元：和RNN计算隐藏层类似。

![image-20260312162823338](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312162823338.png)





记忆单元：通过忘记门Ft来决定记住之前记忆单元Ct-1的状态。

![image-20260312163044398](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312163044398.png)





隐状态：通过输出门Ot来决定是否保留记忆单元的状态，如果当前输出为0表示后面不要保留当前记忆单元的状态。

![image-20260312163248867](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312163248867.png)





整体架构：通过输入门It、忘记门Ft、输出门Ot和记忆单元Ct，来控制保留之前隐状态的重要信息，生成新的隐状态。

![image-20260312163553178](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312163553178.png)



实验

~~~python
import torch
from torch import nn
from d2l import torch as d2l
import matplotlib.pyplot as plt


device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(device)

if __name__ == '__main__':
    batch_size, num_steps = 32, 35
    train_iter, vocab = d2l.load_data_time_machine(batch_size, num_steps)

    vocab_size, num_hiddens = len(vocab), 256
    num_epochs, lr = 500, 1

    num_inputs = vocab_size
    lstm_layer = nn.LSTM(num_inputs, num_hiddens)
    model = d2l.RNNModel(lstm_layer, len(vocab))
    model = model.to(device)
    d2l.train_ch8(model, train_iter, vocab, lr, num_epochs, device)

    plt.show()
~~~





## 3.深度循环神经网络

理解：之前的GRU和LSTM都只有一层隐藏层，而为了使网络更深可以在输入和输出之间加入多层隐藏层，并且当前隐藏层的隐状态依赖于底部的下一层隐藏层的隐状态和当前层前一个隐藏层的隐状态。

![image-20260312165137706](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312165137706.png)



计算方式

![image-20260312165223578](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312165223578.png)



总结：深度循环神经网络使用多层隐藏层来获取更多的非线性性。





## 4.双向循环神经网络

理解：之前的RNN只有一个方向的隐藏层传递信息，只依靠过去的隐状态来预测当前的隐状态，而不能使用未来的隐状态来预测当前的隐状态。在一些填空的单词的预测下，我们可以通过双向循环神经网络同时获取过去和未来的隐状态来预测当前的隐状态，进而预测当前单词。

![image-20260312170716417](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312170716417.png)



架构和计算方式：同时进行两个方向的隐藏层状态的预测，然后合并两个方向的隐藏层状态，输出预测结果。

![image-20260312170817813](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312170817813.png)



总结：双向循环神经网络只能用在训练上，而不能用在推理。通过反向更新的隐藏层来利用方向时间信息。通常用来对序列抽取特征、填空，而不是预测未来。



## 5.机器翻译数据集

实验









## 6.编码器-解码器架构——Encoder、Decoder

理解：Encoder负责将输入转换成状态，而Decoder负责将状态转换成需要的输出。

![image-20260312172507385](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312172507385.png)

实验

~~~python
from torch import nn

class Encoder(nn.Module):
    def __init__(self, **kwargs):
        super(Encoder, self).__init__(**kwargs)

    def forward(self, x, *args):
        raise NotImplementedError

class Decoder(nn.Module):
    def __init__(self, **kwargs):
        super(Decoder, self).__init__(**kwargs)

    def init_state(self, enc_outputs, *args):
        raise NotImplementedError

    def forward(self, X, state):
        raise NotImplementedError
~~~



## 7.序列到序列学习——seq2seq

理解：Seq2seq从一个句子生成另一个句子，并且使用Encoder和Decoder架构，编码器和解码器都是RNN，将编码器的最后隐状态来初始解码器隐状态来完成信息传递。



架构

![image-20260312194433981](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312194433981.png)



编码器-解码器的细节

![image-20260312194516836](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312194516836.png)





训练：在训练时，解码器使用目标句子作为输入，而在推理时，解码器无法使用目标句子作为输入。

![image-20260312194618239](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312194618239.png)





衡量生成序列的好坏——使用BLEU

![image-20260312194914991](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312194914991.png)





## 8.束搜索

问题：在seq2seq中，使用贪心搜索来预测序列，在当前时刻预测概率最大的词输出，但是最后贪心得到的预测结果可能不是最优的。最优的算法是穷举所有预测结果的可能性，但是计算量太大无法实现。束搜索是在每次搜索时，保存k个最好的候选。

![image-20260312200350516](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312200350516.png)









# 十一、注意力机制

## 1.注意力机制

理解：向注意力池化层中加入查询，有偏向性的选择某些输入，使得随意（有目标性）的得到输出。

![image-20260312201429757](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312201429757.png)





非参注意力池化层：不需要参数来有偏向性的选择输入值，即不需要参数学习的注意力机制。

![image-20260312202336828](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312202336828.png)

![image-20260312202656819](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312202656819.png)





参数化的注意力机制：在非参注意力机制的基础上引入可以学习的参数w。

![image-20260312203024334](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312203024334.png)





总结：通过查询和key来进行有偏向性的选择输入，重点在对注意力权重的设计。

![image-20260312203255528](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312203255528.png)





## 2.注意力分数

理解：注意力分数是query和key的相似度，注意力权重注意力分数softmax的结果。

![image-20260312203850597](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312203850597.png)

![image-20260312205204368](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312205204368.png)





两种常见的注意力分数的计算

第一种：将query和key合并起来进入一个单输出单隐藏层的MLP

![image-20260312205254741](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312205254741.png)





第二种：直接将query和key做内积

![image-20260312205327753](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312205327753.png)





## 3.使用注意力机制的seq2seq

理解：在机器翻译中，每个词的翻译结果都与原句子的不同词相关。

![image-20260312210618984](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312210618984.png)



加入注意力：与之前的seq2seq不同的是，之前的seq2seq中直接拿编码器的最后一层RNN结果作为解码器的输入。而加入注意力后，将编码器的每次RNN的输出结果（作为key和value）和解码器的对上一个词的预测输出（作为query）合并进入注意力池化层中，然后计算出池化后的结果，将结果作为解码器的输入。

![image-20260312210732216](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312210732216.png)

总结：注意力机制可以根据解码器RNN的输出来匹配到合适的编码器RNN的输出，从而更有效的传递信息。





## 4.自注意力

理解：自注意力池化层将Xi当做key、value和query来对序列抽取特征，并且自注意力机制在计算每个Xi抽取特征是完全并行的，但对长序列计算复杂度较高。在

架构

![image-20260312214737028](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312214737028.png)



比较

![image-20260312214830890](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312214830890.png)





位置编码：与CNN和RNN不同，自注意力机制并没有记录位置信息，需要位置编码将信息注入到输入中。

![屏幕截图 2026-03-12 214858](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-12 214858.png)





总结：与CNN和RNN相比，自注意力机制抽取特征的对象选择不同，计算复杂度较高，需要位置编码使自注意力机制能够记忆位置信息。

![image-20260312215213290](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260312215213290.png)





## 5.Transformer

理解：基于编码器-解码器架构来处理序列对，跟使用注意力的seq2seq不同，Transformer是纯基于注意力。

![image-20260313093832659](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313093832659.png)





多头注意力：类似于CNN的多输出通道，多头注意力是通过h个独立的注意力池化，对同一key、value和query，希望抽取不同的信息，最后合并各个头输出得到最终输出。

![屏幕截图 2026-03-13 094813](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-13 094813.png)





![image-20260313095328672](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313095328672.png)





有掩码的多头注意力：由于解码器对序列中的一个元素输出时，不应该考虑该元素之后的元素，所以通过掩码掩盖后面的不考虑的元素。

![image-20260313095440110](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313095440110.png)





基于位置的前馈网络：等效一个全连接层，对序列中的每个元素做全连接，用于规范输入和输出的大小。

![屏幕截图 2026-03-13 095546](C:\Users\HP\Pictures\Screenshots\屏幕截图 2026-03-13 095546.png)





层归一化：通过残差路径和对每个样本的元素进行归一化，在预防梯度消失的同时加快了训练的速度。

![image-20260313095914045](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313095914045.png)





信息传递：类似于seq2seq加入注意力机制的做法，将编码器的输出作为解码器某个Transformer块中的多头注意力的key和value，并且它的query来自于目标序列。

![image-20260313100525132](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313100525132.png)





预测：在预测第t+1个输出时，在解码器的自注意力池化层中，输入前t个预测值，并将t个预测值作为key和value，第t个预测值作为query，最后输出第t+1的预测值。

![image-20260313100849426](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313100849426.png)





总结：Transformer是一个纯基于注意力机制的编码-解码器，并且编码器和解码器都有n个transformer块，每个块里使用多头注意力机制，基于位置的前馈网络（类似于全连接层），利用层归一化预防梯度消失和加快训练速度。





实验



# 十二、BERT

## 1.BERT

动机：类似于CV的微调，BERT是基于微调的NLP（自然语言处理）模型（NLP的迁移学习），由于预训练的模型抽取了足够多的特征信息，所以针对新的任务只需增加一个简单的输出层。

![image-20260313103042010](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313103042010.png)



架构：BERT是只有编码器的Transformer。

![image-20260313103554506](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313103554506.png)





创新点：基于Transformer的编码器做了如下修改，模型更大，训练数据更多。

（1）对输入的修改：每个样本是一个句子对，加入了额外的片段嵌入（将句子分割开），位置编码可以学习（之前是固定的sin和cos函数的位置编码）。

![image-20260313104908791](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313104908791.png)



（2）预训练任务1：带掩码的语言模型，由于Transformer的编码器是双向的，而标准语言模型要求是单向的预测，所以带掩码的语言模型每次随机将一些词元换成<mask>。由于微调任务中不出现<mask>，所以BERT设计概率随机换词元。

![image-20260313105226660](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313105226660.png)





（3）预训练任务2：下一句子预测，BERT中预测一个句子对中两个句子是不是相邻的。

![image-20260313105736841](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313105736841.png)





实验





## 2.BERT微调

理解：即使下游任务不同，使用BERT微调时，只需要增加输出层。但根据任务的不同，输入的表示和使用BERT的特性也会不一样。

![image-20260313150702029](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313150702029.png)



BERT的应用：句子分类、命名实体识别、

![image-20260313150746937](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313150746937.png)

![image-20260313150831988](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313150831988.png)

![image-20260313150908110](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313150908110.png)





实验









# 十三、优化算法

## 1.凸优化

![image-20260313151829742](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313151829742.png)

![image-20260313152051168](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313152051168.png)





## 2.随机梯度下降

![image-20260313152546073](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313152546073.png)



## 3.小批量随机梯度下降

相较于单样本的随机梯度下降，小批量随机梯度下降可以完全利用硬件资源。

![image-20260313153115236](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313153115236.png)





## 4.冲量法

使用冲量法替代梯度，使得梯度平滑的变化，求解最优解更稳定。

![image-20260313153805145](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313153805145.png)





## 5.Adam

Adam对梯度做更好的平滑。

![image-20260313154546129](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313154546129.png)

处理类似于Batch Normal，Adam不仅对梯度做平滑，同时对梯度各个维度值做重新调整。

![image-20260313155157923](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260313155157923.png)



总结：深度学习模型大多数是非凸的，小批量随机梯度下降是最常用的优化算法，冲量对梯度做平滑，Adam对梯度做平滑，且对梯度各个维度值做重新调整。



# 十四、Mamba模型

## 1.状态空间模型——SSM

理解：与RNN类似，只是将激活函数tanh删除了，将非线性转换成线性。

![image-20260316220108622](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260316220108622.png)



## 2.Mamba

理解：与Transformer类似，只是将Muti-Head self-Attention 替换成SSM（线性注意力）；由于Muti-Head self-Attention 训练计算两两之间的token时间复杂度是O(n*n)，时间复杂度高，而SSM计算的时间复杂度是O(n)。

![image-20260316220901716](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260316220901716.png)





## 3.Mamba块

理解：设计与其他模型与Mamba块之间的组合。

![image-20260316221534409](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260316221534409.png)





## 4.Mamba的扫描

理解：在CV上，可以设计不同的Mamba扫描顺序。

![image-20260316221750078](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260316221750078.png)





## 5.Mamba的模态兼容

理解：在语言、视频、时间序列、图片等模态中，设计Mamba的结合。

![image-20260316222008661](C:\Users\HP\AppData\Roaming\Typora\typora-user-images\image-20260316222008661.png)
