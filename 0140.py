from time import sleep
import os

def text():
    os.system('cls' if os.name == 'nt' else 'clear')
    print("🕑 ТАЙМЕР\nПиши секунды: ", end="")
    timer()

def timer():
    time_for_timer = int(input())
    os.system('cls' if os.name == 'nt' else 'clear')
    for seconds in range(time_for_timer):
        print(f"Время: {seconds + 1}", end="")
        for milliseconds in range(1, 9):
            print(f".{milliseconds}")
            os.system('cls' if os.name == 'nt' else 'clear')
            sleep(0.1)
        sleep(1)
        os.system('cls' if os.name == 'nt' else 'clear')
    text()

text()