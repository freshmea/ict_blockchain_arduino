import winsound
import pygame
import time
from pygame.locals import *




tones = {
    "B0": 31,
    "C1": 33,
    "CS1": 35,
    "D1": 37,
    "DS1": 39,
    "E1": 41,
    "F1": 44,
    "FS1": 46,
    "G1": 49,
    "GS1": 52,
    "A1": 55,
    "AS1": 58,
    "B1": 62,
    "C2": 65,
    "CS2": 69,
    "D2": 73,
    "DS2": 78,
    "E2": 82,
    "F2": 87,
    "FS2": 93,
    "G2": 98,
    "GS2": 104,
    "A2": 110,
    "AS2": 117,
    "B2": 123,
    "C3": 131,
    "CS3": 139,
    "D3": 147,
    "DS3": 156,
    "E3": 165,
    "F3": 175,
    "FS3": 185,
    "G3": 196,
    "GS3": 208,
    "A3": 220,
    "AS3": 233,
    "B3": 247,
    "C4": 262,
    "CS4": 277,
    "D4": 294,
    "DS4": 311,
    "E4": 330,
    "F4": 349,
    "FS4": 370,
    "G4": 392,
    "GS4": 415,
    "A4": 440,
    "AS4": 466,
    "B4": 494,
    "C5": 523,
    "CS5": 554,
    "D5": 587,
    "DS5": 622,
    "E5": 659,
    "F5": 698,
    "FS5": 740,
    "G5": 784,
    "GS5": 831,
    "A5": 880,
    "AS5": 932,
    "B5": 988,
    "C6": 1047,
    "CS6": 1109,
    "D6": 1175,
    "DS6": 1245,
    "E6": 1319,
    "F6": 1397,
    "FS6": 1480,
    "G6": 1568,
    "GS6": 1661,
    "A6": 1760,
    "AS6": 1865,
    "B6": 1976,
    "C7": 2093,
    "CS7": 2217,
    "D7": 2349,
    "DS7": 2489,
    "E7": 2637,
    "F7": 2794,
    "FS7": 2960,
    "G7": 3136,
    "GS7": 3322,
    "A7": 3520,
    "AS7": 3729,
    "B7": 3951,
    "C8": 4186,
    "CS8": 4435,
    "D8": 4699,
    "DS8": 4978,
    "E8": 5274,
    "F8": 5588,
    "FS8": 5920,
    "G8": 6272,
    "GS8": 6645,
    "A8": 7040,
    "AS8": 7459,
    "B8": 7902,
    0: 0,
    '0': 0,
    "SILENT": 0,
    "R": 0
}
mysong = ['E7', 'E7', 0, 'E7', 0, 'C7', 'E7', 0, 'G7', 0, 0, 0, 'G6', 0, 0, 0,
         'C7', 0, 0, 'G6', 0, 0, 'E6', 0, 0, 'A6', 0, 'B6', 0, 'AS6', 'A6', 0,
         'G6', 'E7', 'G7', 'A7', 0, 'F7', 'G7', 0, 'E7', 0, 'C7', 'D7', 'B6', 0, 0,
         'C7', 0, 0, 'G6', 0, 0, 'E6', 0, 0, 'A6', 0, 'B6', 0, 'AS6', 'A6', 0,
         'G6', 'E7', 'G7', 'A7', 0, 'F7', 'G7', 0, 'E7', 0, 'C7', 'D7', 'B6', 0, 0]
mytempo = [12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
          12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
          9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
          12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
          9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12]
# mysong = [0, 'B4', 0, 'D5', 0, 'F5', 0, 0, 0, 'D5', 'D5', 'D5', 0, 0, 'D5', 0, 'B4', 'B4', 0, 'F5', 0, 'F5', 0, 'G5', 0, 'G5', 0, 'F5', 0, 'F5', 0, 'D5', 0, 'F5', 0, 'F5', 0, 'D5', 0, 'D5', 0, 'C5', 0, 'F5'] 
# mytempo = [982, 459, 139, 272, 259, 189, 4001, 102, 102, 337, 0, 41, 1028, 120, 110, 61, 103, 96, 2261, 130, 250, 102, 187, 120, 171, 102, 158, 103, 167, 102, 198, 239, 282, 103, 126, 140, 120, 102, 179, 108, 181, 220, 2601, 103]
# mysong = [0, 'E5', 0, 'F5', 0, 'E5', 0, 'C5', 0, 'C5', 0, 'D5', 0, 'E5', 0, 'E5', 0, 'A5', 0, 'A5', 0, 'E5'] 
# mytempo = [467, 171, 219, 191, 239, 320, 480, 200, 231, 169, 261, 279, 521, 332, 267, 181, 62, 147, 281, 169, 261, 309]
mysong, mytempo = [0, 'B4', 0, 0, 'C5', 'C5', 0, 'D5', 0, 'B4', 0, 'D5', 0, 'D5', 0, 'E5', 0, 'F5', 0, 'D5', 0, 'F5', 0, 'G5', 0, 'A5', 0, 'B5', 0, 'A5', 0, 'G5', 0, 'F5', 0, 'E5', 0, 'D5', 0, 'C5', 0, 'C5', 0, 'C5', 0, 'D5', 0, 'E5', 0, 'C5', 0, 'D5', 0, 'D5', 0, 'E5', 0, 'F5', 0, 'D5', 0, 'F5', 0, 'B5', 0, 'A5', 0, 'G5', 0, 'F5', 0, 'E5', 0, 'D5', 0, 'C5', 0, 'B4'],  [1544, 217, 569, 489, 105, 285, 65, 602, 332, 257, 677, 461, 441, 173, 178, 193, 121, 266, 677, 477, 460, 411, 503, 303, 217, 232, 272, 519, 603, 281, 244, 291, 221, 522, 647, 324, 232, 359, 228, 383, 1409, 307, 666, 244, 332, 217, 303, 345, 652, 314, 1691, 560, 351, 201, 216, 276, 185, 247, 646, 266, 724, 201, 616, 479, 420, 247, 190, 247, 233, 169, 215, 204, 314, 397, 481, 328, 692, 356]
mysong, mytempo = [0, 'C5', 0, 'C5', 0, 'D5', 0, 'E5', 0, 'C5', 0, 'E5', 0, 'E5', 0, 'F5', 0, 'G5', 0, 'E5', 0, 'G5', 0, 'A5', 0, 'B5', 0, 'C6', 0, 'B5', 0, 'A5', 0, 'G5', 0, 'F5', 0, 'E5', 0, 'D5', 0, 'D5', 0, 'D5', 0, 'E5', 0, 'F5', 0, 'D5', 0, 'E5', 0, 'E5', 0, 'F5', 0, 'G5', 0, 'E5', 0, 'G5', 0, 'B5', 0, 'C6', 0, 'B5', 0, 'A5', 0, 'G5', 0, 'F5', 0, 'E5', 0, 'D5', 0, 'C5'], [900, 288, 556, 324, 107, 214, 226, 258, 580, 217, 669, 314, 483, 172, 206, 201, 261, 433, 412, 292, 489, 394, 406, 234, 165, 372, 801, 560, 417, 331, 64, 290, 198, 548, 434, 286, 154, 333, 155, 531, 1140, 459, 373, 342, 165, 405, 91, 420, 400, 220, 1455, 437, 393, 374, 35, 338, 97, 425, 421, 193, 612, 262, 573, 696, 277, 738, 284, 258, 185, 301, 120, 291, 192, 201, 270, 596, 268, 445, 535, 643]
mysong, mytempo = ['C5', 0, 'E5', 0, 'G5', 0, 'C5', 0, 'E5', 0, 'G5', 0, 'A5', 0, 'A5', 0, 'A5', 0, 'G5', 0, 'F5', 0, 'F5', 0, 'F5', 0, 'E5', 0, 'E5', 0, 'E5', 0, 'D5', 0, 'D5', 0, 'D5', 0, 'C5'] ,  [ 488, 373, 406, 824, 635, 184, 569, 139, 455, 275, 581, 159, 537, 225, 504, 278, 500, 244, 529, 1365, 513, 221, 374, 347, 519, 212, 495, 267, 491, 298, 504, 213, 565, 213, 359, 390, 225, 474, 899]
mysong, mytempo = [0, 'C5', 0, 'C5', 0, 'G5', 0, 'G5', 0, 'A5', 0, 'A5', 0, 'G5', 0, 'F5', 0, 'F5', 0, 'E5', 0, 'E5', 0, 'D5', 0, 'D5', 0, 'C5', 0, 'A5', 0, 'G5', 0, 'G5', 0, 'F5', 0, 'F5', 0, 'E5', 0, 'E5', 0, 'D5', 0, 'A5', 0, 'G5', 0, 'G5', 0, 'F5', 0, 'F5', 0, 'E5', 0, 'E5', 0, 'D5', 0, 'C5', 0, 'C5', 0, 'G5', 0, 'G5', 0, 'A5', 0, 'A5', 0, 'G5', 0, 'F5', 0, 'F5', 0, 'E5', 0, 'E5', 0, 'E5', 0, 'D5', 0, 'D5', 0, 'D5', 0, 'C5', 0, 0, 'E5', 'E5', 0, 'F5', 0, 'G5', 0, 0, 'A5', 'A5'] ,  [2838, 242, 293, 188, 293, 177, 297, 165, 376, 151, 392, 193, 344, 251, 797, 210, 323, 196, 320, 196, 284, 218, 289, 162, 358, 249, 304, 224, 861, 248, 318, 229, 292, 214, 276, 218, 281, 232, 340, 215, 260, 234, 300, 261, 724, 249, 327, 184, 310, 205, 260, 219, 276, 276, 222, 194, 342, 230, 285, 313, 646, 203, 307, 202, 268, 248, 275, 220, 238, 215, 326, 198, 330, 705, 512, 192, 504, 182, 149, 143, 32, 136, 267, 127, 365, 102, 255, 127, 197, 186, 523, 401, 868, 197, 103, 74, 126, 103, 102, 123, 110, 101, 107, 331]
mysong, mytempo = ['D5', 0, 'E5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'D5', 0, 'E5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'D5', 0, 'E5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'FS5', 0, 'D5', 0, 'E5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'D5', 0, 'E5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'D5', 0, 'E5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'G5', 0, 'FS5'] ,  [281, 307, 218, 353, 201, 402, 127, 175, 103, 31, 115, 196, 103, 181, 108, 317, 192, 143, 183, 125, 207, 337, 143, 171, 103, 41, 141, 322, 102, 35, 146, 177, 219, 75, 172, 141, 191, 375, 141, 173, 104, 69, 137, 224, 103, 46, 125, 350, 108, 279, 350, 480, 342, 1236, 201, 449, 160, 416, 290, 289, 139, 168, 103, 37, 126, 310, 103, 24, 122, 274, 223, 75, 167, 140, 176, 385, 192, 137, 108, 55, 126, 282, 106, 47, 127, 215, 230, 67, 131, 146, 180, 379, 137, 198, 103, 60, 105, 279, 106, 62, 202, 312, 155, 268, 281, 169, 1055]
mysong, mytempo = [0, 'C5', 0, 'D5', 0, 'E5', 0, 'C5', 0, 'E5', 0, 'C5', 0, 'E5', 0, 'D5', 0, 'E5', 0, 'F5', 0, 'F5', 0, 'D5', 0, 'E5', 0, 'D5', 0, 'F5', 0, 'E5', 0, 'F5', 0, 'G5', 0, 'E5', 0, 'G5', 0, 'E5', 0, 'G5', 0, 'F5', 0, 'G5', 0, 'A5', 0, 'A5', 0, 'G5', 0, 'F5', 0, 'A5', 0, 'G5', 0, 'C5', 0, 'D5', 0, 'E5', 0, 'F5', 0, 'G5', 0, 'A5', 0, 'A5', 0, 'A5', 0, 'D5', 0, 'E5', 0, 'F5', 0, 'G5', 0, 'A5', 0, 'B5', 0, 'B5', 0, 'E5', 0, 'F5', 0, 'G5', 0, 'A5', 0, 'B5', 0, 'C6', 0, 0, 'B5', 'B5', 0, 'B5', 0, 'A5', 0, 'E5', 0, 'F5', 0, 'A5', 0, 'F5', 0, 'B5'] ,  [1123, 659, 130, 161, 79, 559, 240, 139, 70, 480, 90, 430, 99, 580, 450, 760, 119, 140, 90, 51, 169, 80, 220, 409, 220, 179, 100, 170, 260, 752, 960, 738, 50, 109, 160, 240, 540, 99, 121, 209, 421, 400, 180, 490, 651, 749, 131, 89, 190, 50, 171, 79, 220, 140, 1041, 279, 160, 669, 1721, 690, 260, 99, 160, 68, 150, 129, 201, 210, 10, 180, 120, 540, 50, 120, 2200, 700, 241, 289, 421, 120, 120, 130, 129, 109, 162, 88, 501, 819, 1450, 961, 349, 371, 228, 120, 160, 130, 130, 169, 120, 179, 200, 510, 850, 360, 1, 97, 100, 29, 110, 1040, 1020, 1400, 590, 419, 2921, 759, 20, 481, 170, 559]


SCREEN_X = 640   # 화면 넓이
SCREEN_Y = 480   # 화면 높이
pygame.init()
screen = pygame.display.set_mode((SCREEN_X, SCREEN_Y))
ab= 100
for a in range(10):
	winsound.Beep(ab, 50)
	ab += 1000

for i in range(len(mysong)): 
	print(i)
	if mysong[i] != 0:
		winsound.Beep(tones[mysong[i]], mytempo[i])
	else :
		time.sleep(mytempo[i]/1000)

song=[]
temp=[]
key ='C5'
key_DOWN = False
playing = True
t_temp = pygame.time.get_ticks()
def keydown(note):
	global t_temp
	global key
	global key_DOWN
	
	# if not key_DOWN:
	
	key = note
	key_DOWN = True
	if int(pygame.time.get_ticks()-t_temp) != 0 :
		song.append(0)
		temp.append(int(pygame.time.get_ticks()-t_temp))
		winsound.Beep(tones[note],50)
	t_temp = pygame.time.get_ticks()

def keyup():
	global key
	global t_temp
	global	key_DOWN
	if int(pygame.time.get_ticks()-t_temp) != 0 :
		# if key_DOWN:
		song.append(key)
		temp.append(int(pygame.time.get_ticks()-t_temp))
		t_temp = pygame.time.get_ticks()
		key_DOWN = False

while(playing):
	pressed_key = pygame.key.get_pressed()
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			playing = False
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_1:
				keydown('C2')
			if event.key == pygame.K_2:
				keydown('D2')
			if event.key == pygame.K_3:
				keydown('E2')
			if event.key == pygame.K_4:
				keydown('F2')
			if event.key == pygame.K_5:
				keydown('G2')
			if event.key == pygame.K_6:
				keydown('A2')
			if event.key == pygame.K_7:
				keydown('B2')
			if event.key == pygame.K_8:
				keydown('C3')
			if event.key == pygame.K_9:
				keydown('D3')
			if event.key == pygame.K_0:
				keydown('E3')

			if event.key == pygame.K_q:
				keydown('F3')
			if event.key == pygame.K_w:
				keydown('G3')
			if event.key == pygame.K_e:
				keydown('A3')
			if event.key == pygame.K_r:
				keydown('B3')
			if event.key == pygame.K_t:
				keydown('C4')
			if event.key == pygame.K_y:
				keydown('D4')
			if event.key == pygame.K_u:
				keydown('E4')
			if event.key == pygame.K_i:
				keydown('F4')
			if event.key == pygame.K_o:
				keydown('G4')
			if event.key == pygame.K_p:
				keydown('A4')

			if event.key == pygame.K_a:
				keydown('B4')
			if event.key == pygame.K_s:
				keydown('C5')
			if event.key == pygame.K_d:
				keydown('D5')
			if event.key == pygame.K_f:
				keydown('E5')
			if event.key == pygame.K_g:
				keydown('F5')
			if event.key == pygame.K_h:
				keydown('G5')
			if event.key == pygame.K_j:
				keydown('A5')
			if event.key == pygame.K_k:
				keydown('B5')
			if event.key == pygame.K_l:
				keydown('C6')

			if event.key == pygame.K_z:
				keydown('D6')
			if event.key == pygame.K_x:
				keydown('E6')
			if event.key == pygame.K_c:
				keydown('F6')
			if event.key == pygame.K_v:
				keydown('G6')
			if event.key == pygame.K_b:
				keydown('A6')
			if event.key == pygame.K_n:
				keydown('B6')
			if event.key == pygame.K_m:
				keydown('C7')
			if event.mod == pygame.KMOD_NONE:
				pass
			else:
				if event.mod & pygame.KMOD_LSHIFT:
					if event.key == pygame.K_1:
						keydown('CS2')
					if event.key == pygame.K_2:
						keydown('DS2')
					if event.key == pygame.K_4:
						keydown('FS2')
					if event.key == pygame.K_5:
						keydown('GS2')
					if event.key == pygame.K_6:
						keydown('AS2')
					if event.key == pygame.K_8:
						keydown('CS3')
					if event.key == pygame.K_9:
						keydown('DS3')

					if event.key == pygame.K_q:
						keydown('FS3')
					if event.key == pygame.K_w:
						keydown('GS3')
					if event.key == pygame.K_e:
						keydown('AS3')
					if event.key == pygame.K_t:
						keydown('CS4')
					if event.key == pygame.K_y:
						keydown('DS4')
					if event.key == pygame.K_i:
						keydown('FS4')
					if event.key == pygame.K_o:
						keydown('GS4')
					if event.key == pygame.K_p:
						keydown('AS4')

					if event.key == pygame.K_s:
						keydown('CS5')
					if event.key == pygame.K_d:
						keydown('DS5')
					if event.key == pygame.K_g:
						keydown('FS5')
					if event.key == pygame.K_h:
						keydown('GS5')
					if event.key == pygame.K_l:
						keydown('AS5')

					if event.key == pygame.K_z:
						keydown('DS6')
					if event.key == pygame.K_c:
						keydown('FS6')
					if event.key == pygame.K_v:
						keydown('GS6')
					if event.key == pygame.K_b:
						keydown('AS6')


		if event.type == pygame.KEYUP:
			if event.key == pygame.K_1:
				keyup()
			if event.key == pygame.K_2:
				keyup()
			if event.key == pygame.K_3:
				keyup()
			if event.key == pygame.K_4:
				keyup()
			if event.key == pygame.K_5:
				keyup()
			if event.key == pygame.K_6:
				keyup()
			if event.key == pygame.K_7:
				keyup()
			if event.key == pygame.K_8:
				keyup()
			if event.key == pygame.K_9:
				keyup()
			if event.key == pygame.K_0:
				keyup()

			if event.key == pygame.K_q:
				keyup()
			if event.key == pygame.K_w:
				keyup()
			if event.key == pygame.K_e:
				keyup()
			if event.key == pygame.K_r:
				keyup()
			if event.key == pygame.K_t:
				keyup()
			if event.key == pygame.K_y:
				keyup()
			if event.key == pygame.K_u:
				keyup()
			if event.key == pygame.K_i:
				keyup()
			if event.key == pygame.K_o:
				keyup()
			if event.key == pygame.K_p:
				keyup()

			if event.key == pygame.K_a:
				keyup()
			if event.key == pygame.K_s:
				keyup()
			if event.key == pygame.K_d:
				keyup()
			if event.key == pygame.K_f:
				keyup()
			if event.key == pygame.K_g:
				keyup()
			if event.key == pygame.K_h:
				keyup()
			if event.key == pygame.K_j:
				keyup()
			if event.key == pygame.K_k:
				keyup()
			if event.key == pygame.K_l:
				keyup()

			if event.key == pygame.K_z:
				keyup()
			if event.key == pygame.K_x:
				keyup()
			if event.key == pygame.K_c:
				keyup()
			if event.key == pygame.K_v:
				keyup()
			if event.key == pygame.K_b:
				keyup()
			if event.key == pygame.K_n:
				keyup()
			if event.key == pygame.K_m:
				keyup()
			if event.mod == pygame.KMOD_NONE:
				pass
			else:
				if event.mod & pygame.KMOD_LSHIFT:
					if event.key == pygame.K_1:
						keyup()
					if event.key == pygame.K_2:
						keyup()
					if event.key == pygame.K_4:
						keyup()
					if event.key == pygame.K_5:
						keyup()
					if event.key == pygame.K_6:
						keyup()
					if event.key == pygame.K_8:
						keyup()
					if event.key == pygame.K_9:
						keyup()

					if event.key == pygame.K_q:
						keyup()
					if event.key == pygame.K_w:
						keyup()
					if event.key == pygame.K_e:
						keyup()
					if event.key == pygame.K_t:
						keyup()
					if event.key == pygame.K_y:
						keyup()
					if event.key == pygame.K_i:
						keyup()
					if event.key == pygame.K_o:
						keyup()
					if event.key == pygame.K_p:
						keyup()

					if event.key == pygame.K_s:
						keyup()
					if event.key == pygame.K_d:
						keyup()
					if event.key == pygame.K_g:
						keyup()
					if event.key == pygame.K_h:
						keyup()
					if event.key == pygame.K_l:
						keyup()

					if event.key == pygame.K_z:
						keyup()
					if event.key == pygame.K_c:
						keyup()
					if event.key == pygame.K_v:
						keyup()
					if event.key == pygame.K_b:
						keyup()

	print(song,", ", temp)
