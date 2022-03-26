bili_ini = """[launcher]
cps=bilibili
channel=14
sub_channel=0
game_install_path=D:/Genshin Impact/Genshin Impact Game
game_dynamic_bg_name=7a0e3aa7c296b1562549b8bde366ae87_2682713341520311671.png
game_dynamic_bg_md5=9b49182ecb99ed57b4a740549e466c5d
game_start_name=YuanShen.exe
is_first_exit=false
exit_type=2
speed_limit_enabled=false
"""
bili_ini_short = """[General]
channel=14
cps=bilibili
game_version=2.5.0
sub_channel=0
plugin_sdk_version=3.3.0
"""
mihoyo_ini = """[launcher]
cps=mihoyo
channel=1
sub_channel=1
game_install_path=D:/Genshin Impact/Genshin Impact Game
game_dynamic_bg_name=7a0e3aa7c296b1562549b8bde366ae87_2682713341520311671.png
game_dynamic_bg_md5=9b49182ecb99ed57b4a740549e466c5d
game_start_name=YuanShen.exe
is_first_exit=false
exit_type=2
speed_limit_enabled=false"""
mihoyo_ini_short = """[General]
channel=1
cps=mihoyo
game_version=2.5.0
sub_channel=1
plugin_sdk_version=3.3.0"""

def Change_To_Bili():
    with open("D:\\Genshin Impact\\Genshin Impact Game\\config.ini","w") as f_bili_short:
        f_bili_short.write(bili_ini_short)
    with open("D:\\Genshin Impact\\config.ini","w") as f_bili:
        f_bili.write(bili_ini)

def Change_To_mihoyo():
    with open("D:\\Genshin Impact\\Genshin Impact Game\\config.ini","w") as f_mihoyo_short:
        f_mihoyo_short.write(mihoyo_ini_short)
    with open("D:\\Genshin Impact\\config.ini","w") as f_mihoyo:
        f_mihoyo.write(mihoyo_ini)

if __name__ =="__main__":
    change = int(input("1:Change_To_Bili\n2:Change_To_mihoyo\n"))
    if change==1:
        Change_To_Bili()
        print("success!")
    elif change==2:
        Change_To_mihoyo()
        print("success!")
    else:
        print("error!")