# #this file is only for testing purposes
# def min_cost(T, data):
#     results = []
    
#     for case in range(T):
#         N = data[case]['N']
#         c = data[case]['c']
#         y = data[case]['y']
        
#         # dp数组，存储到第i个月为止的最小成本
#         dp = [0] * (N + 1)
#         inventory = 0  # 初始库存为0

#         # 从第一个月开始计算
#         for i in range(N):
#             # 计算使用库存和生产产品的最小成本
#             cost = c[i] * y[i] + dp[i]  # 当月生产y[i]个产品的成本
#             if i > 0:
#                 cost = min(cost, dp[i - 1] + c[i] * y[i] + inventory)
            
#             dp[i + 1] = cost
#             inventory += y[i]  # 更新库存
        
#         results.append(dp[N])
    
#     return results

# # Sample Input
# T = 1
# data = [
#     {
#         'N': 3,
#         'c': [2, 5, 3],
#         'y': [2, 4, 5]
#     }
# ]

# # Call the function
# results = min_cost(T, data)
# for res in results:
#     print(res)

#1.无人机规划问题。
#先画一个图，再画一个总能耗最低的图
#首先计算P（v）/v的最小功耗也就是自由飞行的时候
#2024.6.7添加注释
# import numpy as np
# import matplotlib.pyplot as plt

# # 定义函数
# def polynomial(v):
#     return 0.07 * v**2 + 0.0391 * v - 13.196 + 390.95 / v

# # 生成一组 x 值
# v_values = np.linspace(1, 100, 400)  # 从1到100生成400个点

# # 计算对应的 y 值
# y_values = polynomial(v_values)

# # 找到最低点的坐标
# min_index = np.argmin(y_values)
# min_v = v_values[min_index]
# min_y = y_values[min_index]

# # 绘制图像
# plt.plot(v_values, y_values)
# plt.scatter(min_v, min_y, color='red', label=f'Minimum Point: ({min_v:.2f}, {min_y:.2f})')
# plt.title('Polynomial Graph: 0.07*v^2 + 0.0391*v - 13.196 + 390.95/v')
# plt.xlabel('v')
# plt.ylabel('Polynomial Value')
# plt.grid(True)
# plt.legend()
# plt.show()
import numpy as np
def square(x):
    return x*x;
square(5)
