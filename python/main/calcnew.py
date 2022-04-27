fil = []
with open("M_20220419.TXT", "r") as fp:

    for line in fp.readlines():

        print(line)
        line = line.strip('\n')  #去掉列表中每一个元素的换行符
        li = line.split(",")
        tim = li[-2]
        tim = float(tim)
        tim -= 4.33
        li[-2] = str(tim)
        tim = li[-3]
        tim = float(tim)
        tim += 26.554
        li[-3] = str(tim)
        li.append("\n")
        fil.append(li)
        for i in range(len(li)):
            if i == len(li) - 2:
                break
            li[i] += ","

print(fil)
with open("new.txt", "w") as f:
    for i in fil:
        f.writelines(i)
