import random
import time
import os

def peremesh(s):
    char = list(s)
    random.shuffle(char)
    return ''.join(char)

def clearConsole():
    os.system('cls')

arrayWord = [
    'кот', 'дом', 'солнце', 'дерево', 'цветок', 'книга', 'вода', 'птица', 'молоко', 'день',
    'ночь', 'окно', 'мама', 'папа', 'звезда', 'дождь', 'друзья', 'игра', 'школа', 'радуга',
    'медведь', 'рыба', 'песок', 'зима', 'весна', 'архитектура', 'интеллект', 'реакция',
    'решение', 'конструкция', 'критерий', 'оригинальность', 'перспектива', 'концентрация',
    'абстракция', 'гипотеза', 'дисциплина', 'комбинация', 'квалификация', 'репрезентация',
    'конфликт', 'организация', 'пропорция', 'трансформация', 'корреляция', 'структура',
    'иллюзия', 'актуализация', 'реализация', 'инновация', 'эквивалентность', 'элегантность',
    'рентгенография', 'эпистемология', 'антропоморфизм', 'экзистенциализм', 'метафизика',
    'хронометраж', 'холокост', 'экспериментальность', 'интеллектуальность', 'контингент',
    'экспоненциальность', 'тенденциозность', 'коллективизация', 'экзегеза', 'идеология',
    'эпифании', 'антагонистичность', 'параллелепипед', 'экстравагантность', 'катастрофа',
    'абстракционизм', 'ренессанс', 'трансцендентальность'
]

def switch(x):
    if x == 1:
        return arrayWord[random.randint(0, 25)]
    elif x == 2:
        return arrayWord[random.randint(26, 50)]
    elif x == 3:
        return arrayWord[random.randint(51, 75)]

points = 0
times = 0
sessionCount = 0
attemptCount = 0
proigCount = 0

print("Добро пожаловать в игру СЛОВА")
while True:
    print("Выбирайте режим игры\n1 - легкий\n2 - средний\n3 - тяжелый\n4 - если хотите узнать статистику текущей сессии\n5 - очистить консоль\n6 - выход")
    try:
        userChoice = int(input("Ваш выбор: "))
    except ValueError:
        print("Введите корректное число.")
        continue

    if userChoice == 4:
        print("Количество ваших очков: " + str(points))
        if points != 0:
            print("Среднее время на ответ: " + str(round((times / sessionCount), 3)) + " сек")
        print('Количество побед/проигрышей за сессию: ' + str(sessionCount) + "/" + str(proigCount))
        continue
    elif userChoice == 6:
        print("Выход из игры.")
        break
    elif userChoice == 5:
        clearConsole()
        continue

    if userChoice not in [1, 2, 3]:
        print("Некорректный выбор уровня сложности.")
        continue

    wordToGuess = switch(userChoice)
    originalWord = wordToGuess
    scrambledWord = peremesh(wordToGuess)
    print('Слово, которое вам необходимо будет разгадать: ' + scrambledWord)

    startTime = time.time()
    isRunning = True

    while isRunning:
        userGuess = input("Введите предполагаемое слово (чтобы выйти, напишите 'стоп'): ").lower()
        attemptCount += 1
        if originalWord == userGuess:
            points += userChoice
            times += round(time.time() - startTime, 2)
            print('Вы угадали!!!')
            print('Ваше время: ' + str(round(time.time() - startTime, 2)) + ' сек.')
            isRunning = False
            sessionCount += 1
            attemptCount = 0
        elif userGuess == "стоп":
            print('Вы сдались. Это слово: ' + wordToGuess)
            isRunning = False
            proigCount += 1
            attemptCount = 0
        else:
            if attemptCount == 5:
                nstr = ""
                print("У вас есть возможность воспользоваться подсказкой, введите букву, а мы покажем ее расположение в слове")
                n = input("Ваша буква: ")
                for bukv in originalWord:
                    if bukv == n:
                        nstr += bukv
                    else:
                        nstr += "*"
                print("Ваша подсказка: " + nstr)
            print('Пробуйте еще раз')
