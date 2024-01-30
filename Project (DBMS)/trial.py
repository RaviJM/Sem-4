import pymysql
#connect with mysql connector
mydb = pymysql.connect(host="localhost", user="root", passwd="ravi123", database="ravidb")
mycursor = mydb.cursor()

name = "hij"

mycursor.execute(f'''update fun1 set name = "fghjk" where name="{name}"''')
mydb.commit()
