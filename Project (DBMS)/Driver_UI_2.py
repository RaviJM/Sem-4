import tkinter as tk


class DriverUI:
    def __init__(self, master):
        self.master = master
        master.title("CABoom")

        # create notification box
        self.notification_frame = tk.Frame(master, padx=10, pady=10)
        self.notification_frame.pack()

        self.notification_label = tk.Label(self.notification_frame, text="No new ride requests")
        self.notification_label.pack(side=tk.LEFT)

        self.accept_button = tk.Button(self.notification_frame, text="Accept", bg="green", fg="black",
                                       state=tk.NORMAL)
        self.accept_button.pack(side=tk.LEFT, padx=10)

        self.decline_button = tk.Button(self.notification_frame, text="Decline", bg="red", fg="black",
                                        state=tk.NORMAL)
        self.decline_button.pack(side=tk.LEFT)

        # create a driver account menu
        self.driver_menu = tk.Menu(master)
        self.details_menu = tk.Menu(self.driver_menu, tearoff=0)
        self.details_menu.add_command(label="Account", command=self.show_account_details)
        self.details_menu.add_command(label="History", command=self.show_ride_history)
        self.driver_menu.add_cascade(label="Details", menu=self.details_menu)
        master.config(menu=self.driver_menu)

        # run main loop
        self.update_notification()
        master.mainloop()

    def update_notification(self):
        # update the notification box
        self.notification_label.config(text="No new ride requests")
        self.accept_button.config(state=tk.NORMAL)
        self.decline_button.config(state=tk.NORMAL)

        # check for new ride requests every 2 seconds
        self.master.after(2000, self.update_notification)

    def show_account_details(self):
        # create a new window to show driver account details
        account_window = tk.Toplevel(self.master)
        account_window.title("Driver Account Details")

        # create labels to display driver account details
        name_label = tk.Label(account_window, text="Name: Adit Shah")
        name_label.pack()

        age_label = tk.Label(account_window, text="Age: 20")
        age_label.pack()

        car_label = tk.Label(account_window, text="Car: Ferrari LaFerrari")
        car_label.pack()

    def show_ride_history(self):
        # create a new window to show driver ride history
        history_window = tk.Toplevel(self.master)
        history_window.title("Driver Ride History")

        # create labels to display driver ride history

        ride_id = tk.Label(history_window, text ="Ride 1-")
        ride_id.pack()

        customer_id = tk.Label(history_window, text = "C_ID: 2342")
        customer_id.pack()

        date_label = tk.Label(history_window, text="Date: 04-04-2023")
        date_label.pack()

        start_label = tk.Label(history_window, text="Start Location: Pandit Deendayal Energy University")
        start_label.pack()

        end_label = tk.Label(history_window, text="End Location: Ahmedabad International Airport")
        end_label.pack()

        fare_label = tk.Label(history_window, text="Fare: $1200")
        fare_label.pack()

        ride_id = tk.Label(history_window, text="Ride 2-")
        ride_id.pack()

        customer_id = tk.Label(history_window, text = "C_ID: 8397")
        customer_id.pack()

        date_label = tk.Label(history_window, text="Date: 09-04-2023")
        date_label.pack()

        start_label = tk.Label(history_window, text="Start Location: Ahmedabad One Mall")
        start_label.pack()

        end_label = tk.Label(history_window, text="End Location: Taj Skyline")
        end_label.pack()

        fare_label = tk.Label(history_window, text="Fare: $1900")
        fare_label.pack()

root = tk.Tk()
app = DriverUI(root)
root.mainloop()
