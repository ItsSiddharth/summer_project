import cv2
import sys
import socket


facecascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
UDP_IP_ADDRESS = ""
UDP_PORT_NO = 4210

cap = cv2.VideoCapture(0)

centre_x = 338
centre_y = 330

message = ['Client Message1', 'Client Message2']
if len(sys.argv) > 1:
    serverHost = sys.argv[1]

clientSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
clientSock.sendto(bytes("hi", "utf-8"), (UDP_IP_ADDRESS, UDP_PORT_NO)) 
while(1):
    _, img = cap.read()
    cv2.flip(img, 0)
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    faces = facecascade.detectMultiScale(gray,1.3,5)
    for (x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        centre_x = x + (w/2)
        centre_y = y + (h/2)
    
    
    # print(clientSock)
    
    print(bytes(str(centre_x), "utf-8"))
    # clientSock.close()


    cv2.imshow('img',img)
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

clientSock.close()
cap.release()
cv2.destroyAllWindows()




