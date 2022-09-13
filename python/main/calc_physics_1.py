import numpy as np

data_litst = [1.502, 1.502, 1.479, 1.470, 1.528, 1.474]
sd = np.var(data_litst)
pd = pow(0.004 / pow(3, 1 / 2), 2)
fd = pow(sd / 5 + pd, 1 / 2)
dl = np.average(data_litst)
# 变量后缀为l的是平均值
# 变量前面呆f的是不确定度
# 变量前带s是方差
# 变量带p的是不确定度公式的定值
print(fd)
print("-----------------------------------------")
pt = pow(0.1 / pow(3, 1 / 2), 2)
t_list = [15.94, 16.05, 16.16, 16.03, 16.06, 16.09]
st = np.var(t_list)
tl = np.average(t_list)
ft = pow(st / 5 + pt, 1 / 2)
print(ft)

print("-----------------------------------------")
fs = 0.48 / pow(3, 1 / 2)
print(fs)
print("-----------------------------------------")
Er = pow(pow(2 * 0.0094 / dl, 2) + pow(0.065 / tl, 2) + pow(0.28 / 121.4, 2), 1 / 2)
print(Er)
