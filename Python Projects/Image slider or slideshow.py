# This is an python GUI program which is used to have image slide show.
 
# importing the modules
from itertools import cycle
import tkinter as tk
 
# creating a class called imageShow
class App(tk.Tk):
 
    # __init__ function
    def __init__(self, image_file, x, y, delay):
 
        # creating a display window
        tk.Tk.__init__(self)
        self.geometry('+{}+{}'.format(x, y))
        self.delay = delay
        self.pictures = cycle((tk.PhotoImage(file = image), image)
        for image in image_file)
        self.pictures_display=tk.Label(self)
        self.pictures_display.pack()
 
    def show(self):
 
        image_obj, image_name = next(self.pictures)
        self.pictures_display.config(image=image_obj)
        self.title(image_name)
        self.after(self.delay, self.show)
 
    def runApp(self):
        self.mainloop()
 
delay = 4000
 
image_file = [
    '1.gif',
    '2.gif',
    '3.gif',
    '4.gif',
    '5.gif',
    '6.gif',
    '7.gif',
    '8.gif',
    '9.gif',
    '10.gif'
]
 
x = 100
y = 50
 
image_show = App(image_file, x, y, delay)
image_show.show()
image_show.runApp()
