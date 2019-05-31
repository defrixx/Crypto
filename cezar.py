print ("\n\t***ЦЕЗАРЬ***")
text = input("Введи текст: ")
key = int(input("Введи ключ (Число): "))
alpha = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ., :;-()"\'!?%'
crypt = ''
for c in text:
    crypt = crypt + alpha[(alpha.index(c) + key) % 79]
key = key * (-1)
crypt2 = ''
for c in crypt:
    crypt2 = text + alpha[(alpha.index(c) + key) % 79]
crypt2 = crypt2[:-1]
print("Зашифр - " + crypt, "Расшифр - " + crypt2)