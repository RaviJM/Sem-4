import pymysql

mydb = pymysql.connect(host="localhost", user="root", passwd="ravi123", database="ravidb")
mycursor = mydb.cursor()

st="hij"
mycursor.execute(f'select count(name) from fun1 where name = "{st}"')
a=mycursor.fetchone()

if a[0] == 1:
    print("ek")
else:
    print("nai")









#
# print(st3[0])
# print(st4[0])
#
# # print(result)
#
#
# # if (result[0][1] == None and result[0][0] == 17):
# #     print("yesyesyes")
#
#
# # list1=[]
# # for i in result:
# #     list1.append(i)
# # for i in list1:
# #     print(i)