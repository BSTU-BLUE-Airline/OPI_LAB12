import random
# открытие файла и добавление слов в массив arrayWord
with open('text.txt', 'r', encoding='utf-8') as f:
    arrayWord = [line.strip() for line in f]

# функция которая перемешивает слово
def peremesh(s):
    char = list(s)
    random.shuffle(char)
    return ''.join(char)
print("Добро пожаловать в игру СЛОВА" + "\n" + "Выбирайте режим игры" + "\n" + "1 - легкий" + "\n" + "2 - средний" + "\n" + "3 - тяжелый")
x = int(input("Ваш выбор: "))
def switch(x):
    if x == 1:
        sometext = arrayWord[random.randint(0, 25)]
    elif x == 2:
        sometext = arrayWord[random.randint(26, 50)]
    elif x == 3:
        sometext = arrayWord[random.randint(51, 75)]
    return sometext
txt = switch(x)
wordOriginal = txt
word = peremesh(txt)
print('Слово, которое вам необходимо будет разгадать: ' + word)
some = True
while some:
    myword = input("Введите предполагаемое слово (чтобы выйти напишите ""стоп""): ")
    if wordOriginal == myword:
        print('Вы угадали!!!')
        some = False
    elif myword == "стоп":
        print('Вы сдались( это слово: ' + txt)
        some = False
    else:
        print('Пробуйте еще раз')

