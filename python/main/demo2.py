#! /usr/bin/env python
# -*- coding: utf-8 -*-
#python demo.py
#Q 退出程序

from __future__ import absolute_import, division, print_function

import argparse
import os
import turtle
import warnings
from collections import deque
from timeit import time

import cv2
import datetimepip
import numpy as np
from astar import Array2D, AStar, Point
from deep_sort import nn_matching, preprocessing
from deep_sort.detection import Detection
from deep_sort.detection import Detection as ddet
from deep_sort.tracker import Tracker
from keras import backend
from PIL import Image
from tools import generate_detections as gdet
from yolo import YOLO


# 找到目标函数
def find_marker(image):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)  #将导入的图片转化为灰度图片
    gray = cv2.GaussianBlur(gray, (5, 5), 0) #图像降噪处理
    edged = cv2.Canny(gray, 35, 125) #边缘检测 最大值125
    (cnts, _) = cv2.findContours(edged.copy(), cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE) #检测轮廓
    # 求最大面积
    c = max(cnts, key=cv2.contourArea) 
    # cv2.minAreaRect() c代表点集，返回rect[0]是最小外接矩形中心点坐标，
    # rect[1][0]是width，rect[1][1]是height，rect[2]是角度
    return cv2.minAreaRect(c) #返回所获得的最小外接矩形

# 距离计算函数
def distance_to_camera(knownWidth, focalLength, perWidth):
    return (knownWidth * focalLength) / perWidth

#已知摄像头的距离
KNOWN_DISTANCE = 1

# A4纸的长和宽(单位:inches)
KNOWN_WIDTH = 11.69
KNOWN_HEIGHT = 8.27
IMAGE_PATHS = ["D:/deep_sort_yolov3-master/A4paper.jpg"]
#将一张样品图片放在D:/pythonProject1/venv/里，可以更改地址

# 读入第一张图，通过已知距离计算相机焦距
image = cv2.imread(IMAGE_PATHS[0])
marker = find_marker(image)
focalLength = (marker[1][0] * KNOWN_DISTANCE) / KNOWN_WIDTH

backend.clear_session()
ap = argparse.ArgumentParser() #创建解析器，编写命令行接口
ap.add_argument("-i", "--input",help="path to input video", default = "./test_video/test.avi")
ap.add_argument("-c", "--class",help="name of class", default = "person")
args = vars(ap.parse_args())

pts = [deque(maxlen=30) for _ in range(9999)]
warnings.filterwarnings('ignore')

# 初始化颜色列表以表示每个可能的类标签
np.random.seed(100) #seed指定随机生成的值的初始整数 使用seed函数则每次随机生成的值相同
COLORS = np.random.randint(0, 255, size=(200, 3),
	dtype="uint8")#随机一个处于0到255之间的200行3列的随机整数

def main(yolo):

    start = time.time()
    #参数定义
    max_cosine_distance = 0.5 #余弦距离的控制阈值
    nn_budget = None
    nms_max_overlap = 0.3 #非极大抑制的阈值

    counter = []
    #deep_sort
    #model_filename = 'model_data/market1501.pb'
    model_filename = 'model_data/mars-small128.pb'
    
    encoder = gdet.create_box_encoder(model_filename,batch_size=1)

    metric = nn_matching.NearestNeighborDistanceMetric("cosine", max_cosine_distance, nn_budget)
    tracker = Tracker(metric)

    writeVideo_flag = True
    #video_path = "./output/output.avi"
    #video_capture = cv2.VideoCapture(args["input"])
    video_capture = cv2.VideoCapture(0)

    if writeVideo_flag:
    # Define the codec and create VideoWriter object
        w = int(video_capture.get(3))
        h = int(video_capture.get(4))
        fourcc = cv2.VideoWriter_fourcc(*'MJPG')
        out = cv2.VideoWriter('./output/'+args["input"][43:57]+ "_" + args["class"] + '_output.avi', fourcc, 15, (w, h))
        list_file = open('detection.txt', 'w')
        frame_index = -1

    fps = 0.0
    while True:

        ret, frame = video_capture.read()  # frame shape 640*480*3
        if ret != True:
            break
        t1 = time.time()

       # image = Image.fromarray(frame)
        image = Image.fromarray(frame[...,::-1]) #bgr to rgb
        boxs,class_names = yolo.detect_image(image)
        features = encoder(frame,boxs)
        # score to 1.0 here).
        detections = [Detection(bbox, 1.0, feature) for bbox, feature in zip(boxs, features)]
        # Run non-maxima suppression.
        boxes = np.array([d.tlwh for d in detections])
        scores = np.array([d.confidence for d in detections])
        indices = preprocessing.non_max_suppression(boxes, nms_max_overlap, scores)
        detections = [detections[i] for i in indices]

        # Call the tracker
        tracker.predict()
        tracker.update(detections)

        i = int(0)
        indexIDs = []
        c = []
        boxes = []
        for det in detections:
            bbox = det.to_tlbr()
            cv2.rectangle(frame,(int(bbox[0]), int(bbox[1])), (int(bbox[2]), int(bbox[3])),(255,255,255), 2)

        for track in tracker.tracks:
            if not track.is_confirmed() or track.time_since_update > 1:
                continue
            #boxes.append([track[0], track[1], track[2], track[3]])
            indexIDs.append(int(track.track_id))
            counter.append(int(track.track_id))
            bbox = track.to_tlbr()
            color = [int(c) for c in COLORS[indexIDs[i] % len(COLORS)]]

            cv2.rectangle(frame, (int(bbox[0]), int(bbox[1])), (int(bbox[2]), int(bbox[3])),(color), 3)
            cv2.putText(frame,str(track.track_id),(int(bbox[0]), int(bbox[1] -50)),0, 5e-3 * 150, (color),2)
            if len(class_names) > 0:
               class_name = class_names[0]
               cv2.putText(frame, str(class_names[0]),(int(bbox[0]), int(bbox[1] -20)),0, 5e-3 * 150, (color),2)

            i += 1
            #bbox_center_point(x1,y1)
            center = (int(((bbox[0])+(bbox[2]))/2),int(((bbox[1])+(bbox[3]))/2))
            distance=5.58*int(focalLength)/(int((bbox[3])-(bbox[1])))
            x=int(10-distance)
            y=int(int(((bbox[2])-(bbox[0]))/2)*distance/(int(focalLength)))
            
            
            map2d=Array2D(10,10)
            map2d[4][0]= 1
            map2d[4][1] = 1
            map2d[4][2] = 1
            map2d[4][3] = 1
            map2d[4][4] = 1
            map2d[4][5] = 1
            map2d[4][6] = 1
            p=Point(x,y)  
            object=Point(2,3)
            
            aStar=AStar(map2d,p,object)
            pathList=aStar.start()
            turtle.setup(20, 20, 5, 5)
            turtle.setup()   
            for point in pathList:
                map2d[point.x][point.y]=8
                turtle.pendown()
                turtle.goto (point.x,point.y)
                turtle.penup()
            print("----------------------")
            map2d.showArray2D()     
           
            #track_id[center]
            pts[track.track_id].append(center)
            thickness = 5
            #center point
            cv2.circle(frame,  (center), 1, color, thickness)

            #draw motion path
            for j in range(1, len(pts[track.track_id])):
               if pts[track.track_id][j - 1] is None or pts[track.track_id][j] is None:
                    continue
               thickness = int(np.sqrt(64 / double(j + 1)) * 2)
               cv2.line(frame,(pts[track.track_id][j-1]), (pts[track.track_id][j]),(color),thickness)
               #cv2.putText(frame, str(class_names[j]),(int(bbox[0]), int(bbox[1] -20)),0, 5e-3 * 150, (255,255,255),2)

        count = len(set(counter))
        cv2.putText(frame, "Total Object Counter: "+str(count),(int(20), int(120)),0, 5e-3 * 200, (0,255,0),2)
        cv2.putText(frame, "Current Object Counter: "+str(i),(int(20), int(80)),0, 5e-3 * 200, (0,255,0),2)
        cv2.putText(frame, "FPS: %f"%(fps),(int(20), int(40)),0, 5e-3 * 200, (0,255,0),3)
        cv2.namedWindow("YOLO3_Deep_SORT", 0)
        cv2.resizeWindow('YOLO3_Deep_SORT', 1024, 768)
        cv2.imshow('YOLO3_Deep_SORT', frame)

        if writeVideo_flag:
            #save a frame
            out.write(frame)
            frame_index = frame_index + 1
            list_file.write(str(frame_index)+' ')
            if len(boxs) != 0:
                for i in range(0,len(boxs)):
                    list_file.write(str(boxs[i][0]) + ' '+str(boxs[i][1]) + ' '+str(boxs[i][2]) + ' '+str(boxs[i][3]) + ' ')
            list_file.write('\n')
        fps  = ( fps + (1./(time.time()-t1)) ) / 2
        #print(set(counter))

        # Press Q to stop!
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    print(" ")
    print("[Finish]")
    end = time.time()

    if len(pts[track.track_id]) != None:
       print(args["input"][43:57]+": "+ str(count) + " " + str(class_name) +' Found')

    else:
       print("[No Found]")

    video_capture.release()

    if writeVideo_flag:
        out.release()
        list_file.close()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main(YOLO())
