import shutil

first_path = "D:\\Genshin Impact\\Genshin Impact Game\\config.ini"
second_path = "D:\\Genshin Impact\\config.ini"


# test_path2 = "D:\\abcin\code\\1xingao\\config.ini"
# test_path = "D:\\abcin\code\\1xingao\\config.ini"

sdk_path = "D:\\abcin\\code\\1xingao\\PCGameSDK.dll"
game_dir = "D:\\Genshin Impact\\Genshin Impact Game\\YuanShen_Data\\Plugins\\"

def change_file(chenel :int,cps:str,subs:int,path:str) -> None:
    changed_file = []

    with open(path,"r") as file:
        for line in file.readlines():

            if "cps=" in line:
                line = "cps=" + str(cps)+"\n"
            
            if "sub_channel=" in line:
                line = "sub_channel=" +str(subs)+"\n"

            elif "channel=" in  line:
                line = "channel="+str(chenel)+"\n"
                
            changed_file.append(line)


    with open(path,"w") as f:
        for i in changed_file:
            f.writelines(i)
            
    
# change_file(14,"bilibili",0,test_path)
if __name__ == "__main__":
    try:

        res = int(input("change to\n 0.mihoyo\n1.bilibil\n"))
        if res :
            
            change_file(14,"bilibili",0,first_path)
            change_file(14,"bilibili",0,second_path)
            shutil.copy(sdk_path,game_dir)
        elif not res:

            change_file(1,"mihoyo",1,first_path)
            change_file(1,"mihoyo",1,second_path)

    except IOError as e:
        print ("Error: 没有找到文件或读取文件失败")
        print("错误信息：" + e)
    else:
        print ("内容写入文件成功")
    
   
