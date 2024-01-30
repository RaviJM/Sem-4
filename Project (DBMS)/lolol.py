import tkinter as tk
from tkinter import messagebox
import pymysql
mydb = pymysql.connect(host="localhost", user="root", passwd="ravi123", database="projdb")
mycursor = mydb.cursor()

userid = 1


def show_login_frame():
    login_frame.tkraise()

def show_signup_frame():
    signup_frame.tkraise()

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
        #enter into the new window





    else:
        messagebox.showerror("Login Failed", "Invalid username or password")




#haven't applied the logic of showing error if user already exists
def signup():

    global userid

    userid +=0      #(will be automatically added)
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








# Create main window
root = tk.Tk()
root.title("Login and Signup")
root.geometry("210x400")

# Create login frame
login_frame = tk.Frame(root)
login_frame.grid(row=0, column=0)


login_label = tk.Label(login_frame, text="Login", font=("Helvetica", 16))
login_label.pack(pady=20)

login_username_label = tk.Label(login_frame, text="Username")
login_username_label.pack()
login_username_entry = tk.Entry(login_frame)
login_username_entry.pack(pady=30)

login_password_label = tk.Label(login_frame, text="Password")
login_password_label.pack()
login_password_entry = tk.Entry(login_frame, show="*")
login_password_entry.pack(pady=30)

login_button = tk.Button(login_frame, text="Login", command=login)
login_button.pack(pady=20)

signup_link = tk.Label(login_frame, text="New user? Signup here", fg="blue", cursor="hand2")
signup_link.pack()
signup_link.bind("<Button-1>", lambda event: show_signup_frame())

# Create signup frame
signup_frame = tk.Frame(root)
signup_frame.grid(row=0, column=0)

signup_label = tk.Label(signup_frame, text="Signup", font=("Helvetica", 16))
signup_label.pack(pady=20)

signup_username_label = tk.Label(signup_frame, text="Username")
signup_username_label.pack()
signup_username_entry = tk.Entry(signup_frame)
signup_username_entry.pack()

signup_password_label = tk.Label(signup_frame, text="Password")
signup_password_label.pack()
signup_password_entry = tk.Entry(signup_frame, show="*")
signup_password_entry.pack()

signup_email_label = tk.Label(signup_frame, text="Email")
signup_email_label.pack()
signup_email_entry = tk.Entry(signup_frame)
signup_email_entry.pack()

signup_phoneNumber_label = tk.Label(signup_frame, text="Phone Number")
signup_phoneNumber_label.pack()
signup_phoneNumber_entry = tk.Entry(signup_frame)
signup_phoneNumber_entry.pack()

signup_address_label = tk.Label(signup_frame, text="Address")
signup_address_label.pack()
signup_address_entry = tk.Entry(signup_frame)
signup_address_entry.pack()

signup_button = tk.Button(signup_frame, text="Signup", command=signup)
signup_button.pack(pady=20)

login_link = tk.Label(signup_frame, text="Already have an account? Login here", fg="blue", cursor="hand2")
login_link.pack()
login_link.bind("<Button-1>", lambda event: show_login_frame())

# Show login frame initially
show_login_frame()

# Start GUI event loop
root.mainloop()
