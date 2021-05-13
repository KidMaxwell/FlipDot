
class Dots:
    """represents a Dot on the FlipDot Display"""
    
    def __init__(self,column, row):
        self.column=column
        self.row=row
        self.state=False
        
    def setState(self, newState):
        self.state=newState
        
    
