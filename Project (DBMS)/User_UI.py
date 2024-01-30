from tkinter import *
import tkinter.messagebox as tmsg

def CheckFare():
    a = clickedS.get()
    b = clickedE.get()
    fare = 0

    if a == "Select Pick-up point" or b == "Select Destination point":
        tmsg.showerror("Invalid", "Please select Pick-up and Destination point")

    elif a == b:
        tmsg.showerror("Invalid", "Pick-up and Drop location must be different!")

    else:
        if (a == "Raysan" and b == "Kalupur") or (a == "Kalupur" and b == "Raysan"):
            fare = 240
        elif (a == "Raysan" and b == "Motera") or (a == "Motera" and b == "Raysan"):
            fare = 110
        elif (a == "Raysan" and b == "Iskon") or (a == "Iskon" and b == "Raysan"):
            fare = 310
        elif (a == "Raysan" and b == "Satellite") or (a == "Satellite" and b == "Raysan"):
            fare = 320
        elif (a == "Kalupur" and b == "Motera") or (a == "Motera" and b == "Kalupur"):
            fare = 130
        elif (a == "Kalupur" and b == "Iskon") or (a == "Iskon" and b == "Kalupur"):
            fare = 100
        elif (a == "Kalupur" and b == "Satellite") or (a == "Satellite" and b == "Kalupur"):
            fare = 100
        elif (a == "Motera" and b == "Iskon") or (a == "Iskon" and b == "Motera"):
            fare = 230
        elif (a == "Motera" and b == "Satellite") or (a == "Satellite" and b == "Motera"):
            fare = 230
        elif (a == "Iskon" and b == "Satellite") or (a == "Satellite" and b == "Iskon"):
            fare = 30

        tmsg.showinfo(f"Fare", f"The Fare of your Ride will be : Rs. {fare}")



def BookRide():

    ##      INSERT DATA INTO MySQL TABLE HERE
    ##      DISPLAY MSG THAT RIDE IS BOOKED!
    pass







root = Tk()
root.geometry("400x220")
root.minsize(400, 220)
root.maxsize(400, 220)
root.title("Book My Cab")


frame1 = Frame(root, borderwidth=15, bg="sky blue")
# frame1.config(height=10)
frame1.pack(side=TOP)






#making labels Start Location & End Location
####################################################################################

#start Location label
startLabel = Label(frame1, text="Start Location", font="arial 15 bold", bg="sky blue")
startLabel.grid(row=0, column=0, padx=15, pady=5)
# startLabel.pack(side=LEFT)

#end Location label
endLabel = Label(frame1, text="End Location", font="arial 15 bold", bg="sky blue")
endLabel.grid(row=0, column=1, padx=15, pady=5)
# endLabel.pack(side=LEFT)

####################################################################################



#making dropdown menus for Start Location & End Location
####################################################################################

#start location dropdown menu
sOptions = ["Raysan", "Kalupur", "Motera", "Iskon", "Satellite"]

#data type of menu text
clickedS = StringVar()

#initial menu text
clickedS.set("Select Pick-up point")

#create dropdown menu
sDrop = OptionMenu(frame1, clickedS, *sOptions)
sDrop.grid(row=1, column=0, padx=15, pady=15)



#end location dropdown menu
eOptions = ["Raysan", "Kalupur", "Motera", "Iskon", "Satellite"]

#data type of menu text
clickedE = StringVar()

#initial menu text
clickedE.set("Select Destination point")

#create dropdown menu
eDrop = OptionMenu(frame1, clickedE, *eOptions)
eDrop.grid(row=1, column=1, padx=15, pady=15)
####################################################################################



#making frame for CheckFareButton and BookRideButton and adding buttons
####################################################################################
#making buttons
frame2 = Frame(root, borderwidth=5, bg="sky blue")
frame2.pack(side=TOP)



# making Button for Checking Fare
b1 = Button(frame2, fg="black", text="Check Fare", height=2, width=10, command=CheckFare)
b1.pack(side=LEFT, padx=10, pady=20)

# making Button for Booking Ride
b2 = Button(frame2, fg="black", text="Book Ride", height=2, width=10, command=BookRide)
b2.pack(side=LEFT, padx=10, pady=20)
####################################################################################





root.mainloop()
