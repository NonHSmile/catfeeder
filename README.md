## 01204223 Practicum for Computer Engineering 
Department of Computer Engineering Faculty of Engineering Kasetsart University

## Project name 
Cat feeder


## รายละเอียด 
ที่ให้อาหารเเมวโดยอาหารจะหล่นลงมาเมื่อกดปุ่มและจะมีเสียงเพลงเพื่อเรียกแมวมากินอาหารโดย Servo จะหมุนให้อาหารตกลงมาที่ถาดจนถาดมีน้ำหนักเพียงพอที่จะกด ลิมิต สวิตซ์ เพลงก็จะหยุดทันทีโดยที่หน้า web app จะมีปุ่มที่ให้ผู้ใช้สามารถเลือกเพลงได้ว่าผู้ใช้ต้องการเปิดเพลงไหนเพื่อเรียกเเมวมากินแล้วจึงกดปุ่มเพื่อให้อาหารกับเเมวทันที

## ที่มาของโครงงาน 
การให้อาหารสัตว์เลี้ยงโดยทั่วไปคือผู้ให้อาหารจะต้องอยู่ใกล้ถาดอาหารซึ่งหากในกรณีที่ผู้ให้อาหารไม่สามารถอยู่ใกล้ถาดอาหารด้วยเหตุใดก็ตามก็จะไม่สามารถทำเช่นนั้นได้ดังนั้นพวกเราจึดคิดค้นการให้อาหารผ่านหน้า web app ขึ้นมาโดยที่หน้า web app ดังกล่าวสามารถสั่งให้อาหารทันทีได้แล้วยังสามารถเลือกเพลงที่จะเปิดเรียกแมวมาได้

## ลักษณะการทำงาน 
เมื่อเปิดเครื่องและเติมอาหารในถังจนเต็มก็ทำตามขั้นตอนดังนี้
1. เลือกเพลง
2. กดปุ่ม Feed Me
Servo ก็จะหมุนทำให้อาหารหล่นลงมาใส่ถาดเรื่อยๆพร้อมๆกับเพลงที่เลือกไว้จากหน้าเว็ปจะดังขึ้นเพื่อเรียกแมวมากินอาหารที่หล่นลงมาและเมื่ออาหารในถาดมีน้ำหนักมากพอจนสามารถกดลิมิตสวิตซ์ได้เพลงก็จะหยุดลงพร้อมๆกับ servo ที่หมุนกลับมาที่เดิมเพื่อป้องกันไม่ให้อาหารหล่นลงมาจนล้นถาด
  
## เทคนิคการใช้ 
### Backend
- ใช้ Flask python ในการสื่อสารกับ Frontend

### Frontend
- ใช้การ fetch method ต่างๆในการส่งข้อมูลให้ Backend
- ใช้ html ในการตกแต่งหน้าเว็บ

### Hardware
- เนื่องจากไฟจาก raspberry pi ไม่เพียงพอต่อ micro servo จึงจำเป็นต้องใช้ serial dongle มาช่วย
- เขียนโปรแกรมใน arduino ผ่าน vnc viewer เนื่องจากสะดวกกว่า
- ใช้ servo ในการเปิดปิดให้น้ำไหล
- ใช้ limit swited ในการบอกว่ามีอาหารอยู่ในถาดหรือไม่
  
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
  datetime  	import	datetime  
  flask		import	Flask  
               		render_template  
			request  
			url_for  
   practicumm	import	find_mcu_boards  
                    	McuBoard  
				  

## Software 
  Arduino IDE  
  Editor in Raspberry Pi  
  
## Schematic
![170408](https://user-images.githubusercontent.com/63298507/134486715-8650256e-644a-4db1-b4c7-41c709eb8651.jpg)

## product picture

![LINE_ALBUM_4202021_210923_0](https://user-images.githubusercontent.com/63298507/134481319-acb59502-efef-405e-a304-c8fa51aec971.jpg)

![LINE_ALBUM_4202021_210923_1](https://user-images.githubusercontent.com/63298507/134481337-5bd4a3c3-16a2-4ad8-bc66-eacedbcd8b13.jpg)

## Developers
  Mr.Apiwat     Sukthawornpradit  6210500587   
  Ms.Phakinee   Sirisukpoca       6210503748   
  Ms.Sirapat    Inchan            6210503888   
  Ms.Apichaya   Jarutikorn        6210503896   


## presentation VDO
https://www.youtube.com/watch?v=1Fk-dulr1qI
