print ("\n\t***АТБАШ***")
text = input("Введи текст: ")
alpha = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюя'+'АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'+'., :;-()"\'!?%'
ahpla = 'яюэьыъщшчцхфутсрпонмлкйизжёедгвба'+'ЯЮЭЬЫЪЩШЧЦХФУТСРПОНМЛКЙИЗЖЁЕДГВБА'+'%?!\")(-;: ,.'
crypt = ''
for c in text:
    crypt = crypt + ahpla[alpha.index(c)]
for c in crypt:
    crypt2 = text + alpha[ahpla.index(c)]
crypt2 = crypt2[:-1]
print("Зашифр - " + crypt, "Расшифр - " + crypt2)
x = input()