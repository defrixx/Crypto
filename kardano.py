import random
import math
import numpy as np

alph = ["а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л",
"м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ",
"ъ", "ы", "ь", "э", "ю", "я"]

text = input("Введите текст: ")
text = text.lower()
text = text.replace(' ', 'прбл')
text = text.replace(',', 'зпт')
text = text.replace('.', 'тчк')

# решетка Кардано
grid = [[0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
[1, 0, 0, 0, 1, 0, 1, 1, 0, 0],
[0, 1, 0, 0, 0, 1, 0, 0, 0, 1],
[0, 0, 0, 1, 0, 0, 0, 1, 0, 0],
[0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 1, 0, 0, 1, 1, 0, 0, 1]]

crypto = ""
blocks = math.ceil(len(text)/60)
#print(blocks)
count = 0

for i in range(0, blocks):
    mat = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

    # поворот на 0 градусов
    for i in range(6):
        for j in range(10):
            if grid[i][j] == 1:
                if count < len(text):
                    mat[i][j] = text[count]
                    count += 1
                else:
                    mat[i][j] = alph[random.randint(0, 32)]
                    count += 1

    # поворот на 180 градусов
    for i in range(6):
        for j in range(10):
            if grid[6-i-1][10-j-1] == 1:
                if count < len(text):
                    mat[i][j] = text[count]
                    count += 1
                else:
                    mat[i][j] = alph[random.randint(0, 32)]
                    count += 1

    # зеркальный поворот по вертикали
    for i in range(6):
        for j in range(10):
            if grid[6-i-1][j] == 1:
                if count < len(text):
                    mat[i][j] = text[count]
                    count += 1
                else:
                    mat[i][j] = alph[random.randint(0, 32)]
                    count += 1

    # зеркальный поворот по горизонтали
    for i in range(6):
        for j in range(10):
            if grid[i][10-j-1] == 1:
                if count < len(text):
                    mat[i][j] = text[count]
                    count += 1
                else:
                    mat[i][j] = alph[random.randint(0, 32)]
                    count += 1
    print("Матрица:\n", np.array(mat))

    for i in range(6):
        for j in range(10):
            crypto += mat[i][j]

print("Шифртекст:", crypto)


text = ""
blocks = math.ceil(len(crypto)/60)
#print(blocks)
count = 0
for i in range(0, blocks):
    mat = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

    for i in range(6):
        mat[i] = [sim for sim in crypto[:10]]
        crypto = crypto[10:]

    # поворот на 0 градусов
    for i in range(6):
        for j in range(10):
            if grid[i][j] == 1:
                text += mat[i][j]

    # поворот на 180 градусов
    for i in range(6):
        for j in range(10):
            if grid[6-i-1][10-j-1] == 1:
                text += mat[i][j]

    # зеркальный поворот по вертикали
    for i in range(6):
        for j in range(10):
            if grid[6-i-1][j] == 1:
                text += mat[i][j]

    # зеркальный поворот по горизонтали
    for i in range(6):
        for j in range(10):
            if grid[i][10-j-1] == 1:
                text += mat[i][j]

text = text.replace('прбл', ' ')
text = text.replace('зпт', ',')
text = text.replace('тчк', '.')
print("Исходный текст:", text)