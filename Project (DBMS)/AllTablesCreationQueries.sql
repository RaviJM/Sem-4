use projdb;
CREATE TABLE Users (
  user_id INT PRIMARY KEY AUTO_INCREMENT,
  username VARCHAR(50) NOT NULL,
  password VARCHAR(255) NOT NULL,
  email VARCHAR(255) NOT NULL,
  phone_number VARCHAR(15) NOT NULL,
  address VARCHAR(255) NOT NULL,
  payment_details VARCHAR(255),
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);


CREATE TABLE Vehicles (
  vehicle_id INT PRIMARY KEY AUTO_INCREMENT,
  make VARCHAR(50) NOT NULL,
  model VARCHAR(50) NOT NULL,
  year INT NOT NULL,
  color VARCHAR(50) NOT NULL,
  license_plate VARCHAR(20) NOT NULL,
  capacity INT NOT NULL,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);


CREATE TABLE Drivers (
  driver_id INT PRIMARY KEY AUTO_INCREMENT,
  username VARCHAR(50) NOT NULL,
  password VARCHAR(255) NOT NULL,
  email VARCHAR(255) NOT NULL,
  phone_number VARCHAR(15) NOT NULL,
  name VARCHAR(100) NOT NULL,
  address VARCHAR(255) NOT NULL,
  vehicle_id INT,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  FOREIGN KEY (vehicle_id) REFERENCES Vehicles(vehicle_id)
);


CREATE TABLE fare_ref (
	start_location VARCHAR(255) NOT NULL,
    end_location VARCHAR(255) NOT NULL,
    fare DECIMAL(10 ,2) NOT NULL
);



CREATE TABLE Trips (
  trip_id INT PRIMARY KEY AUTO_INCREMENT,
  user_id INT NOT NULL,
  driver_id INT NOT NULL,
  vehicle_id INT NOT NULL,
  start_location VARCHAR(255) NOT NULL,
  end_location VARCHAR(255) NOT NULL,
  start_time DATETIME NOT NULL,
  end_time DATETIME,
  fare DECIMAL(10, 2) NOT NULL,
  status ENUM('scheduled', 'ongoing', 'completed', 'cancelled') NOT NULL,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  FOREIGN KEY (user_id) REFERENCES Users(user_id),
  FOREIGN KEY (driver_id) REFERENCES Drivers(driver_id),
  FOREIGN KEY (vehicle_id) REFERENCES Vehicles(vehicle_id)
);




CREATE TABLE Payments (
  payment_id INT PRIMARY KEY AUTO_INCREMENT,
  user_id INT NOT NULL,
  driver_id INT NOT NULL,
  trip_id INT NOT NULL,
  amount DECIMAL(10, 2) NOT NULL,
  status ENUM('pending', 'completed', 'cancelled') NOT NULL,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  FOREIGN KEY (user_id) REFERENCES Users(user_id),
  FOREIGN KEY (driver_id) REFERENCES Drivers(driver_id),
  FOREIGN KEY (trip_id) REFERENCES Trips(trip_id)
);



CREATE TABLE current_location (
  driver_id INT NOT NULL,
  location VARCHAR(255) NOT NULL,
  FOREIGN KEY (driver_id) REFERENCES Drivers(driver_id)
);



CREATE TABLE Ratings (
  rating_id INT PRIMARY KEY AUTO_INCREMENT,
  user_id INT NOT NULL,
  driver_id INT NOT NULL,
  trip_id INT NOT NULL,
  rating DECIMAL(3, 2) NOT NULL,
  comments VARCHAR(255),
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  FOREIGN KEY (user_id) REFERENCES Users(user_id),
  FOREIGN KEY (driver_id) REFERENCES Drivers(driver_id),
  FOREIGN KEY (trip_id) REFERENCES Trips(trip_id)
);
