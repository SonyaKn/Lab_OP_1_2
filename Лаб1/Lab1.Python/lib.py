def WriteTo(name):
    num = int(input("Type 1 if you want to create a new file.\n"+ "Type 2 if you want to expand the file.\n"))
    key = chr(24)
    if num == 1:
        with open(name, 'w') as file:
            str = input("Press ENTER to start a new line.\n" + "Press CTRL + X to end the file.\n")
            while str[0] != key:
                file.write(str + '\n')
                str = input()  
    elif num == 2:
        with open(name, 'a') as file:
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
        print("\nThe number of '('  is equal to the number of ')' \n")
    else:
        print("\nThe number of '('  isn`t equal to the number of ')' \n")
    if text.count('{')==text.count('}'):
        print("\nThe number of '{' is equal to the number of '}'\n")
    else:
        print("\nThe number of '{' isn`t equal to the number of '}' \n")
    if text.count('[')==text.count(']'):
        print("\nThe number of '[' is equal to the number of ']'\n")
    else:
        print("\nThe number of '[' isn`t equal to the number of ']' \n")
def Func2(text):
    text=text.split('\n')
    line=''
    counter=0
    for i in range(len(text)):
        line=text[i]
        if line.count('(')!=line.count(')'):
            print("\nIn line [",i+1,"] the number of '('  isn`t equal to the number of ')' \n")
            counter+=1
    if counter==0:
        print("\nThe number of '('  is equal to the number of ')' \n")