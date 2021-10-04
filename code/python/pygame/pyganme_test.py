import pygame
import sys

from pygame.constants import QUIT

class Tset(pygame.sprite.Sprite):
    def __init__(self) -> None:
        super().__init__()
        self.temp = 0
        self.len = 10
        self.image = pygame.image.load('pygame-master/imgs/zombie.png')
        self.rect = self.image.get_rect()
        self.rect.x = 200
        self.rect.y = 400
        self.speed = 1
        
    def move(self):
        if self.len>0 :
            self.rect.x -= self.speed

pygame.init()
screen = pygame.display.set_mode((600,400))
tse = Tset()

while True:
    tse.move()
    for event in pygame.event.get():
        if event.type == QUIT:
            sys.exit()

    screen.fill(0,0,0)
    pygame.display.update()
