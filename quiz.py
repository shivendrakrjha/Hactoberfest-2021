print("Hi! Welcome to Ram quiz.")
print("Try to get as many questions correct as possible......")
score=0
noq=5

ans=input("1.The Orang National Park (ONP) is located in which state? ")
if(ans.lower()=="assam"):
    print("Correct!")
    score+=1
else:
    print("Incorrect!")

ans=input("2.Mont Blanc, the highest peak in Alps is located in which among the following countries? ")
if(ans.lower()=="italy and france"):
    print("Correct!")
    score+=1
else:
    print("Incorrect!")

ans=input("3.Ohm is a unit of measuring _________? ")
if(ans.lower()=="resistance"):
    print("Correct!")
    score+=1
else:
    print("Incorrect!")

ans=input("4.Hang-Seng is share market index at which of the following? ")
if(ans.lower()=="hong kong"):
    print("Correct!")
    score+=1
else:
    print("Incorrect!")

ans=input("10.How many judges are there in the International Court of Justice? ")
if(ans.lower()=="15"):
    print("Correct!")
    score+=1
else:
    print("Incorrect!")

print("Thank you for playing, you got",score,"questions correct!")
print("Marks:",str(20*score)+"%")
if(score>2):
    print("Nice! You PASSED!")
else:
    print("Sorry! You FAILED!")
