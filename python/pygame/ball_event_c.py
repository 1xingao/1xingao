import pygame,sys

pygame.init()
#vinfo = pygame.display.Info()
#size = hight,wide = vinfo.current_w,vinfo.current_h    #获取屏幕分辨率
size = hight,wide = 600,400
screen = pygame.display.set_mode(size,pygame.RESIZABLE)
speed = [0,0]
black = 0,0,0
pygame.display.set_caption("pac")   #构造窗体
ball = pygame.image.load("D:\PycharmProjects\pythonProject3\pyganme\pygame素材/PYG02-ball.gif")
ballrect = ball.get_rect()  #创建一个包围小球的矩形
fps = 500   #每秒移动多少像素的参数
fclock = pygame.time.Clock()
bgcolor = pygame.Color("black")
def rgbchange(a):
    return 0 if a<0 else(255 if a>255 else int(a))
while True:
    for event in pygame.event.get():    #事件获取

        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                speed = [0,-1]
            elif event.key == pygame.K_DOWN:
                speed = [0,1]
            elif event.key == pygame.K_LEFT:
                speed = [-1,0]
            elif event.key == pygame.K_RIGHT:
                speed = [1,0]
            elif event.key == pygame.K_ESCAPE:
                sys.exit()
        elif event.type == pygame.VIDEORESIZE:
            size = hight,wide = event.size[0],event.size[1] #接收新的屏幕尺寸
            screen = pygame.display.set_mode(size,pygame.RESIZABLE)
    if pygame.display.get_active() == False:        #检测是否被最小化
        ballrect = ballrect.move(0,0)
    else: 
        ballrect = ballrect.move(speed[0],speed[1]) #移动函数move
    #弹反操作，边缘检测
    if ballrect.left < 0 or ballrect.right > hight:
        speed[0] = -speed[0]
    if ballrect.top < 0 or ballrect.bottom > wide:
        speed[1] = -speed[1]
    #颜色填充
    bgcolor.r = rgbchange(ballrect.left*255/wide)
    bgcolor.g = rgbchange(ballrect.top*255/hight)
    bgcolor.b = 0
    screen.fill(bgcolor)
    #使小球图片跟随矩形
    screen.blit(ball,ballrect)
    #刷新屏幕
    pygame.display.update()
    fclock.tick(fps)

