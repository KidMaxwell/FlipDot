from dots_raspi import DotsRaspi
from dots import Dots
import datetime
import time

class FlipDot:
    """FlipDot class"""
    
    def __init__(self):
        self.ROWS=16
        self.COLUMNS=28
        self.alphabet=list(open('5x7.font', 'r'))
        self.showInConsole=False

        self.Display=[[0 for r in range(self.ROWS)] for c in range(self.COLUMNS)]

        for c in range(self.COLUMNS):
            for r in range(self.ROWS):
                self.Display[c][r]=DotsRaspi(c,r)
                
        print('Welcome to FlipDot v.1.0')
            
    
    def printDisplay(self):
        print('- - - - - - - - - - - - - - - - - - - - - - - - - - - -')
        for r in range(self.ROWS):
            for c in range(self.COLUMNS):
                if self.Display[c][r].state==True:
                    print('o', end='')
                else:
                    print(' ', end='')
                print(' ', end='')
            print()
        print('- - - - - - - - - - - - - - - - - - - - - - - - - - - -')
    
    def clock(self):
        try:
            while True:
                self.currentTime=str(datetime.datetime.now().time())
                self.import5x7(self.currentTime[0])
                self.segmentFlip(1,4)
                self.import5x7(self.currentTime[1])
                self.segmentFlip(7,4)
                self.singleFlip(13,6,1)
                self.singleFlip(13,8,1)
                self.import5x7(self.currentTime[3])
                self.segmentFlip(15,4)
                self.import5x7(self.currentTime[4])
                self.segmentFlip(21,4)
                self.displayFlip(self.Display)
                self.printDisplay()
                time.sleep(30)
        except KeyboardInterrupt:
            pass
        
    def singleFlip(self, c, r, newState):
        """Flips one Dot"""
        self.Display[c][r].setState(newState)
        
    def segmentFlip(self, TLc, TLr):
        """Flips whatever stands in self.segment"""
        "So first put something into segment, then do a segmentFlip with its position"

        for r in range(len(self.segment[0])):
            for c in range(len(self.segment)):
                #if self.Display[TLc+c][TLr+r].state!=self.segment[c][r].state:
                    self.Display[TLc+c][TLr+r].setState(self.segment[c][r].state)                

    def displayFlip(self, Display):
        for c in range(self.COLUMNS):
            for r in range(self.ROWS):
                #if self.Display[c][r].state!=Display[c][r].state:
                    self.Display[c][r].setState(Display[c][r].state)
        
        
        
        
    def import5x7(self, char):
        """Reads Dot Font from File"""
        
        self.tableRow=ord(char)-32                                                                  #um in 5x7.font den richtigen Eintrag zu erwischen muss man 32 vom Hex wert abziehen
        self.segment=[[0 for r in range(7)] for c in range(5)]                                      #erstelle das segment (2D Liste)
        
        for c in range(5):
            for r in range(7):
                self.segment[c][r]=Dots(c,r)
        
        self.charList=self.alphabet[self.tableRow].split(', ')                                      #Den gelesenen String splitten
        
        #print(self.charList)
        
        for c in range(5):
            self.currentColumnValue=self.charList[c][2:]                                            #in Abhaengigkeit von c den Hex Wert (ohne 0x) als String lesen
            self.currentBitarray='{0:08b}'.format(int(self.currentColumnValue, 16))                 #aus dem Hex String ein Bin String mit festem Format erzeugen
            #print(self.currentColumnValue)
            #print(self.currentBitarray)
            for r in range(7):
                    self.segment[c][r].setState(int(self.currentBitarray[7-r]))                     #states in segment setzen
        if self.showInConsole==True:
            print('- - - - - - - - - - - - - - - - - - - - - - - - - - - -')
            for r in range(7):
                for c in range(5):
                    if self.segment[c][r].state==True:
                        print('o', end='')
                    else:
                        print(' ', end='')
                    print(' ', end='')
                print()
            print('- - - - - - - - - - - - - - - - - - - - - - - - - - - -')
        
a=FlipDot()
a.clock()
a.printDisplay()
