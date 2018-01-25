import curses, serial
def main():
    #set up curses window
    STDSCR = curses.initscr()
    #turn off keys echoing to screen 
    curses.noecho()
    #react to keys being pressed instantaneously instead of     waiting for enter to be pressed
    curses.cbreak()
    #replace default values returned with things like the   arrow keys to things like curses.KEY_LEFT
    STDSCR.keypad(True)

    #set up serial
    #This is currently a linux only implementation. Windows     users
    #should change the /dev/tty* to their COM ports. The
    #COM port that the arduino is located on can be easily 
    #determined within the arduino IDE but make sure they   are
    #the same otherwise no juice. 
    try:
        ser = serial.Serial('/dev/ttyUSB1')
    except serial.SerialException:
        ser = serial.Serial('/dev/ttyUSB0')

    STDSCR.addstr("To exit the program, press CTRL + C in   order to quit the process. ")
    #To change keybindings for the movement change 
    #the keys shown here. You may need to refer to the 
    #python curses documentation which can be reached at    https://docs.python.org/3/library/curses.html for  non-ascii keys. 
    while True: 
        c = STDSCR.getch()
        if c == ord('w') or c == curses.KEY_UP:   
            ser.write('w'.encode())
        elif c == ord('a') or c == curses.KEY_LEFT:
            ser.write('a'.encode())
        elif c == ord('s') or c == curses.KEY_DOWN:
            ser.write('s'.encode())
        elif c == ord('d') or c == curses.KEY_RIGHT:
            ser.write('d'.encode())
        elif c == ord('f'):
            ser.write('f'.encode())
