## 01204223 Practicum for Computer Engineering 
Department of Computer Engineering Faculty of Engineering Kasetsart University

## Project name 
Cat feeder

## Developers
  Mr.Apiwat     Sukthawornpradit  6210500587   
  Ms.Phakinee   Sirisukpoca       6210503748   
  Ms.Sirapat    Inchan            6210503888   
  Ms.Apichaya   Jarutikorn        6210503896   
  
## File details
catfeeder
	|_____ MemberImages
			|_____ 6210500587_Apiwat_Sukthawornpradit.jpg
			|_____ 6210503748_Phakinee_Sirisukpoca.jpg
			|_____ 6210503888_Sirapat_Inchan.jpg
			|_____ 6210503896_Apichaya_Jarutikorn.jpg
	|_____ Project
			|_____ CatFeeder.pdf ( คำอธิบายเพิ่มเติม เกี่ยวกับอุปกรณ์ที่ใช้ต่างๆ และภาพรวมของชิ้นงาน )
			|_____ Schematic.jpg ( รูปภาพผังวงจรส่วนของ Hardware )
	|_____ ProjectImages
			|_____ Hardware_1.jpg ( ภาพส่วนของ Hardware 1 )
			|_____ Hardware_2.jpg ( ภาพส่วนของ Hardware 2 )
			|_____ Logo.png ( โลโก้ของโปรเจค )
			|_____ ProjectImage.jpg ( รูปถ่ายงานโดยรวมของโปรเจค )
			|_____ Webpage.png ( หน้า website ของโปรเจค )
	|_____ SourceCode
			|_____ Backend
					|_____ main.py ( โค้ดเชื่อมต่อระหว่าง Backend และ Frontend รวมถึงการแก้ไขไฟล์เพื่อเชื่อมกับ Hardware )
					|_____ conser.txt ( ไฟล์เชื่อมกันระหว่าง Backend กับ Hardware ถ้าในไฟล์มีข้อมูลเป็นเลข 1 แสดงว่ามีคำสั่งผ่านหน้าเว็บให้อาหารตกลงมา ถ้าเป็น 0 ไม่มีอะไรเกิดขึ้น )
					|_____ conmu.txt ( ไฟล์ที่เก็บที่ชื่อ 1 ชื่อ ที่จะเปิดโดยเขียนโดย Backend และอ่านโดย Hardware ว่าจะให้เล่นเพลงอะไร )
			|_____ Frontend
					|_____ index.html ( โค้ดที่แสดงหน้าเว็บ รวมถึงคำสั่งการเชื่อม Frontend และ Backend บริเวณปุ่มกดต่างๆ)
			|_____ Hardware
					|_____ firmware ( การตั้งค่าพื้นฐานของแต่ละอุปกรณ์  )
							|_____ main.c
							|_____ peri.c
							|_____ peri.h
					|_____ Song
							|_____ LoveWithFish.mp3 ( เพลงด้วยรักและปลาทู - มอส ปฏิภาณ )
							|_____ NANA.mp3 ( เพลงแมวตัวโปรด - NANA (ft. Pom) )
							|_____ PICKME.mp3 ( เพลงPICK ME - PRODUCE48 )
					|_____ usb-generic ( ควบคุมการหมุนของ servo ใช้โปรแกรม Arduino ผ่านโปรแกรม VNC Viewer )
							|_____ peri.py
							|_____ practicum.py
							|_____ usbconfig.h
							|_____ usb-generic.ino
					|_____ control.py ( โปรแกรมใช้ในการควบคุมสวิตช์ เช็คการทำงาน servo และควบคุมเวลาการทำงานของเครื่อง )
	|_____ License.txt
	|_____ README.txt

## Hardware and Equipment
   1. Raspberry Pi 3 Model B+ พร้อม สาย Adapter Model YM-0530 1 ชุด
   2. Board NodeMCU - ATmega328p (Practicum Board v3.2 CPE. KU 2020-11) 1 ชุด
   3. Peripheral board (PRACTICUM PROTOBOARD CPE. KU) 1 ชิ้น
   4. Micro Servo SG90 1 ตัว
   5. Ribbon cable 1 สาย
   6. Mini Micro Limit Switch 4 ตัว
   7. CH340G USB to Serial TTL 1 ตัว
   8. Mini speaker 1 ตัว
   9. Wire 25 สาย

## Library list in Arduino 
  Servo.h
  usbdrv.h
  usbconfig.h

  
## Library list in code which runs on Raspberry Pi 
  usb
  time
  pygame
  datetime	import	datetime
  flask		import	Flask
               		render_template
			request
			url_for
   practicumm	import	find_mcu_boards
                    	McuBoard
				

## Software 
  Arduino IDE
  Editor in Raspberry Pi
  

## presentation VDO
https://www.youtube.com/watch?v=1Fk-dulr1qI

## product picture

![LINE_ALBUM_4202021_210923_0](https://user-images.githubusercontent.com/63298507/134481319-acb59502-efef-405e-a304-c8fa51aec971.jpg)

![LINE_ALBUM_4202021_210923_1](https://user-images.githubusercontent.com/63298507/134481337-5bd4a3c3-16a2-4ad8-bc66-eacedbcd8b13.jpg)
