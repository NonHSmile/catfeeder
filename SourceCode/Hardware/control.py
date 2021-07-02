import usb
from practicum import find_mcu_boards, McuBoard
import time
import pygame
from datetime import datetime

dev = find_mcu_boards()[0]
mcu = McuBoard(dev)


datetimeobj = datetime.now()
hr = datetimeobj.hour+6
minu = datetimeobj.minute
sec = datetimeobj.second
#hr=8
#minu=0
#sec=0

cs = open('conser.txt','r')
sv = cs.read().splitlines()
#cs = open('conser.txt','w')
#cs = cs.write('0')

cm = open('conmu.txt','r')
ms = cm.read().splitlines()


mcu.usb_write(4, value=90)
time.sleep(2)
while True:
  try:
    
    cs = open('conser.txt','r')
    sv = cs.read().splitlines()
    #print(sv)
    cs = open('conser.txt','w')
    cs = cs.write('0')
    cm = open('conmu.txt','r')
    ms = cm.read().splitlines()


    sw = mcu.usb_read(1, length=4)
    #print(sw)
    #print(sv)
    #print(hr, minu)

    if (((sw[0] and sw[1] and sw[2] and sw[3]) != 0) and sv==['1'] or ((hr==8 and minu==0) or (hr==12 and minu==0) or (hr==16 and minu==0))):
      #time.sleep(2)
      mcu.usb_write(4, value=0)
      time.sleep(2)
      
      pygame.mixer.init()
      pygame.mixer.music.load(ms[0])
      pygame.mixer.music.set_volume(4.0)
      pygame.mixer.music.play()
      while pygame.mixer.music.get_busy() == True:
        sw = mcu.usb_read(1, length=4)
        print(sw)
        mcu.usb_write(4 ,value=0)
        time.sleep(2)
        if (((sw[0] and  sw[1] and sw[2] and sw[3]) == 0)):
            #print("sw=0")
            #pygame.mixer.music.set_volume(0.0)
            break
        
        else:
            #print("else")
            #time.sleep(2)
            mcu.usb_write(4, value=0)
            time.sleep(2)
            pass
      #print("YYYYYYYYYYYYYYYYYYYY")

    else:
      pygame.mixer.init()
      mcu.usb_write(4, value=180)
      time.sleep(2)
      #mcu.usb_write(4, value=180)
      pygame.mixer.music.stop()
    time.sleep(0.2)
  except usb.core.USBError:
    print("USB error detected")


#cs = open('conser.txt','w')
#cs = cs.write('0')
