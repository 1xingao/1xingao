import math
from tokenize import Double
import numpy as np
#角度转化为弧度
def dmsToRad(dms:Double):
    temp_dms = abs(dms)
    du = int(temp_dms)
    fn = (temp_dms-du)*100
    fn_tem = int(fn)
    m = (fn-fn_tem)*100
    alldi = du+fn/60+m/3600
    return math.radians(alldi)

c = np.array([[1,0,1],[0,2,2],[4,0,3]])
c = np.matrix(c)
print(c.I)