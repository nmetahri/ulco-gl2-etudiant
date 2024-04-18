import gi
import math
from tictactoe import *

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk, Gdk

class Gui(Gtk.Window):
    
    def __init__(self):
        super().__init__(title="Tictactoe")
        self.set_size_request (400, 450)
        self.case_size = 125

        # main vertical box : drawing area + hbox (label, button1, button2)
        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
        self.add(vbox)

        # drawing area
        self.drawingarea = Gtk.DrawingArea()
        self.drawingarea.add_events(Gdk.EventMask.BUTTON_PRESS_MASK)
        self.drawingarea.connect("draw", self.on_draw)
        self.drawingarea.connect("button-press-event", self.on_area_button_press)
        vbox.pack_start(self.drawingarea, True, True, 0)

        # horizontal box
        hbox = Gtk.Box()
        vbox.pack_end(hbox, False, False, 0)
        # label
        self.label = Gtk.Label(label="Starting...")
        hbox.pack_start(self.label, True, True, 0)
        # button1
        button1 = Gtk.Button(label="rejouer")
        button1.connect("clicked", self.on_button1_clicked)
        hbox.pack_start(button1, True, True, 0)
        # button2
        button2 = Gtk.Button(label="quitter")
        button2.connect("clicked", self.on_button2_clicked)
        hbox.pack_start(button2, True, True, 0)

        # create game (from the C++ module)
        self.game = Jeu()
        # print(self.game.isGameFinished())
    

    def on_draw(self, widget, context):
        self.label.set_text(self.game.getStatus().name)
        
        width = widget.get_allocated_width()
        height = widget.get_allocated_height()

        for i in range(0,3):
            for j in range(0,3):
                cell = self.game.getCell(i,j)

                pos_x = self.case_size * i
                pos_y = self.case_size * j

                context.set_source_rgb(0, 0, 0)
                context.rectangle(pos_x, pos_y, self.case_size, self.case_size)
                context.fill()
                
                if (cell.name != "Vide"):
                    if (cell.name == "Rouge"):
                        context.set_source_rgb(255, 0, 0)
                    elif (cell.name == "Vert"):
                        context.set_source_rgb(0, 255, 0)
                    else :
                        break
                    context.arc(pos_x + self.case_size / 2, pos_y + self.case_size / 2, self.case_size / 2 - 10, 0.0, 2 * math.pi)
                    context.fill()

                context.set_source_rgb(0.5, 0.5, 0.5)
            
                context.set_line_width(3)

                context.move_to(pos_x + self.case_size, pos_y)
                context.line_to(pos_x + self.case_size, pos_y + self.case_size)
                context.stroke()

                context.move_to(pos_x + self.case_size, pos_y + self.case_size)
                context.line_to(pos_x, pos_y + self.case_size)
                context.stroke()


    def on_area_button_press(self, widget, event):
        # TODO on_area_button_press
        if event.button == 1:
            print('TODO on_area_button_press')


    def on_button1_clicked(self, widget):
        self.game = Jeu()
        self.drawingarea.queue_draw()

    def on_button2_clicked(self, widget):
        Gtk.main_quit()

if __name__ == '__main__':
    gui = Gui()
    gui.connect("destroy", Gtk.main_quit)
    gui.show_all()
    Gtk.main()

