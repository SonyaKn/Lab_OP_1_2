def WriteTo(name):
    key = chr(24)
    with open(name, 'w') as file:
        str = input("Press ENTER to start a new line.\n" + "Press CTRL + X to end the file.\n")
        while str[0] != key:
            file.write(str + '\n')
            str = input()    
def ReadingFrom(name):
    with open(name, 'r') as file:
        text=file.read()
        print(text) 
        return text
def Func(text):
    if text.count('(')==text.count(')'):
        print("\nThe number of '(' is equal to the number of ')'\n")
    else:
        print("\nThe number of '(' isn`t equal to the number of ')'\n")