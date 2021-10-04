import pygame,sys

from pygame.constants import KEYDOWN, MOUSEBUTTONDOWN, MOUSEBUTTONUP, MOUSEMOTION, QUIT

pygame.init()

screen = pygame.display.set_mode((600,400),pygame.RESIZABLE)
pygame.display.set_caption("按键返回值")

while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            sys.exit()
        elif event.type == KEYDOWN:
            if event.unicode ==" ":
                print("#",event.key,event.mod)
            elif event.key == pygame.K_ESCAPE:
                sys.exit()
            else:
                print(event.unicode,event.key,event.mod)


        elif event.type == MOUSEMOTION:
            print(event.pos,event.rel,event.buttons)
        elif event.type == MOUSEBUTTONDOWN:
            print(event.pos,event.button)
        elif event.type == MOUSEBUTTONUP:
            print(event.pos,event.button)
        elif event.type == pygame.VIDEORESIZE:
            size = hight,wide = event.size[0],event.size[1] 
            screen = pygame.display.set_mode(size,pygame.RESIZABLE)
    
    
    pygame.display.update()