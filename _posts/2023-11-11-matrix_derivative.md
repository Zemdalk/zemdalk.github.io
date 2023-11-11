---
title: 矩阵求导术
tags: A-技术笔记 线性代数 机器学习 矩阵求导
mathjax: true
mathjax_autoNumber: true
key: 矩阵求导术
sharing: true
typora-root-url: ..
---

> 给定函数$f: \mathbb{R}^{m\times n}\to\mathbb{R}$，如何计算它的导数呢？
> 
> 参考：[矩阵求导术（上） - 知乎](https://zhuanlan.zhihu.com/p/24709748)

<!--more-->

# 问题引入

记$f^D(x_i) = W_D\text{relu}\left(W_{D-1}\text{relu}\left(\cdots W_2\text{relu}(W_1x)\cdots\right)\right)$，即D层神经网络，其中$W_d\in \mathbb{R}^{m_d\times m_{d-1}}, 1\leq d\leq D$。特别地，$m_D=1$。反向传播更新权重时，我们需要对它的权重求导，需计算$\nabla_{W_j}f^D(x_i)$。

即，给定函数

$$
\begin{aligned}
    f: \mathbb{R}^{m\times n} & \to\mathbb{R} \\
    \mathbf{X} & \mapsto f(\mathbf{X}),
\end{aligned}
$$

如何计算它的导数$\nabla_{\mathbf{X}}f(\mathbf{X})$呢？

# 准备：矩阵求导术

## 基本定义

$$
\nabla_{\mathbf{X}}f(\mathbf{X}) := \frac{\partial f}{\partial \mathbf{X}} := \begin{pmatrix}
    \frac{\partial f}{\partial x_{11}} & \cdots & \frac{\partial f}{x_{1n}} \\
    \vdots & & \vdots \\
    \frac{\partial f}{\partial x_{m1}} & \cdots & \frac{\partial f}{x_{mn}} \\
\end{pmatrix}.
$$

## 矩阵导数与微分的联系

$$
\text{d}f = \text{tr}\left(\left(\frac{\partial f}{\partial \mathbf{X}}\right)^T \text{d}\mathbf{X}\right).
$$

## 矩阵微分的运算法则

(1) $\text{d}(\mathbf{X}\pm\mathbf{Y}) = \text{d}\mathbf{X}\pm \text{d}\mathbf{Y}.$

(2) $\text{d}(\mathbf{XY}) = \text{d}\mathbf{X}\cdot\mathbf{Y} + \mathbf{X}\cdot \text{d}\mathbf{Y}.$

(3) $\text{d}\left(\mathbf{X}^{\top}\right) = \left(\text{d}\mathbf{X}\right)^{\top}.$

(4) $\text{d tr}(\mathbf{X}) = \text{tr}\left(\text{d}\mathbf{X}\right)$

(5) $\text{d}(\mathbf{X}\odot\mathbf{Y}) = \text{d}\mathbf{X}\odot \mathbf{Y} + \mathbf{X}\odot\text{d}\mathbf{Y}.$ (Hadamard product).

(6) $\text{d}\sigma(\mathbf{X}) = \sigma'(\mathbf{X})\odot\text{d}\mathbf{X}$，其中$\sigma(\mathbf{X}) := \left[\sigma\left(x_{ij}\right)\right], \sigma'(\mathbf{X}) := \left[\sigma'\left(x_{ij}\right)\right].$

## 迹技巧

要求$\frac{\partial f}{\partial \mathbf{X}}$，只需要先求得微分$\text{d}f$，再将计算结果化成$\text{tr}\left(\left(\frac{\partial f}{\partial \mathbf{X}}\right)^T \text{d}\mathbf{X}\right)$的形式即可。为了完成第二步形式转换，我们需要用到迹技巧(trace trick)：

(1) $a=\text{tr}(a)$, 这里$a$为一个标量。

(2) $\text{tr}(\mathbf{A}^{\top})=\text{tr}(\mathbf{A}).$

(3) $\text{tr}(\mathbf{A}\pm\mathbf{B}) = \text{tr}(\mathbf{A})\pm\text{tr}(\mathbf{B}).$

(4) $\text{tr}(\mathbf{AB}) = \text{tr}(\mathbf{BA}).$

(5) $\text{tr}\left(\mathbf{A}^{\top}\left(\mathbf{B}\odot\mathbf{C}\right)\right) = \text{tr}\left(\left(\mathbf{A}\odot \mathbf{B}\right)^{\top}\mathbf{C}\right), \mathbf{A}, \mathbf{B}, \mathbf{C}\in \mathbb{R}^{m\times n}.$

# 例子：多层神经网络对权重求导

应用上面给出的矩阵求导术（迹技巧），求解引入部分提到的多层神经网络对权重的求导问题。

定义$a_{i,0}:=x_i, a_{i,d} := \text{relu}(W_da_{i,d-1})$, 并定义$f^d(x_i) := W_d\text{relu}(W_{d-1}a_{i,d-2}) = W_d a_{i,d-1} = W_d\text{relu}\left(f^{d-1}(x_i)\right)$. 我们有$a_{i,d}\in\mathbb{R}^{m_d}, W_d\in\mathbb{R}^{m_d\times m_{d-1}}, f^d(x_i)\in\mathbb{R}^{m_d}$。

要计算$\frac{\partial f^D}{\partial W_j}$，其中$m_D=1$，我们可以先计算$\text{d}f$，再应用微分与导数的联系$\text{d}f = \text{tr}\left(\left(\frac{\partial f}{\partial \mathbf{X}}\right)^T \text{d}\mathbf{X}\right)$，应用迹技巧将结果重写为该形式，并求得最终结果。

应用矩阵微分的运算法则，我们有$\text{d}f^d = W_d\text{d}a_{i, d-1} = W_d\left(\mathbf{1}(f^{d-1}(x_i)>0)\odot \text{d}f^{d-1}\right), \forall j+1\leq d\leq D, \text{d}f^j=(\text{d}W_j)a_{i,j-1}$。

定义对角矩阵$A_{i,d} = \mathbf{1}(W_da_{i,d-1}>0)$，我们有$\text{d}f^d=W_dA_{i,d-1}\cdot\text{d}f^{d-1}$。因此

$$
\begin{aligned}
    \text{d}f^D & = W_D\text{d}a_{i,D-1} \\
    & = \text{tr}(W_D\text{d}a_{i,D-1}) \\
    & = \text{tr}(W_DA_{i,D-1}\cdot \text{d}f^{D-1}) \\
    & = \cdots \\
    & = \text{tr}\left(\left(\prod_{k=j+1}^{D}W_kA_{i,k-1}\right)\text{d}f^j\right) \\
    & = \text{tr}\left(\left(\prod_{k=j+1}^{D}W_kA_{i,k-1}\right)(\text{d}W^j)a_{i,j-1}\right) \\
    & = \text{tr}\left(a_{i,j-1}\left(\prod_{k=j+1}^{D}W_kA_{i,k-1}\right)(\text{d}W^j)\right) \\
\end{aligned}
$$

应用微分与导数的联系，得

$$
\nabla_{W_j}f^D(x_i) = \left[a_{i,j-1}\left(\prod_{k=j+1}^{D}W_kA_{i,k-1}\right)\right]^{\top}
$$