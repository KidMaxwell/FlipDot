import subprocess
from time import sleep

class DotsRaspi:
    """represents a Dot on the FlipDot Display"""
    
    def __init__(self,column, row):
        self.row=row
        self.column=column
        self.state=False
        subprocess.Popen(["FlipDotShort", str(self.row), str(self.column), str(self.state)])
        sleep(0.01)

    def setState(self, newState):
        self.state=newState
        subprocess.Popen(["FlipDotShort", str(self.row), str(self.column), str(self.state)])
        sleep(0.01)
    
