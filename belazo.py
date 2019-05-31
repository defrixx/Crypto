alph = ["а","б","в","г","д","е","ё","ж","з","и","й","к","л","м","н","о","п","р","с","т","у","ф",
"х","ц","ч","ш","щ","ъ","ы","ь","э","ю","я"]

i = 0
while i == 0:
    print("\n\t\t***БЕЛАЗО***")
    print ("\n\t1 - Зашифровать\n\t2 - Расшифровать\n\t3 - Выход")
    v = input()
    if v == '1':
        print ("Введите текст для зашифрования:")
        text = input()
        text = text.lower()
        print ("Введите ключ:")
        key = input()
        c = ""
        textcount = 0
        keycount = 0
        counter = 0
        for e in text:
            if any(e in s for s in alph):
               c += alph[(alph.index(e) + alph.index(key[counter])) % 33]
               counter += 1
               if counter >= len(key):
                    counter = 0
            else:
                c += e
        print ("Зашифрованный текст: " + c)
    if v == '2':
        print ("Введите текст для расшифрования:")
        text = input()
        text = text.lower()
        print ("Введите ключ:")
        key = input()
        c = ""
        textcount = 0
        keycount = 0
        counter = 0
        for e in text:
            if any(e in s for s in alph): #проверка наличия символа в алфавите
                c += alph[(alph.index(e) - alph.index(key[counter])) % 33]
                counter += 1
                if counter >= len(key):
                    counter = 0
            else:
                c += e
        print ("Расшифрованный текст: " + c)
    else:
        exit()