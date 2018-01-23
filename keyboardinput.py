import curses, serial

#set up curses window
STDSCR = curses.initscr()
#turn off keys echoing to screen 
#curses.noecho()
#react to keys being pressed instantaneously instead of waiting for enter to be pressed
curses.cbreak()
#replace default values returned with things like the arrow keys to things like curses.KEY_LEFT
STDSCR.keypad(True)

#set up serial
ser = serial.Serial('/dev/ttyUSB0')

while True: 
    c = STDSCR.getch()
    if c == ord('w'):   
        ser.write('w'.encode())
    elif c == ord('a'):
        ser.write('a'.encode())
    elif c == ord('s'):
        ser.write('s'.encode())
    elif c == ord('d'):
        ser.write('d'.encode())


def exit():
    curses.nocbreak()
    STDSCR.keypad(False)
    curses.echo()
    curses.endwin()