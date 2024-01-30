from tkinter import *
from tkinter import messagebox
import tkinter.messagebox as tmsg
import pymysql

def show_login_frame():
    login_frame.pack()
    login_frame.tkraise()

    frame1.pack_forget()
    frame2.pack_forget()
    signup_frame.pack_forget()

def show_signup_frame():
    signup_frame.pack()
    signup_frame.tkraise()

    login_frame.pack_forget()
    frame1.pack_forget()
    frame2.pack_forget()


def show_User_UI_frame():
    frame1.pack()
    frame1.tkraise()
    frame2.pack()
    frame2.tkraise()

    signup_frame.pack_forget()
    login_frame.pack_forget()

def login():
    username = login_username_entry.get()
    password = login_password_entry.get()

    #Check if username and password are valid
    mycursor.execute(f'''select username from users where username = "{username}"''')
    username2 = mycursor.fetchone()
    mycursor.execute(f'''select password from users where password = "{password}"''')
    password2 = mycursor.fetchone()

    if username2 == None:
        username2 = "None"
    if password2 == None:
        password2 = "None"
    if (username == username2[0] and password == password2[0]):
        messagebox.showinfo("Login Successful", "Welcome, {}".format(username))
        #raise the User_UI frame and change root dimensions
        root.geometry("400x180")
        show_User_UI_frame()
    else:
        messagebox.showerror("Login Failed", "Invalid username or password")

def signup():

    #userid      #(will be automatically added)
    username3 = signup_username_entry.get()
    password3 = signup_password_entry.get()
    email3 = signup_email_entry.get()
    phoneNumber3 = signup_phoneNumber_entry.get()
    address3 = signup_address_entry.get()
    #paymentDetails     (will be added later)
    #createdAt      (will be automatically added)

    mycursor.execute(f'''select count(username) from users where username = "{username3}"''')
    a = mycursor.fetchone()

    # insert only if entry is unique (doesn't already exist in table)
    if a[0] == 0:
        mycursor.execute(
            f'''insert into users(username,password,email,phone_number,address) values("{username3}","{password3}","{email3}","{phoneNumber3}","{address3}")''')
        mydb.commit()
        messagebox.showinfo("Signup Successful", "Account created for {}".format(username3))
        show_login_frame()
    else:
        # show error
        messagebox.showerror("Unsuccessful", "User already exists by this Name!")

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













#connect with mysql connector
mydb = pymysql.connect(host="localhost", user="root", passwd="ravi123", database="projdb")
mycursor = mydb.cursor()

# Create main window
root = Tk()
root.title("Book My Cab")
root.geometry("400x400")
# root.minsize(400, 220)
# root.maxsize(400, 220)

# Create login frame
login_frame = Frame(root, height=400, width=400)
login_frame.pack()

login_label = Label(login_frame, text="Login", font=("Helvetica", 16))
login_label.pack(pady=20)

login_username_label = Label(login_frame, text="Username")
login_username_label.pack()
login_username_entry = Entry(login_frame)
login_username_entry.pack(pady=30)

login_password_label = Label(login_frame, text="Password")
login_password_label.pack()
login_password_entry = Entry(login_frame, show="*")
login_password_entry.pack(pady=30)

login_button = Button(login_frame, text="Login", height=2, width=8, command=login)
login_button.pack(pady=20)

signup_link = Label(login_frame, text="New user? Signup here", fg="blue", cursor="hand2")
signup_link.pack()
signup_link.bind("<Button-1>", lambda event: show_signup_frame())

# Create signup frame
signup_frame = Frame(root, height=400, width=400)
signup_frame.pack()

signup_label = Label(signup_frame, text="Signup", font=("Helvetica", 16))
signup_label.pack(pady=20)

signup_username_label = Label(signup_frame, text="Username")
signup_username_label.pack()
signup_username_entry = Entry(signup_frame)
signup_username_entry.pack()

signup_password_label = Label(signup_frame, text="Password")
signup_password_label.pack()
signup_password_entry = Entry(signup_frame, show="*")
signup_password_entry.pack()

signup_email_label = Label(signup_frame, text="Email")
signup_email_label.pack()
signup_email_entry = Entry(signup_frame)
signup_email_entry.pack()

signup_phoneNumber_label = Label(signup_frame, text="Phone Number")
signup_phoneNumber_label.pack()
signup_phoneNumber_entry = Entry(signup_frame)
signup_phoneNumber_entry.pack()

signup_address_label = Label(signup_frame, text="Address")
signup_address_label.pack()
signup_address_entry = Entry(signup_frame)
signup_address_entry.pack()

signup_button = Button(signup_frame, text="Signup", height=2, width=8, command=signup)
signup_button.pack(pady=20)

login_link = Label(signup_frame, text="Already have an account? Login here", fg="blue", cursor="hand2")
login_link.pack()
login_link.bind("<Button-1>", lambda event: show_login_frame())

#########################################################################################################
#########################################################################################################
#########################################################################################################
#           USER UI INTERFACE STARTS HERE       #

frame1 = Frame(root, bg="orange", height=200, width=400)
# frame1.config(height=10)
frame1.pack(side=TOP, padx=40, pady=30)

#making labels Start Location & End Location
#########################################################################################################

#start Location label
startLabel = Label(frame1, text="Start Location", font="arial 15 bold", bg="sky blue")
startLabel.grid(row=0, column=0, padx=15, pady=5)
# startLabel.pack(side=LEFT)

#end Location label
endLabel = Label(frame1, text="End Location", font="arial 15 bold", bg="sky blue")
endLabel.grid(row=0, column=1, padx=15, pady=5)
# endLabel.pack(side=LEFT)

#########################################################################################################

#making dropdown menus for Start Location & End Location
#########################################################################################################

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
#########################################################################################################

#making frame for CheckFareButton and BookRideButton and adding buttons
#########################################################################################################
#making buttons
frame2 = Frame(root)
frame2.pack()

# making Button for Checking Fare
b1 = Button(frame2, fg="black", text="Check Fare", height=2, width=10, command=CheckFare)
b1.grid(row=0, column=0)
# making Button for Booking Ride
b2 = Button(frame2, fg="black", text="Book Ride", height=2, width=10, command=BookRide)
b2.grid(row=0, column=1)
#########################################################################################################

# Show login frame initially
show_login_frame()

root.mainloop()
