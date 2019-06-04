global code
global decode
alphavite = 'абвгдежзийклмнопрстуфхцчшщъыьэюя'  # алфавит
alphavite2 = alphavite.upper()
alphavite3 = ',.!:\'\"#?@[](){} '
text = input("Введите текст сообщения: ")
code = ''  # Зашифрованное сообщение
slow = 0
for i in text:  # блок шифрования
    if i.islower():
        code += alphavite[(alphavite.find(i) + slow) % len(alphavite)]
    elif i.isupper():
        code += alphavite2[(alphavite2.find(i) + slow) % len(alphavite2)]
    else:
        code += alphavite3[(alphavite3.find(i) + slow) % len(alphavite3)]
    slow += 1
print("Зашифрованное сообщение", code)
decode = ''
text_decode = code
if code == '':
    text_decode = text
slow = 0
for i in text_decode:
    if i.islower():
        decode += alphavite[(alphavite.find(i) - slow) % len(alphavite)]
    elif i.isupper():
        decode += alphavite2[(alphavite2.find(i) - slow) % len(alphavite2)]
    else:
        decode += alphavite3[(alphavite3.find(i) - slow) % len(alphavite3)]
    slow += 1
print("Расшифрованное сообщение", decode)