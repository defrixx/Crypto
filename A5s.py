import random

alph = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: "

s = input("Введите сообщение: ")    # ввод сообщения
np = len(s)
while len(s) % 9 != 0:
	randd = random.randint(0, 65)
	s2 = alph[randd]
	s = s + s2

dva = [0]*10000
#for i in range(0, 10000):
#	dva[i] = 0
for i in range(0, len(s)):
	# 256||128||64||32||16||8||4||2||1
	pos = alph.find(s[i])
	if pos >= 256:
		dva[i * 9 + 0] = 1
		pos = pos - 256
	if pos >= 128:
		dva[i * 9 + 1] = 1
		pos = pos - 128
	if pos >= 64:
		dva[i * 9 + 2] = 1
		pos = pos - 64
	if pos >= 32:
		dva[i * 9 + 3] = 1
		pos = pos - 32
	if pos >= 16:
		dva[i * 9 + 4] = 1
		pos = pos - 16
	if pos >= 8:
		dva[i * 9 + 5] = 1
		pos = pos - 8
	if pos >= 4:
		dva[i * 9 + 6] = 1
		pos = pos - 4
	if pos >= 2:
		dva[i * 9 + 7] = 1
		pos = pos - 2
	if pos == 1:
		dva[i * 9 + 8] = 1

# Перевод в двоичный код
dvoich = ""
for i in range(0, int(len(s) * 9)):
	dvoich += str(dva[i])
print("Двочный код:", dvoich)

# Генерация ключа
print_key = ""
sh = [0]*9000
gamma = [0]*81
for i in range(0, 81):
	randd = random.randint(0, 1) # Рандом от 0 до 1
	gamma[i] = randd
	print_key += str(gamma[i])

print("Сгенерированный ключ:", print_key)

for i in range(0, 4500):
	sh[i] = 0

# Выработка гаммы
for j in range(0, 4500):
	F = gamma[67] and gamma[71] or gamma[71] and gamma[74] or gamma[74] and gamma[67]
	if F == gamma[8]:
		zam = gamma[18] ^ gamma[17] ^ gamma[16] ^ gamma[13]
		gamma[18] = gamma[17]
		gamma[17] = gamma[16]
		gamma[16] = gamma[15]
		gamma[15] = gamma[14]
		gamma[14] = gamma[13]
		gamma[13] = gamma[12]
		gamma[12] = gamma[11]
		gamma[11] = gamma[10]
		gamma[10] = gamma[9]
		gamma[9] = gamma[8]
		gamma[8] = gamma[7]
		gamma[7] = gamma[6]
		gamma[6] = gamma[5]
		gamma[5] = gamma[4]
		gamma[4] = gamma[3]
		gamma[3] = gamma[2]
		gamma[2] = gamma[1]
		gamma[1] = gamma[0]
		gamma[0] = zam

	if F == gamma[29]:
		zam = gamma[40] ^ gamma[39]
		gamma[40] = gamma[39]
		gamma[39] = gamma[38]
		gamma[38] = gamma[37]
		gamma[37] = gamma[36]
		gamma[36] = gamma[35]
		gamma[35] = gamma[34]
		gamma[34] = gamma[33]
		gamma[33] = gamma[32]
		gamma[32] = gamma[31]
		gamma[31] = gamma[30]
		gamma[30] = gamma[29]
		gamma[29] = gamma[28]
		gamma[28] = gamma[27]
		gamma[27] = gamma[26]
		gamma[26] = gamma[25]
		gamma[25] = gamma[24]
		gamma[24] = gamma[23]
		gamma[23] = gamma[22]
		gamma[22] = gamma[21]
		gamma[21] = gamma[20]
		gamma[20] = gamma[19]
		gamma[19] = zam

	if F == gamma[51]:
		zam = gamma[63] ^ gamma[62] ^ gamma[61] ^ gamma[48]
		gamma[63] = gamma[62]
		gamma[62] = gamma[61]
		gamma[61] = gamma[60]
		gamma[60] = gamma[59]
		gamma[59] = gamma[58]
		gamma[58] = gamma[57]
		gamma[57] = gamma[56]
		gamma[56] = gamma[55]
		gamma[55] = gamma[54]
		gamma[54] = gamma[53]
		gamma[53] = gamma[52]
		gamma[52] = gamma[51]
		gamma[51] = gamma[50]
		gamma[50] = gamma[49]
		gamma[49] = gamma[48]
		gamma[48] = gamma[47]
		gamma[47] = gamma[46]
		gamma[46] = gamma[45]
		gamma[45] = gamma[44]
		gamma[44] = gamma[43]
		gamma[43] = gamma[42]
		gamma[42] = gamma[41]
		gamma[41] = zam
		zam = gamma[80] ^ gamma[74]
		gamma[80] = gamma[79]

print_gamma = ""
for i in range(0, int(len(s)*9)):
	print_gamma += str(sh[i])
print("Выработанная гамма:", print_gamma)


# Шифруем текст в двоичном коде
encrypt_dv_code = ""

for i in range(0, int(len(s)/9)):
	for j in range(0, 81):
		dva[j + i * 81] = dva[j + i * 81] ^ sh[j]
		encrypt_dv_code += str(dva[j + i * 81])
print("Зашифрованный текст (в двоичном виде):", encrypt_dv_code)


# Расишфровываем текст в двоичном коде
decrypt_dv_code = ""
for i in range(0, int(len(s)/9)):
	for j in range(0, 81):
		dva[j + i * 81] = dva[j + i * 81] ^ sh[j]
		decrypt_dv_code += str(dva[j + i * 81])

print("Расшифрованный текст (в двоичном виде):", decrypt_dv_code)

# Переводи расшифрованный двоичный код в текст
decrypt = ""
for i in range(0, len(s)):
	# 128||64||32||16||8||4||2||1
	pos = 0
	if dva[i * 9 + 0] == 1:
		pos = pos + 256
	if dva[i * 9 + 1] == 1:
		pos = pos + 128
	if dva[i * 9 + 2] == 1:
		pos = pos + 64
	if dva[i * 9 + 3] == 1:
		pos = pos + 32
	if dva[i * 9 + 4] == 1:
		pos = pos + 16
	if dva[i * 9 + 5] == 1:
		pos = pos + 8
	if dva[i * 9 + 6] == 1:
		pos = pos + 4
	if dva[i * 9 + 7] == 1:
		pos = pos + 2
	if dva[i * 9 + 8] == 1:
		pos = pos + 1
	decrypt += str(alph[int(pos)])

print("Расшифрованный текст:", decrypt)
