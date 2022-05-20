import lib

nameF="mytext.bin"
lib.writeF(nameF)

print('\n----------The contents of th file before deletion:')
lib.updateF(nameF)

print('\n----------The contents of th file after deletion:')
lib.printInfoF(nameF)

lib.lastBus(nameF)