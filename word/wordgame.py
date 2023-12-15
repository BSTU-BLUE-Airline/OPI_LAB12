import random

with open('text.txt', 'r', encoding='utf-8') as f:
    arrayWord = [line.strip() for line in f]

for line in arrayWord:
    print(line)

def peremesh(s):
    char = list(s)
    random.shuffle(char)
    return ''.join(char)

word = peremesh(arrayWord[0])
print(word)