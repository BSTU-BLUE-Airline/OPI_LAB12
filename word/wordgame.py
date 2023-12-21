import random
import time

# открытие файла и добавление слов в массив arrayWord
with open('text.txt', 'r', encoding='utf-8') as f:
    arrayWord = [line.strip() for line in f]

# функция, которая перемешивает слово
def peremesh(s):
    char = list(s)
    random.shuffle(char)
    return ''.join(char)

while True:  # Бесконечный цикл
    print("Добро пожаловать в игру СЛОВА" + "\n" + "Выбирайте режим игры" + "\n" + "1 - легкий" + "\n" + "2 - средний" + "\n" + "3 - тяжелый" + "\n" + "4 - выход")
    x = int(input("Ваш выбор: "))
    if x == 4:
        print("Выход из игры.")
        break  # Выход из бесконечного цикла

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

    start_time = time.time()
    some = True
    while some:
        elapsed_time = time.time() - start_time
        myword = input("Введите предполагаемое слово (чтобы выйти, напишите 'стоп'): ")

        if wordOriginal == myword:
            print('Вы угадали!!!')
            print('Ваше время: ' + str(round(elapsed_time, 2)) + ' сек.')
            some = False
        elif myword == "стоп":
            print('Вы сдались. Это слово: ' + txt)
            some = False
        else:
            print('Пробуйте еще раз')
