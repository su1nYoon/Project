import numpy as np
import cv2 as cv

img = cv.imread('soccer.jpg')
r, c, ch = img.shape   #(r, c, ch) ()이므로 튜플 ->값을 바꿀 수 없음(바꿀 필요 없음) 

def mygray(img):
    red = img[:, :, 2]
    green = img[:, :, 1]
    blue = img[:, :, 0]

    temp = 0.299*red + 0.587*green + 0.114*blue
    gray = np.uint8(temp)    #uint : 강제로 형 변환
    return gray

g = mygray(img)
cv.imshow('', g)
cv.waitKey(0)

print(r)
print(c)
print(ch)

# gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# cv.imshow('', gray)
# cv.waitKey(0)
