import lib
name="myFile.txt"
lib.WriteTo(name)
print("Your text:\n")
text=lib.ReadingFrom(name)
lib.Func(text)
