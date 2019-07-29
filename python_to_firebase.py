import pyrebase
import cv2

config = {
  "apiKey": "",
  "authDomain": "nodemcu-4eb31.firebaseio.com",
  "databaseURL": "https://nodemcu-4eb31.firebaseio.com",
  "storageBucket": "nodemcu-4eb31.appspot.com"
}

firebase = pyrebase.initialize_app(config)
db = firebase.database()

facecascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

cap = cv2.VideoCapture(0)

centre_x = 338
centre_y = 330
data_x = {"x-pos": centre_x}
db.set(data_x)
data_y = {"y-pos": centre_y}
db.set(data_y)

while(1):
    _, img = cap.read()
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    faces = facecascade.detectMultiScale(gray,1.3,5)
    for (x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        centre_x = x + (w/2)
        centre_y = y + (h/2)

    db.update({"x-pos": centre_x})
    db.update({"y-pos": centre_y})



    cv2.imshow('img',img)
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

cap.release()
cv2.destroyAllWindows()
