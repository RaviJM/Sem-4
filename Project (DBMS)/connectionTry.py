import pymysql

mydb = pymysql.connect(host="localhost", user="root", passwd="ravi123", database="ravidb")
mycursor = mydb.cursor()
mycursor.execute("show tables")
result = mycursor.fetchall()
print(result)